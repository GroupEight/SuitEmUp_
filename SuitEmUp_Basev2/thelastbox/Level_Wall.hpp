//Level_Wall.h//

#pragma once

#include <vector>

#include "SceneNode.hpp"

class CollisionMan;
class NodeMan;
class SoundPlayer;
class TextureMan;

class Goal;
class Hidden_Wall;
class PlayerObject;

class Wall {
public:
 Wall(sf::Vector2f p_xPos, float p_fAng, float p_fHe);

 sf::Vector2f m_xPos;

 float m_fAng, m_fHe;
};

class Darkness {
public:
 Darkness(sf::Vector2f p_xPos, sf::Vector2f p_xSize, float p_fRot, PlayerObject *p_xpPlayer);

 sf::RectangleShape m_xRect;

 PlayerObject *m_xpPlayer;

 bool Update();
};

class Level : public SceneNode {
public:
 Level(std::string p_sDir, SoundPlayer *p_xpSPlayer, TextureMan *p_xpTextMan, CollisionMan *p_xpCMan, NodeMan *p_xpEnemyMan, NodeMan *p_xpEBulletMan, NodeMan *p_xpStarman, PlayerObject *p_xpPlayer);
 ~Level();

 virtual bool Update(sf::Time dt);

 virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

 bool LoadLevel(std::string p_sFile);
 void ClearLevel();

 void placeWallVertices();
 void MakeWalls();

 void setCameraPos( sf::Vector2f pos );
 sf::Vector2f getControlVertexPos( int index );

private:
 //void createControlVertex(sf::Vector2f _pos, float _ang = 0.f, float _height = 0.f);

 b2Vec2 *vs;

 b2Body *m_xpLevelBody;

 std::vector<Wall*> m_xaWalls;
 std::vector<Hidden_Wall*> m_xaHWalls;
 std::vector<Darkness*> m_xaDarkness;

 Goal *m_xpGoal;

 CollisionMan *m_xpCMan;
 TextureMan *m_xpTexMan;

 NodeMan *m_xpEnemyMan;
 NodeMan *m_xpStarman;
 NodeMan *m_xpEBulletMan;

 PlayerObject *m_xpPlayer;

 int v;

 sf::Vector2f cPos;
 float mParallax;

 sf::VertexArray m_xWalls,
  m_xRoof,
  m_xCVertices,
  m_xCVertexSpec;

 sf::Texture *m_xpTex;

 std::string m_sDir;

 SoundPlayer *m_xpSPlayer;
};