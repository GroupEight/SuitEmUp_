//GameObjectMan.h//

#include <vector>

class GameObject;

class GameObjectMan {
public:
	GameObjectMan();
	~GameObjectMan();

	std::vector<GameObject*> GetVector();

	void Add(GameObject *p_xpGobj);

	void UpdateAll(sf::Time p_xDtime);
	void UpdateOnScreen(sf::RenderWindow *p_xpWindow, sf::Time p_xDtime);
	
	void DrawAll(sf::RenderTarget *p_xpTarget);
	void DrawOnScreen(sf::RenderWindow *p_xpWindow);

	void DeleteAll();
	void DeleteOffScreen(sf::RenderWindow *p_xpWindow);

	void CopyFrom(GameObjectMan *p_xpGameObjectMan);

	void Clear();

private:
	std::vector<GameObject*> m_xpaGobjs;
};