#include "MathUtils.h"
#include <math.h>
#include <cmath>
#include <algorithm>

// 加算
Vector3 Add(const Vector3& v1, const Vector3& v2) {
	Vector3 result;
	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return result;
}

// 減算
Vector3 Subtract(const Vector3& v1, const Vector3& v2) {
	Vector3 result;
	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return result;
}

// スカラー倍
Vector3 Multiply(float scalar, const Vector3& v) {
	Vector3 result;
	result.x = v.x * scalar;
	result.y = v.y * scalar;
	result.z = v.z * scalar;
	return result;
}

// 内積
float Dot(const Vector3& v1, const Vector3& v2) {
	float result;
	result = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
	return result;
}

// 長さ (ノルム)
float Length(const Vector3& v) {
	return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

// 正規化
Vector3 Normalize(const Vector3& v) {
	Vector3 result;
	float s = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);

	if (s <= 0.0f) {
		return { 0.0f, 0.0f, 0.0f };
	}

	result.x = v.x / s;
	result.y = v.y / s;
	result.z = v.z / s;
	return result;
}

// 行列の加法
Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 result;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.m[j][i] = m1.m[j][i] + m2.m[j][i];
		}
	}
	return result;
}

// 行列の減法
Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 result;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.m[j][i] = m1.m[j][i] - m2.m[j][i];
		}
	}
	return result;
}

// 行列の積
Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 result;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.m[j][i] = 0;
			for (int k = 0; k < 4; ++k) {
				result.m[j][i] += m1.m[j][k] * m2.m[k][i];
			}
		}
	}
	return result;
}

// 逆行列
Matrix4x4 Inverse(const Matrix4x4& matrix) {
	Matrix4x4 cofactor; // 余因子行列

	for (int row = 0; row < 4; ++row) {
		for (int col = 0; col < 4; ++col) {
			float sub[3][3];
			int subi = 0;
			for (int i = 0; i < 4; ++i) {
				if (i == row) continue;
				int subj = 0;
				for (int j = 0; j < 4; ++j) {
					if (j == col) continue;
					sub[subi][subj] = matrix.m[i][j];
					++subj;
				}
				++subi;
			}

			// 小行列
			float det3 = Determinant3x3(
				sub[0][0], sub[0][1], sub[0][2],
				sub[1][0], sub[1][1], sub[1][2],
				sub[2][0], sub[2][1], sub[2][2]
			);

			cofactor.m[row][col] = ((row + col) % 2 == 0 ? 1 : -1) * det3;
		}
	}

	float det = 0.0f;
	for (int i = 0; i < 4; ++i) {
		det += matrix.m[0][i] * cofactor.m[0][i];
	}

	if (det == 0) {
		Matrix4x4 result = { 0 };
		return result;
	}

	Matrix4x4 result;
	float invDet = 1.0f / det;

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			result.m[i][j] = cofactor.m[j][i] * invDet;
		}
	}

	return result;
}

// 転置行列
Matrix4x4 Transpose(const Matrix4x4& matrix) {
	Matrix4x4 result;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			result.m[j][i] = matrix.m[i][j];
		}
	}
	return result;
}

// 単位行列の作成
Matrix4x4 MakeIdentity4x4() {
	Matrix4x4 result;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.m[j][i] = 0.0f;
		}
	}

	for (int i = 0; i < 4; i++) {
		result.m[i][i] = 1.0f;
	}

	return result;
}

float Determinant3x3(
	float a11, float a12, float a13,
	float a21, float a22, float a23,
	float a31, float a32, float a33) {
	return
		a11 * (a22 * a33 - a23 * a32) -
		a12 * (a21 * a33 - a23 * a31) +
		a13 * (a21 * a32 - a22 * a31);
}

// 平行移動行列
Matrix4x4 MakeTranslateMatrix(const Vector3& translate) {
	Matrix4x4 result;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.m[j][i] = 0.0f;
		}
	}

	for (int i = 0; i < 4; i++) {
		result.m[i][i] = 1.0f;
	}

	result.m[3][0] = translate.x;
	result.m[3][1] = translate.y;
	result.m[3][2] = translate.z;

	return result;
}

// 拡大縮小行列
Matrix4x4 MakeScaleMatrix(const Vector3& scale) {
	Matrix4x4 result;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.m[j][i] = 0.0f;
		}
	}

	result.m[0][0] = scale.x;
	result.m[1][1] = scale.y;
	result.m[2][2] = scale.z;
	result.m[3][3] = 1.0f;

	return result;
}

// 座標変換
Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix) {
	Vector3 result;
	result.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + vector.z * matrix.m[2][0] + 1.0f * matrix.m[3][0];
	result.y = vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + vector.z * matrix.m[2][1] + 1.0f * matrix.m[3][1];
	result.z = vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + vector.z * matrix.m[2][2] + 1.0f * matrix.m[3][2];
	float w = vector.x * matrix.m[0][3] + vector.y * matrix.m[1][3] + vector.z * matrix.m[2][3] + 1.0f * matrix.m[3][3];

	// wで割って正規化
	if (w != 0.0f) {
		result.x /= w;
		result.y /= w;
		result.z /= w;
	}

	return result;
}

// X軸回転行列
Matrix4x4 MakeRotateXMatrix(float radian) {
	Matrix4x4 result;
	result.m[0][0] = 1.0f;
	result.m[0][1] = 0.0f;
	result.m[0][2] = 0.0f;
	result.m[0][3] = 0.0f;

	result.m[1][0] = 0.0f;
	result.m[1][1] = std::cos(radian);
	result.m[1][2] = std::sin(radian);
	result.m[1][3] = 0.0f;

	result.m[2][0] = 0.0f;
	result.m[2][1] = -std::sin(radian);
	result.m[2][2] = std::cos(radian);
	result.m[2][3] = 0.0f;

	result.m[3][0] = 0.0f;
	result.m[3][1] = 0.0f;
	result.m[3][2] = 0.0f;
	result.m[3][3] = 1.0f;

	return result;
}

// Y軸回転行列
Matrix4x4 MakeRotateYMatrix(float radian) {
	Matrix4x4 result;
	result.m[0][0] = std::cos(radian);
	result.m[0][1] = 0.0f;
	result.m[0][2] = -std::sin(radian);
	result.m[0][3] = 0.0f;

	result.m[1][0] = 0.0f;
	result.m[1][1] = 1.0f;
	result.m[1][2] = 0.0f;
	result.m[1][3] = 0.0f;

	result.m[2][0] = std::sin(radian);
	result.m[2][1] = 0.0f;
	result.m[2][2] = std::cos(radian);
	result.m[2][3] = 0.0f;

	result.m[3][0] = 0.0f;
	result.m[3][1] = 0.0f;
	result.m[3][2] = 0.0f;
	result.m[3][3] = 1.0f;

	return result;
}

// Z軸回転行列
Matrix4x4 MakeRotateZMatrix(float radian) {
	Matrix4x4 result;
	result.m[0][0] = std::cos(radian);
	result.m[0][1] = std::sin(radian);
	result.m[0][2] = 0.0f;
	result.m[0][3] = 0.0f;

	result.m[1][0] = -std::sin(radian);
	result.m[1][1] = std::cos(radian);
	result.m[1][2] = 0.0f;
	result.m[1][3] = 0.0f;

	result.m[2][0] = 0.0f;
	result.m[2][1] = 0.0f;
	result.m[2][2] = 1.0f;
	result.m[2][3] = 0.0f;

	result.m[3][0] = 0.0f;
	result.m[3][1] = 0.0f;
	result.m[3][2] = 0.0f;
	result.m[3][3] = 1.0f;

	return result;
}

// 3次元アフィン変換行列
Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate) {
	Matrix4x4 translateMatrix = MakeTranslateMatrix(translate);
	Matrix4x4 scaleMatrix = MakeScaleMatrix(scale);
	Matrix4x4 rotateXMatrix = MakeRotateXMatrix(rotate.x);
	Matrix4x4 rotateYMatrix = MakeRotateYMatrix(rotate.y);
	Matrix4x4 rotateZMatrix = MakeRotateZMatrix(rotate.z);
	Matrix4x4 rotateXYZMatrix = Multiply(rotateXMatrix, Multiply(rotateYMatrix, rotateZMatrix));
	Matrix4x4 scaleRot = Multiply(scaleMatrix, rotateXYZMatrix);
	Matrix4x4 resultMatrix = Multiply(scaleRot, translateMatrix);

	return resultMatrix;
}

// 正射影行列の作成関数
Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip) {
	Matrix4x4 orthoMatrix;

	orthoMatrix.m[0][0] = 2.0f / (right - left);
	orthoMatrix.m[0][1] = 0.0f;
	orthoMatrix.m[0][2] = 0.0f;
	orthoMatrix.m[0][3] = 0.0f;

	orthoMatrix.m[1][0] = 0.0f;
	orthoMatrix.m[1][1] = 2.0f / (top - bottom);
	orthoMatrix.m[1][2] = 0.0f;
	orthoMatrix.m[1][3] = 0.0f;

	orthoMatrix.m[2][0] = 0.0f;
	orthoMatrix.m[2][1] = 0.0f;
	orthoMatrix.m[2][2] = 1.0f / (farClip - nearClip);
	orthoMatrix.m[2][3] = 0.0f;

	orthoMatrix.m[3][0] = (left + right) / (left - right);
	orthoMatrix.m[3][1] = (top + bottom) / (bottom - top);
	orthoMatrix.m[3][2] = nearClip / (nearClip - farClip);
	orthoMatrix.m[3][3] = 1.0f;

	return orthoMatrix;
}

// 透視投影行列の作成関数
Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip) {
	Matrix4x4 perspectiveFovMatrix;

	perspectiveFovMatrix.m[0][0] = (1.0f / aspectRatio) * 1.0f / tan(fovY / 2.0f);
	perspectiveFovMatrix.m[0][1] = 0.0f;
	perspectiveFovMatrix.m[0][2] = 0.0f;
	perspectiveFovMatrix.m[0][3] = 0.0f;

	perspectiveFovMatrix.m[1][0] = 0.0f;
	perspectiveFovMatrix.m[1][1] = 1.0f / tan(fovY / 2.0f);
	perspectiveFovMatrix.m[1][2] = 0.0f;
	perspectiveFovMatrix.m[1][3] = 0.0f;

	perspectiveFovMatrix.m[2][0] = 0.0f;
	perspectiveFovMatrix.m[2][1] = 0.0f;
	perspectiveFovMatrix.m[2][2] = farClip / (farClip - nearClip);
	perspectiveFovMatrix.m[2][3] = 1.0f;

	perspectiveFovMatrix.m[3][0] = 0.0f;
	perspectiveFovMatrix.m[3][1] = 0.0f;
	perspectiveFovMatrix.m[3][2] = (-nearClip * farClip) / (farClip - nearClip);
	perspectiveFovMatrix.m[3][3] = 0.0f;

	return perspectiveFovMatrix;
}

// ビューポートに変換する関数
Matrix4x4 MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth) {
	Matrix4x4 viewportMatrix;

	viewportMatrix.m[0][0] = width / 2.0f;
	viewportMatrix.m[0][1] = 0.0f;
	viewportMatrix.m[0][2] = 0.0f;
	viewportMatrix.m[0][3] = 0.0f;

	viewportMatrix.m[1][0] = 0.0f;
	viewportMatrix.m[1][1] = -(height / 2.0f);
	viewportMatrix.m[1][2] = 0.0f;
	viewportMatrix.m[1][3] = 0.0f;

	viewportMatrix.m[2][0] = 0.0f;
	viewportMatrix.m[2][1] = 0.0f;
	viewportMatrix.m[2][2] = maxDepth - minDepth;
	viewportMatrix.m[2][3] = 0.0f;

	viewportMatrix.m[3][0] = left + (width / 2.0f);
	viewportMatrix.m[3][1] = top + (height / 2.0f);
	viewportMatrix.m[3][2] = minDepth;
	viewportMatrix.m[3][3] = 1.0f;

	return viewportMatrix;
}

// クロス積
Vector3 Cross(const Vector3& v1, const Vector3& v2) {
	Vector3 resultVector;
	resultVector.x = v1.y * v2.z - v1.z * v2.y;
	resultVector.y = v1.z * v2.x - v1.x * v2.z;
	resultVector.z = v1.x * v2.y - v1.y * v2.x;
	return resultVector;
}

Vector3 Project(const Vector3& v1, const Vector3& v2)
{
	Vector3 result;
	float ab = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
	float b2 = (v2.x * v2.x) + (v2.y * v2.y) + (v2.z * v2.z);
	float scalar = ab / b2;
	result.x = scalar * v2.x;
	result.y = scalar * v2.y;
	result.z = scalar * v2.z;
	return result;
}

Vector3 ClosestPoint(const Vector3& point, const Segment& segment)
{
	Vector3 result;
	Vector3 ab = segment.diff;
	Vector3 ap = point - segment.origin; // 終点 - 始点

	float abDot = (ab.x * ab.x) + (ab.y * ab.y) + (ab.z * ab.z);

	if (abDot == 0.0f) {
		return segment.origin;
	}

	float dot = (ap.x * ab.x) + (ap.y * ab.y) + (ap.z * ab.z);
	float t = dot / abDot;

	t = std::clamp(t, 0.0f, 1.0f);

	result.x = segment.origin.x + ab.x * t;
	result.y = segment.origin.y + ab.y * t;
	result.z = segment.origin.z + ab.z * t;

	return result;
}

// ベクトルに直交するベクトルを計算する関数
Vector3 Perpendicular(const Vector3& vector)
{
	if (vector.x != 0.0f || vector.y != 0.0f) {
		return { -vector.y, vector.x, 0.0f };
	}
	return { 0.0f, -vector.z, vector.y };
}

// 球同士の当たり判定を返す関数
bool IsCollision(const Sphere& s1, const Sphere& s2)
{
	float distance = Length(s2.center - s1.center);

	if (distance <= s1.radius + s2.radius) {
		return true;
	}

	return false;
}

// 球と平面の当たり判定を返す関数
bool IsCollision(const Sphere& sphere, const Plane& plane)
{
	float d = plane.normal.x * sphere.center.x +
		plane.normal.y * sphere.center.y +
		plane.normal.z * sphere.center.z -
		plane.distance;

	d = (d < 0.0f) ? -d : d;

	if (d <= sphere.radius) {
		return true;
	}

	return false;
}

// 線と平面の当たり判定を返す関数
bool IsCollision(const Segment& line, const Plane& plane)
{
	float dot = Dot(plane.normal, line.diff);
	if (dot == 0.0f) {
		return false;
	}

	float t = (plane.distance - Dot(line.origin, plane.normal)) / dot;
	if (t >= 0.0f && t <= 1.0f) {
		return true;
	}

	return false;
}

// 三角形と線の当たり判定を返す関数
bool IsCollision(const Triangle& triangle, const Segment& segment)
{
	const Vector3& v0 = triangle.vertices[0];
	const Vector3& v1 = triangle.vertices[1];
	const Vector3& v2 = triangle.vertices[2];

	// 三角形の法線
	Vector3 normal = Normalize(Cross(v1 - v0, v2 - v0));

	float dot = Dot(normal, segment.diff);
	if (std::abs(dot) < 1e-6f) {
		return false;
	}

	float d = Dot(normal, v0);
	float t = (d - Dot(normal, segment.origin)) / dot;

	if (t < 0.0f || t > 1.0f) {
		return false;
	}

	Vector3 p = segment.origin + segment.diff * t;

	// 三角形の辺のベクトル
	Vector3 v01 = v1 - v0;
	Vector3 v12 = v2 - v1;
	Vector3 v20 = v0 - v2;

	Vector3 v0p = p - v0;
	Vector3 v1p = p - v1;
	Vector3 v2p = p - v2;


	Vector3 cross01 = Cross(v01, v0p);
	Vector3 cross12 = Cross(v12, v1p);
	Vector3 cross20 = Cross(v20, v2p);

	if (Dot(cross01, normal) >= 0.0f &&
		Dot(cross12, normal) >= 0.0f &&
		Dot(cross20, normal) >= 0.0f) {
		return true;
	}

	return false;
}

// ボックス同士の当たり判定を返す関数
bool IsCollision(const AABB& aabb1, const AABB& aabb2)
{
	if ((aabb1.min.x <= aabb2.max.x && aabb1.max.x >= aabb2.min.x) &&
		(aabb1.min.y <= aabb2.max.y && aabb1.max.y >= aabb2.min.y) &&
		(aabb1.min.z <= aabb2.max.z && aabb1.max.z >= aabb2.min.z)) {
		return true;
	}

	return false;
}

// ボックスと球の当たり判定を返す関数
bool IsCollision(const AABB& aabb, const Sphere& sphere)
{
	// 最近接点を求める
	Vector3 closestPoint{
		std::clamp(sphere.center.x, aabb.min.x, aabb.max.x),
		std::clamp(sphere.center.y, aabb.min.y, aabb.max.y),
		std::clamp(sphere.center.z, aabb.min.z, aabb.max.z)
	};

	// 最近接点と球の中心との距離を求める
	float distance = Length(closestPoint - sphere.center);
	// 距離が半径よりも小さければ衝突
	if (distance <= sphere.radius) {
		return true;
	}

	return false;
}

// aabbとsegmentの当たり判定を返す関数
bool IsCollision(const AABB& aabb, const Segment& segment)
{
	float txmin = (aabb.min.x - segment.origin.x) / segment.diff.x;
	float txmax = (aabb.max.x - segment.origin.x) / segment.diff.x;

	float tymin = (aabb.min.y - segment.origin.y) / segment.diff.y;
	float tymax = (aabb.max.y - segment.origin.y) / segment.diff.y;

	float tzmin = (aabb.min.z - segment.origin.z) / segment.diff.z;
	float tzmax = (aabb.max.z - segment.origin.z) / segment.diff.z;

	float tNearX = std::min(txmin, txmax);
	float tFarX = std::max(txmin, txmax);
	float tNearY = std::min(tymin, tymax);
	float tFarY = std::max(tymin, tymax);
	float tNearZ = std::min(tzmin, tzmax);
	float tFarZ = std::max(tzmin, tzmax);

	// AABBの衝突点のtが小さいほう
	float tmin = std::max(std::max(tNearX, tNearY), tNearZ);
	// AABBの衝突点のtが大きいほう
	float tmax = std::min(std::min(tFarX, tFarY), tFarZ);
	if (tmin <= tmax) {
		return true;
	}

	return false;
}

bool IsCollision(const Vector2& startPos, const Vector2& targetPos, const float radius1, const float radius2)
{
	float startToTargetX = startPos.x - targetPos.x;
	float startToTargetY = startPos.y - targetPos.y;
	float distance = sqrtf(startToTargetX * startToTargetX + startToTargetY * startToTargetY);

	if (distance <= radius1 + radius2) {
		return true;
	}

	return false;
}

// 線形補間関数
inline Vector3 Lerp(const Vector3& v1, const Vector3& v2, float t)
{
	return v1 + (v2 - v1) * t;
}

// イージング
inline float EaseInOut(float t) {
	return t * t * (3 - 2 * t);
}

// サイン波アニメーション
inline float SineWave(float time, float speed, float amplitude) {
	return std::sin(time * speed) * amplitude;
}

// 往復運動
inline float PingPong(float time, float length) {
	float t = fmod(time, length * 2);
	return (t < length) ? t : (2 * length - t);
}

// オペレーター
Vector3 operator+(const Vector3& v1, const Vector3& v2) {
	return { v1.x + v2.x, v1.y + v2.y, v1.z + v2.z };
}

Vector3 operator-(const Vector3& v1, const Vector3& v2) {
	return { v1.x - v2.x, v1.y - v2.y, v1.z - v2.z };
}

Vector3 operator*(const Vector3& v1, const Vector3& v2) {
	return { v1.x * v2.x, v1.y * v2.y, v1.z * v2.z };
}

Vector3 operator*(float s, const Vector3& v)
{
	return Multiply(s, v);
}

Vector3 operator*(const Vector3& v, float s) {
	return { v.x * s, v.y * s, v.z * s };
}

Vector3 operator/(const Vector3& v, float s)
{
	return Multiply(1.0f / s, v);
}

Matrix4x4 operator+(const Matrix4x4& m1, const Matrix4x4& m2)
{
	return Add(m1, m2);
}

Matrix4x4 operator-(const Matrix4x4& m1, const Matrix4x4& m2)
{
	return Subtract(m1, m2);
}

Matrix4x4 operator*(const Matrix4x4& m1, const Matrix4x4& m2)
{
	return Multiply(m1, m2);
}