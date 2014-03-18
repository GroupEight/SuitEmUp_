//EnemyObject.cpp//

#include "EnemyObject.hpp"

#include "Animation.hpp"

#include "PlayerObject.h"
#include "Player_Arms.hpp"
#include "Star.h"

#include "CollisionMan.h"
#include "NodeMan.h"
#include "TextureMan.h"
#include "SoundPlayer.hpp"

<<<<<<< HEAD
EnemyObject::EnemyObject(CollisionMan *p_xpCollisionMan, TextureMan *p_xpTexMan, NodeMan *p_xpStarman, int p_iHp, float p_fPow, float p_fAggroRange, sf::Vector2f p_xStartpos, PlayerObject *p_xpPlayer, float p_fRot, SoundPlayer *p_xpSPlayer){
	m_xPos = p_xStartpos;

	m_xpPlayer = p_xpPlayer;

	m_xpPBulletMan = m_xpPlayer->GetPBulletMan();

	m_xpStarman = p_xpStarman;

	m_xpTexMan = p_xpTexMan;

	m_xpCMan = p_xpCollisionMan;

	m_xpSPlayer = p_xpSPlayer;

	m_fAggroRange = p_fAggroRange;
	m_fAttackRange = 4.f;
=======
EnemyObject::EnemyObject(CollisionMan *p_xpCollisionMan, TextureMan *p_xpTexMan, int p_iHp, float p_fPow, float p_fAggroRange, sf::Vector2f p_xStartpos, PlayerObject *p_xpPlayer){
	m_xPos = p_xStartpos;
	
	m_fAggroRange = p_fAggroRange;
	m_iHp = p_iHp;
	//m_fPow = p_fPow;

	m_fAttackRange = 5.f;
>>>>>>> 5301b7ce945568afbd97112a1b45c6472c1ec48b

	m_fRadius = 100.f;

	m_fPow = p_fPow;

	m_iHp = p_iHp;

	m_fSpd = 5.f;
	//m_fPow = 0.1f;

	m_fhitting = 0.13f;
	m_bHitting = false;


	m_xpBody = p_xpCollisionMan->GetNewBody(m_xPos, 2.20f, 1);
	
	m_xpIdleTex = p_xpTexMan->Get("Warrior_Idle");
	m_xpRunTex = p_xpTexMan->Get("Warrior_Run");
	m_xpAtkTex = p_xpTexMan->Get("Warrior_Atk");

	m_xpIdleAnim = new Animation(m_xpIdleTex);
	m_xpIdleAnim->setReversed( false );
	m_xpIdleAnim->setFrameSize( sf::Vector2i( 293, 320 ) );
	m_xpIdleAnim->setDuration( sf::seconds( 0.6f ) );
	m_xpIdleAnim->setNumFrames( 8 );
	m_xpIdleAnim->setRepeating( true );
	m_xpIdleAnim->restart();
	m_xpIdleAnim->setScale( 1.f, 1.f );
	m_xpIdleAnim->setOrigin( m_xpIdleAnim->getFrameSize().x/2, m_xpIdleAnim->getFrameSize().y/2 );

	m_xpRunAnim = new Animation(m_xpRunTex);
	m_xpRunAnim->setReversed( false );
	m_xpRunAnim->setFrameSize( sf::Vector2i( 267, 436 ) );
	m_xpRunAnim->setDuration( sf::seconds( 0.6f ) );
	m_xpRunAnim->setNumFrames( 16 );
	m_xpRunAnim->setRepeating( true );
	m_xpRunAnim->restart();
	m_xpRunAnim->setScale( 1.f, 1.f );
	m_xpRunAnim->setOrigin( m_xpRunAnim->getFrameSize().x/2, m_xpRunAnim->getFrameSize().y/2 );

	m_xpAtkAnim = new Animation(m_xpAtkTex);
	m_xpAtkAnim->setReversed( false );
	m_xpAtkAnim->setFrameSize( sf::Vector2i( 293, 321 ) );
	m_xpAtkAnim->setDuration( sf::seconds( 0.6f ) );
	m_xpAtkAnim->setNumFrames( 18 );
	m_xpAtkAnim->setRepeating( true );
	m_xpAtkAnim->restart();
	m_xpAtkAnim->setScale( 1.f, 1.f );
	m_xpAtkAnim->setOrigin( m_xpAtkAnim->getFrameSize().x/2, m_xpAtkAnim->getFrameSize().y/2 );

	/*m_xRunAnim.setSmooth(true);
	m_xAttackAnim.setSmooth(true);
	m_xIdleAnim.setSmooth(true);*/

	/*m_xpAnimSprite->setTexture( m_xpRunAnim );
	m_xpAnimSprite->setOrigin( m_xpAnimSprite->getFrameSize().x/2, m_xpAnimSprite->getFrameSize().y/2 );
	m_xpAnimSprite->setRotation( -90.f );*/

	setRotation(p_fRot);

	SetState(AIState::Passive);
}

void EnemyObject::SetState(EnemyObject::AIState state){
	if (m_eState != state){
		m_eState = state;

		switch (m_eState){
		case EnemyObject::Passive:
			m_xpIdleAnim->setReversed( false );
			m_xpIdleAnim->restart();
			m_xpCurrentAnim = m_xpIdleAnim;
			break; 
		case EnemyObject::Aggro:
			m_xpRunAnim->setReversed( false );
			m_xpRunAnim->restart();
			m_xpCurrentAnim = m_xpRunAnim;
			break;
		case EnemyObject::Attacking:
			m_xpAtkAnim->setReversed( false );
			m_xpAtkAnim->restart();
			m_xpCurrentAnim = m_xpAtkAnim;
			break;
		default:
			break;
		}
	}
}

EnemyObject::AIState EnemyObject::GetState(){
	return m_eState;
}

float EnemyObject::GetAggroRange(){
	return m_fAggroRange;
}

float EnemyObject::GetAttackRange(){
	return m_fAttackRange;
}

bool EnemyObject::Update(sf::Time dt){
	float l_fEnemyDist = sqrtf( ( (m_xpPlayer->GetPosition().x - m_xpBody->GetPosition().x ) * ( m_xpPlayer->GetPosition().x - m_xpBody->GetPosition().x ) ) + ( ( m_xpPlayer->GetPosition().y - m_xpBody->GetPosition().y ) * (m_xpPlayer->GetPosition().y - m_xpBody->GetPosition().y) ) );
	float l_fXtrrot = -90.f;

<<<<<<< HEAD
	//std::cout << l_fEnemyDist << std::endl;

=======
>>>>>>> 5301b7ce945568afbd97112a1b45c6472c1ec48b
	/*if ( l_fEnemyDist < m_fAggroRange && l_fEnemyDist > m_fAttackRange ){
			SetState( EnemyObject::Aggro );
	}
	else if ( l_fEnemyDist > m_fAggroRange && GetState() == EnemyObject::Aggro ){
		SetState( EnemyObject::Passive );
	}
	else if ( l_fEnemyDist <= m_fAttackRange && GetState() == EnemyObject::Aggro ){
		SetState( EnemyObject::Attacking );
	}*/

	if (l_fEnemyDist > m_fAggroRange){
		SetState(EnemyObject::AIState::Passive);
	} 
	else if (l_fEnemyDist <= m_fAggroRange && l_fEnemyDist > m_fAttackRange){
		SetState(EnemyObject::AIState::Aggro);
	}
	else if (l_fEnemyDist <= m_fAttackRange && m_eState == EnemyObject::AIState::Aggro){
		SetState(EnemyObject::AIState::Attacking);
	}

	if (m_eState == EnemyObject::AIState::Passive){
		m_xVel = sf::Vector2f(0, 0);
	}
	else if (m_eState == EnemyObject::AIState::Aggro){		
		setRotation(atan2f( (m_xpPlayer->GetPosition().y - GetPosition().y), (m_xpPlayer->GetPosition().x - GetPosition().x) ) * 180.f / 3.141592f - 90.f);
		m_xVel = m_fSpd * sf::Vector2f(cosf(getRotation() * 3.141592 / 180 + 90.f), sinf(getRotation() * 3.141592 / 180 + 90.f));
<<<<<<< HEAD

		//std::cout << GetPosition().x << " : " << GetPosition().y << " : " << getRotation() << std::endl;
=======
>>>>>>> 5301b7ce945568afbd97112a1b45c6472c1ec48b
	}
	else if (m_eState == EnemyObject::AIState::Attacking){
		m_xVel = sf::Vector2f(0, 0);
		setRotation(atan2f( (m_xpPlayer->GetPosition().y - GetPosition().y), (m_xpPlayer->GetPosition().x - GetPosition().x) ) * 180.f / 3.141592f - 90.f);
		//m_xpPlayer->Damage(m_fPow);
		/*float _dirRot = atan2f( m_xpPlayer->getWorldPosition().y - getWorldPosition().y, m_xpPlayer->getWorldPosition().x - getWorldPosition().x );
		setRotation( _dirRot * 180 / 3.141592 );*/

		m_fhitting += dt.asSeconds();

		if( m_fhitting > 0.35f ) {
			
			//if( m_xpPlayer->Overlap( getPosition(), getRadius())){
				//std::cout << "GEt rekt" << std::endl;	
				m_xpPlayer->Damage(4);
			//}
			m_fhitting=0.f;
		}
	}
	
	if (m_eState == EnemyObject::Passive){
		//std::cout << "Passive";
	}
	else if (m_eState == EnemyObject::Aggro){
		//std::cout << "Aggro";
	}
	else if (m_eState == EnemyObject::Attacking){
		//std::cout << "Attacking";
	}

	m_xpCurrentAnim->update(dt);

	m_xpBody->SetLinearVelocity(b2Vec2(m_xVel.x, m_xVel.y));
	setPosition(m_xpBody->GetPosition().x * 32.f, m_xpBody->GetPosition().y * 32.f);
	m_xpCurrentAnim->setPosition(getPosition());
	m_xpCurrentAnim->setRotation(getRotation());

	if( m_xpPlayer->m_xpPlayerArms[0]->m_bApex ){
		if (m_xpPlayer->Overlap(getPosition(), getRadius() * 3)){
			m_iHp-= 1;
		}	
	}

	for (int i = m_xpPBulletMan->GetVector().size() - 1; i >= 0; i--){
		if (m_xpPBulletMan->GetVector()[i] != NULL){
			if (m_xpPBulletMan->GetVector()[i]->Overlap(getPosition(), m_fRadius)){
				//std::cout << getPosition().x << " : " << getPosition().y << std::endl;
				m_xpPBulletMan->Delete(m_xpPBulletMan->GetVector()[i]);
				m_iHp-= 1;
			}
		}
	}

	if (m_iHp <= 0){
		for (int i = 0; i < 16; i++){
			m_xpStarman->Add(new Star(m_xpTexMan, getPosition(), m_xpPlayer, m_xpSPlayer));

			//m_xpStarman->Add(new EnemyObject(m_xpCMan, m_xpTexMan, m_xpStarman, 5, 1, m_fAggroRange, getPosition(), m_xpPlayer, 0));
		}
		return true;
	}

	return false;
}

void EnemyObject::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw( *m_xpCurrentAnim, states );
}