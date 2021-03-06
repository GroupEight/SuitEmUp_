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

<<<<<<< HEAD
bool SceneNode::Overlap(sf::Vector2f position, float p_fRadius){
=======
/*void SceneNode::Overlap(PlayerBullet *p_xpPBullet, EnemyObject *p_xpEnemy) {
>>>>>>> 5301b7ce945568afbd97112a1b45c6472c1ec48b

	if (sqrt(pow(position.x - getPosition().x, 2) + pow(position.y - getPosition().y, 2)) <= m_fRadius + p_fRadius){
		return true;
	}

<<<<<<< HEAD
	return false;
}
=======
	if (sqrt(pow(m_xpEnemy->getPosition().x - m_xpPBullet->getPosition().x, 2) + pow(m_xpEnemy->getPosition().y - m_xpPBullet->getPosition().y, 2)) <= m_xpEnemy->getRadius() + m_xpPBullet->getRadius())
	{
}
}*/
>>>>>>> 5301b7ce945568afbd97112a1b45c6472c1ec48b

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
<<<<<<< HEAD
		if (getPosition().y - p_xpWindow->getView().getCenter().y < p_xpWindow->getView().getSize().y / 2 && getPosition().y - p_xpWindow->getView().getCenter().y > -p_xpWindow->getView().getSize().y / 2){
			return true;
		}
=======
		 if (getPosition().y - p_xpWindow->getView().getCenter().y < p_xpWindow->getView().getSize().y / 2 && getPosition().y - p_xpWindow->getView().getCenter().y > -p_xpWindow->getView().getSize().y / 2){
			 return true;
		 }
>>>>>>> 5301b7ce945568afbd97112a1b45c6472c1ec48b
	}

	return false;
}

float SceneNode::getRadius(){
	return m_fRadius;
}