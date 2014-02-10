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

	m_fBulletspd = 50.0f;
	m_fPlayerspd = 40.0f;

	m_fFrate = 6.0f;
	m_fMaxrate = 1.0f;
	m_fFiretime = 0.0f;
}

void PlayerObject::UpdateCurrent(sf::Time p_xDtime){
	sf::Vector2f l_xVel((sf::Keyboard::isKeyPressed(sf::Keyboard::D) - sf::Keyboard::isKeyPressed(sf::Keyboard::A)), (sf::Keyboard::isKeyPressed(sf::Keyboard::S) - sf::Keyboard::isKeyPressed(sf::Keyboard::W)));

	setVelocity(l_xVel * m_fPlayerspd * (float)p_xDtime.asSeconds());

	m_fFiretime += (float)p_xDtime.asSeconds();
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_fFiretime > (m_fMaxrate / m_fFrate)){
		m_fFiretime = 0.0f;
		float l_fA = sf::Mouse::getPosition().x - 1024/* - GetPosition().x*/;
		float l_fB = sf::Mouse::getPosition().y - 640/* - GetPosition().y*/;
		float l_fC = sqrt((l_fA * l_fA) + (l_fB * l_fB));

		sf::Vector2f l_xBvel(l_fA/l_fC, l_fB/l_fC);
		
		m_xpBulletMan->Add(new BulletObject(m_xPos, m_fBulletspd * l_xBvel, m_xpSpriteMan->Load("PlaceHolder.png", sf::IntRect(0, 0, 16, 16))));
	}

	float l_fRot = atan2f((sf::Mouse::getPosition().y - 640), (sf::Mouse::getPosition().x - 1024)) * 180 / 3.141592;
	std::cout << l_fRot << std::endl;
	setRotation(l_fRot);

	if (m_xpSprite != NULL){
		m_xpSprite->SetPosition(GetPosition());
		m_xpSprite->setRotation(getRotation());
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

//Rotate player
/*mPRot = atan2f((mCursorPos.y - 720 / 2), (mCursorPos.x - 1280 / 2)) * 180 / 3.141592;
mPlayer->setRotation(mPRot);*/