//Gamestate.cpp//

/*#include "stdafx.h"

#include "Menustate.h"

#include "PlayerObject.h"

Menustate::Menustate(){
	
}

Menustate::~Menustate(){

}

bool Menustate::Enter(){
	return true;
}

void Menustate::Exit(){

}

bool Menustate::Update(sf::Time p_xDtime){
	std::cout << "Menustate\n";

	return false;
}

void Menustate::Draw(){
	// Add the background sprite to the scene
	/*std::unique_ptr<Ground> backgroundSprite(new Ground(mTextures, mWindow.getSize()));
	mGround = backgroundSprite.get();
	mSceneLayers[Background]->attachChild(std::move(backgroundSprite));

	//Add test bump
	std::unique_ptr<Ground_Bump> groundBump(new Ground_Bump(mTextures, 1, 250.f));
	mGroundBump_Test = groundBump.get();
	mGroundBump_Test->setPosition(mSpawnPosition + sf::Vector2f(0, 200.f));
	mGroundBump_Test->setVelocity(40.f, 30.f);
	mSceneLayers[Main]->attachChild(std::move(groundBump));

	//Add Player bump
	std::unique_ptr<Ground_Bump> groundBumpP(new Ground_Bump(mTextures, 0, 100.f));
	mGroundBump_Player = groundBumpP.get();
	mGroundBump_Player->setPosition(mSpawnPosition);
	mSceneLayers[Main]->attachChild(std::move(groundBumpP));

	//Add player
	std::unique_ptr<Player> _player(new Player(mTextures));
	mPlayer = _player.get();
	mPlayer->setPosition(mSpawnPosition);
	mSceneLayers[Main]->attachChild(std::move(_player));
}

std::string Menustate::Next(){
	return "Gamestate";
}

bool Menustate::IsType(const std::string &p_Type){
	return p_Type.compare("Menustate") == 0;
}