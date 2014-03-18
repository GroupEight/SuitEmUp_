//HUD.h//

#include "SceneNode.hpp"

class PlayerObject;

class FontMan;
class TextureMan;

class HUD {
public:
	HUD(TextureMan *p_xpTex, FontMan *p_xpFman, sf::RenderWindow *p_xpWindow, PlayerObject *p_xpPlayer);
	~HUD();
	
	bool Update();
	
	void draw(sf::RenderTarget& target, sf::RenderStates states);

private:
	int m_iStars;
	
	float m_fBarSize;

	PlayerObject *m_xpPlayer;
	
	TextureMan *m_xpTexMan;
	
	sf::Sprite *m_xpHealthBar,
		*m_xpHpBarHit,
		*m_xpHpOverlay,
		*m_xpStarSymbol,
		*m_xpSuits;

	sf::Text *m_xpTxt;
	
	sf::RenderWindow *m_xpWindow;
};