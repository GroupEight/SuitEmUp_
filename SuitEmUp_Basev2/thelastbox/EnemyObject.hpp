//EnemyObject.h//

#pragma once

#include "GameObject.h"

class CollisionMan;
class NodeMan;
class TextureMan;
class SoundPlayer;

class PlayerObject;
class Player_Arms;

class Animation;

class EnemyObject : public GameObject {
public:
	enum AIState {
		Passive,
		Aggro,
		Attacking
	};

public:
<<<<<<< HEAD
	//EnemyObject(CollisionMan *p_xpCollisionMan, TextureMan *p_xpTexMan, float p_fAggroRange, float p_fAttackRange, sf::Vector2f p_xStartpos, PlayerObject *p_xpPlayer, NodeMan *p_xpPBulletMan);
	EnemyObject(CollisionMan *p_xpCollisionMan, TextureMan *p_xpTexMan, NodeMan *p_xpStarman, int p_iHp, float p_fPow, float p_fAggroRange, sf::Vector2f p_xStartpos, PlayerObject *p_xpPlayer, float p_fRot, SoundPlayer *p_xpSPlayer);
=======
	EnemyObject(CollisionMan *p_xpCollisionMan, TextureMan *p_xpTexMan, int p_iHp, float p_fPow, float p_fAggroRange, sf::Vector2f p_xStartpos, PlayerObject *p_xpPlayer);
>>>>>>> 5301b7ce945568afbd97112a1b45c6472c1ec48b

	virtual bool Update(sf::Time p_xDtime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void SetState(EnemyObject::AIState state);
	EnemyObject::AIState GetState();

	float GetAggroRange();
	float GetAttackRange();

	bool m_bHitting;

private:
	Animation *m_xpIdleAnim, 
		*m_xpRunAnim, 
		*m_xpAtkAnim,
		*m_xpCurrentAnim;

	sf::Texture *m_xpIdleTex, 
		*m_xpRunTex, 
		*m_xpAtkTex;

	EnemyObject::AIState m_eState;

	PlayerObject *m_xpPlayer;

	TextureMan *m_xpTexMan;

	CollisionMan *m_xpCMan;

	NodeMan *m_xpPBulletMan;
	NodeMan *m_xpStarman;

	sf::CircleShape *m_hitradius;

	float m_fAggroRange,
		m_fAttackRange,
		m_fSpd,
		m_fPow,
		m_fhitting;

	int m_iHp;
};