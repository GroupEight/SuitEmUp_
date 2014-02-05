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

	//GameObject *GetObject(const std::string &p_srkType, int p = 0);

private:
	std::vector<GameObject*> m_xpaGobjs; // Member_ClassPointerArrayGobjs
};