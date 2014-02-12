//GameObjectMan.h//

#include "GameObject.h"

#include <vector>

class DrawMan;

class GameObjectMan {
public:
	GameObjectMan();
	~GameObjectMan();

	void Add(GameObject *p_xpGobj); // Parameter_ClassPointerGobj
	std::vector<GameObject*> GetVector();

	void UpdateAll(sf::Time dt);
	void DrawAll(DrawMan *p_xpDrawMan);

	void UpdateOnScreen(sf::RenderWindow *p_xpWindow, sf::Time p_xDtime);
	void DrawOnScreen(sf::RenderWindow *p_xpWindow, DrawMan *p_xpDrawMan);

	void DeleteOffScreen(sf::RenderWindow *p_xpWindow);

	void Cleanup();

	//GameObject *GetObject(const std::string &p_srkType, int p = 0);

private:
	std::vector<GameObject*> m_xpaGobjs; // Member_ClassPointerArrayGobjs
};