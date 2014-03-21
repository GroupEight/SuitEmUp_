//NewScoreState.h//

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

class NewScoreState : public State {
public:
	NewScoreState(sf::RenderWindow *p_xpWindow, PlayerObject *p_xpPlayer, CursorObject *p_xpCursor, TextureMan *p_xpTexMan, FontMan *p_xpFman, SoundPlayer *p_xpSPlayer);
	~NewScoreState();

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

	sf::Text *m_xpInfo,
		m_xCurrStars,
		m_xYourScore;

	Score *m_xpCurrScore;

	Menu_Button *m_xpButton,
		*m_xpSubmit;

	bool m_bNewHigh;
};