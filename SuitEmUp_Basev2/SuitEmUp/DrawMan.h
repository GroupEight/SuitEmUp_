//DrawMan.h//

#pragma once

class Sprite;

class DrawMan {
	friend class SpriteMan;
public:
	DrawMan();
	~DrawMan();

	bool Initialize(sf::RenderWindow *p_xpWindow, sf::Vector2f p_xSize);
	void Cleanup();

	void Clear();
	void Present();

	void Draw(Sprite *sprite, sf::Vector2f p_xPos);

private:
	sf::RenderWindow *m_xpWindow;
};