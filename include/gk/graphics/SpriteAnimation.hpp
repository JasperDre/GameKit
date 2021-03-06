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
#ifndef GK_SPRITEANIMATION_HPP_
#define GK_SPRITEANIMATION_HPP_

#include <vector>

#include "gk/core/Timer.hpp"

namespace gk {

class SpriteAnimation {
	public:
		SpriteAnimation(u16 delay, bool isRepeated = true)
			: m_delay(delay), m_isRepeated(isRepeated) {}

		void reset(u16 frameID = 0);

		void start();
		void stop();

		void play();

		void addFrame(u16 frameID) { m_frames.emplace_back(frameID); }
		u16 getFrame(u16 frameID) const;
		u16 currentFrame() const;
		u16 displayedFramesAmount() const;

		bool isPlaying() const { return m_timer.isStarted() && !m_isPaused; }
		bool isFinished() const { return displayedFramesAmount() >= m_frames.size(); }

		u32 size() const { return m_frames.size(); }

		u16 delay() const { return m_delay; }

		void setRepeated(bool isRepeated) { m_isRepeated = isRepeated; }

	private:
		std::vector<u16> m_frames;

		Timer m_timer;

		u16 m_delay = 0;

		bool m_isPaused = false;
		bool m_isRepeated = true;
};

} // namespace gk

#endif // GK_SPRITEANIMATION_HPP_
