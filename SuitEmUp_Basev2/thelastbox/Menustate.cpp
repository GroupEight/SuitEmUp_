//Gamestate.cpp//

#include "stdafx.h"

#include "Menustate.h"

#include "Menu_Button.hpp"

#include "FontMan.h"
#include "SoundPlayer.hpp"
#include "TextureMan.h"
#include "CursorObject.h"

Menustate::Menustate(sf::RenderWindow *p_xpWindow, CursorObject *p_xpCursor, TextureMan *p_xpTextMan, FontMan *p_xpFontMan, SoundPlayer *p_xpSPlayer){
	m_xpWindow = p_xpWindow;

	m_xpView = new sf::View(m_xpWindow->getDefaultView());
	m_xpView->setCenter(m_xpWindow->getSize().x / 2, m_xpWindow->getSize().y / 2);

	m_xpWindow->setView(*m_xpView);

	m_xpBGTex = p_xpTextMan->Get( "Menu_BG" );

	m_xpBG = new sf::Sprite();
	m_xpBG->setTexture( *m_xpBGTex );
	if (SceneNode::FScreenMode == 1.0f){
		m_xpBG->setScale(1 / 1.5f, 1 / 1.5f);
	}
	else {
		m_xpBG->setScale(1 , 1);
	}

	m_xpCursor = p_xpCursor;

	// Create all of the buttons:

	m_xpaButtons[0] = new Menu_Button(p_xpTextMan, p_xpFontMan, m_xpWindow, p_xpSPlayer, 3.0f, "Start Game", 500 * SceneNode::FScreenMode, 100 * SceneNode::FScreenMode);

	m_xpaButtons[1] = new Menu_Button(p_xpTextMan, p_xpFontMan, m_xpWindow, p_xpSPlayer, 3.0f, "Quit", 730 * SceneNode::FScreenMode, 300 * SceneNode::FScreenMode);

	m_xpaButtons[2] = new Menu_Button(p_xpTextMan, p_xpFontMan, m_xpWindow, p_xpSPlayer, 3.0f, "Hi-Score", 1050 * SceneNode::FScreenMode, 255 * SceneNode::FScreenMode);
}

Menustate::~Menustate(){
	for (int i = 0; i < 2; i++){
		delete m_xpaButtons[i];
		m_xpaButtons[i] = NULL;
	}
}

bool Menustate::Enter(){
	m_xpWindow->setView(*m_xpView);

	return true;
}

void Menustate::Exit(){

}

bool Menustate::Update(sf::Time p_xDtime){
	// Goes through all of the buttons and goes though with their intended functions - This is hardcoded
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
		if (m_xpaButtons[0]->isWithinLocalBounds()){
			if (m_xpaButtons[0]->Click()){
				m_sNext = "Gamestate";
				return false;
			}
		}
		if (m_xpaButtons[1]->isWithinLocalBounds()){
			if (m_xpaButtons[1]->Click()){
				m_sNext = "";
				return false;
			}
		}
		if (m_xpaButtons[2]->isWithinLocalBounds()){
			if (m_xpaButtons[2]->Click()){
				m_sNext = "HiScorestate";
				return false;
			}
		}
	}
	else {
		for (int i = 0; i < 3; i++){
			if (m_xpaButtons[i]->isWithinLocalBounds()){
				m_xpaButtons[i]->Hover();
			}
			else {
				m_xpaButtons[i]->Out();
			}
		}
	}

	//m_xpCursor->setPosition( sf::Vector2f( sf::Mouse::getPosition().x, sf::Mouse::getPosition().y ) );

	m_xpCursor->Update(p_xDtime);

	return true;
}

void Menustate::Draw(){
	m_xpWindow->draw( *m_xpBG, sf::RenderStates::Default );

	m_xpCursor->draw( *m_xpWindow, sf::RenderStates::Default);

	//m_xpWindow->draw( *m_xpCursor, sf::RenderStates::Default );

	/*for (int i = 0; i < 3; i++){
		m_xpaButtons[i]->draw(*m_xpWindow, sf::RenderStates::Default);
	}*/
}

std::string Menustate::Next(){
	return m_sNext;
}

bool Menustate::IsType(const std::string &p_Type){
	return p_Type.compare("Menustate") == 0;
}