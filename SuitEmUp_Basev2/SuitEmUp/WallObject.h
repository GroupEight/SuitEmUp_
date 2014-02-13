//WallObject.h//

#include "GameObject.h"

class WallObject : public GameObject {
public:
	WallObject();
	//WallObject(const TextureHolder& textures, b2World *bWorld);
	~WallObject();

	void setCameraPos(sf::Vector2f pos);
	sf::Vector2f getControlVertexPos(int index);

protected:
	//virtual void UpdateCurrent(sf::Time p_xDtime);
private:
	sf::VertexArray	controlVertices;
};