//Star.cpp//

#include "Star.h"

#include "SoundPlayer.hpp"
#include "TextureMan.h"

#include "PlayerObject.h"

Star::Star(TextureMan *p_xpTextureMan, sf::Vector2f p_xPos, PlayerObject *p_xpPlayer, SoundPlayer *p_xpSPlayer){
	
	m_xpTextureMan = p_xpTextureMan;
	
	m_xpPlayer = p_xpPlayer;
	
	m_xpSPlayer = p_xpSPlayer;
	
	m_xpTex = m_xpTextureMan->Get("Star");
	m_xpTex->setSmooth(true);

	m_xpSprite = new sf::Sprite;
	m_xpSprite->setTexture(*m_xpTex);

	m_xPos = p_xPos;

	setPosition(p_xPos);

	m_fRadius = 1.f;

	m_fSpd = 10.0f;

	m_xpSprite->setOrigin( m_xpSprite->getTexture()->getSize().x / 2,  m_xpSprite->getTexture()->getSize().y / 2 );
	m_xpSprite->setScale(1, 1);
	
	setRotation(rand() % 360);
	m_xpSprite->setRotation(getRotation());

	int l_i = rand() % 16;
	m_fDeacc = 1.f - .05 * l_i;
	
	//m_xVel = m_fSpd * sf::Vector2f(cosf((getRotation() + 90.f)* 3.141592 / 180 ), sinf((getRotation() + 90.f)* 3.141592 / 180 ));
	//setPosition(m_xpBody->GetPosition().x, m_xpBody->GetPosition().y);

	m_bCollect = false;
}

Star::~Star(){

}

bool Star::Update(sf::Time p_xDtime){	
	if (m_xpPlayer->Overlap(getPosition(), 200 * m_fRadius) && m_fDeacc == 0.f){
		m_bCollect = true;
	}

	if (m_bCollect){
		setRotation(atan2f( (m_xpPlayer->getPosition().y - getPosition().y), (m_xpPlayer->getPosition().x - getPosition().x) ) * 180.f / 3.141592f - 90.f);
		m_xVel = m_fSpd * sf::Vector2f(cosf(getRotation() * 3.141592 / 180 + 90.f), sinf(getRotation() * 3.141592 / 180 + 90.f));
	}
	else if (!m_bCollect){
		m_xVel = m_fDeacc * m_fSpd * sf::Vector2f(cosf(getRotation() * 3.141592 / 180 + 90.f), sinf(getRotation() * 3.141592 / 180 + 90.f));
	}

	m_xpSprite->setPosition(getPosition());
	m_xpSprite->setRotation(m_xpSprite->getRotation() + 5.f);

	move(m_xVel);

	if (m_xpPlayer->Overlap(getPosition(), m_fRadius)){
		int r = rand() % 3;
		if (r == 0) m_xpSPlayer->Play("Star_Collect0", getPosition());
		if (r == 1) m_xpSPlayer->Play("Star_Collect1", getPosition());
		if (r == 2) m_xpSPlayer->Play("Star_Collect2", getPosition());
		//m_xpSPlayer->Play("Star_Collect0", getPosition());
		m_xpPlayer->StarsPlus();
		//m_xpPlayer->Damage(.1);
		return true;
	}

	if (m_fDeacc > 0.f){
		m_fDeacc-= .025f;
	}
	else {
		m_fDeacc = 0.f;
	}

	return false;
}

void Star::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(*m_xpSprite, states);
}