//CursorObject.cpp//

#include "CursorObject.h"

#include "TextureMan.h"

CursorObject::CursorObject(TextureMan *p_xpTexMan, sf::RenderWindow *p_xpWindow){
	m_xpSprite = new sf::Sprite(*p_xpTexMan->Get("Mouse_Cursor"));

	m_xpSprite->setOrigin(sf::Vector2f(m_xpSprite->getTexture()->getSize().x / 2, m_xpSprite->getTexture()->getSize().y / 2));

	m_xpWindow = p_xpWindow;
}

CursorObject::~CursorObject(){
	// Empty...
}

bool CursorObject::Update(sf::Time p_xDtime){
	//m_xPos = sf::Vector2f(sf::Mouse::getPosition().x - (m_xpWindow->getView().getCenter().x + m_xpWindow->getSize().x / 2), sf::Mouse::getPosition().y - (m_xpWindow->getView().getCenter().y + m_xpWindow->getSize().y / 2));
	//setPosition(sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y));

	//std::cout << m_xPos.x << ": " << m_xPos.y << std::endl;
	
	//m_vMousePos = sf::Mouse::getPosition(p_rxWindow);
	
	//sf::Vector2i xPos = sf::Mouse::getPosition(p_rxWindow);
	
	setPosition(m_xpWindow->mapPixelToCoords(sf::Mouse::getPosition(*m_xpWindow)));

	m_xpSprite->setPosition(getPosition());

	return false;
}

void CursorObject::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(*m_xpSprite, states);
}