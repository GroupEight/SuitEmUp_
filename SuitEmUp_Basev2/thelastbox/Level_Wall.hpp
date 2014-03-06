#pragma once

#include "SceneNode.hpp"

class TextureMan;

class Level_Wall : public SceneNode {
public:
	Level_Wall(TextureMan *p_xpTextMan, b2World *p_xpWorld);

	virtual void Update(sf::Time dt);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::VertexArray controlVertices;

	void setCameraPos( sf::Vector2f pos );
	sf::Vector2f getControlVertexPos( int index );

private:
	bool placeControlVertices();
	void placeWallVertices();
	void createControlVertex(sf::Vector2f _pos, float _ang = 0.f, float _height = 0.f);

	b2World *mBWorld;
	b2Vec2 vs[47];

	int v;

	sf::Vector2f cPos;
	float mParallax;

	sf::VertexArray mWalls,
		mRoof,
		controlVertexSpec;

	sf::Texture *m_xpTex;

	b2World *m_xpWorld;
};