//GfxMan.h//

#include "stdafx.h"

#include "DrawMan.h"

#include "Sprite.h"

DrawMan::DrawMan(){
	m_xpWindow = nullptr;
}

DrawMan::~DrawMan(){

};

bool DrawMan::Init(sf::RenderWindow *p_xpWindow){
	m_xpWindow = p_xpWindow;
	if (m_xpWindow == nullptr){
		return false;
	}
	return true;
}

void DrawMan::Cleanup(){
	if (m_xpWindow != nullptr) {
		delete m_xpWindow;
		m_xpWindow = nullptr;
	}
}

void DrawMan::Clear(){
	m_xpWindow->clear(sf::Color::Blue);
}

void DrawMan::Present(){
	m_xpWindow->display();
}

void DrawMan::Draw(const sf::Drawable *p_xpDrawable, sf::RenderStates p_xRstates){
	if (p_xpDrawable != NULL){
		m_xpWindow->draw(*p_xpDrawable, p_xRstates);
	}
}