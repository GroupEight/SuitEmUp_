//GfxMan.h//

#pragma once

#include <map>
#include <string>

#include "DrawMan.h"
#include "Sprite.h"

class AnimatedSprite;
class Background;
class Sprite;

class GfxMan {
public:
	GfxMan(); // Parameter_ClassPointerDman
	~GfxMan();

	bool Init(const std::string &p_sDir); // Parameter_StringReferenceKonstantDir

	void Cleanup();

	Sprite *LoadSprite(std::string p_sFname, sf::IntRect p_xRect = sf::IntRect(0, 0, 0, 0));

	Background *LoadBackground(std::string p_sFname, sf::Vector2f p_xSize);

	AnimatedSprite* LoadAnimatedSprite(const std::string &p_sFname);

private:
	bool Loadimg(const std::string &p_sFname);

private:
	DrawMan *m_xpDrawman;
	std::string m_sDir;

	std::map<std::string, sf::Texture*> m_xaSprites;
};