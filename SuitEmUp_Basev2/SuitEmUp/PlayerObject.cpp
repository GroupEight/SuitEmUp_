//PlayerObject.cpp//

#include "stdafx.h"

#include "PlayerObject.h"

#include "BulletObject.h"

#include "AnimatedSprite.h"
#include "Sprite.h"

#include "GameObjectMan.h"
#include "GfxMan.h"

PlayerObject::PlayerObject(Sprite *p_xpSprite, GameObjectMan *p_xpBulletMan, GfxMan *p_xpGfxMan){
	SetPosition(sf::Vector2f(512, 320));
	setOrigin(0.5 * p_xpSprite->GetPosition().x, 0.5 * p_xpSprite->GetPosition().y);

	m_xpSprite = p_xpSprite;
	m_xpSprite = p_xpSprite;
	m_xpSprite->SetPosition(m_xPos);

	m_xpBulletMan = p_xpBulletMan;

	m_xpGfxMan = p_xpGfxMan;

	m_fBulletspd = 5.0f;
	m_fPlayerspd = 180.0f;

	m_fFrate = 1.5f;
	m_fMaxrate = 1.0f;
	m_fFiretime = 0.0f;

	m_fHeat = 0.0f;
	m_fHeatup = 4.0f;
	m_fCooldown = 4.0f;
	m_fMaxheat = 25.0f;
	m_fMinheat = 15.0f;

	m_bOverheat = false;
}

void PlayerObject::UpdateCurrent(sf::Time p_xDtime){
	sf::Vector2f l_xVel((sf::Keyboard::isKeyPressed(sf::Keyboard::D) - sf::Keyboard::isKeyPressed(sf::Keyboard::A)), (sf::Keyboard::isKeyPressed(sf::Keyboard::S) - sf::Keyboard::isKeyPressed(sf::Keyboard::W)));

	setVelocity(l_xVel * m_fPlayerspd * (float)p_xDtime.asSeconds());

	m_fFiretime += (float)p_xDtime.asSeconds();

	if (m_fHeat > 0.0f){
		m_fHeat -= (m_fCooldown * (float)p_xDtime.asSeconds());
	}
	else {
		m_fHeat = 0.0f;
	}

	if (m_fHeat <= m_fMinheat){
		m_bOverheat = false;
	}
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_fFiretime > (m_fMaxrate / m_fFrate) && m_bOverheat == false){
		m_fFiretime = 0.0f;
		//m_fHeat += m_fHeatup;

		float l_fA = sf::Mouse::getPosition().x - 1024;
		float l_fB = sf::Mouse::getPosition().y - 640;
		float l_fC = sqrt((l_fA * l_fA) + (l_fB * l_fB));

		sf::Vector2f l_xBvel(l_fA/l_fC, l_fB/l_fC);
		
		m_xpBulletMan->Add(new BulletObject(m_xPos, m_fBulletspd * l_xBvel, m_xpGfxMan->LoadSprite("Bullet_Player.png", sf::IntRect(0, 0, 133, 16))));
	}

	if (m_fHeat > m_fMaxheat){
		m_bOverheat = true;
	}

	//std::cout << m_fHeat << std::endl;

	float l_fRot = atan2f((sf::Mouse::getPosition().y - 640), (sf::Mouse::getPosition().x - 1024)) * 180 / 3.141592;
	setRotation(l_fRot);

	if (m_xpSprite != NULL){
		m_xpSprite->SetPosition(GetPosition());
		m_xpSprite->SetRotation(getRotation() - 90.0f);
	}

	//std::cout << GetPosition().x << ": " << GetPosition().y << std::endl;
}

Sprite* PlayerObject::GetSprite(){
	return m_xpSprite;
}

bool PlayerObject::HasGraphics() const {
	return m_xpSprite != NULL;
}

Gfx *PlayerObject::GetGraphics(){
	return m_xpSprite;
}

/*void PlayerObject::SetGraphics(Gfx *p_xpGfx){
	/*if (m_xpSprite->IsGraphic("Sprite")){
		m_xpSprite = p_xpGfx;
	}
}*/

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