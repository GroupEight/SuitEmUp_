//Player_Arms.cpp//

#include "Player_Arms.hpp"

#include "TextureMan.h"

#include "PlayerObject.h"

Player_Arms::Player_Arms(TextureMan *p_xpTextMan, int p_iArmDir, PlayerObject *p_xpPlayer)
: m_xControlVertices (sf::Points, 3)
, m_xArms(sf::TrianglesStrip, 40)
, m_iArmDir(p_iArmDir){
	m_xpGloveTex = p_xpTextMan->Get("Player_Glove_Empty");
	m_xpGloveTex->setSmooth( true );
	m_xpGlove = new sf::Sprite(*m_xpGloveTex);
	m_xpGlove->setOrigin( m_xpGlove->getLocalBounds().width / 2.f, m_xpGlove->getLocalBounds().height / 2.f );

	m_xpPlayer = p_xpPlayer;

	std::cout << getOrigin().x << getOrigin().y << std::endl;
	//setOrigin(m_xpPlayer->getPosition().x - getPosition().x, m_xpPlayer->getPosition().y - getPosition().y);
	setOrigin(0, 10);
	std::cout << getOrigin().x << getOrigin().y << std::endl;

	m_bPunching = false;

	m_fPunchLength = 0;
	m_fPunchInterp = 0;
}

void Player_Arms::setArmsPosition(sf::Vector2i armLength, float p_fRot){

	if(m_bPunching){
		m_fPunchLength = sinf( m_fPunchInterp * 3.141592 / 180 );
		m_fPunchInterp += 15.f; //Degrees

		if(m_fPunchInterp > 180.f){
			m_bPunching = false;
			m_fPunchLength = 0.f;
			m_fPunchInterp = 0.f;
		}
	}

	//float l_fA = m_xpPlayer->getPosition().x * m_xpPlayer->getPosition().x;
	//float l_fB = m_xpPlayer->getPosition().y * m_xpPlayer->getPosition().y;
	/*float l_fA = sf::Mouse::getPosition().x * sf::Mouse::getPosition().x;
	float l_fB = sf::Mouse::getPosition().y * sf::Mouse::getPosition().y;
	float l_fC = sqrtf(l_fA + l_fB);
	float l_fCos = l_fA / l_fC;
	float l_fSin = l_fB / l_fC;*/
	float l_fCos = 0;
	float l_fSin = 0;

	m_xControlVertices[0].position = sf::Vector2f( l_fCos + m_xpPlayer->getPosition().x, l_fSin + m_xpPlayer->getPosition().y + 15.f * m_iArmDir );
	m_xControlVertices[1].position = sf::Vector2f( l_fCos + m_xpPlayer->getPosition().x + 40.f, l_fSin + m_xpPlayer->getPosition().y - 50.f * m_iArmDir);
	m_xControlVertices[2].position = sf::Vector2f( l_fCos + m_xpPlayer->getPosition().x + 60.f + m_fPunchLength * 300.f, l_fSin + m_xpPlayer->getPosition().y );

	int q = 0;
	float lastX = 0;
	float lastY = 0;
	float armWidth = 6.f;

	for (float t = 0 ; t < 1 ; t += 0.05){
		// The interpolation Line
		float xa = GetPt( m_xControlVertices[0].position.x , m_xControlVertices[1].position.x , t );
		float ya = GetPt( m_xControlVertices[0].position.y , m_xControlVertices[1].position.y , t );
		float xb = GetPt( m_xControlVertices[1].position.x , m_xControlVertices[2].position.x , t );
		float yb = GetPt( m_xControlVertices[1].position.y , m_xControlVertices[2].position.y , t );

		// The resulting position
		float x = GetPt( xa , xb , t );
		float y = GetPt( ya , yb , t );

		//Determine angle
		//float a = (90.f * 3.141592 / 180) + atan2f( (y - lastY), (x - lastX) );
		float a = (m_xpPlayer->getRotation()) + atan2f( (y - lastY), (x - lastX) );

		//Add vertices
		m_xArms[q].position = sf::Vector2f( x + cosf(a) * -armWidth/2, y + sinf(a) * -armWidth/2);
		m_xArms[q+1].position = sf::Vector2f( x + cosf(a) * armWidth/2, y + sinf(a) * armWidth/2 );

		//Color
		m_xArms[q].color = sf::Color::Black;
		m_xArms[q+1].color = sf::Color::Black;

		q+=2;

		lastX = x;
		lastY = y;

		m_xpGlove->setPosition( x, y );
		//m_xpGlove->setRotation( -90 + a * 180 / 3.141592 );
		//m_xpGlove->setRotation(p_fRot);
	}
}

bool Player_Arms::Punch(){
	m_bPunching = true;
	
	return true;
}

float Player_Arms::GetPt( int n1 , int n2 , float perc ){
    int diff = n2 - n1;

    return n1 + ( diff * perc );
}

void Player_Arms::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	target.draw( m_xArms, states );
	//target.draw( *m_xpGlove, states );
}