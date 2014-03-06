//PlayerBullet.cpp//

#include "PlayerBullet.hpp"

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
}