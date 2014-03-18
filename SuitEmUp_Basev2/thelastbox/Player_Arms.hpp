//Player_Arms.h//

#pragma once

#include "SceneNode.hpp"

class TextureMan;

class PlayerObject;

class Player_Arms : public SceneNode {
public:
	Player_Arms(TextureMan *p_xpTextMan, int p_iArmDir, PlayerObject *p_xpPlayer);

	void setArmsPosition(sf::Vector2i armLength, float p_fRot);

	bool Punch();

	bool m_bPunching;
	bool m_bApex;

	sf::Sprite *m_xpGlove;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	int m_iArmDir;

	float m_fPunchLength,
		m_fPunchInterp;

	float GetPt( int n1 , int n2 , float perc );

<<<<<<< HEAD
=======
	bool m_bPunching;

	PlayerObject *m_xpPlayer;

>>>>>>> 5301b7ce945568afbd97112a1b45c6472c1ec48b
	sf::VertexArray m_xControlVertices,
		m_xArms;

	sf::Texture *m_xpGloveTex;
	
};