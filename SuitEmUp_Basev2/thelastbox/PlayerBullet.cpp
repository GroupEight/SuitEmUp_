//PlayerBullet.cpp//

#include "PlayerBullet.hpp"
/*
PlayerBullet::PlayerBullet(sf::Texture *p_xpTex, sf::Vector2f p_xPos, float p_fRot){
	m_xpTex = p_xpTex;
	m_xpTex->setSmooth(true);

	m_xpSprite = new sf::Sprite;
	m_xpSprite->setTexture(*m_xpTex);

	m_xPos = p_xPos;

	m_xVel = sf::Vector2f(cosf(p_fRot * 3.141592 / 180 ) * 2000.f, sinf(p_fRot * 3.141592 / 180 ) * 2000.f);
}

PlayerBullet::~PlayerBullet(){

}

void PlayerBullet::Update(sf::Time p_xDtime){
	float l_fRot = atan2f(m_xVel.x, m_xVel.y) * 180 / 3.141592;
	setRotation(l_fRot);
}

void PlayerBullet::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(*m_xpSprite, states);
}*/



#include "TextureMan.h"
#include "PlayerObject.h"


PlayerBullet::PlayerBullet(TextureMan *p_xpTextureMan, sf::Vector2f p_xPos, float p_fRot){
	//std::cout << "SPAWN!!";
	m_xpTextureMan = p_xpTextureMan;
	
	//m_xpPlayer = p_xpPlayer;
	
	

	m_xpTex = m_xpTextureMan->Get("Player_Bullet");
	m_xpTex->setSmooth(true);

	m_xpSprite = new sf::Sprite;
	m_xpSprite->setTexture(*m_xpTex);

	m_xPos = p_xPos;

	setPosition(p_xPos);

	m_fSpd = 10.0f;

	//m_xpSprite->setOrigin( 2.f, 2.f );
	m_xpSprite->setScale(1.1,1.1);
	
	
	setRotation(p_fRot);
	
		m_xVel = m_fSpd * sf::Vector2f(cosf((getRotation() + 90.f)* 3.141592 / 180 ), sinf((getRotation() + 90.f)* 3.141592 / 180 ));

	

	
	
}

PlayerBullet::~PlayerBullet(){

}

void PlayerBullet::Update(sf::Time p_xDtime){
	m_xpSprite->setRotation(getRotation() + 90 );

	move(m_xVel);

	//setPosition(getPosition());
	
	m_xpSprite->setPosition(getPosition());
	
}

void PlayerBullet::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(*m_xpSprite, states);
}