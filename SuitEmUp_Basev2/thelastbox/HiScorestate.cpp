//HiScorestate.cpp//

#include "HiScorestate.h"

#include "FontMan.h"
#include "TextureMan.h"

#include "CursorObject.h"
#include "Menu_Button.hpp"
#include "PlayerObject.h"

#include "Score.h"

#include <fstream>
#include <sstream>

HiScorestate::HiScorestate(sf::RenderWindow *p_xpWindow, PlayerObject *p_xpPlayer, CursorObject *p_xpCursor, TextureMan *p_xpTexMan, FontMan *p_xpFman, SoundPlayer *p_xpSPlayer){
	m_xpWindow = p_xpWindow;
	m_xpPlayer = p_xpPlayer;
	m_xpCursor = p_xpCursor;
	m_xpFman = p_xpFman;

	m_xpButton = new Menu_Button(p_xpTexMan, p_xpFman, p_xpWindow, p_xpSPlayer, 3.0, "Menu", SceneNode::FScreenMode * 640, SceneNode::FScreenMode * 640);
}

HiScorestate::~HiScorestate(){
	for (int i = m_xaScoreTable.size() - 1; i >= 0; i--){
		delete m_xaScoreTable[i];
		m_xaScoreTable[i] = NULL;
	}

	m_xaScoreTable.clear();
}

bool HiScorestate::Enter(){

	for (int i = m_xaScoreTable.size() - 1; i >= 0; i--){
		delete m_xaScoreTable[i];
		m_xaScoreTable[i] = NULL;
	}

	m_xaScoreTable.clear();

	// Reading in the current High-Score from a .txt document

	std::ifstream stream;
	std::string l_sFile = "../rec/HiScore.txt";
	stream.open(l_sFile.c_str());

	if (!stream.is_open()){
		return false;
	}

	std::string l_sRow;
	stream >> l_sRow;

	int i = 0;

	while (!stream.eof() && i < 10){
		std::getline(stream, l_sRow);
		if (l_sRow.length() == 0){
			continue;
		}

		std::stringstream ss(l_sRow);

		std::string l_sName;
		int l_iScore;

		ss >> l_sName;
		ss >> l_iScore;

		// Creates a new Score
		
		m_xaScoreTable.push_back(new Score(l_sName, l_iScore, m_xpFman));

		std::string l_sTxt = l_sName;

		i++;
	}

	stream.close();

	// Sets the color:

	for (int i = 0; i < m_xaScoreTable.size(); i++){
		std::ostringstream convert;
		convert << (i + 1);

		if (i + 1 < 10){
			m_xaScoreTable[i]->m_xpScore->setString((convert.str() + "  - " + m_xaScoreTable[i]->m_xpScore->getString()));
		}
		else {
			m_xaScoreTable[i]->m_xpScore->setString((convert.str() + " - " + m_xaScoreTable[i]->m_xpScore->getString()));
		}

		if (i % 2 == 1){
			sf::Color l_xColor;
			l_xColor.r = 128;
			l_xColor.b = 128;
			l_xColor.g = 128;
			m_xaScoreTable[i]->m_xpScore->setColor(l_xColor);
			m_xaScoreTable[i]->m_xpStarstxt->setColor(l_xColor);
		}
		else {
			sf::Color l_xColor;
			l_xColor.r = 160;
			l_xColor.b = 160;
			l_xColor.g = 160;
			m_xaScoreTable[i]->m_xpScore->setColor(l_xColor);
			m_xaScoreTable[i]->m_xpStarstxt->setColor(l_xColor);
		}

		m_xaScoreTable[i]->m_xpScore->setPosition(SceneNode::FScreenMode * 360, SceneNode::FScreenMode * (20 + 45 * i));
		m_xaScoreTable[i]->m_xpStarstxt->setPosition(SceneNode::FScreenMode * 830, SceneNode::FScreenMode * (20 + 45 * i));
	}

	return true;
}

void HiScorestate::Exit(){
	for (int i = m_xaScoreTable.size() - 1; i >= 0; i--){
		delete m_xaScoreTable[i];
		m_xaScoreTable[i] = NULL;
	}

	m_xaScoreTable.clear();
}

bool HiScorestate::Update(sf::Time p_xDtime){
	// Presents a button that returns the player to the main menu

	if (m_xpButton->isWithinLocalBounds()){
		m_xpButton->Hover();
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			if (m_xpButton->Click()){
				return false;
			}
		}
	}
	else {
		m_xpButton->Out();
	}

	m_xpCursor->Update(p_xDtime);

	return true;
}

void HiScorestate::Draw(){
	// Draws all of the names, the button and the Cursor

	for (int i = 0; i < m_xaScoreTable.size(); i++){
		m_xpWindow->draw(*m_xaScoreTable[i]->m_xpScore);
		m_xpWindow->draw(*m_xaScoreTable[i]->m_xpStarstxt);
	}

	m_xpButton->draw(*m_xpWindow, sf::RenderStates::Default);

	m_xpCursor->draw(*m_xpWindow, sf::RenderStates::Default);
}

std::string HiScorestate::Next(){
	return "Menustate";
}

bool HiScorestate::IsType(const std::string &p_sType){
	return p_sType.compare("HiScorestate") == 0;
}