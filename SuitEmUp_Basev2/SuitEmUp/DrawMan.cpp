//SpriteMan.h//

#include "stdafx.h"

#include "DrawMan.h"

#include "Sprite.h"

DrawMan::DrawMan(){
	m_xpWindow = nullptr;
}

DrawMan::~DrawMan(){

};

bool DrawMan::Initialize(sf::RenderWindow *p_xpWindow, sf::Vector2f p_xSize){
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

void DrawMan::Draw(Sprite *sprite, sf::Vector2f p_xPos){
	if (sprite != NULL){
		//if (sprite->IsSprite("Sprite")){
		//	SDL_Rect src = { sprite->m_iX, sprite->m_iY, sprite->m_iW, sprite->m_iH };
		//	SDL_Rect dst = { x, y, sprite->m_iW, sprite->m_iH };
		//	SDL_RenderCopy(m_renderer, sprite->m_TexpAlpha, &src, &dst);
		//}
		//else if (sprite->IsSprite("Text")){
		//	SDL_Rect l_cLoc = { x, y, 0, 0 };
		//	SDL_RenderCopy(m_renderer, sprite->m_TexpAlpha, NULL, &l_cLoc);
		//	// SDL_BlitSurface(sprite->m_SurpAlpha, NULL, );
		//}
	}
}