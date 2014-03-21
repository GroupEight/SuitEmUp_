//NewScoreState.cpp//

#include "NewScoreState.h"

#include "FontMan.h"
#include "TextureMan.h"

#include "CursorObject.h"
#include "Menu_Button.hpp"
#include "PlayerObject.h"

#include "Score.h"

#include <fstream>
#include <sstream>

NewScoreState::NewScoreState(sf::RenderWindow *p_xpWindow, PlayerObject *p_xpPlayer, CursorObject *p_xpCursor, TextureMan *p_xpTexMan, FontMan *p_xpFman, SoundPlayer *p_xpSPlayer){
	m_xpWindow = p_xpWindow;
	m_xpPlayer = p_xpPlayer;
	m_xpCursor = p_xpCursor;
	m_xpFman = p_xpFman;

	m_xpInfo = new sf::Text(sf::String(std::string(" ")), *m_xpFman->Get("Standard"), 100);

	m_xCurrStars.setString(std::string(" "));
	m_xCurrStars.setFont(*m_xpFman->Get("Standard"));
	m_xCurrStars.setCharacterSize(75);

	m_xYourScore = m_xCurrStars;
	m_xYourScore.setString("     You");

	m_xpButton = new Menu_Button(p_xpTexMan, p_xpFman, p_xpWindow, p_xpSPlayer, 3.0, "Menu", SceneNode::FScreenMode * 640, SceneNode::FScreenMode * 640);
	m_xpSubmit = new Menu_Button(p_xpTexMan, p_xpFman, p_xpWindow, p_xpSPlayer, 3.0, "Submit", SceneNode::FScreenMode * 640, SceneNode::FScreenMode * 640);
}

NewScoreState::~NewScoreState(){
	for (int i = m_xaScoreTable.size() - 1; i >= 0; i--){
		delete m_xaScoreTable[i];
		m_xaScoreTable[i] = NULL;
	}

	m_xaScoreTable.clear();
}

bool NewScoreState::Enter(){
	sf::View l_xView = m_xpWindow->getView();
	l_xView.setCenter(m_xpWindow->getSize().x / 2, m_xpWindow->getSize().y / 2);
	m_xpWindow->setView(l_xView);

	m_bNewHigh = false;

	for (int i = m_xaScoreTable.size() - 1; i >= 0; i--){
		delete m_xaScoreTable[i];
		m_xaScoreTable[i] = NULL;
	}

	m_xaScoreTable.clear();

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

		m_xaScoreTable.push_back(new Score(l_sName, l_iScore, m_xpFman));

		std::string l_sTxt = l_sName;

		i++;
	}

	stream.close();

	int r = rand() % 16;
	std::string l_sName = "You";

	switch(r){
	case 0:
		l_sName = "Martin";
		break;
	case 1:
		l_sName = "Joakim";
		break;
	case 2:
		l_sName = "Oscar";
		break;
	case 3:
		l_sName = "Bjorn";
		break;
	case 4:
		l_sName = "Markus";
		break;
	case 5:
		l_sName = "William";
		break;
	case 6:
		l_sName = "Hampus";
		break;
	case 7:
		l_sName = "Felix";
		break;
	case 8:
		l_sName = "Mayes";
		break;
	case 9:
		l_sName = "Cirno";
		break;
	case 10:
		l_sName = "Adam";
		break;
	case 11:
		l_sName = "Felix";
		break;
	case 12:
		l_sName = "AAA";
		break;
	case 13:
		l_sName = "Tommi";
		break;
	case 14:
		l_sName = "Snufkin";
		break;
	case 15:
		l_sName = "Luigi";
		break;
	}

	m_xpCurrScore = new Score(l_sName, m_xpPlayer->GetStars(), m_xpFman);	

	for (int ii = m_xaScoreTable.size() - 1; ii >= 0; ii--){
		if (m_xaScoreTable[ii]->m_iStars < m_xpCurrScore->m_iStars){
			for (int iii = m_xaScoreTable.size() - 1; iii >= ii; iii--){
				if (iii + 1 > 9){
					delete m_xaScoreTable[iii];
					m_xaScoreTable[iii] = NULL;
				}
				else {
					m_xaScoreTable[ii] = m_xaScoreTable[ii - 1];
				}
			}
			m_xaScoreTable[ii] = m_xpCurrScore;

			m_bNewHigh = true;
		}
	}

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

	sf::Color l_xColor;
	l_xColor.r = 255;
	l_xColor.b = 255;
	l_xColor.g = 255;
	m_xpCurrScore->m_xpScore->setColor(l_xColor);
	m_xpCurrScore->m_xpStarstxt->setColor(l_xColor);
	
	m_xCurrStars = *m_xpCurrScore->m_xpStarstxt;

	m_xYourScore.setPosition(SceneNode::FScreenMode * 360, SceneNode::FScreenMode  * 510);
	m_xCurrStars.setPosition(SceneNode::FScreenMode  * 830, SceneNode::FScreenMode  * 510);

	return true;
}

void NewScoreState::Exit(){
	for (int i = m_xaScoreTable.size() - 1; i >= 0; i--){
		delete m_xaScoreTable[i];
		m_xaScoreTable[i] = NULL;
	}

	m_xaScoreTable.clear();
}

bool NewScoreState::Update(sf::Time p_xDtime){
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

void NewScoreState::Draw(){
	for (int i = 0; i < m_xaScoreTable.size(); i++){
		m_xpWindow->draw(*m_xaScoreTable[i]->m_xpScore);
		m_xpWindow->draw(*m_xaScoreTable[i]->m_xpStarstxt);
	}

	m_xpWindow->draw(m_xYourScore);
	m_xpWindow->draw(m_xCurrStars);

	m_xpButton->draw(*m_xpWindow, sf::RenderStates::Default);

	m_xpCursor->draw(*m_xpWindow, sf::RenderStates::Default);
}

std::string NewScoreState::Next(){
	return "Menustate";
}

bool NewScoreState::IsType(const std::string &p_sType){
	return p_sType.compare("NewScoreState") == 0;
}