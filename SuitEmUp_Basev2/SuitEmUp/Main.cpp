//Main.cpp//

#include "stdafx.h"

#include "Core.h"

int _tmain(int argc, _TCHAR* argv[]){
	Core Game;
	const unsigned int t = 5;

	for (int i = 0; i < t; i++){
		if (Game.Init()){
			Game.Run();
			Game.Cleanup();
			break;
		}
		else {
			std::cout << "Initializing error : " << t - 1 << " tries left.\n";
			Game.Cleanup();
		}
	}
	
	return 0;
}