////////////////////////////////////////////////////////////
// File: vec3.h
// Author: Anudeep        saianudeep265@gmail.com
// Created on: 12 Feb 2023 16:10 IST
////////////////////////////////////////////////////////////

#pragma once

#include <iostream>
#include <cmath>
#include <array>

class vec3 {
public:
	vec3(float dVecx = 0.0f, float dVecy = 0.0f, float dVecz = 0.0f) : m_dVec3{ dVecx , dVecy , dVecz } {}

	virtual ~vec3() = default;

	float x() const {
		return m_dVec3[0];
	}

	float y() const {
		return m_dVec3[1];
	}

	float z() const {
		return m_dVec3[2];
	}

	vec3 operator-() const {
		return vec3(-m_dVec3[0], -m_dVec3[1], -m_dVec3[2]);
	}

	vec3& operator+=(const vec3& v) {
		m_dVec3[0] += v.m_dVec3[0];
		m_dVec3[1] += v.m_dVec3[1];
		m_dVec3[2] += v.m_dVec3[2];
		return *this;
	}

	vec3& operator*=(double val) {
		m_dVec3[0] *= val;
		m_dVec3[1] *= val;
		m_dVec3[2] *= val;
		return *this;
	}

	vec3& operator/=(double val) {
		return *this *= 1 / val;
	}

	float length_squared() const {
		return m_dVec3[0] * m_dVec3[0] + m_dVec3[1] * m_dVec3[1] + m_dVec3[2] * m_dVec3[2];
	}

	float length() const {
		return std::sqrt(length_squared());
	}

protected:
	std::array<float, 3> m_dVec3;
};

typedef vec3 point3;

std::ostream& operator<<(std::ostream& out, const vec3& v) {
	return out << v.x() << ' ' << v.y() << ' ' << v.z();
}

vec3 operator+(const vec3& v1, const vec3& v2) {
	return vec3(v1.x() + v2.x(), v1.y() + v2.y(), v1.z() + v2.z());
}

vec3 operator-(const vec3& v1, const vec3& v2) {
	return vec3(v1.x() - v2.x(), v1.y() - v2.y(), v1.z() - v2.z());
}

vec3 operator*(const vec3& v1, const vec3& v2) {
	return vec3(v1.x() * v2.x(), v1.y() * v2.y(), v1.z() * v2.z());
}

vec3 operator*(const vec3& v1, float val) {
	return vec3(v1.x() * val, v1.y() * val, v1.z() * val);
}

vec3 operator*(float val, const vec3& v1) {
	return v1 * val;
}

vec3 operator/(const vec3& v1, float val) {
	return (1 / val) * v1;
}

vec3 unit_vector(vec3 v) {
	return v / v.length();
}

float dot(const vec3& v1, const vec3& v2) {
	return v1.x() * v2.x() +
		   v1.y() * v2.y() +
		   v1.z() * v2.z();
}

vec3 cross(const vec3& v1, const vec3& v2) {
	return vec3(v1.y() * v2.z() - v1.z() * v2.y(),
				v1.z() * v2.x() - v1.x() * v2.z(),
				v1.x() * v2.y() - v1.y() * v2.x()
				);
}
