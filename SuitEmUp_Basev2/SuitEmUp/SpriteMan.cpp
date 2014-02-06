//SpriteMan.cpp//

#include "stdafx.h"

#include "SpriteMan.h"

#include "Sprite.h"

#include <map>
#include <string>

#include <fstream>
#include <iostream>
#include <sstream>

//#include "AnimatedSprite.h"

SpriteMan::SpriteMan(){
	
}

SpriteMan::~SpriteMan(){

}

bool SpriteMan::Init(const std::string &p_srkDir){
	//IMG_Init(IMG_INIT_PNG);
	m_sDir = p_srkDir;

	return true;
}

void SpriteMan::Cleanup(){
	/*std::map<std::string, Pair>::iterator it = m_xaSprites.begin();
	while (it != m_xaSprites.end()){
		/*SDL_FreeSurface(it->second.m_SurpAlpha);
		SDL_DestroyTexture(it->second.m_TexpAlpha);
		it++;
	}
	m_xaSprites.clear();*/
}

Sprite* SpriteMan::Load(const std::string p_sFname, sf::IntRect p_xRect){
	std::map<std::string, sf::Texture>::iterator it = m_xaSprites.find(p_sFname);

	if (it == m_xaSprites.end()){
		sf::Texture l_xTex;

		if (p_xRect == sf::IntRect(0, 0, 0, 0)){
			if (!l_xTex.loadFromFile(m_sDir + p_sFname)){
				return NULL;
			}
		}
		else {
			if (!l_xTex.loadFromFile(m_sDir + p_sFname, p_xRect)){
				return NULL;
			}
		}

		Sprite *l_xpSprite = new Sprite(l_xTex);

		m_xaSprites.insert(std::pair<std::string, sf::Texture>(p_sFname, l_xTex));

		return l_xpSprite;
	}
	return NULL;
}

/*AnimatedSprite* SpriteMan::Load(const std::string &p_srkFname){
	std::ifstream stream;
	stream.open(p_srkFname.c_str());
	if (!stream.is_open()) {
		return nullptr;
	}

	std::string row;
	stream >> row;
	std::map<std::string, Pair>::iterator it = m_Sprites.find(row);
	if (it == m_Sprites.end()) {
		if (!Loadimg(row)){
			stream.close();
			return nullptr;
		}
		it = m_Sprites.find(row);
	}

	SDL_Surface *surface = it->second.m_SurpAlpha;
	SDL_Texture *texture = it->second.m_TexpAlpha;
	AnimatedSprite *sprite = new AnimatedSprite(surface, texture, 0, 0, 0, 0);


	while (!stream.eof()) {
		std::getline(stream, row);
		if (row.length() == 0) {
			continue;
		}
		std::stringstream ss(row);

		AnimatedSprite::Frame frame;
		ss >> frame.duration;
		ss >> frame.x;
		ss >> frame.y;
		ss >> frame.w;
		ss >> frame.h;
		sprite->AddFrame(frame);
		//std::cout << " " << frame.duration << " " << frame.x << " " << frame.y << " " << frame.w << " " << frame.h << " " << std::endl;
	}
	stream.close();

	return sprite;
}*/

/*Sprite *SpriteMan::LoadText(const char *p_ipkText, const int p_ikSize, const int p_ikRch, const int p_ikGch, const int p_ikBch){
	TTF_Font *l_xpFont = TTF_OpenFont("FreeSerifBold.ttf", p_ikSize); // Local_TypedefPointerFont

	SDL_Color l_cCol0 = { p_ikRch, p_ikGch, p_ikBch };
	SDL_Color l_cCol1 = { 0, 0, 0 };

	SDL_Surface *l_cpTextsur = TTF_RenderText_Solid(l_xpFont, p_ipkText, l_cCol0); // Local_ClassPointerTextsur
	if (l_cpTextsur == NULL){
		return nullptr;
	}

	SDL_Texture *l_cpTexttex = SDL_CreateTextureFromSurface(m_Drawman->m_renderer, l_cpTextsur); // Local_ClassPointerTexttex
	if (l_cpTexttex == NULL){
		return nullptr;
	}

	//SDL_BlitSurface(l_cpTextsur, NULL, );

	//Pair m_pair = { l_cpTextsur, l_cpTexttex };

	return new Text(l_cpTextsur, l_cpTexttex);
}*/

bool SpriteMan::Loadimg(const std::string &p_srkFname){
	std::string path = m_sDir + p_srkFname;
//	SDL_Surface* surface = IMG_Load(path.c_str());
	/*if (surface == nullptr) {
		return false;
	};*/

	/*SDL_Texture* texture = SDL_CreateTextureFromSurface(
		m_Drawman->m_renderer,
		surface);*/

	//Pair pair = { surface, texture };
	//m_xaSprites.insert(std::pair<std::string, Pair>(p_srkFname, pair));

	return true;
}