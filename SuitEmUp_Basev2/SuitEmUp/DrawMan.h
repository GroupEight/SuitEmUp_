//DrawMan.h//

#pragma once

class Sprite;

class DrawMan {
	friend class GfxMan;
public:
	DrawMan();
	~DrawMan();

	bool Init(sf::RenderWindow *p_xpWindow);
	void Cleanup();

	void Clear();
	void Present();

	void Draw(const sf::Drawable *p_xpDrawable, sf::RenderStates p_xRstates = sf::RenderStates::RenderStates());

private:
	sf::RenderWindow *m_xpWindow;
};