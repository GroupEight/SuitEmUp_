//Sprite.cpp//

#include "stdafx.h"

#include "Sprite.h"

Sprite::Sprite()
: m_xSprite(){
	
}

Sprite::Sprite(const sf::Texture &p_xTex){
	SetTexture(p_xTex);
	
	m_xSprite.setOrigin(sf::Vector2f(GetTexture()->getSize().x * 0.5, GetTexture()->getSize().y * 0.5));
}

Sprite::~Sprite(){

}

void Sprite::SetTexture(const sf::Texture& p_xTex){
	m_xSprite.setTexture(p_xTex);
}

const sf::Texture* Sprite::GetTexture() const {
	return m_xSprite.getTexture();
}

void Sprite::SetSprite(sf::Sprite p_xSprite){
	m_xSprite = p_xSprite;
}

const sf::Sprite Sprite::GetSprite(){
	return m_xSprite;
}

void Sprite::SetPosition(sf::Vector2f p_xPos){
	m_xSprite.setPosition(p_xPos);
}

sf::Vector2f Sprite::GetPosition(){
	return m_xSprite.getPosition();
}

void Sprite::SetRotation(float p_fPos){
	m_xSprite.setRotation(p_fPos);
}

float Sprite::GetRotation(){
	return m_xSprite.getRotation();
}

void Sprite::draw(sf::RenderTarget& p_xTarget, sf::RenderStates p_xStates) const {
	p_xStates.transform *= getTransform();
	p_xTarget.draw(m_xSprite, p_xStates);
}