//HUD.cpp//

#include "HUD.h"

<<<<<<< HEAD
#include "PlayerObject.h"

#include "FontMan.h"
#include "TextureMan.h"

#include <sstream>

HUD::HUD(TextureMan *p_xpTex, FontMan *p_xpFman, sf::RenderWindow *p_xpWindow, PlayerObject *p_xpPlayer){
	m_xpHealthBar = new sf::Sprite(*p_xpTex->Get("Base_Hp"));
	m_xpHpBarHit = new sf::Sprite(*p_xpTex->Get("Hit_Hp"));
	m_xpHpOverlay = new sf::Sprite(*p_xpTex->Get("Bar_Hp"));

	m_xpStarSymbol = new sf::Sprite(*p_xpTex->Get("HUD_Star"));

	m_xpSuits = new sf::Sprite(*p_xpTex->Get("Suit_Life"));
	m_xpSuits->setScale(.9f, .9f);

	m_xpPlayer = p_xpPlayer;

	m_fBarSize = m_xpHpOverlay->getLocalBounds().width;
	m_xpHpOverlay->setOrigin(-260, -115);

	std::string l_sT;

	m_xpTxt = new sf::Text(sf::String(std::string()), *p_xpFman->Get("Standard"), 75);
	m_xpTxt->setColor(sf::Color::White);

	m_xpWindow = p_xpWindow;
=======
HUD::HUD(TextureMan *p_xpTex, sf::RenderWindow p_xpWindow){

>>>>>>> 5301b7ce945568afbd97112a1b45c6472c1ec48b
}

HUD::~HUD(){

}

bool HUD::Update(){
<<<<<<< HEAD
	m_xpHealthBar->setPosition( 200.f + m_xpWindow->getView().getCenter().x - m_xpWindow->getSize().x * .85f, 150.f + m_xpWindow->getView().getCenter().y - m_xpWindow->getSize().y * .855f);
	m_xpHpBarHit->setPosition(m_xpHealthBar->getPosition());

	bool l_b = false;

	int l_i = 1 + 12 * (m_xpPlayer->GetHp() / m_xpPlayer->GetMaxHp());

	if (l_i > 10){
		l_i = 10;
	}

	m_xpSuits->setPosition(175.f + m_xpWindow->getView().getCenter().x - m_xpWindow->getSize().x * .805f, 135.f + m_xpWindow->getView().getCenter().y - m_xpWindow->getSize().y * .80f);
	m_xpSuits->setTextureRect(sf::IntRect(sf::Vector2i((160 * (10 - l_i)), 0), sf::Vector2i(1600/10, 199)));
	
	float l_fLifeBar = (m_xpPlayer->GetHp() / m_xpPlayer->GetMaxHp());
	m_xpHpOverlay->setPosition(200.f + m_xpWindow->getView().getCenter().x - m_xpWindow->getSize().x * .85f, 150.f + m_xpWindow->getView().getCenter().y - m_xpWindow->getSize().y * .855f);
	m_xpHpOverlay->setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(m_fBarSize * l_fLifeBar, m_xpHpOverlay->getLocalBounds().height)));

	std::ostringstream convert;
	convert << m_xpPlayer->GetStars();
	m_xpTxt->setString(std::string(convert.str() + " x "));
	m_xpStarSymbol->setPosition( -200.f + m_xpWindow->getView().getCenter().x + m_xpWindow->getSize().x * .75f, 150.f + m_xpWindow->getView().getCenter().y - m_xpWindow->getSize().y * .75f);
	//m_xpStarSymbol->setPosition(m_xpWindow->getView().getCenter().x + m_xpWindow->getSize().x * .50f, m_xpWindow->getView().getCenter().y - m_xpWindow->getSize().y * .85f);
	m_xpTxt->setPosition( m_xpStarSymbol->getPosition().x - m_xpTxt->getLocalBounds().width, m_xpStarSymbol->getPosition().y);
	//m_xpTxt->setPosition(m_xpStarSymbol->getPosition().x + m_xpStarSymbol->getTexture()->getSize().x, m_xpStarSymbol->getPosition().y);

=======
>>>>>>> 5301b7ce945568afbd97112a1b45c6472c1ec48b
	return false;
}

void HUD::draw(sf::RenderTarget& target, sf::RenderStates states){
<<<<<<< HEAD
	if (!m_xpPlayer->GetInv()){
		m_xpWindow->draw(*m_xpHealthBar);
	}
	else {
		m_xpWindow->draw(*m_xpHpBarHit);
	}
	m_xpWindow->draw(*m_xpSuits);
	m_xpWindow->draw(*m_xpHpOverlay);
	m_xpWindow->draw(*m_xpStarSymbol);
	m_xpWindow->draw(*m_xpTxt);
=======

>>>>>>> 5301b7ce945568afbd97112a1b45c6472c1ec48b
}