//EnemyObject.h//

#include "stdafx.h"

#include "EnemyObject.h"

EnemyObject::EnemyObject(){
	
}

EnemyObject::EnemyObject(sf::Vector2f p_xStartPos, GameObject *p_xpTarget){
	m_xStartPos = p_xStartPos;

	m_xpTarget = p_xpTarget;
}

void EnemyObject::UpdateCurrent(sf::Time dt){

}