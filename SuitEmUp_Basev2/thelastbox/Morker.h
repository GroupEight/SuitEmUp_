//Morker.h//

#pragma once

#include "GameObject.h"
#include "Gamestate.hpp"


class CollisionMan;
class TextureMan;

class PlayerObject;
class Player_Arms;
class Animation;
class Star;
class EnemyBullet;

class Morker : public GameObject {
public:
	enum AIState {
		Passive,
		Aggro,
		Attacking,
	};

public:
	Morker(CollisionMan *p_xpCollisionMan, TextureMan *p_xpTexMan, float p_fAggroRange, float p_fAttackRange, sf::Vector2f p_xStartpos, PlayerObject *p_xpPlayer, NodeMan *p_xpEBulletMan, NodeMan *p_xpStarMan, SoundPlayer *p_xpSPlayer, float p_fRot);

	virtual bool Update(sf::Time p_xDtime);
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

	PlayerObject *m_xpPlayer;

	NodeMan *m_xpPBulletMan;
	NodeMan *m_xpEBulletMan;
	NodeMan *m_xpStarMan;

	TextureMan *m_xpTextureMan;

	sf::Texture *m_xpTex;

	float m_fAggroRange,
		m_fAttackRange,
		m_fSpd,
		m_fFirerate,
		m_fzigzag;

	EnemyBullet *m_xpEBullet;

	Star *m_xpStar;
	int m_iHp;
};