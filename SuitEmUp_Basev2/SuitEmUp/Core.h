//Core.h//

#pragma once


class DrawMan;
class Stateman;
class SpriteMan;

class Gamestate;
class Menustate;

class Core {
public:
	Core();
	~Core();

	bool Init();
	void Run();
	void Draw();
	void Cleanup();

	bool UpdateDeltaTime();
	void UpdEvents();

private:
	sf::RenderWindow *m_xpWindow;
	sf::Clock *m_xpClock;

	DrawMan *m_xpDrawMan; // Member_ClassPointerDrawMan
	Stateman *m_xpStateman; // Member_ClassPointerStateman
	SpriteMan *m_xpSpriteMan; // Member_ClassPointerSpriteMan

	Gamestate *m_xpGamestate; // Member_Gamestate
	Menustate *m_xpMenustate; // Member_Menustate

	int m_iWi; // Member_IntegerWi
	int m_iHe;// Member_IntegerHe

	sf::Time m_xDtime; // Member_FloatingDtime
	sf::Time m_xFps;
};