//Morker.h//

#pragma once

#include "GameObject.h"

class CollisionMan;
class TextureMan;

class Animation;

class Morker : public GameObject {
public:
	enum AIState {
		Passive,
		Aggro,
		Attacking,
	};

public:
	Morker(CollisionMan *p_xpCollisionMan, TextureMan *p_xpTexMan, float p_fAggroRange, float p_fAttackRange, sf::Vector2f p_xStartpos);

	virtual void Update(sf::Time p_xDtime);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void SetState(Morker::AIState state);
	Morker::AIState GetState();

	float GetAggroRange();
	float GetAttackRange();

private:
	Animation *m_xpIdleAnim, 
		*m_xpRunAnim, 
		*m_xpAtkAnim,
		*m_xpCurrentAnim;

	sf::Texture *m_xpIdleTex, 
		*m_xpRunTex, 
		*m_xpAtkTex;

	Morker::AIState m_eState;

	float m_fAggroRange;
	float m_fAttackRange;
	float m_fFirerate;
};