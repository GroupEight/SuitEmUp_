//AnimatedSprite.h//

#include "stdafx.h"

#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(sf::RenderTarget *p_xpTarget, sf::RenderStates *p_xpStates)
: m_xSprite()
, m_xFrameSize()
, m_xNumFrames(0)
, m_xCurrentFrame(0)
, m_xDuration(sf::Time::Zero)
, m_xElapsedTime(sf::Time::Zero)
, m_bRepeat(false){

}

AnimatedSprite::AnimatedSprite(sf::RenderTarget *p_xpTarget, sf::RenderStates *p_xpStates, const sf::Texture& p_xTexture)
: m_xSprite(p_xTexture)
, m_xFrameSize()
, m_xNumFrames(0)
, m_xCurrentFrame(0)
, m_xDuration(sf::Time::Zero)
, m_xElapsedTime(sf::Time::Zero)
, m_bRepeat(false){

}

void AnimatedSprite::SetFrameSize(sf::Vector2i p_xFrameSize){
	m_xFrameSize = p_xFrameSize;
}

sf::Vector2i AnimatedSprite::GetFrameSize() const {
	return m_xFrameSize;
}

void AnimatedSprite::SetNumFrames(std::size_t p_xNumFrames){
	m_xNumFrames = p_xNumFrames;
}

std::size_t AnimatedSprite::GetNumFrames() const {
	return m_xNumFrames;
}

void AnimatedSprite::SetDuration(sf::Time p_xDuration){
	m_xDuration = p_xDuration;
}

sf::Time AnimatedSprite::GetDuration() const {
	return m_xDuration;
}

void AnimatedSprite::SetRepeating(bool p_bFlag){
	m_bRepeat = p_bFlag;
}

bool AnimatedSprite::IsRepeating() const {
	return m_bRepeat;
}

void AnimatedSprite::Restart(){
	m_xCurrentFrame = 0;
}

bool AnimatedSprite::IsFinished() const {
	return m_xCurrentFrame >= m_xNumFrames;
}

sf::FloatRect AnimatedSprite::GetLocalBounds() const {
	return sf::FloatRect(getOrigin(), static_cast<sf::Vector2f>(GetFrameSize()));
}

sf::FloatRect AnimatedSprite::GetGlobalBounds() const {
	return getTransform().transformRect(GetLocalBounds());
}

void AnimatedSprite::Update(sf::Time p_xDt){
	sf::Time l_sFps = m_xDuration / static_cast<float>(m_xNumFrames);
	m_xElapsedTime += p_xDt;

	sf::Vector2i l_xTextureBounds(m_xSprite.getTexture()->getSize());
	sf::IntRect l_xTextureRect = m_xSprite.getTextureRect();

	if (m_xCurrentFrame == 0)
		l_xTextureRect = sf::IntRect(0, 0, m_xFrameSize.x, m_xFrameSize.y);

	// While we have a frame to process
	while (m_xElapsedTime >= l_sFps && (m_xCurrentFrame <= m_xNumFrames || m_bRepeat)){
		// Move the texture rect left
		l_xTextureRect.left += l_xTextureRect.width;

		// If we reach the end of the texture
		if (l_xTextureRect.left + l_xTextureRect.width > l_xTextureBounds.x){
			// Move it down one line
			l_xTextureRect.left = 0;
			l_xTextureRect.top += l_xTextureRect.height;
		}

		// And progress to next frame
		m_xElapsedTime -= l_sFps;
		if (m_bRepeat){
			m_xCurrentFrame = (m_xCurrentFrame + 1) % m_xNumFrames;

			if (m_xCurrentFrame == 0)
				l_xTextureRect = sf::IntRect(0, 0, m_xFrameSize.x, m_xFrameSize.y);
		}
		else {
			m_xCurrentFrame++;
		}
	}

	m_xSprite.setTextureRect(l_xTextureRect);
}