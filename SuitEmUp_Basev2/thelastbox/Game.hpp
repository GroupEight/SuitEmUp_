//Game.h//

#pragma once

class CollisionMan;
class FontMan;
class NodeMan;
class Stateman;
class SoundPlayer;
class TextureMan;

class CursorObject;
class Ground;
class PlayerObject;

class Gamestate;
class HiScorestate;
class Menustate;
class NewScoreState;

class Game {
public:
	Game();
	//Game( sf::ContextSettings settings );

	bool Init();
	void Run();
	void Cleanup();

	bool UpdateDeltaTime();
	void UpdEvents();

	void LoadTexts(TextureMan *p_xpTextMan);
	void LoadSounds();

	void processEvents();
	void render();	

private:
	static const sf::Time TimePerFrame;

	sf::RenderWindow *m_xpWindow;
	sf::Clock *m_xpClock;

	Stateman *m_xpStateman; // Member_ClassPointerStateman
	CollisionMan *m_xpCollisionMan; // Member_ClassPointerCollisionMan
	SoundPlayer *m_xpSPlayer;
	TextureMan *m_xpTextMan;
	FontMan *m_xpFontMan;

	NodeMan *m_xpPBulletman;
	NodeMan *m_xpEBulletman;
	NodeMan *m_xpStarMan;
	NodeMan *m_xpEnemyMan;

	CursorObject *m_xpCursor;
	Ground *m_xpGround;
	PlayerObject *m_xpPlayer;

	Gamestate *m_xpGamestate; // Member_Gamestate
	HiScorestate *m_xpHiScorestate;
	Menustate *m_xpMenustate; // Member_Menustate
	NewScoreState *m_xpNewScoreState;

	//b2World *m_xpWorld;

	sf::Time m_xDtime; // Member_FloatingDtime
	sf::Time m_xFps;

	int m_iWi; // Member_IntegerWi
	int m_iHe;// Member_IntegerHe
};