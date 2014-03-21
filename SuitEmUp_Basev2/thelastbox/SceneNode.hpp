//SceneNode.h//

#pragma once

class PlayerBullet;
class EnemyObject;

class SceneNode : public sf::Transformable, public sf::Drawable {
public:
	SceneNode();
	~SceneNode();
		
	virtual bool Update(sf::Time dt);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

	virtual bool Overlap(sf::Vector2f position, float p_fRadius);

	bool Show();
	bool Hide();
	bool GetIsShowing();

	sf::Vector2f getWorldPosition() const;
	sf::Transform getWorldTransform() const;

	bool OnScreen(sf::RenderWindow *p_xpWindow);

	virtual float getRadius();

	static float FScreenMode;

protected:
	sf::Vector2f m_xPos;

	sf::Vector2f m_xVel;

	bool m_bShowing;

	float m_fRadius;

	PlayerBullet *m_xpPBullet;

	EnemyObject *m_xpEnemy;
};