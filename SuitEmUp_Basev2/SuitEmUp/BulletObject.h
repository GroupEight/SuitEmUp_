//BulletObject.h//

#include "GameObject.h"

class Sprite;

class BulletObject : public GameObject {
public:
	BulletObject(sf::Vector2f p_xPos, sf::Vector2f p_xVel, Sprite *p_xpSprite);

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};