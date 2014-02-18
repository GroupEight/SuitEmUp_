//Sprite.h//

#pragma once

#include <string>

#include "Gfx.h"

class Sprite : public Gfx {
	friend class DrawMan;
	friend class GfxMan;

public:
	Sprite();
	Sprite(const sf::Texture *p_xpTex);
	
	~Sprite();

	void SetTexture(const sf::Texture *p_xpTex);
	const sf::Texture *GetTexture() const;

	void SetSprite(sf::Sprite p_xSprite);
	sf::Sprite *GetSprite();

	void SetPosition(sf::Vector2f p_xPos);
	sf::Vector2f GetPosition();

	void SetRotation(float p_fPos);
	float GetRotation();

	sf::Drawable *GetParent();

	bool IsGraphic(const std::string &p_sType);

protected:
	std::string m_sName;
	sf::Sprite *m_xpSprite;
};