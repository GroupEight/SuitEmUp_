//AnimatedSprite.h//

#include <memory>

#include "Sprite.h"

class AnimatedSprite : public Sprite, sf::Transformable {
public:
	AnimatedSprite(sf::RenderTarget *p_xpTarget, sf::RenderStates *p_xpStates);
	explicit AnimatedSprite(sf::RenderTarget *p_xpTarget, sf::RenderStates *p_xpStates, const sf::Texture& p_xTexture);

	void SetFrameSize(sf::Vector2i p_xFrameSize);
	sf::Vector2i GetFrameSize() const;

	void SetNumFrames(std::size_t p_xNumFrames);
	std::size_t GetNumFrames() const;

	void SetDuration(sf::Time p_xDuration);
	sf::Time GetDuration() const;

	void SetRepeating(bool p_bFlag);
	bool IsRepeating() const;

	void Restart();
	bool IsFinished() const;

	sf::FloatRect GetLocalBounds() const;
	sf::FloatRect GetGlobalBounds() const;

	void Update(sf::Time p_xDt);

private:
	sf::Sprite m_xSprite;
	sf::Vector2i m_xFrameSize;
	std::size_t m_xNumFrames;
	std::size_t m_xCurrentFrame;
	sf::Time m_xDuration;
	sf::Time m_xElapsedTime;
	bool m_bRepeat;
};