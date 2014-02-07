//GameObjectMan.h//

#include "GameObject.h"

#include <vector>

class GameObjectMan {
public:
	GameObjectMan();
	~GameObjectMan();

	void Add(GameObject *p_xpGobj); // Parameter_ClassPointerGobj
	std::vector<GameObject*> GetVector();

	void UpdateAll(sf::Time dt);

	void OnScreen(sf::Vector2f p_xV0, sf::Vector2f p_xV1 = sf::Vector2f(0, 0));

	void Cleanup();

	//GameObject *GetObject(const std::string &p_srkType, int p = 0);

private:
	std::vector<GameObject*> m_xpaGobjs; // Member_ClassPointerArrayGobjs
};