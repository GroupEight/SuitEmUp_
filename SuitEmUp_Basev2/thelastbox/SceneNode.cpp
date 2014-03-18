//SceneNode.cpp//

#include "SceneNode.hpp"
#include "EnemyObject.hpp"
#include "PlayerBullet.hpp"


SceneNode::SceneNode(){
	m_bShowing = true;
}

SceneNode::~SceneNode(){

}

bool SceneNode::Update(sf::Time dt){
	return false;
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	// Apply transform of current node
	states.transform *= getTransform();

	// If showing, draw node and children with changed transform
	/*if(bShowing){
		drawCurrent(target, states);
		drawChildren(target, states);
	}*/
}

bool SceneNode::Overlap(sf::Vector2f position, float p_fRadius){

	if (sqrt(pow(position.x - getPosition().x, 2) + pow(position.y - getPosition().y, 2)) <= m_fRadius + p_fRadius){
		return true;
	}

	return false;
}

sf::Vector2f SceneNode::getWorldPosition() const {
	return getWorldTransform() * sf::Vector2f();
}

sf::Transform SceneNode::getWorldTransform() const {
	sf::Transform transform = sf::Transform::Identity;

	/*for (const SceneNode* node = this; node != nullptr; node = node->mParent)
		transform = node->getTransform() * transform;*/

	return transform;
}

bool SceneNode::Show(){
	m_bShowing = true;
	return m_bShowing;
}

bool SceneNode::Hide(){
	m_bShowing = false;
	return m_bShowing;
}

bool SceneNode::GetIsShowing(){
	return m_bShowing;
}

bool SceneNode::OnScreen(sf::RenderWindow *p_xpWindow){
	if (getPosition().x - p_xpWindow->getView().getCenter().x < p_xpWindow->getView().getSize().x / 2 && getPosition().x - p_xpWindow->getView().getCenter().x > -p_xpWindow->getView().getSize().x / 2){
		if (getPosition().y - p_xpWindow->getView().getCenter().y < p_xpWindow->getView().getSize().y / 2 && getPosition().y - p_xpWindow->getView().getCenter().y > -p_xpWindow->getView().getSize().y / 2){
			return true;
		}
	}
	return false;
}

float SceneNode::getRadius(){
	return m_fRadius;
}