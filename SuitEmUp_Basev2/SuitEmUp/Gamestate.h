//Gamestate.h//

#pragma once

#include <string>

#include "State.h"

class DrawMan;
class SpriteMan;
class GameObjectMan;

class PlayerObject;

class Gamestate : public State {
public:
	Gamestate(DrawMan *p_xpDrawMan, SpriteMan *p_xpSpriteMan, sf::RenderWindow *p_xpWindow);
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
	SpriteMan *m_xpSpriteMan;

	GameObjectMan *m_xpBulletMan;
	GameObjectMan *m_xpEnemyMan;

	PlayerObject *m_xpPlayer;

	sf::View *m_xpWorldView;
};