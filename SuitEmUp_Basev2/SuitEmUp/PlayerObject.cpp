//PlayerObject.cpp//

#include "stdafx.h"

#include "PlayerObject.h"

#include "Sprite.h"

PlayerObject::PlayerObject(Sprite *p_xpSprite){
	SetPosition(sf::Vector2f(512, 320));
	m_xpSprite = p_xpSprite;
	m_xpSprite->setPosition(m_xPos);
}

void PlayerObject::UpdateCurrent(sf::Time p_xDtime){
	sf::Vector2f l_xVel((sf::Keyboard::isKeyPressed(sf::Keyboard::D) - sf::Keyboard::isKeyPressed(sf::Keyboard::A)), (sf::Keyboard::isKeyPressed(sf::Keyboard::S) - sf::Keyboard::isKeyPressed(sf::Keyboard::W)));

	setVelocity(l_xVel * (float)p_xDtime.asMicroseconds());

	//SetPosition(m_xPos + m_xVel);

	if (m_xpSprite != NULL){
		m_xpSprite->SetPosition(m_xPos);
	}
}

Sprite* PlayerObject::GetSprite(){
	return m_xpSprite;
}

void PlayerObject::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	//p_xWindow.draw(m_xpSprite->GetSprite());
	target.draw(m_xpSprite->GetSprite(), states);
}