//MusicPlayer.h//

#pragma once

#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Audio/Music.hpp>

#include <vector>

struct MPair {
	std::string Param0;
	std::string Param1;
};

class MusicPlayer : private sf::NonCopyable {
public:
	MusicPlayer(std::string p_sDir);

	void Play(std::string p_sCname);
	void Stop();

	void SetPaused(bool p_bPaused);
	void SetVolume(float p_fVolume);

	void Load(std::string p_sFname, std::string p_sCname);

private:
	sf::SoundBuffer *m_xpSoundBuffers;

	std::string m_sDir;

	std::vector<MPair*> m_xpaMusic;
	sf::Music *m_xpCurrent;

	float mVolume;
};