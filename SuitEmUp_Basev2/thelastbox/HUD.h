//HUD.h//

#include "SceneNode.hpp"

class TextureMan;

class HUD : SceneNode {
public:
	HUD(TextureMan *p_xpTex, sf::RenderWindow p_xpWindow);
	~HUD();

	bool Update();

	void draw(sf::RenderTarget& target, sf::RenderStates states);

private:
	int m_iStars;

	float *m_xfSuit;

	TextureMan *m_xpTexMan;

	sf::Sprite m_xHealthBar,
		m_xStarSymbol,
		m_xSuits[10];

	sf::RenderWindow m_xpWindow;
};