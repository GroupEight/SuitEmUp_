//Gfx.h//

#pragma once

class Gfx : sf::Drawable {
public:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	virtual sf::Drawable *GetParent() = 0;

	virtual bool IsGraphic(const std::string &p_sType) = 0;
};