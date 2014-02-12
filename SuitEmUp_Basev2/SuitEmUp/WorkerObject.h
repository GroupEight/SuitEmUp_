//WorkerObject.h//

#pragma once

#include "EnemyObject.h"

class WorkerObject : public EnemyObject {
	enum m_AIState {
		m_eIdle,
		m_eAttack
	};

public:
	WorkerObject(sf::Vector2f p_xStartPos, GameObject *p_xpTarget, Sprite *p_xpSprite);
	~WorkerObject();

private:
	WorkerObject::m_AIState m_xState;

	void UpdateCurrent(sf::Time p_xDtime);
	void UpdateParents(sf::Time p_xDtime);
};