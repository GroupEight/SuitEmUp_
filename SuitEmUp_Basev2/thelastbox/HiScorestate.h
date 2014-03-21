//HiScorestate.h//

#pragma once

#include "State.h"

#include <vector>

class FontMan;
class SoundPlayer;
class TextureMan;

class CursorObject;
class Menu_Button;
class PlayerObject;

class Score;

class HiScorestate : public State {
public:
	HiScorestate(sf::RenderWindow *p_xpWindow, PlayerObject *p_xpPlayer, CursorObject *p_xpCursor, TextureMan *p_xpTexMan, FontMan *p_xpFman, SoundPlayer *p_xpSPlayer);
	~HiScorestate();

	bool Enter();
	void Exit();
	bool Update(sf::Time p_xDtime);
	void Draw();
	std::string Next();
	bool IsType(const std::string &p_sType);

private:
	sf::RenderWindow *m_xpWindow;

	std::vector<Score*> m_xaScoreTable;

	CursorObject *m_xpCursor;
	PlayerObject *m_xpPlayer;

	FontMan *m_xpFman;

	Menu_Button *m_xpButton;
};