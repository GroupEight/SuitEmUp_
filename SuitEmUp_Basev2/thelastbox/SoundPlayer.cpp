//SoundPlayer.cpp//

#include "SoundPlayer.hpp"

#include <cmath>

/*namespace
{
	// Sound coordinate system, point of view of a player in front of the screen:
	// X = left; Y = up; Z = back (out of the screen)
	const float ListenerZ = 300.f;
	const float Attenuation = 8.f;
	const float MinDistance2D = 200.f;
	const float MinDistance3D = std::sqrt(MinDistance2D*MinDistance2D + ListenerZ*ListenerZ);
}*/

/*SoundPlayer::SoundPlayer()
: mSoundBuffers()
, mSounds(){
	mSoundBuffers.load(SFX::Cymbal_Hit_01,	"../rec/Sounds/Cymbal_Hit_01.wav");
	mSoundBuffers.load(SFX::Cymbal_Hit_02,	"../rec/Sounds/Cymbal_Hit_02.wav");
	mSoundBuffers.load(SFX::Cymbal_Hit_03,	"../rec/Sounds/Cymbal_Hit_03.wav");
	mSoundBuffers.load(SFX::Button_Hover,	"../rec/Sounds/Button_Hover.wav");
	mSoundBuffers.load(SFX::Button_Click,	"../rec/Sounds/Button_Click.wav");

	// Listener points towards the screen (default in SFML)
	sf::Listener::setDirection(0.f, 0.f, -1.f);
}*/

SoundPlayer::SoundPlayer(std::string p_sDir){
	m_sDir = p_sDir;

	m_fListenerZ = 300.f;
	m_fAttenuation = 8.f;
	m_fMinDistance2D = 200.f;
	m_fMinDistance3D = std::sqrt(m_fMinDistance2D*m_fMinDistance2D + m_fListenerZ*m_fListenerZ);
}

std::vector<SPair*> SoundPlayer::GetVector(){
	return m_xpaSfx;
}

void *SoundPlayer::Load(std::string p_sFname, std::string p_sCname){
	sf::SoundBuffer *l_xpSoundBuffer = new sf::SoundBuffer;
	SPair *l_xpPair = new SPair;

	if (!l_xpSoundBuffer->loadFromFile(m_sDir + p_sFname)){
		return NULL;
	}

	l_xpPair->Param0 = l_xpSoundBuffer;

	l_xpPair->Param1 = p_sCname;
	
	m_xpaSfx.push_back(l_xpPair);
}

void SoundPlayer::Play(std::string p_sCname){
<<<<<<< HEAD
	RemoveStoppedSounds();

=======
	//RemoveStoppedSounds();
>>>>>>> 5301b7ce945568afbd97112a1b45c6472c1ec48b
	Play(p_sCname, GetListenerPosition());
}

void SoundPlayer::Play(std::string p_sCname, sf::Vector2f p_xPos){
	for (int i = 0; i < m_xpaSfx.size(); i++){
		if (m_xpaSfx[i]->Param1.compare(p_sCname) == 0){
			sf::Sound *l_xpSound = new sf::Sound(*m_xpaSfx[i]->Param0);

			l_xpSound->setPosition(p_xPos.x, -p_xPos.y, 0.f);
			l_xpSound->setAttenuation(m_fAttenuation);
			l_xpSound->setMinDistance(m_fMinDistance3D);
			
			l_xpSound->play();

			m_xpaSounds.push_back(l_xpSound);
		}
	}
}

void SoundPlayer::RemoveStoppedSounds(){
	//m_xpaSfx[0]->Param0->remove_if([] (const sf::Sound& s)
	/*{
		return s.getStatus() == sf::Sound::Stopped;
	});*/

	//for (int i = m_xpaSounds.size() - 1; i >= 0; i--){
	for (int i = 0; i < m_xpaSounds.size(); i++){
		if (m_xpaSounds[i] != NULL){
			if (m_xpaSounds[i]->getStatus() == sf::Sound::Stopped){
				delete m_xpaSounds[i];
				m_xpaSounds[i] = NULL;
			}
		}
	}
}

void SoundPlayer::SetListenerPosition(sf::Vector2f p_xPos){
	sf::Listener::setPosition(p_xPos.x, -p_xPos.y, m_fListenerZ);
}

sf::Vector2f SoundPlayer::GetListenerPosition() const{
	sf::Vector3f l_xPos = sf::Listener::getPosition();
	return sf::Vector2f(l_xPos.x, -l_xPos.y);
}
