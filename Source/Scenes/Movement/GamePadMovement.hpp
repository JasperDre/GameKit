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
#ifndef GameKit_GAMEPADMOVEMENT_HPP_
#define GameKit_GAMEPADMOVEMENT_HPP_

#include "Core/input/InputHandler.hpp"
#include "Scenes/Movement/Movement.hpp"

namespace GameKit {

class GamePadMovement : public Movement {
	public:
		void process(SceneObject &object) override;

		void setKeys(GameKey left, GameKey right, GameKey up, GameKey down) {
			m_left = left;
			m_right = right;
			m_up = up;
			m_down = down;
		}

	private:
		GameKey m_left;
		GameKey m_right;
		GameKey m_up;
		GameKey m_down;
};

} // namespace GameKit

#endif // GameKit_GAMEPADMOVEMENT_HPP_
