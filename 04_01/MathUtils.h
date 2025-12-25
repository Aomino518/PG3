#pragma once

struct Vector2 {
	float x, y;
};

struct Vector3 {
	float x, y, z;
};

struct Vector4 {
	float x, y, z, w;
};

struct Matrix3x3 {
	float m[3][3];
};

struct Matrix4x4 {
	float m[4][4];
};

struct Sphere {
	Vector3 center;
	float radius;
};

struct Plane {
	Vector3 normal;
	float distance;
};

struct Segment {
	Vector3 origin;
	Vector3 diff;
};

struct Triangle {
	Vector3 vertices[3];
	float distance;
};

struct AABB {
	Vector3 min;
	Vector3 max;
};

// 加算
Vector3 Add(const Vector3& v1, const Vector3& v2);
// 減算
Vector3 Subtract(const Vector3& v1, const Vector3& v2);
// スカラー倍
Vector3 Multiply(float scalar, const Vector3& v);
// 内積
float Dot(const Vector3& v1, const Vector3& v2);
// 長さ (ノルム)
float Length(const Vector3& v);
// 正規化
Vector3 Normalize(const Vector3& v);

// 行列の加法
Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2);
// 行列の減法
Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2);
// 行列の積
Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);
// 逆行列
Matrix4x4 Inverse(const Matrix4x4& matrix);
// 転置行列
Matrix4x4 Transpose(const Matrix4x4& matrix);
// 単位行列の作成
Matrix4x4 MakeIdentity4x4();

float Determinant3x3(
	float a11, float a12, float a13,
	float a21, float a22, float a23,
	float a31, float a32, float a33);

/// <summary>
/// 平行移動行列関数
/// </summary>
/// <param name="translate">方向</param>
/// <returns>平行移動行列</returns>
Matrix4x4 MakeTranslateMatrix(const Vector3& translate);

/// <summary>
/// 拡大縮小行列関数
/// </summary>
/// <param name="scale">スケール</param>
/// <returns>拡大縮小行列</returns>
Matrix4x4 MakeScaleMatrix(const Vector3& scale);

/// <summary>
/// 座標変換関数
/// </summary>
/// <param name="vector">ベクトル</param>
/// <param name="matrix">行列</param>
/// <returns>(3+1)次元同次座標系</returns>
Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix);

/// <summary>
/// X軸回転行列関数
/// </summary>
/// <param name="radian">ラジアン</param>
/// <returns>X軸回転行列</returns>
Matrix4x4 MakeRotateXMatrix(float radian);

/// <summary>
/// Y軸回転行列関数
/// </summary>
/// <param name="radian">ラジアン</param>
/// <returns>Y軸回転行列</returns>
Matrix4x4 MakeRotateYMatrix(float radian);

/// <summary>
/// Z軸回転行列関数
/// </summary>
/// <param name="radian">ラジアン</param>
/// <returns>Z軸回転行列</returns>
Matrix4x4 MakeRotateZMatrix(float radian);

/// <summary>
/// 3次元アフィン変換行列
/// </summary>
/// <param name="scale">拡縮行列</param>
/// <param name="rotate">回転行列</param>
/// <param name="translate">平行移動行列</param>
/// <returns></returns>
Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);

/// <summary>
/// 正射影行列の作成関数
/// </summary>
/// <param name="left">左上のX座標</param>
/// <param name="top">左上のY座標</param>
/// <param name="right">右下のX座標</param>
/// <param name="bottom">右下のY座標</param>
/// <returns>正射影行列</returns>
Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip);

/// <summary>
/// 透視投影行列の作成関数
/// </summary>
/// <param name="fovY">画角Y</param>
/// <param name="aspectRatio">アスペクト比</param>
/// <param name="nearClip">近平面への距離</param>
/// <param name="farClip">遠平面への距離</param>
/// <returns>透視投影行列</returns>
Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip);

/// <summary>
/// ビューポートに変換する関数
/// </summary>
/// <param name="left">左上のX座標</param>
/// <param name="top">左上のY座標</param>
/// <param name="width">右下のX座標</param>
/// <param name="height">右下のY座標</param>
/// <param name="minDepth">最小深度値</param>
/// <param name="maxDepth">最大深度値</param>
/// <returns>ビューポート行列</returns>
Matrix4x4 MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth);

/// <summary>
/// クロス積を求める関数
/// </summary>
/// <param name="v1">1つ目のベクター</param>
/// <param name="v2">2つ目のベクター</param>
/// <returns>クロス積</returns>
Vector3 Cross(const Vector3& v1, const Vector3& v2);

/// <summary>
/// 正射影ベクトルを求める関数
/// </summary>
/// <param name="v1">ベクトル1</param>
/// <param name="v2">ベクトル2</param>
/// <returns></returns>
Vector3 Project(const Vector3& v1, const Vector3& v2);

/// <summary>
/// 最近接点を求める関数
/// </summary>
/// <param name="point">ポイント</param>
/// <param name="segment">セグメント</param>
/// <returns></returns>
Vector3 ClosestPoint(const Vector3& point, const Segment& segment);

/// <summary>
/// ベクトルに直交するベクトルを計算する関数
/// </summary>
/// <param name="vector">ベクトル</param>
/// <returns>trueかfalseか</returns>
Vector3 Perpendicular(const Vector3& vector);

/// <summary>
/// 球同士の当たり判定を返す関数
/// </summary>
/// <param name="s1">球1</param>
/// <param name="s2">球2</param>
/// <returns>trueかfalseか</returns>
bool IsCollision(const Sphere& s1, const Sphere& s2);

/// <summary>
/// 球と平面の当たり判定を返す関数
/// </summary>
/// <param name="sphere">球</param>
/// <param name="plane">平面</param>
/// <returns>trueかfalseか</returns>
bool IsCollision(const Sphere& sphere, const Plane& plane);

/// <summary>
/// 球と平面の当たり判定を返す関数
/// </summary>
/// <param name="line">線</param>
/// <param name="plane">平面</param>
/// <returns>trueかfalseか</returns>
bool IsCollision(const Segment& line, const Plane& plane);

/// <summary>
/// 三角形と線の当たり判定を返す関数
/// </summary>
/// <param name="triangle">三角形</param>
/// <param name="segment">線</param>
/// <returns>trueかfalseか</returns>
bool IsCollision(const Triangle& triangle, const Segment& segment);

/// <summary>
/// ボックス同士の当たり判定を返す関数
/// </summary>
/// <param name="aabb1">ボックス1</param>
/// <param name="aabb2">ボックス2</param>
/// <returns>trueかfalseか</returns>
bool IsCollision(const AABB& aabb1, const AABB& aabb2);

/// <summary>
/// ボックスと球の当たり判定を返す関数
/// </summary>
/// <param name="aabb">ボックス</param>
/// <param name="sphere">球</param>
/// <returns>trueかfalseか</returns>
bool IsCollision(const AABB& aabb, const Sphere& sphere);

/// <summary>
/// aabbとsegmentの当たり判定を返す関数
///</summary>
///<param name="aabb">ボックス</param>
///<param name="segment">線</param>
///<returns>trueかfalseか</returns>
bool IsCollision(const AABB& aabb, const Segment& segment);

/// <summary>
/// 円同士の当たり判定を返す関数
/// </summary>
/// <param name="startPos">始まりの座標</param>
/// <param name="targetPos">対象の座標</param>
/// <param name="radius1">円1</param>
/// <param name="radius2">円2</param>
/// <returns>trueかfalseか</returns>
bool IsCollision(const Vector2& startPos, const Vector2& targetPos, const float radius1, const float radius2);

/// <summary>
/// 線形補間関数
/// </summary>
/// <param name="v1">point1</param>
/// <param name="v2">point2</param>
/// <param name="t">補間係数</param>
/// <returns>補間結果</returns>
inline Vector3 Lerp(const Vector3& v1, const Vector3& v2, float t);

/// <summary>
/// イージング
/// </summary>
/// <param name="t"></param>
/// <returns></returns>
inline float EaseInOut(float t);

/// <summary>
/// サイン波アニメーション
/// </summary>
/// <param name="time"></param>
/// <param name="speed"></param>
/// <param name="amplitude"></param>
/// <returns></returns>
inline float SineWave(float time, float speed, float amplitude);

/// <summary>
/// 往復運動
/// </summary>
/// <param name="time"></param>
/// <param name="length"></param>
/// <returns></returns>
inline float PingPong(float time, float length);

// オペレーター
Vector3 operator+(const Vector3& v1, const Vector3& v2);

Vector3 operator-(const Vector3& v1, const Vector3& v2);

Vector3 operator*(const Vector3& v1, const Vector3& v2);

Vector3 operator*(float s, const Vector3& v);

Vector3 operator*(const Vector3& v, float s);

Vector3 operator/(const Vector3& v, float s);

Matrix4x4 operator+(const Matrix4x4& m1, const Matrix4x4& m2);

Matrix4x4 operator-(const Matrix4x4& m1, const Matrix4x4& m2);

Matrix4x4 operator*(const Matrix4x4& m1, const Matrix4x4& m2);

Matrix4x4 operator+(const Matrix4x4& m1, const Matrix4x4& m2);

Matrix4x4 operator-(const Matrix4x4& m1, const Matrix4x4& m2);

Matrix4x4 operator*(const Matrix4x4& m1, const Matrix4x4& m2);
