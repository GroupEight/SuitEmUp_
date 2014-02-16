//Sprite.cpp//

#include "stdafx.h"

#include "Sprite.h"

Sprite::Sprite()
: m_xpSprite(){
	
}

Sprite::Sprite(const sf::Texture *p_xpTex){
	sf::Sprite l_xSprite;
	l_xSprite.setTexture(*p_xpTex);

	m_xpSprite = new sf::Sprite(l_xSprite);
	
	m_xpSprite->setOrigin(sf::Vector2f(GetTexture()->getSize().x * 0.5, GetTexture()->getSize().y * 0.5));
}

Sprite::~Sprite(){

}

void Sprite::SetTexture(const sf::Texture *p_xpTex){
	m_xpSprite->setTexture(*p_xpTex);
}

const sf::Texture* Sprite::GetTexture() const {
	return m_xpSprite->getTexture();
}

void Sprite::SetSprite(sf::Sprite p_xSprite){
	m_xpSprite = &p_xSprite;
}

const sf::Sprite *Sprite::GetSprite(){
	return m_xpSprite;
}

void Sprite::SetPosition(sf::Vector2f p_xPos){
	m_xpSprite->setPosition(p_xPos);
}

sf::Vector2f Sprite::GetPosition(){
	return m_xpSprite->getPosition();
}

void Sprite::SetRotation(float p_fPos){
	m_xpSprite->setRotation(p_fPos);
}

float Sprite::GetRotation(){
	return m_xpSprite->getRotation();
}

sf::Drawable *Sprite::GetParent(){
	return m_xpSprite;
}

bool Sprite::IsGraphic(const std::string &p_sType){
	return p_sType.compare("Sprite") == 0;
}