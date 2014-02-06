//Gamestate.cpp//

#include "stdafx.h"

#include "Gamestate.h"

#include "DrawMan.h"
#include "GameObjectMan.h"
#include "SpriteMan.h"

#include "PlayerObject.h"

Gamestate::Gamestate(DrawMan *p_xpDrawMan, SpriteMan *p_xpSpriteMan){
	m_xpDrawMan = p_xpDrawMan;

	m_xpBulletMan = new GameObjectMan;

	m_xpPlayer = new PlayerObject(p_xpSpriteMan->Load("PlaceHolder.png", sf::IntRect(0, 0, 0, 0)));
}

Gamestate::~Gamestate(){
	delete m_xpPlayer;
	m_xpPlayer = NULL;
}

bool Gamestate::Enter(){
	return true;
}

void Gamestate::Exit(){
	
}

bool Gamestate::Update(sf::Time p_xDtime){
	m_xpPlayer->Update(p_xDtime);

	return true;
}

void Gamestate::Draw(){
	m_xpDrawMan->Draw(m_xpPlayer->GetSprite());
}

std::string Gamestate::Next(){
	return "Menustate";
}

bool Gamestate::IsType(const std::string &p_Type){
	return p_Type.compare("Gamestate") == 0;
}