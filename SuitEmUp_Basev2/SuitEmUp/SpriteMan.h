//SpriteMan.h//

#pragma once

#include <map>
#include <string>

#include "DrawMan.h"
#include "Sprite.h"

class AnimatedSprite;
class Sprite;

class SpriteMan {
public:
	SpriteMan(); // Parameter_ClassPointerDman
	~SpriteMan();

	bool Init(const std::string &p_sDir); // Parameter_StringReferenceKonstantDir

	void Cleanup();

	Sprite* Load(const std::string p_sFname, // Parameter_StringReferenceKonstantFname
		sf::IntRect p_xRect = sf::IntRect(0, 0, 0, 0)); // Parameter_ClassSize

	Sprite* Load(const std::string &p_sFname); // Parameter_StringReferenceKonstantFname

	//AnimatedSprite* Load(const std::string &p_sFname);

private:
	bool Loadimg(const std::string &p_sFname);

private:
	DrawMan *m_xpDrawman;
	std::string m_sDir;

	std::map<std::string, sf::Texture> m_xaSprites;
	
	//sf::Sprite m_xSprite;
};