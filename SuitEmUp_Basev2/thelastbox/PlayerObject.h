//PlayerObject.h//

#pragma once

#include "GameObject.h"

class Animation;
class Player_Arms;
class Tool_Whip;

class CollisionMan;
class NodeMan;
class TextureMan;
class SoundPlayer;
class EnemyObject;

class PlayerObject : public GameObject {
public:
	enum State {
		Idle,
		Run_F, 
		Run_B,
		Run_L,
		Run_R,
		Whipping
	};

	enum Tool {
		Melee,
		Crossbow,
		Whip
	};

public:
	PlayerObject(sf::RenderWindow *p_xpWindow, CollisionMan *p_xpCollisionMan, NodeMan *p_xpBulletMan, TextureMan *p_xpTextureMan, NodeMan *p_xpEBulletMan, NodeMan *p_xpEnemyMan, SoundPlayer *p_xpSPlayer);
	~PlayerObject();

	void Damage(float p_fDmg);

	virtual bool Update(sf::Time p_xDtime);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void setState(PlayerObject::State state);
	void setTool(PlayerObject::Tool tool);

	void doWhip(sf::Vector2f _pos);

	PlayerObject::State GetState();
	PlayerObject::Tool GetTool();

	NodeMan *GetPBulletMan();

	float GetHp();
	float GetMaxHp();

	int GetStars();
	void SetStars(int p);

	void StarsPlus();

	bool GetInv();

	bool m_bColliding;

	bool m_bPunching;

	Player_Arms *m_xpPlayerArms[2];

private:

	CollisionMan *m_xpCollisionMan;
	NodeMan *m_xpBulletMan;
	NodeMan *m_xpEBulletMan;
	NodeMan *m_xpEnemyMan;
	TextureMan *m_xpTextureMan;
	SoundPlayer *m_xpSPlayer;

	sf::RenderWindow *m_xpWindow;

	PlayerObject::State m_eState;
	PlayerObject::Tool m_eTool;

	sf::Vector2f lastPosition;

	sf::Sprite mSprite;

	Animation *m_xpIdleAnim,
		*m_xpRunAnim,
		*m_xpStepAnim,
		*m_xpCurrentAnim,
		*m_xpCrossbow;
	
	Tool_Whip *m_xpWhip;

	unsigned int m_iStarCount,
		m_iStarSfx;
	
	float m_fBulletspd,
		m_fPlayerspd,
		m_fFiretime,
		m_fFrate,
		m_fMaxrate,
		m_fHeat,
		m_fHeatup,
		m_fCooldown,
		m_fMaxheat,
		m_fMinheat,
		m_fSuit,
		m_fInv,
		m_fInvMax,
		m_fArmCdwn;

	bool m_bOverheat,
		punchArm;

	sf::Vector2f m_xWhipPos;

	sf::Texture *m_xpIdleTex, 
		*m_xpRunTex, 
		*m_xpSStepTex, 
		*m_xpCrossbowTex,
		*m_xpBulletTex;
};