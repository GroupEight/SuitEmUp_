#pragma once

#include "GameObject.h"

class PlayerObject;

class SoundPlayer;
class TextureMan;

class Star : public GameObject {
public:

	Star(TextureMan *p_xpTextureMan, sf::Vector2f p_xPos, PlayerObject *p_xpPlayer, SoundPlayer *p_xpSPlayer);
	~Star();

	TextureMan *m_xpTextureMan;

	PlayerObject *m_xpPlayer;

	bool Update(sf::Time p_xDtime);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states ) const;

private:
	float m_fSpd,
		m_fDeacc;

	bool m_bCollect;

	SoundPlayer *m_xpSPlayer;

	sf::Sprite *m_xpSprite;
	sf::Texture *m_xpTex;
};

