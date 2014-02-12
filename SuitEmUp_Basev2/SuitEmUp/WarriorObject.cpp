//WarriorObject.cpp//

#include "WarriorObject.h"

#include "Sprite.h"

WarriorObject::WarriorObject(sf::Vector2f p_xStartPos, GameObject *p_xpTarget, Sprite *p_xpSprite){
	m_xStartPos = p_xStartPos;
	m_xPos = m_xStartPos;

	m_xpTarget = p_xpTarget;

	m_xpSprite = p_xpSprite;

	m_xState = m_AIState::m_eIdle;

	m_iHp = 10;
	m_iPow = 1;

	m_fSpd = 20.0f;

	m_xAggrozone = sf::Vector2f(1024, 640);
}

WarriorObject::~WarriorObject(){

}

void WarriorObject::UpdateParents(sf::Time p_xDtime){
	EnemyObject::UpdateCurrent(p_xDtime);
	GameObject::UpdateCurrent(p_xDtime);
}

void WarriorObject::UpdateCurrent(sf::Time p_xDtime){
	if (m_xState == m_AIState::m_eIdle){
		std::cout << "Idle\n";
		if (m_xpTarget->GetPosition().x - m_xAggrozone.x < GetPosition().x && m_xpTarget->GetPosition().x + m_xAggrozone.x > GetPosition().x){
			m_xState = m_AIState::m_eAttack;
		}
		if (m_xpTarget->GetPosition().y - m_xAggrozone.y < GetPosition().y && m_xpTarget->GetPosition().y + m_xAggrozone.y > GetPosition().y){
			m_xState = m_AIState::m_eAttack;
		}
	}
	if (m_xState == m_AIState::m_eAttack){
		std::cout << "Attack\n";
		if (m_xpTarget->GetPosition().x > GetPosition().x){
			m_xVel.x = m_fSpd * (float)p_xDtime.asSeconds();
		}
		if (m_xpTarget->GetPosition().x < GetPosition().x){
			m_xVel.x = -m_fSpd * (float)p_xDtime.asSeconds();
		}
		if (m_xpTarget->GetPosition().y > GetPosition().y){
			m_xVel.y = m_fSpd * (float)p_xDtime.asSeconds();
		}
		if (m_xpTarget->GetPosition().y < GetPosition().y){
			m_xVel.y = -m_fSpd * (float)p_xDtime.asSeconds();
		}
	}
	if (m_xpSprite != NULL){
		m_xpSprite->SetPosition(GetPosition());
		m_xpSprite->setRotation(getRotation());
	}
	std::cout << m_xPos.x << ": " << m_xPos.y << std::endl;;
}