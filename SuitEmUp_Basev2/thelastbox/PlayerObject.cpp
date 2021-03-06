//PlayerObject.cpp//

#include "PlayerObject.h"

#include "PlayerBullet.hpp"

#include "Animation.hpp"
#include "Player_Arms.hpp"
#include "Tool_Whip.hpp"

#include "CollisionMan.h"
#include "InputMan.h"
#include "NodeMan.h"
#include "SoundPlayer.hpp"
#include "TextureMan.h"
#include "SoundPlayer.hpp"
#include "EnemyObject.hpp"

<<<<<<< HEAD
PlayerObject::PlayerObject(sf::RenderWindow *p_xpWindow, CollisionMan *p_xpCollisionMan, NodeMan *p_xpBulletMan, TextureMan *p_xpTextureMan, NodeMan *p_xpEBulletMan, NodeMan *p_xpEnemyMan, SoundPlayer *p_xpSPlayer){

	m_xPos = sf::Vector2f(0, 0);

	m_xpEBulletMan = p_xpEBulletMan;
	m_xpEnemyMan = p_xpEnemyMan;
=======
PlayerObject::PlayerObject(sf::RenderWindow *p_xpWindow, CollisionMan *p_xpCollisionMan, NodeMan *p_xpBulletMan, TextureMan *p_xpTextureMan, InputMan *p_xpIMan){
	m_xPos = sf::Vector2f(0, 0);

	m_xpWindow = p_xpWindow;

>>>>>>> 5301b7ce945568afbd97112a1b45c6472c1ec48b
	m_xpBulletMan = p_xpBulletMan;
	m_xpCollisionMan = p_xpCollisionMan;
	m_xpIMan = p_xpIMan;
	m_xpTextureMan = p_xpTextureMan;
	m_xpWindow = p_xpWindow;
	m_xpSPlayer = p_xpSPlayer;

	
	m_xpBody = p_xpCollisionMan->GetNewBody(sf::Vector2f(m_xPos.x, m_xPos.y), 1.0f, 1);

	m_xpIdleTex = m_xpTextureMan->Get("Player_Idle");
	m_xpRunTex = m_xpTextureMan->Get("Player_Run");
	m_xpSStepTex = m_xpTextureMan->Get("Player_Side_Step");
	m_xpCrossbowTex = m_xpTextureMan->Get("Crossbow");
	m_xpBulletTex = m_xpTextureMan->Get("Player_Bullet");

	//m_xpAnimation = new Animation;

	m_xpIdleAnim = new Animation(m_xpIdleTex);
	m_xpIdleAnim->setReversed( false );
	m_xpIdleAnim->setOrigin(sf::Vector2f(m_xpIdleAnim->getFrameSize().x / 2, m_xpIdleAnim->getFrameSize().y / 2));
	m_xpIdleAnim->restart();
	m_xpIdleAnim->setFrameSize( sf::Vector2i( 177, 291 ) );
	m_xpIdleAnim->setDuration( sf::seconds( 0.8f ) );
	m_xpIdleAnim->setNumFrames( 12 );
	m_xpIdleAnim->setRepeating( true );
	m_xpIdleAnim->setScale( 1.f, 1.f );

	m_xpRunAnim = new Animation(m_xpRunTex);
	m_xpRunAnim->setReversed( false );
	m_xpRunAnim->setOrigin(sf::Vector2f(m_xpRunAnim->getFrameSize().x / 2, m_xpRunAnim->getFrameSize().y / 2));
	m_xpRunAnim->restart();
	m_xpRunAnim->setFrameSize( sf::Vector2i( 177, 291 ) );
	m_xpRunAnim->setDuration( sf::seconds( 0.7f ) );
	m_xpRunAnim->setNumFrames( 16 );
	m_xpRunAnim->setRepeating( true );
	m_xpRunAnim->setScale( 0.9f, 0.9f );

	m_xpStepAnim = new Animation(m_xpSStepTex);
	m_xpStepAnim->setReversed( false );
	m_xpStepAnim->restart();
	m_xpStepAnim->setFrameSize( sf::Vector2i( 356, 291 ) );
	m_xpStepAnim->setDuration( sf::seconds( 0.7f ) );
	m_xpStepAnim->setNumFrames( 12 );
	m_xpStepAnim->setRepeating( true );
	m_xpStepAnim->setScale( 1.f, 1.f );

	m_xpCrossbow = new Animation(m_xpCrossbowTex);
<<<<<<< HEAD
	m_xpCrossbow->setRotation( 90 );
=======
	m_xpCrossbow->setOrigin( m_xpCrossbow->getFrameSize().x / 10, m_xpCrossbow->getFrameSize().y / 2  + GetPosition().x);
	//m_xpCrossbow->setOrigin(GetPosition());
	m_xpCrossbow->setPosition( 280.f, -90.f );
>>>>>>> 5301b7ce945568afbd97112a1b45c6472c1ec48b
	m_xpCrossbow->setReversed( false );
	m_xpCrossbow->setFrameSize( sf::Vector2i( 178, 291 ) );
	m_xpCrossbow->setDuration( sf::seconds( 0.4f ) );
	m_xpCrossbow->setNumFrames( 7 );
	m_xpCrossbow->setRepeating( true );
	m_xpCrossbow->setScale( 1.f, 1.f );
	m_xpCrossbow->setOrigin( m_xpCrossbow->getFrameSize().x/2, m_xpCrossbow->getFrameSize().y );


	setState( State::Idle );
	setTool( Tool::Crossbow ); // Start tool

<<<<<<< HEAD
	m_xpPlayerArms[0] = new Player_Arms(m_xpTextureMan, -1);
	m_xpPlayerArms[0]->setOrigin( 0.f, -30.f );
	m_xpPlayerArms[1] = new Player_Arms(m_xpTextureMan, 1);
	m_xpPlayerArms[1]->setOrigin( 0.f, 30.f );
=======
	m_xpPlayerArms[0] = new Player_Arms(m_xpTextureMan, 1, this);
	m_xpPlayerArms[0]->setPosition(sf::Vector2f(getPosition().x + 10, getPosition().y + 10));

	m_xpPlayerArms[1] = new Player_Arms(m_xpTextureMan, -1, this);
	m_xpPlayerArms[1]->setPosition(sf::Vector2f(getPosition().x + 10, getPosition().y + 10));
>>>>>>> 5301b7ce945568afbd97112a1b45c6472c1ec48b

	m_fPlayerspd = 1080.0f; // Players movement speed
	m_fBulletspd = 1024.0f; // The speed that the players bullets fly in

<<<<<<< HEAD
	m_fFrate = 1.f; // How many bullets the player can shoot every second
	m_fMaxrate = 3.f; // How much a "second" is in the above statement
=======
	m_fFrate = 1.0f; // How many bullets the player can shoot every second
	m_fMaxrate = 64.0f; // How much time a "second" is in the above statement
>>>>>>> 5301b7ce945568afbd97112a1b45c6472c1ec48b
	m_fFiretime = 0.0f; // How long ago the player fired his weapon

	m_fHeat = 0.0f; // The currrent weapon-heat
	m_fHeatup = 4.0f; // How much the heat increases with every shot
	m_fCooldown = 4.0f; // How much the heat decreases with each passing second
	m_fMaxheat = 25.0f; // When m_fHeat is greater than this the player is rendered unable to shoot
	m_fMinheat = 15.0f; // If the player's weapon is overheated then it has to coll down to this much

	m_fSuit = GetMaxHp();

	m_fInvMax = 0.2f;
	m_fInv = m_fInvMax;

	//Whip
	m_xpWhip = new Tool_Whip( m_xpTextureMan );
	m_xpWhip->setOrigin( 50.f, 0.f );

	m_xWhipPos = sf::Vector2f( 0.f, 0.f );

	m_bOverheat = false; // Wether the weapon is overheated or not

<<<<<<< HEAD
	punchArm = false;
=======
	m_bPunchArm = false;

	m_fSuit = 100.f;
>>>>>>> 5301b7ce945568afbd97112a1b45c6472c1ec48b
}

PlayerObject::~PlayerObject(){
	if (m_xpCurrentAnim != NULL){
		delete m_xpCurrentAnim;
		m_xpCurrentAnim = NULL;
	}
	if (m_xpCurrentAnim != NULL){
		delete m_xpCurrentAnim;
		m_xpCurrentAnim = NULL;
	}
	if (m_xpCurrentAnim != NULL){
		delete m_xpCurrentAnim;
		m_xpCurrentAnim = NULL;
	}
	if (m_xpCurrentAnim != NULL){
		delete m_xpCurrentAnim;
		m_xpCurrentAnim = NULL;
	}
	if (m_xpCrossbow != NULL){
		delete m_xpCrossbow;
		m_xpCrossbow = NULL;
	}
}

void PlayerObject::Damage(float p_fDmg){
	m_fSuit-= p_fDmg;
}

void PlayerObject::Damage(float p_fDmg){
	m_fSuit-= p_fDmg;

	m_fInv = m_fInvMax;
}

void PlayerObject::setTool(PlayerObject::Tool tool){
	if (m_eTool != tool){
		m_eTool = tool;
	}
}

void PlayerObject::setState(PlayerObject::State state){
	if( m_eState != state ){

		m_eState = state;

		switch (m_eState){
		case PlayerObject::Idle:
			m_xpIdleAnim->setReversed( false );
			m_xpCurrentAnim = m_xpIdleAnim;
			m_xpCurrentAnim->setOrigin(m_xpCurrentAnim->getFrameSize().x/2, m_xpCurrentAnim->getFrameSize().y/2);
			m_xpCurrentAnim->restart();
			break;
		case PlayerObject::Run_F:
			m_xpRunAnim->setReversed( false );
			m_xpCurrentAnim = m_xpRunAnim;
			m_xpCurrentAnim->setOrigin(m_xpCurrentAnim->getFrameSize().x/2, m_xpCurrentAnim->getFrameSize().y/2);
			m_xpCurrentAnim->restart();
			break;
		case PlayerObject::Run_B:
			m_xpRunAnim->setReversed( true );
			m_xpCurrentAnim = m_xpRunAnim;
			m_xpCurrentAnim->setOrigin(m_xpCurrentAnim->getFrameSize().x/2, m_xpCurrentAnim->getFrameSize().y/2);
			m_xpCurrentAnim->restart();
			break;
		case PlayerObject::Run_L:
			m_xpStepAnim->setReversed( false );
			m_xpCurrentAnim = m_xpStepAnim;
			m_xpCurrentAnim->setOrigin(m_xpCurrentAnim->getFrameSize().x/2, m_xpCurrentAnim->getFrameSize().y/2);
			m_xpCurrentAnim->restart();
			break;
		case PlayerObject::Run_R:
			m_xpStepAnim->setReversed( true );
			m_xpCurrentAnim = m_xpStepAnim;
			m_xpCurrentAnim->setOrigin(m_xpCurrentAnim->getFrameSize().x/2, m_xpCurrentAnim->getFrameSize().y/2);
			m_xpCurrentAnim->restart();
			break;
		default:
			break;
		}
	}
}

<<<<<<< HEAD
/*void PlayerObject::setCursorPosition(sf::Vector2f _pos){
	//mLArm->setArmsPosition( sqrtf( (_pos.x - 1280/2.f) * (_pos.x - 1280/2.f) + (_pos.y - 720/2.f) * (_pos.y - 720/2.f) ) );
	//mRArm->setArmsPosition( sqrtf( (_pos.x - 1280/2.f) * (_pos.x - 1280/2.f) + (_pos.y - 720/2.f) * (_pos.y - 720/2.f) ) );
	mLArm->setArmsPosition( _pos );
	mRArm->setArmsPosition( _pos );
}*/

void PlayerObject::doWhip(sf::Vector2f _pos){
	m_xpBody->GetFixtureList()->SetDensity(10.f);
	m_xpBody->ResetMassData();
	m_xWhipPos = _pos;
	setState( State::Whipping );
	m_xpWhip->setState( Tool_Whip::Whipping );
}

=======
>>>>>>> 5301b7ce945568afbd97112a1b45c6472c1ec48b
PlayerObject::State PlayerObject::GetState(){
	return m_eState;
}

PlayerObject::Tool PlayerObject::GetTool(){
	return m_eTool;
}

<<<<<<< HEAD
NodeMan *PlayerObject::GetPBulletMan(){
	return m_xpBulletMan;
}

float PlayerObject::GetHp(){
	return m_fSuit;
}

float PlayerObject::GetMaxHp(){
	return 100.f;
}

int PlayerObject::GetStars(){
	return m_iStarCount;
}

void PlayerObject::SetStars(int p){
	m_iStarCount = p;
}

void PlayerObject::StarsPlus(){
	m_iStarCount++;
}

bool PlayerObject::GetInv(){
	if (m_fInv > 0.f){
		return true;
	}
	else {
		return false;
	}
}

bool PlayerObject::Update(sf::Time p_xDtime){
	m_fRadius = 5.f;

=======
void PlayerObject::Update(sf::Time p_xDtime){
>>>>>>> 5301b7ce945568afbd97112a1b45c6472c1ec48b
	m_xVel = sf::Vector2f(sf::Keyboard::isKeyPressed(sf::Keyboard::D) - sf::Keyboard::isKeyPressed(sf::Keyboard::A), sf::Keyboard::isKeyPressed(sf::Keyboard::S) - sf::Keyboard::isKeyPressed(sf::Keyboard::W));
	m_xVel.x = (m_xVel.x * m_fPlayerspd * (float)p_xDtime.asSeconds());
	m_xVel.y = (m_xVel.y * m_fPlayerspd * (float)p_xDtime.asSeconds());

<<<<<<< HEAD
	 sf::Vector2f cursorPos = sf::Vector2f( ( (float)sf::Mouse::getPosition(*m_xpWindow).x - m_xpWindow->getViewport( m_xpWindow->getView() ).width/2 )*1.5, ( (float)sf::Mouse::getPosition(*m_xpWindow).y - m_xpWindow->getViewport( m_xpWindow->getView() ).height/2 )*1.5 );

	 float l_fRot = atan2f( cursorPos.x, cursorPos.y) * 180.f / 3.141592f;

	 setRotation( -l_fRot );


	 if( sf::Keyboard::isKeyPressed( sf::Keyboard::LShift ) ){
	  setTool( Tool::Whip ); 
  
	  if( m_xpWhip->getState() == Tool_Whip::Inactive || m_xpWhip->getState() == Tool_Whip::Passive ){
	   m_xpWhip->setState( Tool_Whip::Swinging );
	  }else if( m_xpWhip->getState() == Tool_Whip::Swinging ){
	   if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) ){
		for ( SceneNode* e : m_xpEnemyMan->GetVector() ){
		  if (e != NULL) {
		 EnemyObject *_e = dynamic_cast<EnemyObject*>(e);

		 float cursorToEDist_Y = e->getPosition().y - (m_xpCurrentAnim->getPosition().y + cursorPos.y);
		 float cursorToEDist_X = e->getPosition().x - (m_xpCurrentAnim->getPosition().x + cursorPos.x);
		 float cursorToEDist = sqrtf( pow( cursorToEDist_X, 2 ) + pow( cursorToEDist_Y, 2 ) );

		 if( cursorToEDist < 50.f ){
		  doWhip( e->getPosition() );
		  }
		 }
		}
	   }
	  }
	}else{

		if( m_xpWhip->getState() == Tool_Whip::Passive ){
			m_xpWhip->Update(p_xDtime);
		}
		if( m_xpWhip->getState() == Tool_Whip::Swinging ){
			m_xpWhip->setState( Tool_Whip::Passive );
		}
	}
=======
	//setRotation( atan2f( (sf::Mouse::getPosition().y - m_xpWindow->getSize().y / 2 + m_xpWindow->getPosition().y), (sf::Mouse::getPosition().x - m_xpWindow->getSize().x / 2) ) * 180.f / 3.141592f + m_xpWindow->getPosition().x);
	float l_fRot = atan2f( (sf::Mouse::getPosition().x - 1280.f / 1 + m_xpWindow->getPosition().x), (sf::Mouse::getPosition().y - 720.f / 1 + m_xpWindow->getPosition().y) ) * 180.f / 3.141592f;

	l_fRot+= 0;
>>>>>>> 5301b7ce945568afbd97112a1b45c6472c1ec48b

	setRotation(-l_fRot);

	//m_xpAnimation[0]->setOrigin(m_xpAnimation[0]->getFrameSize().x/2, m_xpAnimation[0]->getFrameSize().y/2);
	//m_xpAnimation[1]->setOrigin(m_xpAnimation[1]->getFrameSize().x/2, m_xpAnimation[1]->getFrameSize().y/2);
	m_xpCrossbow->update(p_xDtime);
	m_xpWhip->Update(p_xDtime);

	if( m_eState == State::Whipping ){
		sf::Vector2f _dir = sf::Vector2f( m_xWhipPos.x - getPosition().x, m_xWhipPos.y - getPosition().y );
		float _dist = sqrtf( pow( _dir.x, 2 ) + pow( _dir.y, 2 ) );

		m_xpWhip->setWhipDistance( _dist );

		if( m_xpWhip->getState() == Tool_Whip::Dragging ){
			
			m_xVel = _dir / 2.f;
			setRotation( -90.f + atan2f( m_xVel.y, m_xVel.x ) * 180 / 3.141592 );

			if( _dist < 50.f ){
				m_xpBody->GetFixtureList()->SetDensity(1.f);
				m_xpBody->ResetMassData();

				setState( State::Idle );
				setTool( Tool::Crossbow );
				m_xpWhip->setState( Tool_Whip::Inactive );
			}
		}
	}else{

		if (m_xVel != sf::Vector2f(0, 0)){ //As long as the player is pressing at least one of the movement-keys, 
			// this is to prevent the character from returning to original position/rotation.
			float velRot = atan2f( m_xVel.y, m_xVel.x ) * 180 / 3.141592;
   if( velRot < 0 ){
    velRot = 180 - velRot*-1 + 180;
   }
   float _rot = atan2f(sinf((getRotation()- 90.f) * 3.141592 / 180), cosf((getRotation() - 90.f) * 3.141592 / 180)) * 180 / 3.141592 + 180;

   float rotComp = velRot - _rot;
   if( rotComp < 0 ){
    rotComp = 180 - rotComp*-1 + 180;
   }

   std::cout << rotComp << std::endl;
   if ( rotComp < 45 || rotComp > 315 ){
    setState(State::Run_F); //Set state for animations etc
   }
   else if ( rotComp < 90+45 && rotComp > 90-45 ){
    setState(State::Run_R);
   }
   else if ( rotComp < 270+45 && rotComp > 270-45 ){
    setState(State::Run_L);
   }
   else {
    setState(State::Run_B);
   }
			/*if (((atan2f( m_xVel.y, m_xVel.x ) * 180 / 3.141592) < getRotation() + 45.f) && ((atan2f( m_xVel.y, m_xVel.x) * 180 / 3.141592) > getRotation() - 45.f)){
				setState(State::Run_F); //Set state for animations etc
			}
			else if (((atan2f(m_xVel.y, m_xVel.x) * 180 / 3.141592) >= getRotation() + 45.f) && ((atan2f( m_xVel.y, m_xVel.x) * 180 / 3.141592) <= getRotation() + 135.f)){
				setState(State::Run_R);
			}
			else if (((atan2f(m_xVel.y, m_xVel.x) * 180 / 3.141592) <= getRotation() - 45.f) && ((atan2f( m_xVel.y, m_xVel.x) * 180 / 3.141592) >= getRotation() - 135.f)){
				setState(State::Run_L);
			}
			else {
				setState(State::Run_B);
			}*/
			//m_xpBody->SetLinearVelocity(b2Vec2(cosf(getRotation()) * 50.f / 32.f * (float)p_xDtime.asMilliseconds() , sin(getRotation())  * 50.f / 32.f * (float)p_xDtime.asMilliseconds()));
			//setPosition(m_xpBody->GetPosition().x * 32.f, m_xpBody->GetPosition().y * 32.f);
			//m_xPos = sf::Vector2f(m_xpBody->GetPosition().x * 32.f, m_xpBody->GetPosition().y * 32.f);
		} else {
			setState(State::Idle);
			m_xpBody->SetLinearVelocity( b2Vec2(0.f, 0.f));
		
			//setPosition(m_xpBody->GetPosition().x * 32.f, m_xpBody->GetPosition().y * 32.f);
		}
	}

<<<<<<< HEAD
		m_xpBody->SetLinearVelocity(b2Vec2(m_xVel.x, m_xVel.y));
		setPosition(m_xpBody->GetPosition().x * 32.f, m_xpBody->GetPosition().y * 32.f);
		m_xpCurrentAnim->setPosition(getPosition());
		m_xpCurrentAnim->setRotation(getRotation());
		m_xpCrossbow->setPosition(getPosition());
		m_xpCrossbow->setRotation(getRotation() + 180.f);
		m_xpWhip->setPosition(getPosition());
		m_xpWhip->setRotation(getRotation());
		m_xpPlayerArms[0]->setPosition(getPosition());
		m_xpPlayerArms[0]->setRotation(getRotation() + 90.f);
		m_xpPlayerArms[1]->setPosition(getPosition());
		m_xpPlayerArms[1]->setRotation(getRotation() + 90.f);
		
		switch (m_eState){
		case PlayerObject::Idle:
			m_xpIdleAnim->update(p_xDtime);
			break;
		case PlayerObject::Run_F:
			m_xpRunAnim->update(p_xDtime);
			break;
		case PlayerObject::Run_B:
			m_xpRunAnim->update(p_xDtime);
			break;
		case PlayerObject::Run_L:
			m_xpStepAnim->update(p_xDtime);
			break;
		case PlayerObject::Run_R:
			m_xpStepAnim->update(p_xDtime);
			break;
		default:
			break;
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_fFiretime <= 0 ){ //&& m_fFiretime > (m_fMaxrate / m_fFrate) && m_bOverheat == false
			if (GetTool() == Tool::Crossbow){

			m_fFiretime = m_fFrate / m_fMaxrate;
=======
	m_xpBody->SetLinearVelocity(b2Vec2(m_xVel.x, m_xVel.y));
	setPosition(m_xpBody->GetPosition().x * 32.f, m_xpBody->GetPosition().y * 32.f);
	m_xpCurrentAnim->setPosition(getPosition());
	m_xpCurrentAnim->setRotation(getRotation());
	m_xpCrossbow->setPosition(getPosition());
	m_xpCrossbow->setRotation(getRotation());
	for (int i = 0; i < 2; i++){
		m_xpPlayerArms[i]->setPosition(GetPosition());
		m_xpPlayerArms[i]->setRotation(0);
		m_xpPlayerArms[i]->setArmsPosition(sf::Mouse::getPosition(), l_fRot);
	}

	switch (m_eState){
	case PlayerObject::Idle:
		m_xpIdleAnim->update(p_xDtime);
		break;
	case PlayerObject::Run_F:
		m_xpRunAnim->update(p_xDtime);
		break;
	case PlayerObject::Run_B:
		m_xpRunAnim->update(p_xDtime);
		break;
	case PlayerObject::Run_L:
		m_xpStepAnim->update(p_xDtime);
		break;
	case PlayerObject::Run_R:
		m_xpStepAnim->update(p_xDtime);
		break;
	default:
		break;
	}

	m_fSuit-= (float)p_xDtime.asSeconds();
	std::cout << m_fSuit << std::endl;

	//if (m_xpIMan->KeyIsDown(sf::Mouse::Button::Left) && m_fFiretime > (m_fFrate / m_fMaxrate) ){ //&& m_fFiretime > (m_fMaxrate / m_fFrate) && m_bOverheat == false
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && m_fFiretime > (m_fFrate / m_fMaxrate) ){ //&& m_fFiretime > (m_fMaxrate / m_fFrate) && m_bOverheat == false
		m_fFiretime = 0;
		if (GetTool() == Tool::Crossbow){

			m_fFiretime = m_fFrate;
>>>>>>> 5301b7ce945568afbd97112a1b45c6472c1ec48b
			m_xpBulletMan->Add(new PlayerBullet(m_xpTextureMan, getPosition(), getRotation()));
		}
		else {
			setTool(Tool::Crossbow);
		}
	}else if( sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ){
		setTool(Tool::Whip);
	}

<<<<<<< HEAD
	//std::cout << m_fSuit;
	/*if (m_fSuit <= 0){
		return true;
	}*/

	for (int i = m_xpEBulletMan->GetVector().size() - 1; i >= 0; i--){
		if (m_xpEBulletMan->GetVector()[i] != NULL){
			if (m_xpEBulletMan->GetVector()[i]->Overlap(getPosition(), m_fRadius)){
				std::cout << getPosition().x << " : " << getPosition().y << std::endl;
				m_xpEBulletMan->Delete(m_xpEBulletMan->GetVector()[i]);
				m_fSuit--;
			}
		}
	}

	 m_xpPlayerArms[0]->setArmsPosition(sf::Vector2f(0, 0));
	 m_xpPlayerArms[1]->setArmsPosition(sf::Vector2f(0, 0));

	 if( sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) ){

	  switch (punchArm){ // false = Left Arm, true = Right Arm
	  case false:
	   if( !m_xpPlayerArms[0]->m_bPunching){
		if( m_eTool == Tool::Melee ){
		 int s = rand() % 3;

		 m_xpPlayerArms[0]->Punch();

		 punchArm = true;
		}
		else {
		 setTool( Tool::Melee );
		}
	   }
	   break;
	  case true:
	   if ( !m_xpPlayerArms[1]->m_bPunching){
		if( m_eTool == Tool::Melee ){
		 int s = rand() % 3;

		 //m_xpPlayerArms[1]->Punch();

		 punchArm = false;
		}
		else {
		 setTool( Tool::Melee );
		}
	   }
	   break;
	  }
	 }
	if (m_fSuit <= 0.f){
		return true;
	}

	//std::cout << m_fSuit << std::endl;

	m_fSuit-= (float)p_xDtime.asSeconds();
	m_fFiretime-= (float)p_xDtime.asSeconds();
	m_fInv-= (float)p_xDtime.asSeconds();

	return false;
}

void PlayerObject::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(*m_xpCurrentAnim, states);
	target.draw( *m_xpPlayerArms[0], states );
	target.draw( *m_xpPlayerArms[1], states );

	if( m_eTool == Tool::Crossbow){
		target.draw(*m_xpCrossbow, states);
	}
	
	target.draw(*m_xpWhip, states);
=======
	//if (m_xpIMan->KeyIsDown(sf::Mouse::Button::Right) && m_fFiretime > (m_fFrate / m_fMaxrate)){
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) && m_fFiretime > (m_fFrate / m_fMaxrate)){
		if( m_eTool == Tool::Melee ){
			m_fFiretime = 0.125 * (m_fFrate / m_fMaxrate);
			int s = rand() % 3;

			m_xpPlayerArms[m_bPunchArm]->Punch();
			//m_xpSPlayer->Play("Cymbal_Hit" + s);
			m_bPunchArm = rand() % 2;

			if (m_bPunchArm){
				m_bPunchArm = false;
			}
			else if (!m_bPunchArm){
				m_bPunchArm = true;
			}
		}
		else {
			setTool( Tool::Melee );
		}
	}

	m_fFiretime+= (float)p_xDtime.asSeconds();

	/*if (m_fSuit <= 0.f){
		return true;
	}
	return false;*/
}

void PlayerObject::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(*m_xpPlayerArms[0], states);
	target.draw(*m_xpPlayerArms[1], states);

	if ( m_eTool == Tool::Crossbow){
		target.draw(*m_xpCrossbow, states);
	}
	
	target.draw(*m_xpCurrentAnim, states);
>>>>>>> 5301b7ce945568afbd97112a1b45c6472c1ec48b
}