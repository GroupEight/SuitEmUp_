//PlayerObject.h//

#include "GameObject.h"

class Sprite;

class PlayerObject : public GameObject {
public:
	PlayerObject();

private:
	void UpdateCurrent(sf::Time p_xDtime);

	void DrawCurrent(sf::RenderWindow p_xWindow) const;

private:
	Sprite *m_xpSprite;
};