//WarriorObject.h//

#pragma once

#include "EnemyObject.h"

class Sprite;

class WarriorObject : public EnemyObject {
	enum m_AIState {
		m_eIdle,
		m_eAttack
	};

public:
	WarriorObject(Sprite *p_xpSprite, sf::Vector2f p_xStartPos, GameObject *p_xpTarget);
	~WarriorObject();

	bool HasGraphics() const;
	Gfx *GetGraphics();

private:
	WarriorObject::m_AIState m_xState;

	Sprite *m_xpSprite;

	void UpdateCurrent(sf::Time p_xDtime);
	void UpdateParents(sf::Time p_xDtime);
};