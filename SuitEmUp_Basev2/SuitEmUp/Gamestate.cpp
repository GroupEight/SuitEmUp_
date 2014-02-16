//Gamestate.cpp//

#include "Gamestate.h"

#include "DrawMan.h"
#include "GameObjectMan.h"
#include "GfxMan.h"

#include "BGObject.h"
#include "PlayerObject.h"
#include "WorkerObject.h"
#include "WarriorObject.h"

Gamestate::Gamestate(DrawMan *p_xpDrawMan, GfxMan *p_xpGfxMan, sf::RenderWindow *p_xpWindow){
	m_xpDrawMan = p_xpDrawMan;

	m_xpGfxMan = p_xpGfxMan;

	m_xpWindow = p_xpWindow;

	m_xpBulletMan = new GameObjectMan;
	m_xpEnemyMan = new GameObjectMan;

	m_xpPlayer = new PlayerObject(m_xpGfxMan->LoadSprite("Player_Anim/Player_Anim_Idle.png", sf::IntRect(0, 0, 180, 291)), m_xpBulletMan, m_xpGfxMan);
	m_xpBGround = new BGObject(m_xpGfxMan->LoadBackground("Ground.png", sf::Vector2f(m_xpWindow->getSize().x, m_xpWindow->getSize().y)), m_xpPlayer, m_xpWindow);
	m_xpEnemyMan->Add(new WarriorObject(m_xpGfxMan->LoadSprite("Warrior_01.png", sf::IntRect(0, 0, 0, 0)), sf::Vector2f(-40, -40), m_xpPlayer));

	m_xpWorldView = new sf::View(m_xpWindow->getDefaultView());

	m_fZoom = 1.0f;
}

Gamestate::~Gamestate(){
	if (m_xpBulletMan != NULL){
		delete m_xpBulletMan;
		m_xpBulletMan = NULL;
	}
	if (m_xpEnemyMan != NULL){
		delete m_xpEnemyMan;
		m_xpEnemyMan = NULL;
	}
	if (m_xpPlayer != NULL){
		delete m_xpPlayer;
		m_xpPlayer = NULL;
	}
	if (m_xpWorldView != NULL){
		delete m_xpWorldView;
		m_xpWorldView = NULL;
	}
}

bool Gamestate::Enter(){
	return true;
}

void Gamestate::Exit(){
	
}

bool Gamestate::Update(sf::Time p_xDtime){
	m_xpPlayer->Update(p_xDtime);

	m_xpBulletMan->UpdateAll(p_xDtime);
	m_xpEnemyMan->UpdateAll(p_xDtime);

	m_xpBGround->Update(p_xDtime);

	m_xpWorldView->setCenter(m_xpPlayer->GetPosition());

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && m_fZoom < 1.5f){
		m_fZoom += 0.025f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && m_fZoom > 0.5f){
		m_fZoom -= 0.025f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
		m_fZoom = 1.0f;
	}
	m_xpWorldView->setSize(m_fZoom * m_xpWindow->getSize().x, m_fZoom * m_xpWindow->getSize().y);
	m_xpWindow->setView(*m_xpWorldView);

	m_xpBulletMan->DeleteOffScreen(m_xpWindow);

	return true;
}

void Gamestate::Draw(){
	m_xpDrawMan->Draw(m_xpBGround->GetGraphics()->GetParent(), m_xpBGround->GetTexture());

	m_xpDrawMan->Draw(m_xpPlayer->GetSprite()->GetParent(), sf::RenderStates::RenderStates());

	m_xpBulletMan->DrawOnScreen(m_xpWindow, m_xpDrawMan);
	m_xpEnemyMan->DrawOnScreen(m_xpWindow, m_xpDrawMan);
}

std::string Gamestate::Next(){
	return "Menustate";
}

bool Gamestate::IsType(const std::string &p_sType){
	return p_sType.compare("Gamestate") == 0;
}