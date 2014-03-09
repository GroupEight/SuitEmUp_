//InputMan.cpp//

#include "InputMan.h"

InputMan::InputMan(sf::RenderWindow *p_xpWindow){
	m_xpWindow = p_xpWindow;
}

InputMan::~InputMan(){

}

bool InputMan::KeyIsDown(sf::Mouse::Button p_xBpress){
	sf::Event l_xEvent;
	while (m_xpWindow->pollEvent(l_xEvent)){
		//if (l_xEvent.type == sf::Event::MouseButtonPressed){
			if (l_xEvent.mouseButton.button == p_xBpress){
				return true;
			}
		//}
	}
}

bool InputMan::KeyIsReleased(sf::Mouse::Button p_xBpress){
	while (m_xpWindow->pollEvent(m_xEvent)){
		if (sf::Event::MouseButtonReleased){
			if (m_xEvent.mouseButton.button == p_xBpress){
				return true;
			}
		}
	}
}

bool InputMan::KeyIsDown(sf::Keyboard::Key p_xKpress){
	while (m_xpWindow->pollEvent(m_xEvent)){
		if (sf::Event::KeyPressed){
			if (m_xEvent.mouseButton.button == p_xKpress){
				return true;
			}
		}
	}
}

bool InputMan::KeyIsReleased(sf::Keyboard::Key p_xKpress){
	while (m_xpWindow->pollEvent(m_xEvent)){
		if (sf::Event::KeyReleased){
			if (m_xEvent.mouseButton.button == p_xKpress){
				return true;
			}
		}
	}
}

bool InputMan::IsInFocus(){
	return !m_xEvent.LostFocus;
}