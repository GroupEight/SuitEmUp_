//BGObject.cpp//

#include "BGObject.h"

#include "PlayerObject.h"

#include "Background.h"
#include "Sprite.h"

BGObject::BGObject(Background *p_xpBg, PlayerObject *p_xpPlayer, sf::RenderWindow *p_xpWindow){
	m_xpWindow = p_xpWindow;

	m_xpBg = p_xpBg;
	m_xpPlayer = p_xpPlayer;
}

BGObject::~BGObject(){
	
}

void BGObject::UpdateCurrent(sf::Time dt){
	sf::Vector2f p_xOffset = m_xpPlayer->GetPosition() + sf::Vector2f(m_xpWindow->getSize().x, m_xpWindow->getSize().y);

	m_xpBg->UpdateTexCoords(p_xOffset, m_xpPlayer->GetPosition());
}

sf::Texture *BGObject::GetTexture(){
	return m_xpBg->GetTexture();
}

bool BGObject::HasGraphics() const {
	return m_xpBg != NULL;
}

Gfx *BGObject::GetGraphics(){
	return m_xpBg;
}