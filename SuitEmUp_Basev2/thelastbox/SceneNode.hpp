//SceneNode.h//

#pragma once

class SceneNode : public sf::Transformable, public sf::Drawable {
public:
	SceneNode();
	~SceneNode();
		
	virtual void Update(sf::Time dt);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

	virtual void Overlap();

	bool Show();
	bool Hide();
	bool GetIsShowing();

	sf::Vector2f getWorldPosition() const;
	sf::Transform getWorldTransform() const;

	bool OnScreen(sf::RenderWindow *p_xpWindow);

protected:
	sf::Vector2f m_xPos;

	sf::Vector2f m_xVel;

	bool m_bShowing;
};