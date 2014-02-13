//EnemyObject.h//

#pragma once

#include "GameObject.h"

class EnemyObject : public GameObject {
public:
	EnemyObject();
	EnemyObject(sf::Vector2f p_xStartPos, GameObject *p_xpTarget = nullptr);

	virtual ~EnemyObject() {};

protected:
	virtual void UpdateCurrent(sf::Time dt);

	sf::Vector2f m_xAggrozone;
	sf::Vector2f m_xStartPos;

	GameObject *m_xpTarget;

	int m_iHp,
		m_iPow;

	float m_fSpd;

	bool m_bAlive;
};