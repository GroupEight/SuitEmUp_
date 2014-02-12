//Gamestate.cpp//

#include "stdafx.h"

#include "Gamestate.h"

#include "DrawMan.h"
#include "GameObjectMan.h"
#include "SpriteMan.h"

#include "PlayerObject.h"
#include "WorkerObject.h"
#include "WarriorObject.h"

Gamestate::Gamestate(DrawMan *p_xpDrawMan, SpriteMan *p_xpSpriteMan, sf::RenderWindow *p_xpWindow){
	m_xpDrawMan = p_xpDrawMan;

	m_xpSpriteMan = p_xpSpriteMan;

	m_xpWindow = p_xpWindow;

	m_xpBulletMan = new GameObjectMan;
	m_xpEnemyMan = new GameObjectMan;

	m_xpPlayer = new PlayerObject(m_xpSpriteMan->Load("Player_Anim/Player_Anim_Idle.png", sf::IntRect(0, 0, 180, 291)), m_xpBulletMan, m_xpSpriteMan);
	m_xpEnemyMan->Add(new WarriorObject(sf::Vector2f(0, 0), m_xpPlayer, m_xpSpriteMan->Load("Player_Anim/Player_Anim_Idle.png", sf::IntRect(0, 0, 180, 291))));

	m_xpWorldView = new sf::View(m_xpWindow->getDefaultView());
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
	m_xpEnemyMan->UpdateOnScreen(m_xpWindow, p_xDtime);

	m_xpWorldView->setCenter(m_xpPlayer->GetPosition() - m_xpPlayer->GetWorldPosition());
	m_xpWorldView->setSize(m_xpWindow->getSize().x, m_xpWindow->getSize().y);

	m_xpBulletMan->DeleteOffScreen(m_xpWindow);

	return true;
}

void Gamestate::Draw(){
	m_xpWindow->setView(*m_xpWorldView);

	m_xpDrawMan->Draw(m_xpPlayer->GetSprite(), sf::RenderStates::RenderStates());

	m_xpBulletMan->DrawOnScreen(m_xpWindow, m_xpDrawMan);
	m_xpEnemyMan->DrawOnScreen(m_xpWindow, m_xpDrawMan);
}

std::string Gamestate::Next(){
	return "Menustate";
}

bool Gamestate::IsType(const std::string &p_Type){
	return p_Type.compare("Gamestate") == 0;
}