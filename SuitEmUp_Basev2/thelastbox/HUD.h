//HUD.h//

#include "SceneNode.hpp"

<<<<<<< HEAD
class PlayerObject;

class FontMan;
class TextureMan;

class HUD {
public:
	HUD(TextureMan *p_xpTex, FontMan *p_xpFman, sf::RenderWindow *p_xpWindow, PlayerObject *p_xpPlayer);
	~HUD();
	
	bool Update();
	
=======
class TextureMan;

class HUD : SceneNode {
public:
	HUD(TextureMan *p_xpTex, sf::RenderWindow p_xpWindow);
	~HUD();

	bool Update();

>>>>>>> 5301b7ce945568afbd97112a1b45c6472c1ec48b
	void draw(sf::RenderTarget& target, sf::RenderStates states);

private:
	int m_iStars;
<<<<<<< HEAD
	
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
=======

	float *m_xfSuit;

	TextureMan *m_xpTexMan;

	sf::Sprite m_xHealthBar,
		m_xStarSymbol,
		m_xSuits[10];

	sf::RenderWindow m_xpWindow;
>>>>>>> 5301b7ce945568afbd97112a1b45c6472c1ec48b
};