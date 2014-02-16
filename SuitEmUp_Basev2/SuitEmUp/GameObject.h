//GameObject.h//

#pragma once

#include <string>
#include <vector>
#include <memory>

class Gfx;

class GameObject : public sf::Transformable {
public:
	typedef std::unique_ptr<GameObject> Ptr;

public:
	GameObject();

	~GameObject() {};

	void Update(sf::Time p_xDtime);
	//virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::Vector2f GetWorldPosition() const;
	sf::Transform GetWorldTransform() const;

	const sf::Vector2f &GetPosition();
	void SetPosition(const sf::Vector2f &p_xPos);

	void setVelocity(sf::Vector2f p_xVel);
	sf::Vector2f getVelocity() const;

	virtual bool HasGraphics() const = 0;
	virtual Gfx *GetGraphics() = 0;
	virtual void SetGraphics(Gfx *p_xpGfx);

	bool HasCollider() const;
	//Collider* GetCollider();

	bool OnScreen(sf::RenderWindow *p_xpWindow);

protected:
	virtual void UpdateCurrent(sf::Time p_xDtime);
	virtual void UpdateParents(sf::Time p_xDtime);

protected:
	sf::Vector2f m_xPos;
	sf::Vector2f m_xVel;
};