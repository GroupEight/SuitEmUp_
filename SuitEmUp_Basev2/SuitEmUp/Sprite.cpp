//Sprite.cpp//

#include "stdafx.h"

#include "Sprite.h"

Sprite::Sprite()
: m_xSprite(){
	
}

Sprite::Sprite(const sf::Texture &p_xTex)
: m_xSprite(p_xTex){
	
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

void Sprite::draw(sf::RenderTarget& p_xTarget, sf::RenderStates p_xStates) const {
	p_xStates.transform *= getTransform();
	p_xTarget.draw(m_xSprite, p_xStates);
}