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
#ifndef GameKit_LOGGERUTILS_HPP_
#define GameKit_LOGGERUTILS_HPP_

#include "Core/Logger.hpp"

//======================================================================================
// GameKit::Vector2
//======================================================================================
#include "Core/Vector2.hpp"

template<typename T>
GameKit::Logger &operator<<(GameKit::Logger &stream, const GameKit::Vector2<T> &vec) {
	stream.addSpace();
	return stream << "GameKit::Vector2(" << vec.x << ", " << vec.y << ")";
}

//======================================================================================
// GameKit::Vector3
//======================================================================================
#include "Core/Vector3.hpp"

template<typename T>
GameKit::Logger &operator<<(GameKit::Logger &stream, const GameKit::Vector3<T> &vec) {
	stream.addSpace();
	return stream << "GameKit::Vector3(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
}

//======================================================================================
// GameKit::Vector4
//======================================================================================
#include "Core/Vector4.hpp"

template<typename T>
GameKit::Logger &operator<<(GameKit::Logger &stream, const GameKit::Vector4<T> &vec) {
	stream.addSpace();
	return stream << "GameKit::Vector4(" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << ")";
}

//======================================================================================
// GameKit::Color
//======================================================================================
#include "Graphics/Color.hpp"

GameKit::Logger &operator<<(GameKit::Logger &stream, const GameKit::Color &color);

//======================================================================================
// GameKit::Rect
//======================================================================================
#include "Core/Rect.hpp"

template<typename T>
GameKit::Logger &operator<<(GameKit::Logger &stream, const GameKit::Rect<T> &rect) {
	stream.addSpace();
	return stream << "GameKit::Rect(" << rect.x << ", " << rect.y << ", " << rect.sizeX << ", " << rect.sizeY << ")";
}

//======================================================================================
// GameKit::Box
//======================================================================================
#include "Core/Box.hpp"

template<typename T>
GameKit::Logger &operator<<(GameKit::Logger &stream, const GameKit::Box<T> &box) {
	stream.addSpace();
	return stream << "GameKit::Box(" << box.x << ", " << box.y << ", " << box.z << ", " << box.sizeX << ", " << box.sizeY << ", " << box.sizeZ << ")";
}

#endif // GameKit_LOGGERUTILS_HPP_
