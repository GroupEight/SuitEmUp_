#include "Level_Wall.hpp"
#include "SFML\OpenGL.hpp"
#include <Windows.h>
#include <sstream>
#include <typeinfo>

#include "TextureMan.h"

Level_Wall::Level_Wall(TextureMan *p_xpTextMan, b2World *p_xpWorld)
: controlVertices( sf::Points, 47)
, controlVertexSpec(sf::Points, controlVertices.getVertexCount())
, mWalls( sf::TrianglesStrip, 100 )
, mRoof( sf::TrianglesStrip, 100 )
, mParallax( 0.2 ){
	m_xpTex = p_xpTextMan->Get("Walls");
	m_xpTex->setRepeated( true );
	m_xpTex->setSmooth( true );

	if (placeControlVertices()){
		placeWallVertices();

		//Collision
		b2BodyDef groundBodyDef;
		groundBodyDef.type = b2_staticBody;

		b2Body* staticbody = mBWorld->CreateBody(&groundBodyDef);

		b2ChainShape chain;

		chain.CreateLoop(vs, controlVertices.getVertexCount() - 1);
	
		b2FixtureDef fixtureDef;
		fixtureDef.shape = &chain;
		fixtureDef.density = 0.0f;
		b2Fixture* myFixture = staticbody->CreateFixture(&fixtureDef);
	}
}

bool Level_Wall::placeControlVertices(){
	v = 0;

	createControlVertex( sf::Vector2f( 0, 550 ));
	createControlVertex( sf::Vector2f( 500, 550 ));
	createControlVertex( sf::Vector2f( 600, 450 ));
	createControlVertex( sf::Vector2f( 700, 225 ));
	createControlVertex( sf::Vector2f( 750, 0 ));
	createControlVertex( sf::Vector2f( 700, -225 ));
	createControlVertex( sf::Vector2f( 600, -450 ));
	createControlVertex( sf::Vector2f( 500, -550 ), 10.f);
	createControlVertex( sf::Vector2f( 300, -550 ), 20.f);
	createControlVertex( sf::Vector2f( 200, -600 ), -5.f, 10.f);
	createControlVertex( sf::Vector2f( 125, -750 ), -20.f);
	createControlVertex( sf::Vector2f( 125, -1300 ), 20.f);
	createControlVertex( sf::Vector2f( 200, -1450 ), -40.f, -20.f);

	//Passage 2 Right
	createControlVertex( sf::Vector2f( 1500, -1450 ));

	//Room 2
	createControlVertex( sf::Vector2f( 1600, -1250 ));
	createControlVertex( sf::Vector2f( 1800, -1150 ));
	createControlVertex( sf::Vector2f( 1900, -1150 ));
	createControlVertex( sf::Vector2f( 2300, -1200 ));
	createControlVertex( sf::Vector2f( 2500, -1450 ));
	createControlVertex( sf::Vector2f( 2500, -1700 ));
	createControlVertex( sf::Vector2f( 2300, -1950 ));
	createControlVertex( sf::Vector2f( 1900, -2000 ));
	createControlVertex( sf::Vector2f( 1800, -2000 ));
	createControlVertex( sf::Vector2f( 1600, -1900 ));

	//Passage 2 Left
	createControlVertex( sf::Vector2f( 1500, -1800 ));

	createControlVertex( sf::Vector2f( 300, -1800 ));
	createControlVertex( sf::Vector2f( 200, -1850 ));
	createControlVertex( sf::Vector2f( 125, -1900 ));

	createControlVertex( sf::Vector2f( 0, -1925 ));

	createControlVertex( sf::Vector2f( -125, -1900 ));
	createControlVertex( sf::Vector2f( -200, -1750 ));
	createControlVertex( sf::Vector2f( -225, -1600 ));
	createControlVertex( sf::Vector2f( -200, -1450 ), 20.f);
	createControlVertex( sf::Vector2f( -150, -1300 ), -20.f);
	createControlVertex( sf::Vector2f( -150, -750 ), 20.f);
	createControlVertex( sf::Vector2f( -200, -600 ), 5.f, 10.f);
	createControlVertex( sf::Vector2f( -300, -550 ), -20.f);
	createControlVertex( sf::Vector2f( -500, -550 ), -10.f);
	createControlVertex( sf::Vector2f( -600, -450 ));
	createControlVertex( sf::Vector2f( -700, -225 ), 0.f, -50.f);

	//Passage 3 Left
	createControlVertex( sf::Vector2f( -1350, -225 ));

	// Hidden room 1
	createControlVertex( sf::Vector2f( -1450, 0 ));

	//Passage 3 Right
	createControlVertex( sf::Vector2f( -1350, 225 ));

	createControlVertex( sf::Vector2f( -700, 225 ), 0.f, -50.f);
	createControlVertex( sf::Vector2f( -600, 450 ));
	createControlVertex( sf::Vector2f( -500, 550 ));
	createControlVertex( sf::Vector2f( 0, 550 ));

	return true;
}

sf::Vector2f Level_Wall::getControlVertexPos( int index ){
	return controlVertices[index].position;
}

void Level_Wall::createControlVertex(sf::Vector2f _pos, float _ang, float _height){
	controlVertexSpec[v].position = sf::Vector2f( _ang, _height );
	controlVertices[v].position = _pos;

	//Collision
	vs[v].Set( _pos.x / 32.f, _pos.y / 32.f );

	v++;
}

void Level_Wall::placeWallVertices(){
	float angleBetweenPoints = 0;
	float distanceBetweenPoints = 0;
	float wallHeight = 50.f;
	int lastVertex = controlVertices.getVertexCount()-1;

	int q = 0;

	for(int i = 0; i<=lastVertex; i++)
	{
		float offsetAngle = controlVertexSpec[i].position.x * 3.141592 / 180;
		float offsetHeight = controlVertexSpec[i].position.y;

		//float camDistance = sqrt( ( (controlVertices[i].position.x - cPos.x) * (controlVertices[i].position.x - cPos.x) ) + ( (controlVertices[i].position.y - cPos.y) * (controlVertices[i].position.y - cPos.y) ) );
		float camDistanceX = controlVertices[i].position.x - cPos.x;
		float camDistanceY = controlVertices[i].position.y - cPos.y;
		
		//ANGLE
		if(i>0 && i<lastVertex){
			angleBetweenPoints = (90.f * 3.141592 / 180) + atan2f( ( controlVertices[i+1].position.y - controlVertices[i-1].position.y ), ( controlVertices[i+1].position.x - controlVertices[i-1].position.x ) );
		}else{
			angleBetweenPoints = (90.f * 3.141592 / 180);
		}
		

		//POSITION
		mWalls[q].position = sf::Vector2f( controlVertices[i].position.x, controlVertices[i].position.y );
		mWalls[q+1].position = sf::Vector2f( mParallax * camDistanceX + controlVertices[i].position.x + cosf( angleBetweenPoints + offsetAngle ) * (wallHeight + offsetHeight), mParallax * camDistanceY + controlVertices[i].position.y + sinf( angleBetweenPoints + offsetAngle ) * (wallHeight + offsetHeight) );

		mRoof[q].position = sf::Vector2f( mWalls[q+1].position.x + cosf( angleBetweenPoints + offsetAngle ) * -1, mWalls[q+1].position.y + sinf( angleBetweenPoints + offsetAngle ) * -1 );
		mRoof[q+1].position = sf::Vector2f( mWalls[q+1].position.x + cosf( angleBetweenPoints + offsetAngle ) * ( 800.f ), mWalls[q+1].position.y + sinf( angleBetweenPoints + offsetAngle ) * ( 800.f ) );

		//ROOF COLOR
		mRoof[q].color = sf::Color::Black;
		mRoof[q+1].color = sf::Color::Black;

		
		//TEX-COORDS
		if(i>0){
			float _x = controlVertices[i-1].position.x - controlVertices[i].position.x;
			float _y = controlVertices[i-1].position.y - controlVertices[i].position.y;
			distanceBetweenPoints = sqrtf( ( _x * _x ) + ( _y * _y ) );

			//Add the length of the new quad to the last texCoords to make sure that the textures isn't stretched/squashed.
			mWalls[q].texCoords = sf::Vector2f( mWalls[q-1].texCoords.x + distanceBetweenPoints, m_xpTex->getSize().y );
			mWalls[q+1].texCoords = sf::Vector2f( mWalls[q-1].texCoords.x + distanceBetweenPoints, 0 );
		}else{
			mWalls[q].texCoords = sf::Vector2f( 0, m_xpTex->getSize().y );
			mWalls[q+1].texCoords = sf::Vector2f( 0, 0 );
		}
		

		q+=2;
	}

	//Fix for weird extra vertex added
	mWalls[q].position = mWalls[q-1].position;
	mWalls[q].texCoords = mWalls[q-1].texCoords;
	mRoof[q].position = mRoof[q-1].position;
	mRoof[q].color = sf::Color::Black;
	
}

void Level_Wall::Update(sf::Time dt){
	placeWallVertices();
}

void Level_Wall::setCameraPos( sf::Vector2f pos ){
	cPos = pos;
}

void Level_Wall::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	glEnable( GL_CULL_FACE );

	states.texture = m_xpTex;
	target.draw( mWalls, states );

	glDisable( GL_CULL_FACE );

	states.texture = nullptr;
	target.draw( mRoof, states );
}