//InputMan.h//

#pragma once

class InputMan {
public:
	InputMan(sf::RenderWindow *p_xpWindow);
	~InputMan();

	bool KeyIsDown(sf::Mouse::Button p_xBpress);
	bool KeyIsReleased(sf::Mouse::Button p_xBpress);

	bool KeyIsDown(sf::Keyboard::Key p_xKpress);
	bool KeyIsReleased(sf::Keyboard::Key p_xKpress);

	bool IsInFocus();

private:
	sf::Event m_xEvent;

	sf::RenderWindow *m_xpWindow;
};