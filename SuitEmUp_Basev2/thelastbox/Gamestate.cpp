//Gamestate.cpp//

#include "Gamestate.hpp"

#include "CollisionMan.h"
#include "MusicPlayer.hpp"
#include "NodeMan.h"
#include "SoundPlayer.hpp"

#include "PlayerBullet.hpp"
#include "CursorObject.h"
#include "EnemyObject.hpp"
#include "FontMan.h"
#include "Morker.h"
#include "Ground.hpp"
#include "HUD.h"
#include "Level_Wall.hpp"
#include "Menu_Button.hpp"
#include "Player_Arms.hpp"
#include "PlayerObject.h"
#include "Prompt.hpp"
#include "Star.h"

Gamestate::Gamestate(sf::RenderWindow *p_xpWindow, SoundPlayer *p_xpSPlayer, CollisionMan *p_xpCollisionMan, TextureMan *p_xpTextMan, FontMan *p_xpFMan, NodeMan *p_xpPBulletMan, NodeMan *p_xpEBulletMan, NodeMan *p_xpStarMan, NodeMan *p_xpEnemyMan, PlayerObject *p_xpPlayer, CursorObject *p_xpCursor, Ground *p_xpGround){
	m_xpWindow = p_xpWindow;

	m_xpCollisionMan = p_xpCollisionMan;

	m_xpTextureMan = p_xpTextMan;

	m_xpFman = p_xpFMan;

	m_xpPBulletMan = p_xpPBulletMan;

	m_xpStarMan = p_xpStarMan;

	m_xpPlayer = p_xpPlayer;

	m_xpCursor = p_xpCursor;

	m_xpGround = p_xpGround;

	m_xpSPlayer = p_xpSPlayer;

	m_xpMPlayer = new MusicPlayer("../rec/Music/");

	m_xpMPlayer->Load("Bennie_Motens_KC_Jazz_Band-South_1924.ogg", "Main0");

	m_xpHUD = new HUD(m_xpTextureMan, p_xpFMan, m_xpWindow, m_xpPlayer);

	//m_xpPBulletMan = new NodeMan;
	m_xpEnemyMan = p_xpEnemyMan;
	m_xpEBulletMan = p_xpEBulletMan;

	m_xpLevel = new Level("../rec/Levels/", m_xpSPlayer, m_xpTextureMan, m_xpCollisionMan, m_xpEnemyMan, m_xpEBulletMan, m_xpStarMan, m_xpPlayer);

	//m_xpEnemyMan->Add(new EnemyObject(m_xpCollisionMan, m_xpTextureMan, 120.0f, 4.5f, sf::Vector2f(10, 10), m_xpPlayer));

	//m_xpEnemyMan->Add(new Morker(m_xpCollisionMan, m_xpTextureMan, 120.0f, 25.f, sf::Vector2f(10, 10), m_xpPlayer, m_xpEBulletMan, m_xpTex, m_xpPBulletMan, m_xpStarMan));

	//m_xpPlayer = new PlayerObject(m_xpGfxMan->LoadAnimatedSprite("Animations/Player_Anim_Idle.txt"), m_xpBulletMan, m_xpGfxMan);
	//m_xpGround = new BGObject(m_xpGfxMan->LoadBackground("Graphics/Ground.png", sf::Vector2f(m_xpWindow->getSize().x, m_xpWindow->getSize().y)), m_xpPlayer, m_xpWindow);
	//m_xpEnemyMan->Add(new WarriorObject(m_xpGfxMan->LoadSprite("Graphics/Warrior_01.png", sf::IntRect(0, 0, 0, 0)), sf::Vector2f(-40, -40), m_xpPlayer));

	m_xpWorldView = new sf::View(m_xpWindow->getDefaultView());
	m_xpWorldView->setCenter(0.0f, 0.0f);

	m_fMaxZoom = 2.7f;
	m_fStrtZoom = 1.5f;
	m_fMinZoom = 0.9f;

	m_fCurrZoom = m_fStrtZoom;

	m_xpWorldView->zoom(m_fCurrZoom);
}

bool Gamestate::Enter(){
	m_eState = Gamestate::SubStates::Play;
	m_xpPlayer->SetStars(0);
	m_xpPlayer->SetPosition(sf::Vector2f(0, 0));
	m_fEndTime = 1.2f;

	m_xpMPlayer->Play("Main0");

	return m_xpLevel->LoadLevel("Tst.txt");
}

void Gamestate::Exit(){
	m_xpLevel->ClearLevel();
}

bool Gamestate::Update(sf::Time p_xDtime){
	m_xpCursor->Update(p_xDtime);

	m_xpSPlayer->RemoveStoppedSounds();

	if (m_eState == Gamestate::SubStates::Play){
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
			//m_eState = Gamestate::SubStates::Pause;
			m_sNext = "Menustate";
			return false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
			m_sNext = "Gamestate";
			return false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)){
			//m_sNext = "Gamestate";
			//return false;
			//m_xpLevel->ClearLevel();
			//m_xpStarMan->Add( new Star( m_xpTextureMan, sf::Vector2f(0.f, 0.f), 0.f, m_xpPlayer ) );
		}

		//m_xpLevel->placeWallVertices();
		if (m_xpLevel->Update(p_xDtime)){
			EndText = new sf::Text(sf::String("You Win!"), *m_xpFman->Get("Standard"), 200);
			EndText->setColor(sf::Color::White);
			EndText->setPosition(m_xpWindow->getView().getCenter());
			m_sNext = "Menustate";
			m_eState = Gamestate::SubStates::End;
		}

		if (m_xpPlayer->Update(p_xDtime)){ // Update Player
			EndText = new sf::Text(sf::String("Too Bad,\nYou Lose..."), *m_xpFman->Get("Standard"), 200);
			EndText->setColor(sf::Color::White);
			EndText->setPosition(m_xpWindow->getView().getCenter());
			m_sNext = "Menustate";
			m_eState = Gamestate::SubStates::End;
		}

		m_xpGround->Update(p_xDtime);

		m_xpEnemyMan->DeleteOnTrue(p_xDtime); // Update all enemies

		m_xpPBulletMan->UpdateAll(p_xDtime); // Update all of the player bullets
		m_xpEBulletMan->UpdateAll(p_xDtime); // Update and delete all enemy bullets

		m_xpStarMan->DeleteOnTrue(p_xDtime); // Update all of the stars

		m_xpCollisionMan->Update(p_xDtime); // Have CollisionMan update the world
	}
	else if (m_eState == Gamestate::SubStates::Pause){
		if (m_xpQuitPrompt->m_eState == Prompt::State::btn1){ //If "yes" button has been pressed{
			m_xpQuitPrompt->m_eState = Prompt::State::none; //Reset the state
		}
		else if(m_xpQuitPrompt->m_eState == Prompt::State::btn2){ //If "cancel" button has been presse{
			m_xpQuitPrompt->Hide();
			m_xpResumeBtn->Show();
			m_xpQuitBtn->Show();
			m_xpBG->setColor(sf::Color::White);
			m_xpQuitPrompt->m_eState = Prompt::State::none; //Reset the state
		}
	}
	else if (m_eState == Gamestate::SubStates::Quit){
		m_sNext = "Menustate";
		return false;
	}
	else if (m_eState == Gamestate::SubStates::End){
		if (m_fEndTime < 0.f){
			return false;
		}
		else {
			m_fEndTime-= (float)p_xDtime.asSeconds();
		}
	}
	
	m_xpWorldView->setCenter( m_xpPlayer->getPosition() ); // Center camera on player
	m_xpWindow->setView(*m_xpWorldView); // Set the worldview

	m_xpHUD->Update();

	m_xpPBulletMan->DeleteOffScreen(m_xpWindow);
	m_xpEBulletMan->DeleteOffScreen(m_xpWindow);

	return true;
}

void Gamestate::Draw(){
	m_xpGround->draw(*m_xpWindow, sf::RenderStates::Default); // Draw the ground
	m_xpPlayer->draw(*m_xpWindow, sf::RenderStates::Default); // Draw the player
	m_xpPBulletMan->DrawAll(m_xpWindow); // Draw the bullets
	m_xpEnemyMan->DrawAll(m_xpWindow); // Draw the enemies
	m_xpEBulletMan->DrawAll(m_xpWindow); // Draw the enemy bullets
	m_xpStarMan->DrawAll(m_xpWindow); // Draw the stars
	m_xpLevel->draw(*m_xpWindow, sf::RenderStates::Default); // Draw the Level

	m_xpHUD->draw(*m_xpWindow, sf::RenderStates::Default);

	if (m_eState == Gamestate::SubStates::End){
		m_xpWindow->draw(*EndText);
	}

	m_xpCursor->draw(*m_xpWindow, sf::RenderStates::Default);
}

void Gamestate::LoadResources(){

	//FONTS
	//m_xpFonts.load(Fonts::LITTLELO, "../rec/Fonts/LITTLELO.TTF");
}

std::string Gamestate::Next(){
	return m_sNext;
}

bool Gamestate::IsType(const std::string &p_sType){
	return p_sType.compare("Gamestate") == 0;
}

void Gamestate::ShowText(std::string p_sText){
	
}