//EnemyObject.h//

#include "GameObject.h"

class EnemyObject : public GameObject {
public:
	EnemyObject();

	void UpdateCurrent(sf::Time dt);

private:
	// Empty
};