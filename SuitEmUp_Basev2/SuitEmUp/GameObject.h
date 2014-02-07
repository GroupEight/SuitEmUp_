//GameObject.h//

#pragma once

#include <string>
#include <vector>
#include <memory>

class Sprite;

class GameObject : public sf::Transformable, public sf::Drawable {
public:
	typedef std::unique_ptr<GameObject> Ptr;

public:
	GameObject();

	/*void AttachChild(Ptr p_xChild);
	Ptr DetachChild(const GameObject &p_xObj);*/

	void Update(sf::Time p_xDtime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

	sf::Vector2f GetWorldPosition() const;
	sf::Transform GetWorldTransform() const;

	const sf::Vector2f &GetPosition();
	void SetPosition(const sf::Vector2f &p_xPos);

	void setVelocity(sf::Vector2f p_xVel);
	sf::Vector2f getVelocity() const;

	bool HasSprite()const;
	virtual Sprite *GetSprite();
	void SetSprite(Sprite *p_xpSprite);

	bool HasCollider() const;
	//Collider* GetCollider();

	bool OnScreen(sf::Vector2f p_xV0, sf::Vector2f p_xV1 = sf::Vector2f(0, 0));

protected:
	virtual void UpdateCurrent(sf::Time p_xDtime);
	virtual void UpdateParents(sf::Time p_xDtime);

	/*virtual void DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void DrawParents(sf::RenderTarget& target, sf::RenderStates states) const;*/

protected:
	sf::Vector2f m_xPos;
	sf::Vector2f m_xVel;

	Sprite *m_xpSprite;

	/*std::vector<Ptr> m_xaChildren;
	GameObject* m_xpParent;*/
};