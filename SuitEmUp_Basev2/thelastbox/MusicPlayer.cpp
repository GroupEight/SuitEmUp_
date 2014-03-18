#include "MusicPlayer.hpp"


MusicPlayer::MusicPlayer(std::string p_sDir)
: mVolume(100.f){
	m_sDir = p_sDir;

	m_xpCurrent = new sf::Music;

	//mFilenames[Music::MenuTheme]    = "../rec/Music/Bennie_Motens_KC_Jazz_Band-South_1924.ogg";
	//mFilenames[Music::InGameTheme] = "../rec/Music/Bennie_Motens_KC_Jazz_Band-South_1924.ogg";
}

void MusicPlayer::Play(std::string p_sCname){
	/*std::map<Music::ID, std::string>	mFilenames;
	std::string filename = mFilenames[theme];
	
	if (!mMusic.openFromFile(filename))
		throw std::runtime_error("Music " + filename + " could not be loaded.");

	mMusic.setVolume(mVolume);
	mMusic.setLoop(true);
	mMusic.play();*/

	for (int i = 0; i < m_xpaMusic.size(); i++){
		if (m_xpaMusic[i]->Param1.compare(p_sCname) == 0){
		//if (p_sCname.compare(m_xpaMusic[i]->Param1)){
			if (m_xpCurrent->openFromFile(m_sDir + m_xpaMusic[i]->Param0)){
				m_xpCurrent->play();
			}
		}
	}
}


void MusicPlayer::Stop(){
	m_xpCurrent->stop();
}

void MusicPlayer::SetVolume(float p_fVolume){
	mVolume = p_fVolume;
}

void MusicPlayer::SetPaused(bool p_bPaused){
	if (p_bPaused)
		m_xpCurrent->pause();
	else
		m_xpCurrent->play();
}

void MusicPlayer::Load(std::string p_sFname, std::string p_sCname){
	MPair *l_xpPair = new MPair;

	l_xpPair->Param0 = p_sFname;
	l_xpPair->Param1 = p_sCname;

	m_xpaMusic.push_back(l_xpPair);
}