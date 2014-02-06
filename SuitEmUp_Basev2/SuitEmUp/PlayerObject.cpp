//PlayerObject.cpp//

#include "stdafx.h"

#include "PlayerObject.h"

#include "BulletObject.h"

#include "AnimatedSprite.h"
#include "Sprite.h"

#include "GameObjectMan.h"
#include "SpriteMan.h"

PlayerObject::PlayerObject(Sprite *p_xpSprite, GameObjectMan *p_xpBulletMan, SpriteMan *p_xpSpriteMan){
	SetPosition(sf::Vector2f(512, 320));
	m_xpSprite = p_xpSprite;
	m_xpSprite->setPosition(m_xPos);

	m_xpBulletMan = p_xpBulletMan;

	m_xpSpriteMan = p_xpSpriteMan;
}

void PlayerObject::UpdateCurrent(sf::Time p_xDtime){
	sf::Vector2f l_xVel((sf::Keyboard::isKeyPressed(sf::Keyboard::D) - sf::Keyboard::isKeyPressed(sf::Keyboard::A)), (sf::Keyboard::isKeyPressed(sf::Keyboard::S) - sf::Keyboard::isKeyPressed(sf::Keyboard::W)));

	setVelocity(l_xVel * 40.0f * (float)p_xDtime.asSeconds());

	if (m_xpSprite != NULL){
		m_xpSprite->SetPosition(m_xPos);
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		m_xpBulletMan->Add(new BulletObject(m_xPos, sf::Vector2f(1, 1), m_xpSpriteMan->Load("PlaceHolder.png", sf::IntRect(0, 0, 16, 16))));
	}
}

Sprite* PlayerObject::GetSprite(){
	return m_xpSprite;
}

void PlayerObject::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	//p_xWindow.draw(m_xpSprite->GetSprite());
	target.draw(m_xpSprite->GetSprite(), states);
}

void PlayerObject::Animate(sf::Time p_xDtime){
	switch (m_eState){
	case PlayerObject::m_eIdle:
		break;
	case PlayerObject::m_eRun:
		m_xpAnimSprite->Update(p_xDtime);
		break;
	default:
		break;
	}
}