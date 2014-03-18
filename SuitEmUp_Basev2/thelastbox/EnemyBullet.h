//EnemyBullet.h//

#pragma once

#include "GameObject.h"

class PlayerObject;
class TextureMan;

class EnemyBullet : public GameObject {
public:
	EnemyBullet(TextureMan *p_xpTextureMan, sf::Vector2f p_xPos, float p_fRot, PlayerObject *p_xpPlayer);
	~EnemyBullet();

	bool Update(sf::Time p_xDtime);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states ) const;

private:
	float m_fSpd;

	TextureMan *m_xpTextureMan;

	PlayerObject *m_xpPlayer;

	sf::Sprite *m_xpSprite;
	sf::Texture *m_xpTex;
};