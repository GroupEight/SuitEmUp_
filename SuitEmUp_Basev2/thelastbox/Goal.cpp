//Goal.cpp//

#include "Goal.h"

#include "PlayerObject.h"

#include "TextureMan.h"

Goal::Goal(sf::Vector2f p_xPos, float p_fRadius, PlayerObject *p_xpPlayer, TextureMan *p_xpTexMan){
	setPosition(p_xPos);

	m_xpPlayer = p_xpPlayer;

	m_fRadius = p_fRadius;

	m_xpSprite = new sf::Sprite(*p_xpTexMan->Get("Suit_Life"));
	m_xpSprite->setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(160, 199)));

	m_xpSprite->setOrigin(80, 100);

	m_xpSprite->setPosition(getPosition());
}

Goal::~Goal(){
	delete m_xpSprite;
	m_xpSprite = NULL;
}

bool Goal::Update(sf::Time dt){
	if (Overlap(m_xpPlayer->getPosition(), m_xpPlayer->getRadius())){
		return true;
	}

	return Overlap(m_xpPlayer->getPosition(), m_xpPlayer->getRadius());
}

void Goal::draw(sf::RenderTarget& target, sf::RenderStates states ) const {
	target.draw(*m_xpSprite);
}