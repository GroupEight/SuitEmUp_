//Gamestate.h//

#pragma once

#include <string>

#include "State.h"

class DrawMan;
class GfxMan;
class GameObjectMan;

class BGObject;
class PlayerObject;

class Gamestate : public State {
public:
	Gamestate(DrawMan *p_xpDrawMan, GfxMan *p_xpGfxMan, sf::RenderWindow *p_xpWindow);
	~Gamestate();

	bool Enter();
	void Exit();
	bool Update(sf::Time p_xDtime); // Parameter_FloatingDtime
	void Draw();
	std::string Next();
	bool IsType(const std::string &p_sType); // Parameter_StringKonstantReferenceType

private:
	sf::RenderWindow *m_xpWindow;

	DrawMan *m_xpDrawMan;
	GfxMan *m_xpGfxMan;

	GameObjectMan *m_xpBulletMan;
	GameObjectMan *m_xpEnemyMan;

	BGObject *m_xpBGround;
	PlayerObject *m_xpPlayer;

	sf::View *m_xpWorldView;

	float m_fZoom;
};