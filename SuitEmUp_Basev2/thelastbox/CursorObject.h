//CursorObject.h//

#include "SceneNode.hpp"

class TextureMan;

class CursorObject : public SceneNode {
public:
	CursorObject(TextureMan *p_xpTexMan, sf::RenderWindow *p_xpWindow);
	~CursorObject();

	bool Update(sf::Time p_xDtime);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::Sprite *m_xpSprite;

	sf::RenderWindow *m_xpWindow;
};