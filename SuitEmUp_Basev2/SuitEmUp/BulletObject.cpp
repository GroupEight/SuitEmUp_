//BulletObject.cpp//

#include "stdafx.h"

#include "BulletObject.h"

#include "Sprite.h"

BulletObject::BulletObject(sf::Vector2f p_xPos, sf::Vector2f p_xVel, Sprite *p_xpSprite){
	m_xPos = p_xPos;
	m_xVel = p_xVel;

	m_xpSprite = p_xpSprite;
}

void BulletObject::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	//p_xWindow.draw(m_xpSprite->GetSprite());
	target.draw(m_xpSprite->GetSprite(), states);
}