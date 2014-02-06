//SpriteMan.h//

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

void DrawMan::Draw(Sprite *p_xSprite, sf::RenderStates p_xRstates){
	if (p_xSprite != NULL){
		m_xpWindow->draw(p_xSprite->GetSprite(), p_xRstates);
	}
}