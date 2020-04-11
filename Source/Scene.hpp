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
#ifndef GameKit_SCENE_HPP_
#define GameKit_SCENE_HPP_

#include "Scene.hpp"

// Behaviours
#include "Scenes/Behaviour/EasyBehaviour.hpp"

// Controllers
#include "Scenes/Controllers/BehaviourController.hpp"
#include "Scenes/Controllers/LifetimeController.hpp"
#include "Scenes/Controllers/MovementController.hpp"

// Components
#include "Scenes/Components/BehaviourComponent.hpp"
#include "Scenes/Components/CollisionComponent.hpp"
#include "Scenes/Components/HealthComponent.hpp"
#include "Scenes/Components/HitboxComponent.hpp"
#include "Scenes/Components/LifetimeComponent.hpp"
#include "Scenes/Components/MovementComponent.hpp"
#include "Scenes/Components/PositionComponent.hpp"

// Movements
#include "Movement/EasyMovement.hpp"
#include "Movement/GamePadMovement.hpp"

// Views
#include "Scenes/View/HitboxView.hpp"
#include "Scenes/View/SpriteView.hpp"

#endif // GameKit_SCENE_HPP_

///////////////////////////////////////////////////////////
/// \defgroup scene
/// \brief Game scene and entity management
///
////////////////////////////////////////////////////////////
