//WarriorObject.h//

#pragma once

#include "EnemyObject.h"

class WarriorObject : public EnemyObject {
	enum m_AIState {
		m_eIdle,
		m_eAttack
	};

public:
	WarriorObject(sf::Vector2f p_xStartPos, GameObject *p_xpTarget, Sprite *p_xpSprite);
	~WarriorObject();

private:
	WarriorObject::m_AIState m_xState;

	void UpdateCurrent(sf::Time p_xDtime);
	void UpdateParents(sf::Time p_xDtime);
};