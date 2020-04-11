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
#ifndef GameKit_ABSTRACTVIEW_HPP_
#define GameKit_ABSTRACTVIEW_HPP_

#include "GL/RenderTarget.hpp"
#include "Scenes/SceneObjectList.hpp"

namespace GameKit {

class AbstractView {
	public:
		virtual ~AbstractView() = default;

		virtual void draw(const SceneObject &object, RenderTarget &target, RenderStates states) = 0;

		virtual void draw(const SceneObjectList &objectList, RenderTarget &target, RenderStates states) {
			for(auto &object : objectList) {
				draw(object, target, states);

				if (object.has<SceneObjectList>())
					draw(object.get<SceneObjectList>(), target, states);
			}
		}
};

} // namespace GameKit

#endif // GameKit_ABSTRACTVIEW_HPP_
