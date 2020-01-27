/*
 * =====================================================================================
 *
 *       Filename:  CoreApplication.cpp
 *
 *    Description:
 *
 *        Created:  14/06/2018 02:00:18
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <ctime>

#include "gk/audio/AudioPlayer.hpp"
#include "gk/core/CoreApplication.hpp"
#include "gk/core/Mouse.hpp"
#include "gk/core/Exception.hpp"

namespace gk {

CoreApplication::CoreApplication(int argc, char **argv) : m_argumentParser(argc, argv) {
}

void CoreApplication::init() {
	std::srand(std::time(nullptr));

	Mouse::setWindow(&m_window);

	ApplicationStateStack::setInstance(m_stateStack);
	ResourceHandler::setInstance(m_resourceHandler);

	m_argumentParser.addArgument("mute", {"", "--no-sound"});
	m_argumentParser.parse();
	if (m_argumentParser.getArgument("mute").isFound)
		AudioPlayer::setMuteState(true);
	// m_argumentParser.debug();
}

int CoreApplication::run(bool isProtected) {
	auto runGame = [&]() {
		if (m_loadSDL)
			m_sdlLoader.load();

		init();
		mainLoop();
	};

	if (isProtected) {
		try {
			runGame();
		}
		catch(const Exception &e) {
			std::cerr << "Fatal error " << e.what() << std::endl;
			return 1;
		}
		// catch(const std::exception &e) {
		// 	std::cerr << "Exception caught: " << e.what() << std::endl;
		// 	return 1;
		// }
		// catch(...) {
		// 	std::cerr << "Fatal error: Unknown error." << std::endl;
		// 	return 1;
		// }
	}
	else {
		runGame();
	}

	return 0;
}

void CoreApplication::createWindow(u16 screenWidth, u16 screenHeight, const char *windowTitle) {
	m_window.open(windowTitle, screenWidth, screenHeight);
}

void CoreApplication::onEvent(const SDL_Event &event) {
	if (event.type == SDL_QUIT) {
		m_window.close();
	}
}

void CoreApplication::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		onEvent(event);

		m_window.onEvent(event);

		if (!m_stateStack.empty())
			m_stateStack.top().onEvent(event);
	}
}

void CoreApplication::mainLoop() {
	m_clock.startFpsTimer();

	while(m_window.isOpen() && m_stateStack.size()) {
		handleEvents();

		m_clock.updateGame([&] {
			if (!m_stateStack.empty())
				m_stateStack.top().update();

			m_stateStack.clearDeletedStates();
		});

		m_clock.drawGame([&] {
			m_window.clear();

			if(!m_stateStack.empty())
				m_window.draw(m_stateStack.top(), m_renderStates);

			m_window.display();
		});
	}
}

} // namespace gk

