//Hidden_Wall.h//

#pragma once

#include "SceneNode.hpp"

class PlayerObject;

class CollisionMan;
class TextureMan;

class Hidden_Wall : public SceneNode {
public:
	enum State {
		closed,
		opening,
		open,
		closing,
	};

public:
	Hidden_Wall(sf::Vector2f p_xPos, float p_fRot, float p_fWallDist, PlayerObject *p_xpPlayer, TextureMan *p_xpTextMan, CollisionMan *p_xpCMan);
<<<<<<< HEAD

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual bool Update(sf::Time dt);

=======

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void Update(sf::Time dt);

>>>>>>> 5301b7ce945568afbd97112a1b45c6472c1ec48b
	void SetCameraPos( sf::Vector2f pos );
	void SetState( Hidden_Wall::State state );
	Hidden_Wall::State getState();

private:
	void PlaceWallVertices();

	int v;

	//Collision
	CollisionMan *m_xpCMan;
	b2Body *mBBody;

	sf::Vector2f cPos,
		m_xPosA,
		m_xPosB;

	float mParallax,
		mWallWidth,
		mWallSlide,
		m_fWallDist;

	Hidden_Wall::State mState;

	PlayerObject *m_xpPlayer;

	sf::VertexArray mWalls,
		mRope1,
		mRope2;

	sf::Texture *m_xpTex, 
		*m_xpRTex;
};