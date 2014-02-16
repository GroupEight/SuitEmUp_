//BGObject.h//

#pragma once

#include "GameObject.h"

class PlayerObject;

class Background;

class BGObject : public GameObject {
public:
	//BGObject(sf::Texture *p_xpTex, sf::Vector2f p_xSize);
	BGObject(Background *p_xpBg, PlayerObject *p_xpPlayer, sf::RenderWindow *p_xpWindow);
	~BGObject();

	bool HasGraphics() const;
	Gfx *GetGraphics();
	//void SetGraphics(Gfx *p_xpGfx);

	sf::Texture *GetTexture();

private:
	virtual void UpdateCurrent(sf::Time dt);

	sf::RenderWindow *m_xpWindow;

	Background *m_xpBg;

	PlayerObject *m_xpPlayer;
};