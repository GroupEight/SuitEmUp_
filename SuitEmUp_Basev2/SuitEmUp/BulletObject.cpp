//BulletObject.cpp//

#include "stdafx.h"

#include "BulletObject.h"

#include "Sprite.h"

BulletObject::BulletObject(sf::Vector2f p_xPos, sf::Vector2f p_xVel, Sprite *p_xpSprite){
	m_xPos = p_xPos;
	m_xVel = p_xVel;

	m_xpSprite = p_xpSprite;
}

BulletObject::~BulletObject(){
	std::cout << "deleted";
}

bool BulletObject::HasGraphics() const {
	return m_xpSprite != NULL;
}

Gfx *BulletObject::GetGraphics(){
	return m_xpSprite;
}

void  BulletObject::UpdateCurrent(sf::Time p_xDtime){
	float l_fRot = atan2f(m_xVel.x, m_xVel.y) * 180 / 3.141592;
	setRotation(l_fRot);

	if (m_xpSprite != NULL){
		m_xpSprite->SetPosition(m_xPos);
		m_xpSprite->SetRotation(getRotation() - 90.0f);
	}
}