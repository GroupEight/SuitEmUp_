//DrawMan.h//

#pragma once

class Sprite;

class DrawMan {
	friend class SpriteMan;
public:
	DrawMan();
	~DrawMan();

	bool Init(sf::RenderWindow *p_xpWindow);
	void Cleanup();

	void Clear();
	void Present();

	void Draw(Sprite *p_xSprite, sf::RenderStates p_xRstates = sf::RenderStates::RenderStates());

private:
	sf::RenderWindow *m_xpWindow;
};