//GameObjectMan.cpp//

#include "GameObjectMan.h"

#include "GameObject.h"

GameObjectMan::GameObjectMan(){
	
}

GameObjectMan::~GameObjectMan(){
	for (int i = m_xpaGobjs.size() - 1; i >= 0; i--){
		if (m_xpaGobjs[i] != NULL){
			delete m_xpaGobjs[i];
			m_xpaGobjs[i] = NULL;
		}
	}
	m_xpaGobjs.clear();
}

std::vector<GameObject*> GameObjectMan::GetVector(){
	return m_xpaGobjs;
}

void GameObjectMan::Add(GameObject *p_xpGobj){
	for (int i = m_xpaGobjs.size() - 1; i >= 0; i--){
		if (m_xpaGobjs[i] == p_xpGobj){
			return;
		}
		if (m_xpaGobjs[i] == NULL){
			m_xpaGobjs[i] = p_xpGobj;
			return;
		}
	}

	m_xpaGobjs.push_back(p_xpGobj);
}

void GameObjectMan::UpdateAll(sf::Time p_xDtime){
	for (int i = m_xpaGobjs.size() - 1; i >= 0; i--){
		if (m_xpaGobjs[i] != NULL){
			m_xpaGobjs[i]->Update(p_xDtime);
		}
	}
}

void GameObjectMan::DrawAll(sf::RenderTarget *p_xpTarget){
	for (int i = m_xpaGobjs.size() - 1; i >= 0; i--){
		if (m_xpaGobjs[i] != NULL){
			m_xpaGobjs[i]->draw(*p_xpTarget, sf::RenderStates::Default);
		}
	}
}

void GameObjectMan::UpdateOnScreen(sf::RenderWindow *p_xpWindow, sf::Time p_xDtime){
	for (int i = m_xpaGobjs.size() - 1; i >= 0; i--){
		if (m_xpaGobjs[i] != NULL){
			if (m_xpaGobjs[i]->OnScreen(p_xpWindow)){
				m_xpaGobjs[i]->Update(p_xDtime);
			}
		}
	}
}

void GameObjectMan::DrawOnScreen(sf::RenderWindow *p_xpWindow){
	for (int i = m_xpaGobjs.size() - 1; i >= 0; i--){
		if (m_xpaGobjs[i] != NULL){
			if (m_xpaGobjs[i]->OnScreen(p_xpWindow)){
				m_xpaGobjs[i]->draw(*p_xpWindow, sf::RenderStates::Default);
			}
		}
	}
}

void GameObjectMan::DeleteAll(){
	for (int i = m_xpaGobjs.size() - 1; i >= 0; i--){
		if (m_xpaGobjs[i] != NULL){
			delete m_xpaGobjs[i];
			m_xpaGobjs[i] = NULL;
		}
	}
	m_xpaGobjs.clear();
}

void GameObjectMan::DeleteOffScreen(sf::RenderWindow *p_xpWindow){
	for (int i = m_xpaGobjs.size() - 1; i >= 0; i--){
		if (m_xpaGobjs[i] != NULL){
			if (!m_xpaGobjs[i]->OnScreen(p_xpWindow)){
				std::cout << i;
				delete m_xpaGobjs[i];
				m_xpaGobjs[i] = NULL;
			}
		}
	}
}

void GameObjectMan::CopyFrom(GameObjectMan *p_xpGameObjectMan){
	for (int i = p_xpGameObjectMan->GetVector().size() - 1; i >= 0; i--){
		Add(p_xpGameObjectMan->GetVector()[i]);
	}
}

void GameObjectMan::Clear(){
	for (int i = 0; i < m_xpaGobjs.size(); i++){
		if (m_xpaGobjs[i] != NULL){
			m_xpaGobjs[i] = NULL;
		}
	}
	m_xpaGobjs.clear();
}