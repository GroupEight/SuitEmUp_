//EnemyBullet.cpp//

#include "EnemyBullet.h"
#include "TextureMan.h"
#include "PlayerObject.h"
#include "Morker.h"


EnemyBullet::EnemyBullet(TextureMan *p_xpTextureMan, sf::Vector2f p_xPos, float p_fRot, PlayerObject *p_xpPlayer){
	//std::cout << "SPAWN!!";
	m_xpTextureMan = p_xpTextureMan;
	
	m_xpPlayer = p_xpPlayer;
	
	m_fRadius = 5.f;

	m_xpTex = m_xpTextureMan->Get("Player_Bullet");
	m_xpTex->setSmooth(true);

	m_xpSprite = new sf::Sprite;
	m_xpSprite->setTexture(*m_xpTex);

	m_xPos = p_xPos;

	setPosition(p_xPos);

	m_fSpd = 10.0f;

	//m_xpSprite->setOrigin( 2.f, 2.f );
	m_xpSprite->setScale(0.5,0.5);
	
	
	setRotation(p_fRot);
	
		m_xVel = m_fSpd * sf::Vector2f(cosf((getRotation() + 90.f)* 3.141592 / 180 ), sinf((getRotation() + 90.f)* 3.141592 / 180 ));

}

EnemyBullet::~EnemyBullet(){

}

bool EnemyBullet::Update(sf::Time p_xDtime){
	m_xpSprite->setRotation(getRotation() + 90);

	move(m_xVel);
	
	m_xpSprite->setPosition(getPosition());

	/*if (m_xpPlayer->Overlap(getPosition(), getRadius())){
		return true;
	}*/

	return false;
}

void EnemyBullet::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(*m_xpSprite, states);
}