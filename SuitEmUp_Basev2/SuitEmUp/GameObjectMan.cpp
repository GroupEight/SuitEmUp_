//GameObjectMan.cpp//

#include "stdafx.h"

#include "GameObjectMan.h"

#include "DrawMan.h"

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
	for (int i = m_xpaGobjs.size() - 1; i >= 0; i--){
		if (m_xpaGobjs[i] != NULL){
			m_xpaGobjs[i]->Update(dt);
		}
	}
}

void GameObjectMan::DrawAll(DrawMan *p_xpDrawMan){
	for (int i = m_xpaGobjs.size() - 1; i >= 0; i--){
		if (m_xpaGobjs[i] != NULL){
			p_xpDrawMan->Draw(m_xpaGobjs[i]->GetSprite(), sf::RenderStates::RenderStates());
		}
	}
}

void GameObjectMan::UpdateOnScreen(sf::RenderWindow *p_xpWindow, sf::Time p_xDtime){
	for (int i = 0; i < m_xpaGobjs.size(); i++){
		if (m_xpaGobjs[i] != NULL){
			if (m_xpaGobjs[i]->OnScreen(p_xpWindow)){
				m_xpaGobjs[i]->Update(p_xDtime);
			}
		}
	}
}

void GameObjectMan::DrawOnScreen(sf::RenderWindow *p_xpWindow, DrawMan *p_xpDrawMan){
	for (int i = 0; i < m_xpaGobjs.size(); i++){
		if (m_xpaGobjs[i] != NULL){
			if (m_xpaGobjs[i]->OnScreen(p_xpWindow)){
				p_xpDrawMan->Draw(m_xpaGobjs[i]->GetSprite(), sf::RenderStates::RenderStates());
			}
		}
	}
}

void GameObjectMan::DeleteOffScreen(sf::RenderWindow *p_xpWindow){
	for (int i = 0; i < m_xpaGobjs.size(); i++){
		if (m_xpaGobjs[i] != NULL){
			if (!m_xpaGobjs[i]->OnScreen(p_xpWindow)){
				std::cout << i;
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