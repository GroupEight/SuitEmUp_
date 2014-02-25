//Gamestate.h//

/*#pragma once

#include <string>

#include "State.h"

class Menustate : public State {
public:
	Menustate();
	~Menustate();

	bool Enter();
	void Exit();
	bool Update(sf::Time p_xDtime); // Parameter_FloatingDtime
	void Draw();
	std::string Next();
	bool IsType(const std::string &p_sType); // Parameter_StringKonstantReferenceType

private:
	// Empty
};