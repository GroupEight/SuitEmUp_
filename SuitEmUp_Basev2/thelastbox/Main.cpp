//Main.cpp//

#include "Game.hpp"
#include "stdafx.h"

int main(){
	srand(time(NULL));

	Game m_xGame;

	if (m_xGame.Init()){
		m_xGame.Run();
	}
	m_xGame.Cleanup();
}