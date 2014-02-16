//Background.cpp//

#include "Background.h"

Background::Background(sf::Texture *p_xpTex, sf::Vector2f p_xSize){
	m_xpTex = p_xpTex;
	m_xpTex->setRepeated(true);

	m_xSize.x = p_xSize.x;
	m_xSize.y = p_xSize.y;

	int i = 0;

	//sf::VertexArray l_xVertArray(sf::Quads, 4);
	m_xVertArray.setPrimitiveType(sf::Quads);
	m_xVertArray.resize(4);

	m_xVertArray[i].position = sf::Vector2f(0, 0);
	m_xVertArray[i + 1].position = sf::Vector2f(0, p_xSize.x);
	m_xVertArray[i + 2].position = sf::Vector2f(m_xSize.y, m_xSize.x);
	m_xVertArray[i + 3].position = sf::Vector2f(m_xSize.y, 0);

	m_xVertArray[i].texCoords = sf::Vector2f(0, 0);
	m_xVertArray[i + 1].texCoords = sf::Vector2f(0, m_xSize.x);
	m_xVertArray[i + 2].texCoords = sf::Vector2f(m_xSize.y, m_xSize.x);
	m_xVertArray[i + 3].texCoords = sf::Vector2f(m_xSize.y, 0);

	m_xVertArray[i].color = sf::Color::Blue;
	m_xVertArray[i + 1].color = sf::Color::Green;
	m_xVertArray[i + 2].color = sf::Color::Yellow;
	m_xVertArray[i + 3].color = sf::Color::Red;

	m_xpVertArray = &m_xVertArray;
}

Background::~Background(){

}



sf::Drawable *Background::GetParent(){
	return m_xpVertArray;
}

sf::Texture *Background::GetTexture(){
	return m_xpTex;
}

void Background::UpdateTexCoords(sf::Vector2f p_xOffset, sf::Vector2f p_xPosition){
	int i = 0;

	m_xVertArray[i + 0].position = sf::Vector2f(p_xPosition.x + m_xSize.x, p_xPosition.y + m_xSize.y);
	m_xVertArray[i + 1].position = sf::Vector2f(p_xPosition.x - m_xSize.x, p_xPosition.y + m_xSize.y);
	m_xVertArray[i + 2].position = sf::Vector2f(p_xPosition.x - m_xSize.x, p_xPosition.y - m_xSize.y);
	m_xVertArray[i + 3].position = sf::Vector2f(p_xPosition.x + m_xSize.x, p_xPosition.y - m_xSize.y);

	m_xVertArray[i + 0].texCoords = sf::Vector2f(0, 0) - p_xOffset;
	m_xVertArray[i + 1].texCoords = sf::Vector2f(m_xSize.y, 0) - p_xOffset;
	m_xVertArray[i + 2].texCoords = sf::Vector2f(m_xSize.y, m_xSize.x) - p_xOffset;
	m_xVertArray[i + 3].texCoords = sf::Vector2f(0, m_xSize.x) - p_xOffset;
}

bool Background::IsGraphic(const std::string &p_sType){
	return p_sType.compare("Background") == 0;
}