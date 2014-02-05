//PlayerObject.h//

#include "GameObject.h"

class Sprite;

class PlayerObject : public GameObject {
public:
	PlayerObject();

private:
	void UpdateCurrent(sf::Time p_xDtime);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	Sprite *m_xpSprite;
};