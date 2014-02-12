//WorkerObject.cpp//

#include "WorkerObject.h"

WorkerObject::WorkerObject(sf::Vector2f p_xStartPos, GameObject *p_xpTarget, Sprite *p_xpSprite){
	m_xStartPos = p_xStartPos;

	m_xpTarget = p_xpTarget;

	m_xpSprite = p_xpSprite;

	m_xState = m_AIState::m_eIdle;

	m_iHp = 10;
	m_iPow = 1;

	m_fSpd = 20.0f;

	m_xAggrozone = sf::Vector2f(1024, 640);
}

WorkerObject::~WorkerObject(){

}

void WorkerObject::UpdateParents(sf::Time p_xDtime){
	EnemyObject::UpdateCurrent(p_xDtime);
	GameObject::UpdateCurrent(p_xDtime);
}

void WorkerObject::UpdateCurrent(sf::Time p_xDtime){
	
}