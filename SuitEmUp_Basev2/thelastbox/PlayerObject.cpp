//PlayerObject.cpp//

#include "PlayerObject.h"

#include "PlayerBullet.hpp"

#include "Animation.hpp"
#include "Player_Arms.hpp"

#include "CollisionMan.h"
#include "InputMan.h"
#include "NodeMan.h"
#include "SoundPlayer.hpp"
#include "TextureMan.h"

PlayerObject::PlayerObject(sf::RenderWindow *p_xpWindow, CollisionMan *p_xpCollisionMan, NodeMan *p_xpBulletMan, TextureMan *p_xpTextureMan, InputMan *p_xpIMan){
	m_xPos = sf::Vector2f(0, 0);

	m_xpWindow = p_xpWindow;

	m_xpBulletMan = p_xpBulletMan;
	m_xpCollisionMan = p_xpCollisionMan;
	m_xpIMan = p_xpIMan;
	m_xpTextureMan = p_xpTextureMan;

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
	//m_xpCrossbow->getsetRotation( 0 );
	m_xpCrossbow->setOrigin( m_xpCrossbow->getFrameSize().x / 10, m_xpCrossbow->getFrameSize().y / 2 );
	//m_xpCrossbow->setOrigin(GetPosition());
	m_xpCrossbow->setPosition( 280.f, -90.f );
	m_xpCrossbow->setReversed( false );
	m_xpCrossbow->setFrameSize( sf::Vector2i( 178, 291 ) );
	m_xpCrossbow->setDuration( sf::seconds( 0.4f ) );
	m_xpCrossbow->setNumFrames( 7 );
	m_xpCrossbow->setRepeating( true );
	m_xpCrossbow->setScale( 1.f, 1.f );

	setState( State::Idle );
	setTool( Tool::Crossbow ); // Start tool

	m_xpPlayerArms[0] = new Player_Arms(m_xpTextureMan, 0);
	m_xpPlayerArms[0]->setPosition(GetPosition());

	m_xpPlayerArms[1] = new Player_Arms(m_xpTextureMan, 0);
	m_xpPlayerArms[1]->setPosition(GetPosition());

	m_fPlayerspd = 720.0f; // Players movement speed
	m_fBulletspd = 5.0f; // The speed that the players bullets fly in

	m_fFrate = 1.5f; // How many bullets the player can shoot every second
	m_fMaxrate = 1.0f; // How much a "second" is in the above statement
	m_fFiretime = 0.0f; // How long ago the player fired his weapon

	m_fHeat = 0.0f; // The currrent weapon-heat
	m_fHeatup = 4.0f; // How much the heat increases with every shot
	m_fCooldown = 4.0f; // How much the heat decreases with each passing second
	m_fMaxheat = 25.0f; // When m_fHeat is greater than this the player is rendered unable to shoot
	m_fMinheat = 15.0f; // If the player's weapon is overheated then it has to coll down to this much

	m_bOverheat = false; // Wether the weapon is overheated or not

	m_bPunchArm = false;
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

void PlayerObject::setTool(PlayerObject::Tool tool){
	if(m_eTool != tool){
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

PlayerObject::State PlayerObject::GetState(){
	return m_eState;
}

PlayerObject::Tool PlayerObject::GetTool(){
	return m_eTool;
}

void PlayerObject::Update(sf::Time p_xDtime){
	m_xVel = sf::Vector2f(sf::Keyboard::isKeyPressed(sf::Keyboard::D) - sf::Keyboard::isKeyPressed(sf::Keyboard::A), sf::Keyboard::isKeyPressed(sf::Keyboard::S) - sf::Keyboard::isKeyPressed(sf::Keyboard::W));
	m_xVel.x = (m_xVel.x * m_fPlayerspd * (float)p_xDtime.asSeconds());
	m_xVel.y = (m_xVel.y * m_fPlayerspd * (float)p_xDtime.asSeconds());
	//std::cout << m_xpBody->GetPosition().x << ": " << m_xpBody->GetPosition().y << std::endl;

	setRotation( atan2f( (sf::Mouse::getPosition().y - m_xpWindow->getSize().y / 2 + m_xpWindow->getPosition().y), (sf::Mouse::getPosition().x - m_xpWindow->getSize().x / 2) ) * 180.f / 3.141592f + m_xpWindow->getPosition().x);
	//setRotation( atan2f( (sf::Mouse::getPosition().x - 1280.f / 2), (sf::Mouse::getPosition().y - 720.f / 2 + m_xpWindow->getPosition().y) ) * 180.f / 3.141592f + m_xpWindow->getPosition().x);

	//m_xpAnimation[0]->setOrigin(m_xpAnimation[0]->getFrameSize().x/2, m_xpAnimation[0]->getFrameSize().y/2);
	//m_xpAnimation[1]->setOrigin(m_xpAnimation[1]->getFrameSize().x/2, m_xpAnimation[1]->getFrameSize().y/2);
	m_xpCrossbow->update(p_xDtime);

	if (m_xVel != sf::Vector2f(0, 0)){ //As long as the player is pressing at least one of the movement-keys, 
		// this is to prevent the character from returning to original position/rotation.
		if (((atan2f( m_xVel.y, m_xVel.x ) * 180 / 3.141592) < getRotation() + 45.f) && ((atan2f( m_xVel.y, m_xVel.x) * 180 / 3.141592) > getRotation() - 45.f)){
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
		}
		//m_xpBody->SetLinearVelocity(b2Vec2(cosf(getRotation()) * 50.f / 32.f * (float)p_xDtime.asMilliseconds() , sin(getRotation())  * 50.f / 32.f * (float)p_xDtime.asMilliseconds()));
		//setPosition(m_xpBody->GetPosition().x * 32.f, m_xpBody->GetPosition().y * 32.f);
		//m_xPos = sf::Vector2f(m_xpBody->GetPosition().x * 32.f, m_xpBody->GetPosition().y * 32.f);
	}
	else {
		setState(State::Idle);
		m_xpBody->SetLinearVelocity( b2Vec2(0.f, 0.f));
		
		//setPosition(m_xpBody->GetPosition().x * 32.f, m_xpBody->GetPosition().y * 32.f);
	}

	m_xpBody->SetLinearVelocity(b2Vec2(m_xVel.x, m_xVel.y));
	setPosition(m_xpBody->GetPosition().x * 32.f, m_xpBody->GetPosition().y * 32.f);
	m_xpCurrentAnim->setPosition(getPosition());
	m_xpCurrentAnim->setRotation(getRotation());
	m_xpCrossbow->setPosition(getPosition());
	m_xpCrossbow->setRotation(getRotation());
	for (int i = 0; i < 2; i++){
		m_xpPlayerArms[0]->setPosition(GetPosition());
		m_xpPlayerArms[0]->setRotation(getRotation());
		m_xpPlayerArms[0]->setArmsPosition(sf::Mouse::getPosition());
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

	//if (m_xpIMan->KeyIsDown(sf::Mouse::Button::Left) && m_fFiretime > (m_fFrate / m_fMaxrate) ){ //&& m_fFiretime > (m_fMaxrate / m_fFrate) && m_bOverheat == false
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && m_fFiretime > (m_fFrate / m_fMaxrate) ){ //&& m_fFiretime > (m_fMaxrate / m_fFrate) && m_bOverheat == false
		if (GetTool() == Tool::Crossbow){

			m_fFiretime = m_fFrate;
			m_xpBulletMan->Add(new PlayerBullet(m_xpTextureMan, getPosition(), getRotation()));
		}
		else {
			setTool(Tool::Crossbow);
		}
	}

	//if (m_xpIMan->KeyIsDown(sf::Mouse::Button::Right) && m_fFiretime > (m_fFrate / m_fMaxrate)){
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) && m_fFiretime > (m_fFrate / m_fMaxrate)){
		if( m_eTool == Tool::Melee ){
			int s = rand() % 3;

			m_xpPlayerArms[m_bPunchArm]->Punch();
//			m_xpSPlayer->Play("Cymbal_Hit" + s);
			m_bPunchArm = rand() % 2;

			/*if (m_bPunchArm){
				m_bPunchArm = false;
			}
			else if (!m_bPunchArm){
				m_bPunchArm = true;
			}*/
		}
		else {
			setTool( Tool::Melee );
		}
	}

	m_fFiretime+= (float)p_xDtime.asSeconds();
}

void PlayerObject::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(*m_xpCurrentAnim, states);

	if (m_eTool == Tool::Melee){
		target.draw(*m_xpPlayerArms[0], states);
		target.draw(*m_xpPlayerArms[1], states);
	}
	else if ( m_eTool == Tool::Crossbow){
		target.draw(*m_xpCrossbow, states);
	}
}