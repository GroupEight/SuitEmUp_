//Background.h//

#include "Gfx.h"

class Background : public Gfx {
public:
	Background(sf::Texture *p_xpTex, sf::Vector2f p_xSize);
	~Background();

	sf::Drawable *GetParent();

	sf::Texture *GetTexture();

	void UpdateTexCoords(sf::Vector2f p_xOffset, sf::Vector2f p_xPosition);

	bool IsGraphic(const std::string &p_sType);

private:
	sf::Vector2f m_xSize;

	sf::VertexArray *m_xpVertArray;
	sf::VertexArray m_xVertArray;

	sf::Texture *m_xpTex;
};