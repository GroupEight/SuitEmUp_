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

void GameObjectMan::Add(GameObject *p_xpGobj){
	for (int i = 0; i < m_xpaGobjs.size(); i++){
		if (m_xpaGobjs[i] == NULL){
			m_xpaGobjs[i] = p_xpGobj;
			return;
		}
	}

	m_xpaGobjs.push_back(p_xpGobj);
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

void GameObjectMan::OnScreen(sf::Vector2f p_xV0, sf::Vector2f p_xV1){
	for (int i = 0; i < m_xpaGobjs.size(); i++){
		if (m_xpaGobjs[i] != NULL){
			if (m_xpaGobjs[i]->OnScreen(p_xV0, p_xV1)){
				delete m_xpaGobjs[i];
				m_xpaGobjs[i] = NULL;
			}
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