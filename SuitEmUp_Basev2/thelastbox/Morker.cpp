//EnemyObject.cpp//

#include "Morker.h"

#include "Animation.hpp"

#include "CollisionMan.h"
#include "TextureMan.h"

Morker::Morker(CollisionMan *p_xpCollisionMan, TextureMan *p_xpTexMan, float p_fAggroRange, float p_fAttackRange, sf::Vector2f p_xStartpos){
	m_xPos = p_xStartpos;

	m_xpBody = p_xpCollisionMan->GetNewBody(m_xPos, 1.0f, 1);

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

	m_fFirerate = 0;

	/*m_xRunAnim.setSmooth(true);
	m_xAttackAnim.setSmooth(true);
	m_xIdleAnim.setSmooth(true);*/

	/*m_xpAnimSprite->setTexture( m_xpRunAnim );
	m_xpAnimSprite->setOrigin( m_xpAnimSprite->getFrameSize().x/2, m_xpAnimSprite->getFrameSize().y/2 );
	m_xpAnimSprite->setRotation( -90.f );*/

	SetState(AIState::Passive);
}

void Morker::SetState(Morker::AIState state){
	if (m_eState != state){
		m_eState = state;

		switch (m_eState){
		case Morker::Passive:
			m_xpIdleAnim->setReversed( false );
			m_xpIdleAnim->restart();
			m_xpCurrentAnim = m_xpIdleAnim;
			break; 
		case Morker::Aggro:
			m_xpRunAnim->setReversed( false );
			m_xpRunAnim->restart();
			m_xpCurrentAnim = m_xpRunAnim;
			break;
		case Morker::Attacking:
			m_xpAtkAnim->setReversed( false );
			m_xpAtkAnim->restart();
			m_xpCurrentAnim = m_xpAtkAnim;
			break;
		default:
			break;
		}
	}
}

Morker::AIState Morker::GetState(){
	return m_eState;
}

float Morker::GetAggroRange(){
	return m_fAggroRange;
}

float Morker::GetAttackRange(){
	return m_fAttackRange;
}

void Morker::Update(sf::Time dt){
	//move( m_xVel * dt.asSeconds() );

	m_xpCurrentAnim->update(dt);

	//if aggro
	m_fFirerate -= 0.0005f;

	if(m_fFirerate <= 0 ) {
		m_fFirerate = 3;

		if(m_fFirerate > 2.5)  {
			 m_xpBody->SetLinearVelocity (b2Vec2(0, -40));
		}	
	}
	
	   if (m_fFirerate > 2.0 && m_fFirerate < 2.5) {
			m_xpBody->SetLinearVelocity (b2Vec2(0 , 25));
		}

	   	if (m_fFirerate > 1.5 && m_fFirerate < 2.0) {
			m_xpBody->SetLinearVelocity (b2Vec2(0 , -25));
		}

	   if (m_fFirerate > 1.0 && m_fFirerate < 1.5) {
			m_xpBody->SetLinearVelocity (b2Vec2(0 , 40));
		}

	    if (m_fFirerate > 0.5 && m_fFirerate < 1.0) {
			m_xpBody->SetLinearVelocity (b2Vec2(0, -25));
		}

	   if (m_fFirerate > 0.0 && m_fFirerate < 0.5) {
			m_xpBody->SetLinearVelocity (b2Vec2(0 , 25));
		}

	   m_xpCurrentAnim->setPosition(sf::Vector2f(m_xpBody->GetPosition().x, m_xpBody->GetPosition().y / 32));
}

void Morker::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	target.draw( *m_xpCurrentAnim, states );
}