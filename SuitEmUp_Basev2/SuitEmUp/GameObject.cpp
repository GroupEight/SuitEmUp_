//GameObject.cpp//

#include "stdafx.h"

#include "GameObject.h"

#include <algorithm>
#include <cassert>
#include <sstream>
#include <typeinfo>

GameObject::GameObject()
/*: m_xaChildren()
, m_xpParent(nullptr)*/{

}

/*void GameObject::AttachChild(Ptr p_xChild){
	p_xChild->m_xpParent = this;
	m_xaChildren.push_back(std::move(p_xChild));
}

GameObject::Ptr GameObject::DetachChild(const GameObject &p_xObj){
	auto found = std::find_if(m_xaChildren.begin(), m_xaChildren.end(), [&](Ptr& p) { return p.get() == &p_xObj; });
	assert(found != m_xaChildren.end());

	Ptr result = std::move(*found);
	result->m_xpParent = nullptr;
	m_xaChildren.erase(found);
	return result;
}*/

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
	std::cout << m_xPos.x << " :" << m_xPos.y << std::endl;

	//move(m_xVel* p_xDtime.asSeconds());

	SetPosition(m_xPos + m_xVel);
}

//void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	/*p_xStates.transform *= getTransform();

	DrawCurrent(p_xTarget, p_xStates);
	DrawParents(p_xTarget, p_xStates);*/
//}

/*void GameObject::DrawCurrent(sf::RenderTarget& p_xTarget, sf::RenderStates p_xStates) const {
	// Do nothing by default
}

void GameObject::DrawParents(sf::RenderTarget& p_xTarget, sf::RenderStates p_xStates) const {
	/*for (const Ptr& l_xChild : m_xaChildren){
		l_xChild->draw(p_xTarget, p_xStates);
	}
	GameObject::DrawCurrent(p_xTarget, p_xStates);
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

bool GameObject::HasSprite() const {
	return (m_xpSprite != NULL);
}

Sprite* GameObject::GetSprite(){
	return m_xpSprite;
}

bool GameObject::HasCollider() const {
	return false;
}

void GameObject::setVelocity(sf::Vector2f p_xVel){
	m_xVel = p_xVel;
}

sf::Vector2f GameObject::getVelocity() const {
	return m_xVel;
}