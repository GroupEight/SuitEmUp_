//SoundPlayer.h//

#include <vector>

struct SPair {
	sf::SoundBuffer *Param0;
	std::string Param1;
};

class SoundPlayer {
public:
	SoundPlayer(std::string p_sDir);

	std::vector<SPair*> GetVector();

	void *Load(std::string p_sFname, std::string p_sCname = "");

	void Play(std::string p_sCname);
	void Play(std::string p_sCname, sf::Vector2f p_xPos);

	void RemoveStoppedSounds();

	void SetListenerPosition(sf::Vector2f p_xPos);

	sf::Vector2f GetListenerPosition() const;

private:
	std::vector<SPair*> m_xpaSfx;

	std::vector<sf::Sound*> m_xpaSounds;

	std::string m_sDir;

	float m_fListenerZ,
		m_fAttenuation,
		m_fMinDistance2D,
		m_fMinDistance3D;
};