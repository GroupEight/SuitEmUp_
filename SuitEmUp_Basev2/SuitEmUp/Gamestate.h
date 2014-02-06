//Gamestate.h//

#pragma once

#include <string>

#include "State.h"

class DrawMan;
class SpriteMan;

class PlayerObject;

class Gamestate : public State {
public:
	Gamestate(DrawMan *p_xpDrawMan, SpriteMan *p_xpSpriteMan);
	~Gamestate();

	bool Enter();
	void Exit();
	bool Update(sf::Time p_xDtime); // Parameter_FloatingDtime
	void Draw();
	std::string Next();
	bool IsType(const std::string &p_sType); // Parameter_StringKonstantReferenceType

private:
	sf::Window *m_xpWindow;

	DrawMan *m_xpDrawMan;

	PlayerObject *m_xpPlayer;
};