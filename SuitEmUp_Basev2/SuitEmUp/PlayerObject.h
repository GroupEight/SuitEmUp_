//PlayerObject.h//

#include "GameObject.h"

class AnimatedSprite;
class Sprite;

class GameObjectMan;
class GfxMan;

class PlayerObject : public GameObject {
public:
	enum m_AnimationState {
		m_eIdle,
		m_eRun
	};

	PlayerObject(Sprite *p_xpSprite, GameObjectMan *p_xpBulletMan, GfxMan *p_xpGfxMan);

	Sprite* GetSprite();

	virtual bool HasGraphics() const;
	virtual Gfx *GetGraphics();
	//virtual void SetGraphics(Gfx *p_xpGfx);

private:
	void UpdateCurrent(sf::Time p_xDtime);

	void Animate(sf::Time p_xDtime);

private:
	PlayerObject::m_AnimationState m_eState;

	Sprite *m_xpSprite;
	AnimatedSprite *m_xpAnimSprite;

	GameObjectMan *m_xpBulletMan;
	GfxMan *m_xpGfxMan;

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