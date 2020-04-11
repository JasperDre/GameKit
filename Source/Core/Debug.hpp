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
#ifndef GameKit_DEBUG_HPP_
#define GameKit_DEBUG_HPP_

#include <cstring>

#include "Core/LoggerUtils.hpp"
#include "Core/Utils.hpp"

#define _FILE (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

#define GameKitDebug()    (GameKit::Logger(GameKit::Debug,   _FILE, __LINE__))
#define GameKitInfo()     (GameKit::Logger(GameKit::Info,    _FILE, __LINE__))
#define GameKitWarning()  (GameKit::Logger(GameKit::Warning, _FILE, __LINE__))
#define GameKitError()    (GameKit::Logger(GameKit::Error,   _FILE, __LINE__))

#define GameKitTrace(s) do { GameKitInfo() << "Function called: " #s; s } while (false);

#endif // GameKit_DEBUG_HPP_
