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
#ifndef GameKit_EXCEPTION_HPP_
#define GameKit_EXCEPTION_HPP_

#include <exception>
#include <string>

#include "Core/Debug.hpp"
#include "Core/Utils.hpp"

#define EXCEPTION(...) (GameKit::Exception(__LINE__, _FILE, __VA_ARGS__))

namespace GameKit {

class Exception {
	public:
		template<typename... Args>
		Exception(u16 line, const std::string &filename, Args... args) noexcept {
			m_errorMsg = Logger::textColor(LoggerColor::Red, true);
			m_errorMsg += "at " + filename + ":" + std::to_string(line) + ": ";
			m_errorMsg += makeString(std::forward<Args>(args)...);
			m_errorMsg += Logger::textColor();
		}

		virtual const char *what() const noexcept {
			return m_errorMsg.c_str();
		}

	private:
		std::string m_errorMsg;
};

} // namespace GameKit

#endif // GameKit_EXCEPTION_HPP_
