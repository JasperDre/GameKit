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
#ifndef GameKit_TILEDIMAGE_HPP_
#define GameKit_TILEDIMAGE_HPP_

#include <string>
#include <vector>

#include "Graphics/Image.hpp"

namespace GameKit {

class TiledImage : public Drawable, public Transformable {
	public:
		TiledImage() = default;
		TiledImage(const std::string &textureName);

		void load(const std::string &textureName);

		void setTile(u16 id, float x, float y, u16 width, u16 height, float clipX, float clipY, u16 clipWidth, u16 clipHeight, const GameKit::Color &color = GameKit::Color::White);
		void setTilePosRect(u16 id, float x, float y, u16 width, u16 height);
		void setTileClipRect(u16 id, float x, float y, u16 clipWidth, u16 clipHeight);
		void setTileColor(u16 id, const GameKit::Color &color);

		void setTileCount(u16 tileCount);

	protected:
		void draw(GameKit::RenderTarget &target, GameKit::RenderStates states) const override;

	private:
		std::vector<Image> m_tiles;

		std::string m_textureName;
};

} // namespace GameKit

#endif // GameKit_TILEDIMAGE_HPP_
