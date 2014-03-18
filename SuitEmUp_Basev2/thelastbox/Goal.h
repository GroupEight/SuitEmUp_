//Goal.h//

#include "SceneNode.hpp"

class PlayerObject;

class TextureMan;

class Goal : SceneNode {
public:
	Goal(sf::Vector2f p_xPos, float p_fRadius, PlayerObject *p_xpPlayer, TextureMan *p_xpTexMan);
	~Goal();

	bool Update(sf::Time dt);

	void draw(sf::RenderTarget& target, sf::RenderStates states ) const;

private:
	PlayerObject *m_xpPlayer;

	sf::Sprite *m_xpSprite;
};