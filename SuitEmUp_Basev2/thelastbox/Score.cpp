//Score.cpp//

#include "Score.h"

#include "FontMan.h"

#include <sstream>

Score::Score(std::string p_sName, int p_iScore, FontMan *p_xpFman){
	m_sName = p_sName;
	m_iStars = p_iScore;

	m_xpScore = new sf::Text(sf::String(std::string(m_sName)), *p_xpFman->Get("Standard"), 75);

	std::ostringstream convert;
	convert << m_iStars;

	m_xpStarstxt = new sf::Text(sf::String(convert.str()), *p_xpFman->Get("Standard"), 75);
}

Score::~Score(){
	delete m_xpScore;
	m_xpScore = NULL;

	delete m_xpStarstxt;
	m_xpStarstxt = NULL;
}