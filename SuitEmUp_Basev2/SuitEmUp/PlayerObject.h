//PlayerObject.h//

#include "GameObject.h"

class AnimatedSprite;
class Sprite;

class GameObjectMan;
class SpriteMan;

class PlayerObject : public GameObject {
public:
	enum m_AnimationState {
		m_eIdle,
		m_eRun
	};

	PlayerObject(Sprite *p_xpSprite, GameObjectMan *p_xpBulletMan, SpriteMan *p_xpSpriteMan);

	Sprite* GetSprite();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	void UpdateCurrent(sf::Time p_xDtime);

	void Animate(sf::Time p_xDtime);

private:
	PlayerObject::m_AnimationState m_eState;

	Sprite *m_xpSprite;
	AnimatedSprite *m_xpAnimSprite;

	GameObjectMan *m_xpBulletMan;
	SpriteMan *m_xpSpriteMan;

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
};