/*
 * =====================================================================================
 *
 *  GameKit
 *  Copyright (C) 2018-2020 Unarelith, Quentin Bazin <openminer@unarelith.net>
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this library; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 *
 * =====================================================================================
 */
#ifndef GK_CAMERA_HPP_
#define GK_CAMERA_HPP_

#include "gk/gl/View.hpp"

namespace gk {

////////////////////////////////////////////////////////////
/// \brief 3D camera that defines what is shown on screen
///
/// Code inspired by SFML `3dee`
///
////////////////////////////////////////////////////////////
class Camera : public View {
	public:
		Camera(float fov, float near, float far);
		virtual ~Camera() = default;

		const Vector3f &getPosition() const override { return m_position; }
		const Vector3d &getDPosition() const { return m_position_d; }
		const Vector3f &getDirection() const { return m_direction; }
		const Vector3f &getUpVector() const { return m_upVector; }

		float getFieldOfView() const { return m_fieldOfView; }
		float getAspectRatio() const { return m_aspect; }
		float getNearClippingPlane() const { return m_nearPlane; }
		float getFarClippingPlane() const { return m_farPlane; }

		void setPosition(float x, float y, float z) { setPosition(Vector3f(x, y, z)); }
		void setPosition(const Vector3f &position);

		void setDPosition(double x, double y, double z) { setDPosition(Vector3d(x, y, z)); }
		void setDPosition(const Vector3d &position);

		void setDirection(float x, float y, float z) { setDirection(Vector3f(x, y, z)); }
		void setDirection(const Vector3f &direction);

		void setTargetPosition(float x, float y, float z) { setTargetPosition(Vector3f(x, y, z)); }
		void setTargetPosition(const Vector3f &target);

		void setUpVector(float x, float y, float z) { setUpVector(Vector3f(x, y, z)); }
		void setUpVector(const Vector3f &upVector);

		void setFieldOfView(float fov);
		void setAspectRatio(float aspect);
		void setNearClippingPlane(float distance);
		void setFarClippingPlane(float distance);

		const Transform &getTransform() const override;
		const Transform &getViewTransform() const override;

	private:
		Vector3d m_position_d{0, 0, 0};
		Vector3f m_direction{0, 0, -1};
		Vector3f m_upVector{0, 1, 0};

		float m_fieldOfView = 90.0f;
		float m_aspect = 1.0f;
		float m_nearPlane = 0.1f;
		float m_farPlane = 1000.0f;
};

} // namespace gk

#endif // GK_CAMERA_HPP_
