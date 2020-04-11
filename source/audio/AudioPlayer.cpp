/*
 * =====================================================================================
 *
 *  GameKit
 *
 *  Copyright (C) 2018-2020 Unarelith, Quentin Bazin <openminer@unarelith.net>
 *  Copyright (C) 2020 the GameKit contributors (see CONTRIBUTORS.md)
 *
 *  This file is part of GameKit.
 *
 *  GameKit is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  GameKit is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with GameKit; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 *
 * =====================================================================================
 */
#include "audio/AudioPlayer.hpp"
#include "audio/Music.hpp"
#include "audio/Sound.hpp"
#include "Resources/ResourceHandler.hpp"

namespace GameKit {

bool AudioPlayer::s_muteState = false;

void AudioPlayer::playMusic(const std::string &resourceName) {
	if (!s_muteState)
		ResourceHandler::getInstance().get<Music>(resourceName).play();
}

void AudioPlayer::playSound(const std::string &resourceName) {
	if (!s_muteState)
		ResourceHandler::getInstance().get<Sound>(resourceName).play();
}

void AudioPlayer::repeatSound(const std::string &resourceName, u8 delay) {
	if (!s_muteState)
		ResourceHandler::getInstance().get<Sound>(resourceName).repeat(delay);
}

void AudioPlayer::pauseMusic() {
	Mix_PauseMusic();
}

void AudioPlayer::resumeMusic() {
	Mix_ResumeMusic();
}

bool AudioPlayer::isMusicPaused() {
	return Mix_PausedMusic();
}

bool AudioPlayer::isMusicPlaying() {
	return Mix_PlayingMusic();
}

} // namespace GameKit

