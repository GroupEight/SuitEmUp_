//Score.h//

#pragma once

class FontMan;

class Score {
public:
	Score(std::string p_sName, int p_iScore, FontMan *p_xpFman);
	~Score();

	std::string m_sName;

	unsigned int m_iStars;

	sf::Text *m_xpScore,
		*m_xpStarstxt;
};