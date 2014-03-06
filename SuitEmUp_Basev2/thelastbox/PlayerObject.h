//PlayerObject.h//

#pragma once

#include "GameObject.h"

class Animation;
class Player_Arms;

class CollisionMan;
class NodeMan;
class TextureMan;

class PlayerObject : public GameObject {
public:
	enum State {
		Idle,
		Run_F, 
		Run_B,
		Run_L,
		Run_R
	};

	enum Tool {
		Melee,
		Crossbow,
	};

public:
	PlayerObject(CollisionMan *p_xpCollisionMan, NodeMan *p_xpBulletMan, TextureMan *p_xpTextureMan);
	~PlayerObject();

	virtual void Update(sf::Time p_xDtime);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void setState(PlayerObject::State state);
	void setTool(PlayerObject::Tool tool);

	PlayerObject::State GetState();
	PlayerObject::Tool GetTool();

	bool m_bColliding;

	bool m_bPunching;

private:

	CollisionMan *m_xpCollisionMan;
	NodeMan *m_xpBulletMan;
	TextureMan *m_xpTextureMan;

	PlayerObject::State m_eState;
	PlayerObject::Tool m_eTool;

	sf::Vector2f lastPosition;

	sf::Sprite mSprite;

	Animation *m_xpIdleAnim,
		*m_xpRunAnim,
		*m_xpStepAnim,
		*m_xpCurrentAnim,
		*m_xpCrossbow;

	Player_Arms *m_xpPlayerArms[2];

	bool punchArm;
	
	float m_fBulletspd,
		m_fPlayerspd,
		m_fFiretime,
		m_fFrate,
		m_fMaxrate,
		m_fHeat,
		m_fHeatup,
		m_fCooldown,
		m_fMaxheat,
		m_fMinheat;

	bool m_bOverheat;

	sf::Texture *m_xpIdleTex, 
		*m_xpRunTex, 
		*m_xpSStepTex, 
		*m_xpCrossbowTex,
		*m_xpBulletTex;
};