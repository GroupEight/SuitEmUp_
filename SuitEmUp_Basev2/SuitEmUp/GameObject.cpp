//GameObject.cpp//

#include "stdafx.h"

#include "GameObject.h"

#include <algorithm>
#include <cassert>
#include <sstream>
#include <typeinfo>

GameObject::GameObject(){

}

void GameObject::Update(sf::Time p_xDtime){
	UpdateCurrent(p_xDtime);
	UpdateParents(p_xDtime);
}

void GameObject::UpdateParents(sf::Time p_xDtime){
	/*for (const Ptr& child : m_xaChildren){
		child->Update(p_xDtime);
	}*/
	GameObject::UpdateCurrent(p_xDtime);
}

void GameObject::UpdateCurrent(sf::Time p_xDtime){
	SetPosition(m_xPos + m_xVel);
}

/*void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const {

}*/

sf::Vector2f GameObject::GetWorldPosition() const {
	return GetWorldTransform() * sf::Vector2f();
}

sf::Transform GameObject::GetWorldTransform() const {
	sf::Transform l_xTransform = sf::Transform::Identity;

	/*for (const GameObject* node = this; node != nullptr; node = node->m_xpParent)
		l_xTransform = node->getTransform() * l_xTransform;*/

	return l_xTransform;
}

const sf::Vector2f &GameObject::GetPosition(){
	return m_xPos;
}

void GameObject::SetPosition(const sf::Vector2f &p_xPos){
	m_xPos = p_xPos;
}

void GameObject::SetGraphics(Gfx *p_xpGfx){

}

bool GameObject::HasCollider() const {
	return false;
}

bool GameObject::OnScreen(sf::RenderWindow *p_xpWindow){
	/*if (GetPosition().x > p_xpWindow->getView().getCenter().x - 1024/2 && GetPosition().x < p_xpWindow->getView().getCenter().x + 1024/2){
		return true;
	}
	else if (GetPosition().y > p_xpWindow->getView().getCenter().y - 640/2 && GetPosition().y < p_xpWindow->getView().getCenter().y + 640/2){
		return true;
	}*/
	if (GetPosition().x > p_xpWindow->getView().getCenter().x - p_xpWindow->getView().getSize().x / 2 && GetPosition().x < p_xpWindow->getView().getCenter().x + p_xpWindow->getView().getSize().x / 2){
		return true;
	}
	else if (GetPosition().y > p_xpWindow->getView().getCenter().y -p_xpWindow->getView().getSize().y / 2 && GetPosition().y < p_xpWindow->getView().getCenter().y + p_xpWindow->getView().getSize().y / 2){
		return true;
	}
	return false;
}

void GameObject::setVelocity(sf::Vector2f p_xVel){
	m_xVel = p_xVel;
}

sf::Vector2f GameObject::getVelocity() const {
	return m_xVel;
}