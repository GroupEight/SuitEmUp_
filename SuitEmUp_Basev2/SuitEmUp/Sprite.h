//Sprite.h//

#pragma once

#include <string>

class Sprite : public sf::Drawable, public sf::Transformable {
	friend class DrawMan;
	friend class SpriteMan;

public:
	Sprite();
	Sprite(const sf::Texture &p_xTex);
	
	~Sprite();

	void SetTexture(const sf::Texture& p_xTex);
	const sf::Texture *GetTexture() const;

	void SetSprite(sf::Sprite p_xSprite);
	const sf::Sprite GetSprite();

	void SetPosition(sf::Vector2f p_xPos);
	sf::Vector2f GetPosition();

	void draw(sf::RenderTarget& m_xTarget, sf::RenderStates m_xStates) const;

protected:
	std::string m_sName;
	sf::Sprite m_xSprite;
};