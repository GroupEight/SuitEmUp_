//Main.cpp//

#include "Game.hpp"

int _tmain(int argc, _TCHAR* argv[]){
	srand(time(NULL));

	Game m_xGame;

	if (m_xGame.Init()){
		m_xGame.Run();
	}
	m_xGame.Cleanup();

	return 0;
}