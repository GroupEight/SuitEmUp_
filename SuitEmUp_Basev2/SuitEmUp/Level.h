//Level.h//

class Level {
public:
	Level();
	~Level();

	bool Load();

private:
	b2Vec2 m_xGravity;
	b2World m_xLevel;
};