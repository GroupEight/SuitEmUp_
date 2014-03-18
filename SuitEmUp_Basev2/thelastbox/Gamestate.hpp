//Gamestate.h//

#pragma once

#include "State.h"

#include <array>

class FontHolder;
class TextureHolder;

class CollisionMan;
class FontMan;
class MusicPlayer;
class NodeMan;
class SoundPlayer;
class TextureMan;

class Ground;

class BGObject;
class CursorObject;
class EnemyObject;
class HUD;
class HWallObject;
class Level;
class Menu_Button;
class PlayerObject;
class Prompt;
class Star;

class Gamestate : public State {
	private:
	enum Layer {
		Background,
		Main,
		LayerCount
	};

	enum SubStates {
		Play,
		Pause,
		Quit,
		End
	};

	enum PauseStates {
		State0,
		State1
	};

public:
	Gamestate(sf::RenderWindow *p_xpWindow, SoundPlayer *p_xpSPlayer, CollisionMan *p_xpCollisionMan, TextureMan *p_xpTextMan, FontMan *p_xpFMan, NodeMan *p_xpPBulletMan, NodeMan *p_xpEBulletMan, NodeMan *p_xpStarMan, NodeMan *p_xpEnemyMan, PlayerObject *p_xpPlayer, CursorObject *p_xpCursor, Ground *p_xpGround);

	bool Enter();
	void Exit();

	bool Update(sf::Time p_xDtime);

	void Draw();

	std::string Next();

	bool IsType(const std::string &p_sType);

	void Gamestate::LoadResources();

	void ShowText(std::string p_sText);

private:
	// Used everywhere:
	sf::RenderWindow *m_xpWindow;
	sf::View *m_xpWorldView;

	TextureMan *m_xpTextureMan;
	FontMan *m_xpFman;
	MusicPlayer *m_xpMPlayer;
	SoundPlayer *m_xpSPlayer;

	CursorObject *m_xpCursor;
	Ground *m_xpGround;

	Gamestate::SubStates m_eState;

	float m_fMinZoom,
		m_fStrtZoom,
		m_fMaxZoom,
		m_fCurrZoom,
		m_fEndTime;

	sf::Text *EndText;

	// Used in Playstate:
	CollisionMan *m_xpCollisionMan;

	PlayerObject *m_xpPlayer;

	HUD *m_xpHUD;

	sf::Texture *m_xpTex;

	NodeMan *m_xpEnemyMan,
		*m_xpEBulletMan,
		*m_xpPBulletMan,
		*m_xpStarMan;

	Level* m_xpLevel;

	sf::FloatRect m_xWorldBounds;
	sf::Vector2f m_xSpawnPosition;

	// Used in Pausestate/Quitstate
	NodeMan *m_xpMenuman;

	Prompt *m_xpQuitPrompt;

	Menu_Button *m_xpResumeBtn;
	Menu_Button *m_xpQuitBtn;

	sf::Sprite *m_xpBG;
};