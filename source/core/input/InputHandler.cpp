/*
 * =====================================================================================
 *
 *       Filename:  InputHandler.cpp
 *
 *    Description:
 *
 *        Created:  17/01/2018 19:10:34
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "gk/core/input/InputHandler.hpp"
#include "gk/core/GameClock.hpp"

namespace gk {

bool InputHandler::isKeyPressedOnce(GameKey key) {
	if(isKeyPressed(key)) {
		if(!m_keysPressedOnce[key]) {
			m_keysPressedOnce[key] = true;
			return true;
		} else {
			return false;
		}
	} else {
		m_keysPressedOnce[key] = false;
		return false;
	}
}

bool InputHandler::isKeyPressedWithDelay(GameKey key, u16 delay) {
	if(isKeyPressed(key) && GameClock::getTicks() - m_lastTimePressed[key] > delay) {
		m_lastTimePressed[key] = GameClock::getTicks();
		return true;
	} else {
		if(!isKeyPressed(key)) m_lastTimePressed[key] = 0;
		return false;
	}
}

void InputHandler::addKey(GameKey key) {
	m_keysPressed[key] = false;
	m_keysPressedOnce[key] = false;
	m_lastTimePressed[key] = 0;
}

} // namespace gk

