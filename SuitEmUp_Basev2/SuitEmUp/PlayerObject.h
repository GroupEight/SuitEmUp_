//PlayerObject.h//

#include "GameObject.h"

class Sprite;

class PlayerObject : public GameObject {
public:
	PlayerObject(Sprite *p_xpSprite);

	Sprite* GetSprite();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	void UpdateCurrent(sf::Time p_xDtime);

private:
	Sprite *m_xpSprite;
};