//PlayerObject.cpp//

#include "stdafx.h"

#include "PlayerObject.h"

#include "Sprite.h"

PlayerObject::PlayerObject(){

}

void PlayerObject::UpdateCurrent(sf::Time p_xDtime){
	sf::Vector2f l_xVel((sf::Keyboard::isKeyPressed(sf::Keyboard::D) - sf::Keyboard::isKeyPressed(sf::Keyboard::A)), (sf::Keyboard::isKeyPressed(sf::Keyboard::S) - sf::Keyboard::isKeyPressed(sf::Keyboard::W)));
	
	setVelocity(l_xVel * (float)p_xDtime.asMicroseconds());
}

void PlayerObject::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	//p_xWindow.draw(m_xpSprite->GetSprite());
	target.draw(m_xpSprite->GetSprite(), states);
}