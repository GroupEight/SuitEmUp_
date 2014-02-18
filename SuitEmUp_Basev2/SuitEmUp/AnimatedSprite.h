//AnimatedSprite.h//

#include <memory>

#include "Gfx.h"

class Sprite;

class AnimatedSprite : public Gfx, sf::Transformable {
public:
	AnimatedSprite(Sprite *p_xpSprite, sf::Vector2i p_xFrameSize, std::size_t p_xNumFrames, std::size_t p_xCurrentFrame, float p_xDuration, bool p_bRepeat);
	//explicit AnimatedSprite(sf::RenderTarget *p_xpTarget, sf::RenderStates *p_xpStates, const sf::Texture& p_xTexture);

	void SetFrameSize(sf::Vector2i p_xFrameSize);
	sf::Vector2i GetFrameSize() const;

	void SetNumFrames(std::size_t p_xNumFrames);
	std::size_t GetNumFrames() const;

	void SetDuration(float p_fDuration);
	float GetDuration() const;

	void SetPosition(sf::Vector2f p_xPos);
	sf::Vector2f GetPosition();

	void SetRepeating(bool p_bFlag);
	bool IsRepeating() const;

	void Restart();
	bool IsFinished() const;

	/*sf::FloatRect GetLocalBounds() const;
	sf::FloatRect GetGlobalBounds() const;*/

	sf::Drawable *GetParent();

	bool IsGraphic(const std::string &p_sType);

	void Update(sf::Time p_xDt);

private:
	Sprite *m_xpSprite;
	sf::Vector2i m_xFrameSize;
	std::size_t m_xNumFrames;
	std::size_t m_xCurrentFrame;
	float m_xElapsedTime;
	float m_fDuration;
	bool m_bRepeat;
};