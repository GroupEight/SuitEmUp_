//Level.cpp//

#include "Level_Wall.hpp"

#include <sstream>
#include <fstream>
#include <iostream>

#include <typeinfo>

#include "CollisionMan.h"
#include "NodeMan.h"
#include "TextureMan.h"

#include "EnemyObject.hpp"
#include "Goal.h"
#include "Hidden_Wall.hpp"
#include "Morker.h"
#include "PlayerObject.h"

Wall::Wall(sf::Vector2f p_xPos, float p_fAng, float p_fHe){
 m_xPos = p_xPos;

 m_fAng = p_fAng;
 m_fHe = p_fHe;
}

Darkness::Darkness(sf::Vector2f p_xPos, sf::Vector2f p_xSize, float p_fRot, PlayerObject *p_xpPlayer){
 m_xRect.setPosition(p_xPos);
 m_xRect.setSize(p_xSize);
 m_xRect.setFillColor(sf::Color::Black);
 
 m_xpPlayer = p_xpPlayer;
}

bool Darkness::Update(){
 if (m_xpPlayer->getPosition().x > m_xRect.getPosition().x && m_xpPlayer->getPosition().x  < m_xRect.getPosition().x + m_xRect.getSize().x){
  if (m_xpPlayer->getPosition().y > m_xRect.getPosition().y && m_xpPlayer->getPosition().y < m_xRect.getPosition().y + m_xRect.getSize().y){
   return true;
  }
 }
 return false;
}

Level::Level(std::string p_sDir, SoundPlayer *p_xpSPlayer, TextureMan *p_xpTextMan, CollisionMan *p_xpCMan, NodeMan *p_xpEnemyMan, NodeMan *p_xpEBulletMan, NodeMan *p_xpStarman, PlayerObject *p_xpPlayer)
: mParallax( 0.2 ){
 m_xpPlayer = p_xpPlayer;
 m_sDir = p_sDir;
 m_xpSPlayer = p_xpSPlayer;

 m_xpCMan = p_xpCMan;
 m_xpTexMan = p_xpTextMan;

 m_xpEnemyMan = p_xpEnemyMan;
 m_xpEBulletMan = p_xpEBulletMan;
 m_xpStarman = p_xpStarman;

 m_xpTex = p_xpTextMan->Get("Wall");
 m_xpTex->setRepeated( true );
 m_xpTex->setSmooth( true );
}

Level::~Level(){
 ClearLevel();
}

bool Level::LoadLevel(std::string p_sFile){
	m_xpGoal = NULL;

    std::string l_sData = m_sDir + p_sFile;

    std::ifstream stream;
    stream.open(l_sData.c_str());

    if (!stream.is_open()){
        return false;
    }

    std::string row;
    stream >> row;

    while (!stream.eof()) {
        std::getline(stream, row);
        if (row.length() == 0){
            continue;
        }
        std::stringstream ss(row);

        std::string l_sType;

        ss >> l_sType;

        if (l_sType.compare("#") == 0){
            row = "";
            continue;
        }

  // Walls:
        if (l_sType.compare("Wall") == 0){

            float l_fPosx, l_fPosy, l_fAng = 0.f, l_fHe = 0.f;

            ss >> l_fPosx;
            ss >> l_fPosy;

            if (row.length() != 0){
                ss >> l_fAng;
            }

            if (row.length() != 0){
                ss >> l_fHe;
            }

   m_xaWalls.push_back(new Wall(sf::Vector2f(l_fPosx, l_fPosy), l_fAng, l_fHe));

            row = "";

            continue;
        }

  // Hidden_Walls:
        if (l_sType.compare("Hidden_Wall") == 0){

            float l_fPosx, l_fPosy, l_fRot, l_fDist;

            ss >> l_fPosx;
            ss >> l_fPosy;

            if (row.length() != 0){
                ss >> l_fRot;
            }
			
			if (row.length() != 0){
                ss >> l_fDist;
            }
			
			m_xaHWalls.push_back(new Hidden_Wall(sf::Vector2f(l_fPosx, l_fPosy), l_fRot, l_fDist, m_xpPlayer, m_xpTexMan, m_xpCMan));

            row = "";

            continue;
        }

  // Darkness
  if (l_sType.compare("Darkness") == 0){

            float l_fPosx, l_fPosy, l_fHe, l_fWi, l_fRot;

            ss >> l_fPosx;
            ss >> l_fPosy;

	ss >> l_fWi;
   ss >> l_fHe;

   ss >> l_fRot;

   m_xaDarkness.push_back(new Darkness(sf::Vector2f(l_fPosx, l_fPosy), sf::Vector2f(l_fWi, l_fHe), l_fRot, m_xpPlayer));

            row = "";

            continue;
        }

        // Enemy:
        if (l_sType.compare("Enemy_W") == 0){
            float l_fPosx, l_fPosy, l_fAggro, l_fAtk, l_fRot;

            int l_iType;
   
   ss >> l_fPosx;
   ss >> l_fPosy;
   ss >> l_fAggro;
   ss >> l_fAtk;
   ss >> l_iType;
   ss >> l_fRot;

   m_xpEnemyMan->Add(new EnemyObject(m_xpCMan, m_xpTexMan, m_xpStarman, 5, 0, l_fAggro, sf::Vector2f(l_fPosx, l_fPosy), m_xpPlayer, l_fRot, m_xpSPlayer ));

            row = "";

            continue;
        }

		if (l_sType.compare("Enemy_M") == 0){
            float l_fPosx, l_fPosy, l_fAggro, l_fAtk, l_fRot;

            int l_iType;
			ss >> l_fPosx;
			ss >> l_fPosy;
			ss >> l_fAggro;
			ss >> l_fAtk;
			ss >> l_iType;
			ss >> l_fRot;
			
			m_xpEnemyMan->Add(new Morker(m_xpCMan, m_xpTexMan, l_fAggro, l_fAtk, sf::Vector2f(l_fPosx, l_fPosy), m_xpPlayer, m_xpEBulletMan, m_xpStarman, m_xpSPlayer, l_fRot));

            row = "";

            continue;
        }
		
        if (l_sType.compare("Player") == 0){
   float l_fPosx, l_fPosy;

   ss >> l_fPosx;
            ss >> l_fPosy;
           
   m_xpPlayer->SetPosition(sf::Vector2f(l_fPosx, l_fPosy));

            row = "";

            continue;
        }

		// Goal
		if (l_sType.compare("Goal") == 0){
            float l_fPosx, l_fPosy, l_fRadius;

			ss >> l_fPosx;
			ss >> l_fPosy;
			ss >> l_fRadius;
			
			if (m_xpGoal != NULL){
				delete m_xpGoal;
				m_xpGoal = NULL;
			}

			m_xpGoal = new Goal(sf::Vector2f(l_fPosx, l_fPosy), l_fRadius, m_xpPlayer, m_xpTexMan);

            row = "";

            continue;
        }
    }

    stream.close();
 
 MakeWalls();

 placeWallVertices();

    //Collision:

 vs = new b2Vec2 [m_xaWalls.size()];
 for (int i = 0; i < m_xaWalls.size(); i++){
  vs[i].Set(m_xaWalls[i]->m_xPos.x / 32, m_xaWalls[i]->m_xPos.y / 32);
 }

 b2BodyDef groundBodyDef;
 groundBodyDef.type = b2_staticBody;

 //b2Body* staticbody = mBWorld->CreateBody(&groundBodyDef);
 m_xpLevelBody = m_xpCMan->GetWorld()->CreateBody(&groundBodyDef);

 b2ChainShape chain;

 chain.CreateLoop(vs, m_xCVertices.getVertexCount() - 1);
 
 b2FixtureDef fixtureDef;
 fixtureDef.shape = &chain;
 fixtureDef.density = 0.0f;
 b2Fixture* myFixture = m_xpLevelBody->CreateFixture(&fixtureDef);

    return true;
}

void Level::ClearLevel(){
 m_xpEnemyMan->DeleteAll();

 m_xCVertices.clear();
 m_xCVertexSpec.clear();
 
 m_xRoof.clear();
 m_xWalls.clear();

 m_xpCMan->GetWorld()->DestroyBody(m_xpLevelBody);

 for (int i = m_xaWalls.size() - 1; i >= 0; i--){
  delete m_xaWalls[i];
  m_xaWalls[i] = NULL;
 }

 m_xaWalls.clear();

 delete m_xpGoal;
 m_xpGoal = NULL;
}

void Level::MakeWalls(){
 m_xCVertices.setPrimitiveType(sf::Points);  m_xCVertices.resize(m_xaWalls.size());
 m_xCVertexSpec.setPrimitiveType(sf::Points); m_xCVertexSpec.resize(m_xaWalls.size());
 m_xWalls.setPrimitiveType(sf::TrianglesStrip); m_xWalls.resize(m_xaWalls.size() * 2);
 m_xRoof.setPrimitiveType(sf::TrianglesStrip); m_xRoof.resize(m_xaWalls.size() * 2);

 for (int i = 0; i < m_xaWalls.size(); i++){
  m_xCVertices[i].position = m_xaWalls[i]->m_xPos;
  m_xCVertexSpec[i].position = sf::Vector2f(m_xaWalls[i]->m_fAng, m_xaWalls[i]->m_fHe);
 }
}

/*void Level::createControlVertex(sf::Vector2f _pos, float _ang, float _height){
 m_xCVertices.setPrimitiveType(sf::Points);  m_xCVertices.resize(47);
 m_xCVertexSpec.setPrimitiveType(sf::Points); m_xCVertices.resize(47);
 m_xWalls.setPrimitiveType(sf::TrianglesStrip); m_xCVertices.resize(100);
 m_xRoof( sf::TrianglesStrip, 100 );

 m_xCVertexSpec[v].position = sf::Vector2f( _ang, _height );
 m_xCVertices[v].position = _pos;

 //Collision
 vs[v].Set( _pos.x / 32.f, _pos.y / 32.f );

 v++;
}*/

void Level::placeWallVertices(){
 float angleBetweenPoints = 0;
 float distanceBetweenPoints = 0;
 float wallHeight = 50.f;
 int lastVertex = m_xCVertices.getVertexCount()-1;

 int q = 0;

 for(int i = 0; i < m_xaWalls.size(); i++){
  float offsetAngle = m_xCVertexSpec[i].position.x * 3.141592 / 180;
  float offsetHeight = m_xCVertexSpec[i].position.y;

  //float camDistance = sqrt( ( (m_xCVertices[i].position.x - cPos.x) * (m_xCVertices[i].position.x - cPos.x) ) + ( (m_xCVertices[i].position.y - cPos.y) * (m_xCVertices[i].position.y - cPos.y) ) );
  float camDistanceX = m_xCVertices[i].position.x - m_xpPlayer->getPosition().x;
  float camDistanceY = m_xCVertices[i].position.y - m_xpPlayer->getPosition().y;
  
  //ANGLE
  if (i>0 && i<lastVertex){
   angleBetweenPoints = (90.f * 3.141592 / 180) + atan2f( ( m_xCVertices[i+1].position.y - m_xCVertices[i-1].position.y ), ( m_xCVertices[i+1].position.x - m_xCVertices[i-1].position.x ) );
  }
  else {
   angleBetweenPoints = (90.f * 3.141592 / 180);
  }

 //POSITION
  m_xWalls[q].position = sf::Vector2f( m_xCVertices[i].position.x, m_xCVertices[i].position.y );
  m_xWalls[q+1].position = sf::Vector2f( mParallax * camDistanceX + m_xCVertices[i].position.x + cosf( angleBetweenPoints + offsetAngle ) * (wallHeight + offsetHeight), mParallax * camDistanceY + m_xCVertices[i].position.y + sinf( angleBetweenPoints + offsetAngle ) * (wallHeight + offsetHeight) );

  m_xRoof[q].position = sf::Vector2f( m_xWalls[q+1].position.x + cosf( angleBetweenPoints + offsetAngle ) * -1, m_xWalls[q+1].position.y + sinf( angleBetweenPoints + offsetAngle ) * -1 );
  m_xRoof[q+1].position = sf::Vector2f( m_xWalls[q+1].position.x + cosf( angleBetweenPoints + offsetAngle ) * ( 1000.f ), m_xWalls[q+1].position.y + sinf( angleBetweenPoints + offsetAngle ) * ( 1000.f ) );

  //ROOF COLOR
  m_xRoof[q].color = sf::Color::Black;
  m_xRoof[q+1].color = sf::Color::Black;
  
  //TEX-COORDS
  if (i>0){
   float _x = m_xCVertices[i-1].position.x - m_xCVertices[i].position.x;
   float _y = m_xCVertices[i-1].position.y - m_xCVertices[i].position.y;
   distanceBetweenPoints = sqrtf( ( _x * _x ) + ( _y * _y ) );

   //Add the length of the new quad to the last texCoords to make sure that the textures isn't stretched/squashed.
   m_xWalls[q].texCoords = sf::Vector2f( m_xWalls[q-1].texCoords.x + distanceBetweenPoints, m_xpTex->getSize().y );
   m_xWalls[q+1].texCoords = sf::Vector2f( m_xWalls[q-1].texCoords.x + distanceBetweenPoints, 0 );
  }
  else {
   m_xWalls[q].texCoords = sf::Vector2f( 0, m_xpTex->getSize().y );
   m_xWalls[q+1].texCoords = sf::Vector2f( 0, 0 );
  }
  q+=2;
 }

 //Fix for weird extra vertex added
 /*m_xWalls[q-1].position = m_xWalls[q-2].position;
 m_xWalls[q-1].texCoords = m_xWalls[q-2].texCoords;
 m_xRoof[q-1].position = m_xRoof[q-2].position;
 m_xRoof[q-1].color = sf::Color::Black;*/ 
}

sf::Vector2f Level::getControlVertexPos( int index ){
 return m_xCVertices[index].position;
}

bool Level::Update(sf::Time dt){
	setCameraPos(m_xpPlayer->getPosition());
	placeWallVertices();
	
	for (int i = 0; i < m_xaHWalls.size(); i++){
		m_xaHWalls[i]->SetCameraPos(cPos);
		m_xaHWalls[i]->Update(dt);
	}
	
	for (int i = m_xaDarkness.size() - 1; i >= 0; i--){
		if (m_xaDarkness[i] != NULL){
			if (m_xaDarkness[i]->Update()){
				delete m_xaDarkness[i];
				m_xaDarkness[i] = NULL;
			}
		}
	}
	
	if (m_xpGoal != NULL){
		return m_xpGoal->Update(dt);
	}

	return false;
}

void Level::setCameraPos( sf::Vector2f pos ){
 cPos = pos;
}

void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	m_xpGoal->draw(target, states);

 glEnable( GL_CULL_FACE );

 states.texture = m_xpTex;
 target.draw( m_xWalls, states );

 glDisable( GL_CULL_FACE );

 states.texture = nullptr;
 target.draw( m_xRoof, states );

 for (int i = 0; i < m_xaDarkness.size(); i++){
  if (m_xaDarkness[i] != NULL){
   target.draw(m_xaDarkness[i]->m_xRect);
  }
 }

 for (int i = 0; i < m_xaHWalls.size(); i++){
  m_xaHWalls[i]->draw(target, states);
 }
}