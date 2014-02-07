//Core.cpp//

#include "stdafx.h"

#include "Core.h"

#include "DrawMan.h"
#include "Stateman.h"
#include "SpriteMan.h"

#include "Gamestate.h"
#include "Menustate.h"

#include <string>

#include <fstream>
#include <iostream>
#include <sstream>

Core::Core(){
	m_xpWindow = NULL;

	m_iWi = 0;
	m_iHe = 0;
}

Core::~Core(){
	
}

bool Core::Init(){
	m_iWi = 1024;
	m_iHe = 640;

	m_xDtime = sf::Time::Zero;
	m_xFps = sf::seconds(1.f / 60.f);

	std::string l_sData = "../data/config.txt",
		l_sSpritepath = "../data/sprites/",
		l_sSoundpath = "../data/sound/",
		l_sHiscorepath = "../data/hiscore.txt",
		l_sStartstate = "Loadstate";

	m_xpWindow = new sf::RenderWindow(sf::VideoMode(m_iWi, m_iHe), "SuitEmUp");
	if (m_xpWindow == NULL){
		return false;
	}

	m_xpDrawMan = new DrawMan;
	if (m_xpDrawMan == NULL){
		return false;
	}
	if (!m_xpDrawMan->Init(m_xpWindow)){
		return false;
	}

	m_xpStateman = new Stateman;
	if (m_xpStateman == NULL){
		return false;
	}

	m_xpSpriteMan = new SpriteMan;
	if (m_xpSpriteMan == NULL){
		return false;
	}
	if (!m_xpSpriteMan->Init("../data/graphics/")){
		return false;
	}

	m_xpGamestate = new Gamestate(m_xpDrawMan, m_xpSpriteMan);
	if (m_xpGamestate == NULL){
		return false;
	}

	m_xpMenustate = new Menustate;
	if (m_xpMenustate == NULL){
		return false;
	}

	m_xpStateman->Add(m_xpGamestate);
	m_xpStateman->Add(m_xpMenustate);

	m_xpStateman->Setstate("Gamestate");

	return true;
}

void Core::Run(){
	m_xpClock = new sf::Clock;

	while (m_xpStateman->IsRunning()){
		UpdEvents();

		if (UpdateDeltaTime()){
			m_xpWindow->clear(sf::Color::Blue);
			
			m_xpStateman->Update(m_xDtime);
			m_xpStateman->Draw();

			m_xpWindow->display();

			m_xDtime = sf::Time::Zero;
		}
	}
}

bool Core::UpdateDeltaTime(){
	m_xDtime += m_xpClock->restart();

	//std::cout << (float)m_xDtime.asMilliseconds() << std::endl;

	if (m_xDtime >= m_xFps){
		//m_xDtime = m_xFps;

		return true;
	}
	return false;
}

void Core::UpdEvents(){
	sf::Event event;
	while (m_xpWindow->pollEvent(event)){
		switch (event.type){
			case sf::Event::Closed:
				m_xpWindow->close();
				m_xpStateman->Quit();
				break;
		}
	}
}

void Core::Cleanup(){
	if (m_xpWindow != NULL){
		delete m_xpWindow;
		m_xpWindow = NULL;
	}
	/*if (m_xpGamestate != NULL){
		delete m_xpGamestate;
		m_xpGamestate = NULL;
	}
	if (m_xpMenustate != NULL){
		delete m_xpMenustate;
		m_xpMenustate = NULL;
	}*/
	if (m_xpDrawMan != NULL){
		delete m_xpDrawMan;
		m_xpDrawMan = NULL;
	}
	if (m_xpStateman != NULL){
		delete m_xpStateman;
		m_xpStateman = NULL;
	}
	if (m_xpSpriteMan != NULL){
		delete m_xpSpriteMan;
		m_xpSpriteMan = NULL;
	}
	if (m_xpClock != NULL){
		delete m_xpClock;
		m_xpStateman = NULL;
	}
}