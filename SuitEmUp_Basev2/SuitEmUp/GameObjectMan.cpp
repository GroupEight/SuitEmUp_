//GameObjectMan.cpp//

#include "stdafx.h"

#include "GameObjectMan.h"

GameObjectMan::GameObjectMan(){
	
}

GameObjectMan::~GameObjectMan(){
	for (int i = 0; i < m_xpaGobjs.size(); i++){
		if (m_xpaGobjs[i] != NULL){
			delete m_xpaGobjs[i];
			m_xpaGobjs[i] = NULL;
		}
	}
	m_xpaGobjs.clear();
}

void GameObjectMan::Add(GameObject *p_cpGobj){
	m_xpaGobjs.push_back(p_cpGobj);
}

std::vector<GameObject*> GameObjectMan::GetVector(){
	return m_xpaGobjs;
}

void GameObjectMan::UpdateAll(sf::Time dt){
	for (int i = 0; i < m_xpaGobjs.size(); i++){
		if (m_xpaGobjs[i] != NULL){
			m_xpaGobjs[i]->Update(dt);
		}
	}
}

void GameObjectMan::Cleanup(){
	for (int i = 0; i < m_xpaGobjs.size(); i++){
		if (m_xpaGobjs[i] != NULL){
			delete m_xpaGobjs[i];
			m_xpaGobjs[i] = NULL;
		}
	}
	m_xpaGobjs.clear();
}