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
#ifndef GameKit_MOUSE_HPP_
#define GameKit_MOUSE_HPP_

#include "Core/Rect.hpp"
#include "Core/Window.hpp"

namespace GameKit {

class Mouse {
	public:
		static void resetToWindowCenter();

		static void setWindow(Window *window) { s_window = window; }

		static void setCursorVisible(bool isVisible);
		static void setCursorGrabbed(bool isGrabbed);

		static Vector2i getPosition();

		static bool isInRect(const IntRect &rect);

	private:
		static Window *s_window;
};

} // namespace GameKit

#endif // GameKit_MOUSE_HPP_