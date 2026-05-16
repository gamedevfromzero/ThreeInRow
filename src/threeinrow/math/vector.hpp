#pragma once 
#include <cmath>
#include <cstdint>


template<typename T> class Vec2;
template<typename T> class Vec3;
template<typename T> class Vec4;

using Vec2f = Vec2<float>;
using Vec3f = Vec3<float>;
using Vec4f = Vec4<float>;

using Vec2i = Vec2<std::int32_t>;
using Vec3i = Vec3<std::int32_t>;
using Vec4i = Vec4<std::int32_t>;

using Vec2u = Vec2<std::uint32_t>;
using Vec3u = Vec3<std::uint32_t>;
using Vec4u = Vec4<std::uint32_t>;

//.//.//.//.//.//.//
//                //
//    VECTOR 2    //
//                //
//.//.//.//.//.//.//

template<typename T>
class Vec2
{
public:
	union
	{
		T x;
		T r;
	};
	union
	{
		T y;
		T g;
	};

	// constructors 
	Vec2<T>()
		: x(0), y(0)
	{

	}
	Vec2<T>(T x, T y)
		: x(x), y(y)
	{

	}
	Vec2<T>(const Vec2<T>& vector)
	{
		x = vector.x;
		y = vector.y;
	}
	Vec2<T>(Vec2<T>&& vector)
	{
		x = vector.x;
		y = vector.y;
	}
	Vec2<T>& operator = (const Vec2<T>& vector)
	{
		x = vector.x;
		y = vector.y;
		return *this;
	}
	Vec2<T>& operator = (Vec2<T>&& vector)
	{
		x = vector.x;
		y = vector.y;
		return *this;
	}
	
	// negation operator
	Vec2<T> operator - ()
	{
		return Vec2<T>(-x, -y);
	}

	// arithmetical operators
	Vec2<T> operator + (const Vec2<T>& vector)
	{
		return Vec2<T>(x + vector.x, y + vector.y);
	}
	Vec2<T> operator - (const Vec2<T>& vector)
	{
		return Vec2<T>(x - vector.x, y - vector.y);
	}
	Vec2<T> operator * (T scalar)
	{
		return Vec2<T>(x * scalar, y * scalar);
	}
	Vec2<T>& operator += (const Vec2<T>& vector)
	{
		x += vector.x;
		y += vector.y;
		return *this;
	}
	Vec2<T>& operator -= (const Vec2<T>& vector)
	{
		x -= vector.x;
		y -= vector.y;
		return *this;
	}
	Vec2<T>& operator *= (T scalar)
	{
		x *= scalar;
		y *= scalar;
		return *this;
	}

	// comparison operators
	bool operator == (const Vec2<T>& vector) const
	{
		return ((x = vector.x) && (y == vector.y));
	}
	bool operator != (const Vec2<T>& vector) const
	{
		return !((x = vector.x) && (y == vector.y));
	}

	// mathematical methods
	T length()
	{
		return std::sqrt(x * x + y * y);
	}
	Vec2<T> normalize()
	{
		T vectorLength = length();
		if (vectorLength == 0)
		{
			return Vec2<T>();
		}
		return Vec2<T>(x / vectorLength, y / vectorLength);
	}
	Vec2<T> dot(const Vec2<T>& vector)
	{
		return Vec2(x * vector.x + y * vector.y);
	}
	Vec2<T> dot(Vec2<T>&& vector)
	{
		return Vec2(x * vector.x + y * vector.y);
	}
	T cross(const Vec2<T>& vector)
	{
		return x * vector.y - y * vector.x;
	}
	T cross(Vec2<T>&& vector)
	{
		return x * vector.y - y * vector.x;
	}

	// syntax sugar for inline Vector manipulations 
	// Vec2
	inline Vec2<T> xy() { return Vec2<T>(x, y); }
	inline Vec2<T> xx() { return Vec2<T>(x, x); }
	inline Vec2<T> yx() { return Vec2<T>(y, x); }
	inline Vec2<T> yy() { return Vec2<T>(y, y); }
	
	// Vector 3
	inline Vec3<T> xxx() { return Vec3<T>(x, x, x); }
	inline Vec3<T> xxy() { return Vec3<T>(x, x, y); }
	inline Vec3<T> xyx() { return Vec3<T>(x, y, x); }
	inline Vec3<T> xyy() { return Vec3<T>(x, y, y); }
	inline Vec3<T> yxx() { return Vec3<T>(y, x, x); }
	inline Vec3<T> yxy() { return Vec3<T>(y, x, y); }
	inline Vec3<T> yyx() { return Vec3<T>(y, y, x); }
	inline Vec3<T> yyy() { return Vec3<T>(y, y, y); }
	// Vector 4	  
	inline Vec4<T> xxxx() { return Vec4<T>(x, x, x, x); }
	inline Vec4<T> xxxy() { return Vec4<T>(x, x, x, y); }
	inline Vec4<T> xxyx() { return Vec4<T>(x, x, y, x); }
	inline Vec4<T> xxyy() { return Vec4<T>(x, x, y, y); }
	inline Vec4<T> xyxx() { return Vec4<T>(x, y, x, x); }
	inline Vec4<T> xyxy() { return Vec4<T>(x, y, x, y); }
	inline Vec4<T> xyyx() { return Vec4<T>(x, y, y, x); }
	inline Vec4<T> xyyy() { return Vec4<T>(x, y, y, y); }
	inline Vec4<T> yxxx() { return Vec4<T>(y, x, x, x); }
	inline Vec4<T> yxxy() { return Vec4<T>(y, x, x, y); }
	inline Vec4<T> yxyx() { return Vec4<T>(y, x, y, x); }
	inline Vec4<T> yxyy() { return Vec4<T>(y, x, y, y); }
	inline Vec4<T> yyxx() { return Vec4<T>(y, y, x, x); }
	inline Vec4<T> yyxy() { return Vec4<T>(y, y, x, y); }
	inline Vec4<T> yyyx() { return Vec4<T>(y, y, y, x); }
	inline Vec4<T> yyyy() { return Vec4<T>(y, y, y, y); }
};


//.//.//.//.//.//.//
//                //
//    VECTOR 3    //
//                //
//.//.//.//.//.//.//

template<typename T>
class Vec3
{
public:
	union
	{
		T x;
		T r;
	};
	union
	{
		T y;
		T g;
	};
	union
	{
		T z;
		T b;
	};

	// constructors
	Vec3<T>()
		: x(0), y(0), z(0)
	{

	}
	Vec3<T>(T x, T y, T z)
		: x(x), y(y), z(z)
	{

	}
	Vec3<T>(Vec2<T> vector, T z)
		: x(vector.x), y(vector.y), z(z)
	{

	}
	Vec3<T>(T x, Vec2<T> vector)
		: x(x), y(vector.x), z(vector.y)
	{

	}
	Vec3<T>(const Vec3<T>& vector)
	{
		x = vector.x;
		y = vector.y;
		z = vector.z;
	}
	Vec3<T>(Vec3&& vector)
	{
		x = vector.x;
		y = vector.y;
		z = vector.z;
	}
	Vec3<T>& operator = (const Vec3<T>& vector)
	{
		x = vector.x;
		y = vector.y;
		z = vector.z;
		return *this;
	}
	Vec3<T>& operator = (Vec3<T>&& vector)
	{
		x = vector.x;
		y = vector.y;
		z = vector.z;
		return *this;
	}

	// negation operator
	Vec3<T> operator - ()
	{
		return Vec3<T>(-x, -y, -z);
	}

	// arithmetical operators
	Vec3<T> operator + (const Vec3<T>& vector)
	{
		return Vec3<T>(x + vector.x, y + vector.y, z + vector.z);
	}
	Vec3<T> operator - (const Vec3<T>& vector)
	{
		return Vec3(x - vector.x, y - vector.y, z - vector.z);
	}
	Vec3<T> operator * (T scalar)
	{
		return Vec3(x * scalar, y * scalar, z * scalar);
	}
	Vec3<T>& operator += (const Vec3<T>& vector)
	{
		x += vector.x;
		y += vector.y;
		z += vector.z;
		return *this;
	}
	Vec3<T>& operator -= (const Vec3<T>& vector)
	{
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;
		return *this;
	}
	Vec3<T>& operator *= (T scalar)
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;
		return *this;
	}

	// comparison operators
	bool operator == (const Vec3<T>& vector) const
	{
		return ((x = vector.x) && (y == vector.y) && (z == vector.z));
	}
	bool operator != (const Vec3<T>& vector) const
	{
		return !((x = vector.x) && (y == vector.y) && (z == vector.z));
	}

	// mathematical methods
	T length()
	{
		return std::sqrt(x * x + y * y + z * z);
	}
	Vec3<T> normalize()
	{
		T vectorLength = length();
		if (vectorLength == 0)
		{
			return Vec3<T>();
		}
		return Vec3<T>(x / vectorLength, y / vectorLength, z / vectorLength);
	}
	Vec3<T> dot(const Vec3& vector)
	{
		return Vec3<T>(x * vector.x + y * vector.y + z * vector.z);
	}
	Vec3<T> dot(Vec3<T>&& vector)
	{
		return Vec3<T>(x * vector.x + y * vector.y + z * vector.z);
	}
	Vec3<T> cross(const Vec3<T>& vector)
	{
		return Vec3<T>(
			y * vector.z - z * vector.y,
			z * vector.x - x * vector.z,
			x * vector.y - y * vector.x
		);
	}
	Vec3<T> cross(Vec3<T>&& vector)
	{
		return Vec3<T>(
			y * vector.z - z * vector.y,
			z * vector.x - x * vector.z,
			x * vector.y - y * vector.x
		);
	}

	// syntax sugar for inline Vector manipulations 
	// Vec2
	inline Vec2<T> xx() { return Vec2<T>(x, x); }
	inline Vec2<T> xy() { return Vec2<T>(x, y); }
	inline Vec2<T> xz() { return Vec2<T>(x, z); }
	inline Vec2<T> yx() { return Vec2<T>(y, x); }
	inline Vec2<T> yy() { return Vec2<T>(y, y); }
	inline Vec2<T> yz() { return Vec2<T>(y, z); }
	inline Vec2<T> zx() { return Vec2<T>(z, x); }
	inline Vec2<T> zy() { return Vec2<T>(z, y); }
	inline Vec2<T> zz() { return Vec2<T>(z, z); }
	// Vec3
	// starting with x
	inline Vec3<T> xxx() { return Vec3<T>(x, x, x); }
	inline Vec3<T> xxy() { return Vec3<T>(x, x, y); }
	inline Vec3<T> xxz() { return Vec3<T>(x, x, z); }
	inline Vec3<T> xyx() { return Vec3<T>(x, y, x); }
	inline Vec3<T> xyy() { return Vec3<T>(x, y, y); }
	inline Vec3<T> xyz() { return Vec3<T>(x, y, z); }
	inline Vec3<T> xzx() { return Vec3<T>(x, z, x); }
	inline Vec3<T> xzy() { return Vec3<T>(x, z, y); }
	inline Vec3<T> xzz() { return Vec3<T>(x, z, z); }
	// starting with y
	inline Vec3<T> yxx() { return Vec3<T>(y, x, x); }
	inline Vec3<T> yxy() { return Vec3<T>(y, x, y); }
	inline Vec3<T> yxz() { return Vec3<T>(y, x, z); }
	inline Vec3<T> yyx() { return Vec3<T>(y, y, x); }
	inline Vec3<T> yyy() { return Vec3<T>(y, y, y); }
	inline Vec3<T> yyz() { return Vec3<T>(y, y, z); }
	inline Vec3<T> yzx() { return Vec3<T>(y, z, x); }
	inline Vec3<T> yzy() { return Vec3<T>(y, z, y); }
	inline Vec3<T> yzz() { return Vec3<T>(y, z, z); }
	// starting with z
	inline Vec3<T> zxx() { return Vec3<T>(z, x, x); }
	inline Vec3<T> zxy() { return Vec3<T>(z, x, y); }
	inline Vec3<T> zxz() { return Vec3<T>(z, x, z); }
	inline Vec3<T> zyx() { return Vec3<T>(z, y, x); }
	inline Vec3<T> zyy() { return Vec3<T>(z, y, y); }
	inline Vec3<T> zyz() { return Vec3<T>(z, y, z); }
	inline Vec3<T> zzx() { return Vec3<T>(z, z, x); }
	inline Vec3<T> zzy() { return Vec3<T>(z, z, y); }
	inline Vec3<T> zzz() { return Vec3<T>(z, z, z); }
	
	// Vec4
	// starting with x 
	inline Vec4<T> xxxx() { return Vec4<T>(x, x, x, x); }
	inline Vec4<T> xxxy() { return Vec4<T>(x, x, x, y); }
	inline Vec4<T> xxxz() { return Vec4<T>(x, x, x, z); }
	inline Vec4<T> xxyx() { return Vec4<T>(x, x, y, x); }
	inline Vec4<T> xxyy() { return Vec4<T>(x, x, y, y); }
	inline Vec4<T> xxyz() { return Vec4<T>(x, x, y, z); }
	inline Vec4<T> xxzx() { return Vec4<T>(x, x, z, x); }
	inline Vec4<T> xxzy() { return Vec4<T>(x, x, z, y); }
	inline Vec4<T> xxzz() { return Vec4<T>(x, x, z, z); }
	inline Vec4<T> xyxx() { return Vec4<T>(x, y, x, x); }
	inline Vec4<T> xyxy() { return Vec4<T>(x, y, x, y); }
	inline Vec4<T> xyxz() { return Vec4<T>(x, y, x, z); }
	inline Vec4<T> xyyx() { return Vec4<T>(x, y, y, x); }
	inline Vec4<T> xyyy() { return Vec4<T>(x, y, y, y); }
	inline Vec4<T> xyzx() { return Vec4<T>(x, y, z, x); }
	inline Vec4<T> xyzy() { return Vec4<T>(x, y, z, y); }
	inline Vec4<T> xyzz() { return Vec4<T>(x, y, z, z); }
	inline Vec4<T> xzxx() { return Vec4<T>(x, z, x, x); }
	inline Vec4<T> xzxy() { return Vec4<T>(x, z, x, y); }
	inline Vec4<T> xzyx() { return Vec4<T>(x, z, y, x); }
	inline Vec4<T> xzyy() { return Vec4<T>(x, z, y, y); }
	inline Vec4<T> xzyz() { return Vec4<T>(x, z, y, z); }
	inline Vec4<T> xzzx() { return Vec4<T>(x, z, z, x); }
	inline Vec4<T> xzzy() { return Vec4<T>(x, z, z, y); }
	inline Vec4<T> xzzz() { return Vec4<T>(x, z, z, z); }
	// starting with y 
	inline Vec4<T> yxxx() { return Vec4<T>(y, x, x, x); }
	inline Vec4<T> yxxy() { return Vec4<T>(y, x, x, y); }
	inline Vec4<T> yxxz() { return Vec4<T>(y, x, x, z); }
	inline Vec4<T> yxyx() { return Vec4<T>(y, x, y, x); }
	inline Vec4<T> yxyy() { return Vec4<T>(y, x, y, y); }
	inline Vec4<T> yxyz() { return Vec4<T>(y, x, y, z); }
	inline Vec4<T> yxzx() { return Vec4<T>(y, x, z, x); }
	inline Vec4<T> yxzy() { return Vec4<T>(y, x, z, y); }
	inline Vec4<T> yxzz() { return Vec4<T>(y, x, z, z); }
	inline Vec4<T> yyxx() { return Vec4<T>(y, y, x, x); }
	inline Vec4<T> yyxy() { return Vec4<T>(y, y, x, y); }
	inline Vec4<T> yyxz() { return Vec4<T>(y, y, x, z); }
	inline Vec4<T> yyyx() { return Vec4<T>(y, y, y, x); }
	inline Vec4<T> yyyy() { return Vec4<T>(y, y, y, y); }
	inline Vec4<T> yyzx() { return Vec4<T>(y, y, z, x); }
	inline Vec4<T> yyzy() { return Vec4<T>(y, y, z, y); }
	inline Vec4<T> yyzz() { return Vec4<T>(y, y, z, z); }
	inline Vec4<T> yzxx() { return Vec4<T>(y, z, x, x); }
	inline Vec4<T> yzxy() { return Vec4<T>(y, z, x, y); }
	inline Vec4<T> yzyx() { return Vec4<T>(y, z, y, x); }
	inline Vec4<T> yzyy() { return Vec4<T>(y, z, y, y); }
	inline Vec4<T> yzyz() { return Vec4<T>(y, z, y, z); }
	inline Vec4<T> yzzx() { return Vec4<T>(y, z, z, x); }
	inline Vec4<T> yzzy() { return Vec4<T>(y, z, z, y); }
	inline Vec4<T> yzzz() { return Vec4<T>(y, z, z, z); }
	// starting with z 
	inline Vec4<T> zxxx() { return Vec4<T>(z, x, x, x); }
	inline Vec4<T> zxxy() { return Vec4<T>(z, x, x, y); }
	inline Vec4<T> zxxz() { return Vec4<T>(z, x, x, z); }
	inline Vec4<T> zxyx() { return Vec4<T>(z, x, y, x); }
	inline Vec4<T> zxyy() { return Vec4<T>(z, x, y, y); }
	inline Vec4<T> zxyz() { return Vec4<T>(z, x, y, z); }
	inline Vec4<T> zxzx() { return Vec4<T>(z, x, z, x); }
	inline Vec4<T> zxzy() { return Vec4<T>(z, x, z, y); }
	inline Vec4<T> zxzz() { return Vec4<T>(z, x, z, z); }
	inline Vec4<T> zyxx() { return Vec4<T>(z, y, x, x); }
	inline Vec4<T> zyxy() { return Vec4<T>(z, y, x, y); }
	inline Vec4<T> zyxz() { return Vec4<T>(z, y, x, z); }
	inline Vec4<T> zyyx() { return Vec4<T>(z, y, y, x); }
	inline Vec4<T> zyyy() { return Vec4<T>(z, y, y, y); }
	inline Vec4<T> zyzx() { return Vec4<T>(z, y, z, x); }
	inline Vec4<T> zyzy() { return Vec4<T>(z, y, z, y); }
	inline Vec4<T> zyzz() { return Vec4<T>(z, y, z, z); }
	inline Vec4<T> zzxx() { return Vec4<T>(z, z, x, x); }
	inline Vec4<T> zzxy() { return Vec4<T>(z, z, x, y); }
	inline Vec4<T> zzyx() { return Vec4<T>(z, z, y, x); }
	inline Vec4<T> zzyy() { return Vec4<T>(z, z, y, y); }
	inline Vec4<T> zzyz() { return Vec4<T>(z, z, y, z); }
	inline Vec4<T> zzzx() { return Vec4<T>(z, z, z, x); }
	inline Vec4<T> zzzy() { return Vec4<T>(z, z, z, y); }
	inline Vec4<T> zzzz() { return Vec4<T>(z, z, z, z); }
};


//.//.//.//.//.//.//
//                //
//    VECTOR 4    //
//                //
//.//.//.//.//.//.//

template<typename T>
class Vec4
{
public:
	union
	{
		T x;
		T r;
	};
	union
	{
		T y;
		T g;
	};
	union
	{
		T z;
		T b;
	};
	union
	{
		T w;
		T a;
	};

	// constructors
	Vec4<T>()
		: x(0), y(0), z(0), w(0)
	{

	}
	Vec4<T>(T x, T y, T z, T w)
		: x(x), y(y), z(z), w(w)
	{

	}
	Vec4<T>(Vec2<T> vector, T z, T w)
		: x(vector.x), y(vector.y), z(z), w(w)
	{

	}
	Vec4(T x, Vec2<T> vector, T w)
		: x(x), y(vector.x), z(vector.y), w(w)
	{

	}
	Vec4<T>(T x, T y, Vec2<T> vector)
		: x(x), y(y), z(vector.x), w(vector.y)
	{

	}
	Vec4<T>(Vec2<T> vectorA, Vec2<T> vectorB)
		: x(vectorA.x), y(vectorA.y), z(vectorB.x), w(vectorB.y)
	{

	}
	Vec4<T>(Vec3<T> vector, T w)
		: x(vector.x), y(vector.y), z(vector.z), w(w)
	{

	}
	Vec4<T>(T x, Vec3<T> vector)
		: x(x), y(vector.x), z(vector.y), w(vector.z)
	{

	}
	Vec4<T>(const Vec4<T>& vector)
	{
		x = vector.x;
		y = vector.y;
		z = vector.z;
		w = vector.w;
	}
	Vec4<T>(Vec4<T>&& vector)
	{
		x = vector.x;
		y = vector.y;
		z = vector.z;
		w = vector.w;
	}
	Vec4<T>& operator = (const Vec4<T>& vector)
	{
		x = vector.x;
		y = vector.y;
		z = vector.z;
		w = vector.w;
		return *this;
	}
	Vec4<T>& operator = (Vec4<T>&& vector)
	{
		x = vector.x;
		y = vector.y;
		z = vector.z;
		w = vector.w;
		return *this;
	}

	// negation operator
	Vec4<T> operator - ()
	{
		return Vec4<T>(-x, -y, -z, -w);
	}

	// arithmetical operators
	Vec4<T> operator + (const Vec4<T>& vector)
	{
		return Vec4<T>(x + vector.x, y + vector.y, z + vector.z, w + vector.w);
	}
	Vec4<T> operator - (const Vec4<T>& vector)
	{
		return Vec4<T>(x - vector.x, y - vector.y, z - vector.z, w - vector.w);
	}
	Vec4<T> operator * (T scalar)
	{
		return Vec4<T>(x * scalar, y * scalar, z * scalar, w * scalar);
	}
	Vec4<T>& operator += (const Vec4<T>& vector)
	{
		x += vector.x;
		y += vector.y;
		z += vector.z;
		w += vector.w;
		return *this;
	}
	Vec4<T>& operator -= (const Vec4<T>& vector)
	{
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;
		w -= vector.w;
		return *this;
	}
	Vec4<T>& operator *= (T scalar)
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;
		w *= scalar;
		return *this;
	}

	// comparison operators
	bool operator == (const Vec4<T>& vector) const
	{
		return ((x = vector.x) && (y == vector.y) && (z == vector.z) && (w == vector.w));
	}
	bool operator != (const Vec4<T>& vector) const
	{
		return !((x = vector.x) && (y == vector.y) && (z == vector.z) && (w == vector.w));
	}

	// mathematical methods
	T length()
	{
		return std::sqrt(x * x + y * y + z * z + w * w);
	}
	Vec4<T> normalize()
	{
		T vectorLength = length();
		if (vectorLength == 0)
		{
			return Vec4<T>();
		}
		return Vec4<T>(x / vectorLength, y / vectorLength, z / vectorLength, w / vectorLength);
	}

	// syntax sugar for inline Vector manipulations 
	// Vec2
	inline Vec2<T> xx() { return Vec2<T>(x, x); }
	inline Vec2<T> xy() { return Vec2<T>(x, y); }
	inline Vec2<T> xz() { return Vec2<T>(x, z); }
	inline Vec2<T> xw() { return Vec2<T>(x, w); }
	inline Vec2<T> yx() { return Vec2<T>(y, x); }
	inline Vec2<T> yy() { return Vec2<T>(y, y); }
	inline Vec2<T> yz() { return Vec2<T>(y, z); }
	inline Vec2<T> yw() { return Vec2<T>(y, w); }
	inline Vec2<T> zx() { return Vec2<T>(z, x); }
	inline Vec2<T> zy() { return Vec2<T>(z, y); }
	inline Vec2<T> zz() { return Vec2<T>(z, z); }
	inline Vec2<T> zw() { return Vec2<T>(z, w); }
	inline Vec2<T> wx() { return Vec2<T>(w, x); }
	inline Vec2<T> wy() { return Vec2<T>(w, y); }
	inline Vec2<T> wz() { return Vec2<T>(w, z); }
	inline Vec2<T> ww() { return Vec2<T>(w, w); }
	// Vec3
	// starting with x 
	inline Vec3<T> xxx() { return Vec3<T>(x, x, x); }
	inline Vec3<T> xxy() { return Vec3<T>(x, x, y); }
	inline Vec3<T> xxz() { return Vec3<T>(x, x, z); }
	inline Vec3<T> xxw() { return Vec3<T>(x, x, w); }
	inline Vec3<T> xyx() { return Vec3<T>(x, y, x); }
	inline Vec3<T> xyy() { return Vec3<T>(x, y, y); }
	inline Vec3<T> xyz() { return Vec3<T>(x, y, z); }
	inline Vec3<T> xyw() { return Vec3<T>(x, y, w); }
	inline Vec3<T> xzx() { return Vec3<T>(x, z, x); }
	inline Vec3<T> xzy() { return Vec3<T>(x, z, y); }
	inline Vec3<T> xzz() { return Vec3<T>(x, z, z); }
	inline Vec3<T> xzw() { return Vec3<T>(x, z, w); }
	inline Vec3<T> xwx() { return Vec3<T>(x, w, x); }
	inline Vec3<T> xwy() { return Vec3<T>(x, w, y); }
	inline Vec3<T> xwz() { return Vec3<T>(x, w, z); }
	inline Vec3<T> xww() { return Vec3<T>(x, w, w); }
	// starting with y
	inline Vec3<T> yxx() { return Vec3<T>(y, x, x); }
	inline Vec3<T> yxy() { return Vec3<T>(y, x, y); }
	inline Vec3<T> yxz() { return Vec3<T>(y, x, z); }
	inline Vec3<T> yxw() { return Vec3<T>(y, x, w); }
	inline Vec3<T> yyx() { return Vec3<T>(y, y, x); }
	inline Vec3<T> yyy() { return Vec3<T>(y, y, y); }
	inline Vec3<T> yyz() { return Vec3<T>(y, y, z); }
	inline Vec3<T> yyw() { return Vec3<T>(y, y, w); }
	inline Vec3<T> yzx() { return Vec3<T>(y, z, x); }
	inline Vec3<T> yzy() { return Vec3<T>(y, z, y); }
	inline Vec3<T> yzz() { return Vec3<T>(y, z, z); }
	inline Vec3<T> yzw() { return Vec3<T>(y, z, w); }
	inline Vec3<T> ywx() { return Vec3<T>(y, w, x); }
	inline Vec3<T> ywy() { return Vec3<T>(y, w, y); }
	inline Vec3<T> ywz() { return Vec3<T>(y, w, z); }
	inline Vec3<T> yww() { return Vec3<T>(y, w, w); }
	// starting with z
	inline Vec3<T> zxx() { return Vec3<T>(z, x, x); }
	inline Vec3<T> zxy() { return Vec3<T>(z, x, y); }
	inline Vec3<T> zxz() { return Vec3<T>(z, x, z); }
	inline Vec3<T> zxw() { return Vec3<T>(z, x, w); }
	inline Vec3<T> zyx() { return Vec3<T>(z, y, x); }
	inline Vec3<T> zyy() { return Vec3<T>(z, y, y); }
	inline Vec3<T> zyz() { return Vec3<T>(z, y, z); }
	inline Vec3<T> zyw() { return Vec3<T>(z, y, w); }
	inline Vec3<T> zzx() { return Vec3<T>(z, z, x); }
	inline Vec3<T> zzy() { return Vec3<T>(z, z, y); }
	inline Vec3<T> zzz() { return Vec3<T>(z, z, z); }
	inline Vec3<T> zzw() { return Vec3<T>(z, z, w); }
	inline Vec3<T> zwx() { return Vec3<T>(z, w, x); }
	inline Vec3<T> zwy() { return Vec3<T>(z, w, y); }
	inline Vec3<T> zwz() { return Vec3<T>(z, w, z); }
	inline Vec3<T> zww() { return Vec3<T>(z, w, w); }
	// starting with w
	inline Vec3<T> wxx() { return Vec3<T>(w, x, x); }
	inline Vec3<T> wxy() { return Vec3<T>(w, x, y); }
	inline Vec3<T> wxz() { return Vec3<T>(w, x, z); }
	inline Vec3<T> wxw() { return Vec3<T>(w, x, w); }
	inline Vec3<T> wyx() { return Vec3<T>(w, y, x); }
	inline Vec3<T> wyy() { return Vec3<T>(w, y, y); }
	inline Vec3<T> wyz() { return Vec3<T>(w, y, z); }
	inline Vec3<T> wyw() { return Vec3<T>(w, y, w); }
	inline Vec3<T> wzx() { return Vec3<T>(w, z, x); }
	inline Vec3<T> wzy() { return Vec3<T>(w, z, y); }
	inline Vec3<T> wzz() { return Vec3<T>(w, z, z); }
	inline Vec3<T> wzw() { return Vec3<T>(w, z, w); }
	inline Vec3<T> wwx() { return Vec3<T>(w, w, x); }
	inline Vec3<T> wwy() { return Vec3<T>(w, w, y); }
	inline Vec3<T> wwz() { return Vec3<T>(w, w, z); }
	inline Vec3<T> www() { return Vec3<T>(w, w, w); }

	// Vec4
	// starting with x 
	inline Vec4<T> xxxx() { return Vec4<T>(x, x, x, x); }
	inline Vec4<T> xxxy() { return Vec4<T>(x, x, x, y); }
	inline Vec4<T> xxxz() { return Vec4<T>(x, x, x, z); }
	inline Vec4<T> xxxw() { return Vec4<T>(x, x, x, w); }
	inline Vec4<T> xxyx() { return Vec4<T>(x, x, y, x); }
	inline Vec4<T> xxyy() { return Vec4<T>(x, x, y, y); }
	inline Vec4<T> xxyz() { return Vec4<T>(x, x, y, z); }
	inline Vec4<T> xxyw() { return Vec4<T>(x, x, y, w); }
	inline Vec4<T> xxzx() { return Vec4<T>(x, x, z, x); }
	inline Vec4<T> xxzy() { return Vec4<T>(x, x, z, y); }
	inline Vec4<T> xxzz() { return Vec4<T>(x, x, z, z); }
	inline Vec4<T> xxzw() { return Vec4<T>(x, x, z, w); }
	inline Vec4<T> xxwx() { return Vec4<T>(x, x, w, x); }
	inline Vec4<T> xxwy() { return Vec4<T>(x, x, w, y); }
	inline Vec4<T> xxwz() { return Vec4<T>(x, x, w, z); }
	inline Vec4<T> xxww() { return Vec4<T>(x, x, w, w); }
	inline Vec4<T> xyxx() { return Vec4<T>(x, y, x, x); }
	inline Vec4<T> xyxy() { return Vec4<T>(x, y, x, y); }
	inline Vec4<T> xyxz() { return Vec4<T>(x, y, x, z); }
	inline Vec4<T> xyxw() { return Vec4<T>(x, y, x, w); }
	inline Vec4<T> xyyx() { return Vec4<T>(x, y, y, x); }
	inline Vec4<T> xyyy() { return Vec4<T>(x, y, y, y); }
	inline Vec4<T> xyyz() { return Vec4<T>(x, y, y, z); }
	inline Vec4<T> xyyw() { return Vec4<T>(x, y, y, w); }
	inline Vec4<T> xyzx() { return Vec4<T>(x, y, z, x); }
	inline Vec4<T> xyzy() { return Vec4<T>(x, y, z, y); }
	inline Vec4<T> xyzz() { return Vec4<T>(x, y, z, z); }
	inline Vec4<T> xyzw() { return Vec4<T>(x, y, z, w); }
	inline Vec4<T> xywx() { return Vec4<T>(x, y, w, x); }
	inline Vec4<T> xywy() { return Vec4<T>(x, y, w, y); }
	inline Vec4<T> xywz() { return Vec4<T>(x, y, w, z); }
	inline Vec4<T> xyww() { return Vec4<T>(x, y, w, w); }
	inline Vec4<T> xzxx() { return Vec4<T>(x, z, x, x); }
	inline Vec4<T> xzxy() { return Vec4<T>(x, z, x, y); }
	inline Vec4<T> xzxz() { return Vec4<T>(x, z, x, z); }
	inline Vec4<T> xzxw() { return Vec4<T>(x, z, x, w); }
	inline Vec4<T> xzyx() { return Vec4<T>(x, z, y, x); }
	inline Vec4<T> xzyy() { return Vec4<T>(x, z, y, y); }
	inline Vec4<T> xzyz() { return Vec4<T>(x, z, y, z); }
	inline Vec4<T> xzyw() { return Vec4<T>(x, z, y, w); }
	inline Vec4<T> xzzx() { return Vec4<T>(x, z, z, x); }
	inline Vec4<T> xzzy() { return Vec4<T>(x, z, z, y); }
	inline Vec4<T> xzzz() { return Vec4<T>(x, z, z, z); }
	inline Vec4<T> xzzw() { return Vec4<T>(x, z, z, w); }
	inline Vec4<T> xzwx() { return Vec4<T>(x, z, w, x); }
	inline Vec4<T> xzwy() { return Vec4<T>(x, z, w, y); }
	inline Vec4<T> xzwz() { return Vec4<T>(x, z, w, z); }
	inline Vec4<T> xzww() { return Vec4<T>(x, z, w, w); }
	inline Vec4<T> xwxx() { return Vec4<T>(x, w, x, x); }
	inline Vec4<T> xwxy() { return Vec4<T>(x, w, x, y); }
	inline Vec4<T> xwxz() { return Vec4<T>(x, w, x, z); }
	inline Vec4<T> xwxw() { return Vec4<T>(x, w, x, w); }
	inline Vec4<T> xwyx() { return Vec4<T>(x, w, y, x); }
	inline Vec4<T> xwyy() { return Vec4<T>(x, w, y, y); }
	inline Vec4<T> xwyz() { return Vec4<T>(x, w, y, z); }
	inline Vec4<T> xwyw() { return Vec4<T>(x, w, y, w); }
	inline Vec4<T> xwzx() { return Vec4<T>(x, w, z, x); }
	inline Vec4<T> xwzy() { return Vec4<T>(x, w, z, y); }
	inline Vec4<T> xwzz() { return Vec4<T>(x, w, z, z); }
	inline Vec4<T> xwzw() { return Vec4<T>(x, w, z, w); }
	inline Vec4<T> xwwx() { return Vec4<T>(x, w, w, x); }
	inline Vec4<T> xwwy() { return Vec4<T>(x, w, w, y); }
	inline Vec4<T> xwwz() { return Vec4<T>(x, w, w, z); }
	inline Vec4<T> xwww() { return Vec4<T>(x, w, w, w); }
	// starting with y
	inline Vec4<T> yxxx() { return Vec4<T>(y, x, x, x); }
	inline Vec4<T> yxxy() { return Vec4<T>(y, x, x, y); }
	inline Vec4<T> yxxz() { return Vec4<T>(y, x, x, z); }
	inline Vec4<T> yxxw() { return Vec4<T>(y, x, x, w); }
	inline Vec4<T> yxyx() { return Vec4<T>(y, x, y, x); }
	inline Vec4<T> yxyy() { return Vec4<T>(y, x, y, y); }
	inline Vec4<T> yxyz() { return Vec4<T>(y, x, y, z); }
	inline Vec4<T> yxyw() { return Vec4<T>(y, x, y, w); }
	inline Vec4<T> yxzx() { return Vec4<T>(y, x, z, x); }
	inline Vec4<T> yxzy() { return Vec4<T>(y, x, z, y); }
	inline Vec4<T> yxzz() { return Vec4<T>(y, x, z, z); }
	inline Vec4<T> yxzw() { return Vec4<T>(y, x, z, w); }
	inline Vec4<T> yxwx() { return Vec4<T>(y, x, w, x); }
	inline Vec4<T> yxwy() { return Vec4<T>(y, x, w, y); }
	inline Vec4<T> yxwz() { return Vec4<T>(y, x, w, z); }
	inline Vec4<T> yxww() { return Vec4<T>(y, x, w, w); }
	inline Vec4<T> yyxx() { return Vec4<T>(y, y, x, x); }
	inline Vec4<T> yyxy() { return Vec4<T>(y, y, x, y); }
	inline Vec4<T> yyxz() { return Vec4<T>(y, y, x, z); }
	inline Vec4<T> yyxw() { return Vec4<T>(y, y, x, w); }
	inline Vec4<T> yyyx() { return Vec4<T>(y, y, y, x); }
	inline Vec4<T> yyyy() { return Vec4<T>(y, y, y, y); }
	inline Vec4<T> yyyz() { return Vec4<T>(y, y, y, z); }
	inline Vec4<T> yyyw() { return Vec4<T>(y, y, y, w); }
	inline Vec4<T> yyzx() { return Vec4<T>(y, y, z, x); }
	inline Vec4<T> yyzy() { return Vec4<T>(y, y, z, y); }
	inline Vec4<T> yyzz() { return Vec4<T>(y, y, z, z); }
	inline Vec4<T> yyzw() { return Vec4<T>(y, y, z, w); }
	inline Vec4<T> yywx() { return Vec4<T>(y, y, w, x); }
	inline Vec4<T> yywy() { return Vec4<T>(y, y, w, y); }
	inline Vec4<T> yywz() { return Vec4<T>(y, y, w, z); }
	inline Vec4<T> yyww() { return Vec4<T>(y, y, w, w); }
	inline Vec4<T> yzxx() { return Vec4<T>(y, z, x, x); }
	inline Vec4<T> yzxy() { return Vec4<T>(y, z, x, y); }
	inline Vec4<T> yzxz() { return Vec4<T>(y, z, x, z); }
	inline Vec4<T> yzxw() { return Vec4<T>(y, z, x, w); }
	inline Vec4<T> yzyx() { return Vec4<T>(y, z, y, x); }
	inline Vec4<T> yzyy() { return Vec4<T>(y, z, y, y); }
	inline Vec4<T> yzyz() { return Vec4<T>(y, z, y, z); }
	inline Vec4<T> yzyw() { return Vec4<T>(y, z, y, w); }
	inline Vec4<T> yzzx() { return Vec4<T>(y, z, z, x); }
	inline Vec4<T> yzzy() { return Vec4<T>(y, z, z, y); }
	inline Vec4<T> yzzz() { return Vec4<T>(y, z, z, z); }
	inline Vec4<T> yzzw() { return Vec4<T>(y, z, z, w); }
	inline Vec4<T> yzwx() { return Vec4<T>(y, z, w, x); }
	inline Vec4<T> yzwy() { return Vec4<T>(y, z, w, y); }
	inline Vec4<T> yzwz() { return Vec4<T>(y, z, w, z); }
	inline Vec4<T> yzww() { return Vec4<T>(y, z, w, w); }
	inline Vec4<T> ywxx() { return Vec4<T>(y, w, x, x); }
	inline Vec4<T> ywxy() { return Vec4<T>(y, w, x, y); }
	inline Vec4<T> ywxz() { return Vec4<T>(y, w, x, z); }
	inline Vec4<T> ywxw() { return Vec4<T>(y, w, x, w); }
	inline Vec4<T> ywyx() { return Vec4<T>(y, w, y, x); }
	inline Vec4<T> ywyy() { return Vec4<T>(y, w, y, y); }
	inline Vec4<T> ywyz() { return Vec4<T>(y, w, y, z); }
	inline Vec4<T> ywyw() { return Vec4<T>(y, w, y, w); }
	inline Vec4<T> ywzx() { return Vec4<T>(y, w, z, x); }
	inline Vec4<T> ywzy() { return Vec4<T>(y, w, z, y); }
	inline Vec4<T> ywzz() { return Vec4<T>(y, w, z, z); }
	inline Vec4<T> ywzw() { return Vec4<T>(y, w, z, w); }
	inline Vec4<T> ywwx() { return Vec4<T>(y, w, w, x); }
	inline Vec4<T> ywwy() { return Vec4<T>(y, w, w, y); }
	inline Vec4<T> ywwz() { return Vec4<T>(y, w, w, z); }
	inline Vec4<T> ywww() { return Vec4<T>(y, w, w, w); }
	// starting with z
	inline Vec4<T> zxxx() { return Vec4<T>(z, x, x, x); }
	inline Vec4<T> zxxy() { return Vec4<T>(z, x, x, y); }
	inline Vec4<T> zxxz() { return Vec4<T>(z, x, x, z); }
	inline Vec4<T> zxxw() { return Vec4<T>(z, x, x, w); }
	inline Vec4<T> zxyx() { return Vec4<T>(z, x, y, x); }
	inline Vec4<T> zxyy() { return Vec4<T>(z, x, y, y); }
	inline Vec4<T> zxyz() { return Vec4<T>(z, x, y, z); }
	inline Vec4<T> zxyw() { return Vec4<T>(z, x, y, w); }
	inline Vec4<T> zxzx() { return Vec4<T>(z, x, z, x); }
	inline Vec4<T> zxzy() { return Vec4<T>(z, x, z, y); }
	inline Vec4<T> zxzz() { return Vec4<T>(z, x, z, z); }
	inline Vec4<T> zxzw() { return Vec4<T>(z, x, z, w); }
	inline Vec4<T> zxwx() { return Vec4<T>(z, x, w, x); }
	inline Vec4<T> zxwy() { return Vec4<T>(z, x, w, y); }
	inline Vec4<T> zxwz() { return Vec4<T>(z, x, w, z); }
	inline Vec4<T> zxww() { return Vec4<T>(z, x, w, w); }
	inline Vec4<T> zyxx() { return Vec4<T>(z, y, x, x); }
	inline Vec4<T> zyxy() { return Vec4<T>(z, y, x, y); }
	inline Vec4<T> zyxz() { return Vec4<T>(z, y, x, z); }
	inline Vec4<T> zyxw() { return Vec4<T>(z, y, x, w); }
	inline Vec4<T> zyyx() { return Vec4<T>(z, y, y, x); }
	inline Vec4<T> zyyy() { return Vec4<T>(z, y, y, y); }
	inline Vec4<T> zyyz() { return Vec4<T>(z, y, y, z); }
	inline Vec4<T> zyyw() { return Vec4<T>(z, y, y, w); }
	inline Vec4<T> zyzx() { return Vec4<T>(z, y, z, x); }
	inline Vec4<T> zyzy() { return Vec4<T>(z, y, z, y); }
	inline Vec4<T> zyzz() { return Vec4<T>(z, y, z, z); }
	inline Vec4<T> zyzw() { return Vec4<T>(z, y, z, w); }
	inline Vec4<T> zywx() { return Vec4<T>(z, y, w, x); }
	inline Vec4<T> zywy() { return Vec4<T>(z, y, w, y); }
	inline Vec4<T> zywz() { return Vec4<T>(z, y, w, z); }
	inline Vec4<T> zyww() { return Vec4<T>(z, y, w, w); }
	inline Vec4<T> zzxx() { return Vec4<T>(z, z, x, x); }
	inline Vec4<T> zzxy() { return Vec4<T>(z, z, x, y); }
	inline Vec4<T> zzxz() { return Vec4<T>(z, z, x, z); }
	inline Vec4<T> zzxw() { return Vec4<T>(z, z, x, w); }
	inline Vec4<T> zzyx() { return Vec4<T>(z, z, y, x); }
	inline Vec4<T> zzyy() { return Vec4<T>(z, z, y, y); }
	inline Vec4<T> zzyz() { return Vec4<T>(z, z, y, z); }
	inline Vec4<T> zzyw() { return Vec4<T>(z, z, y, w); }
	inline Vec4<T> zzzx() { return Vec4<T>(z, z, z, x); }
	inline Vec4<T> zzzy() { return Vec4<T>(z, z, z, y); }
	inline Vec4<T> zzzz() { return Vec4<T>(z, z, z, z); }
	inline Vec4<T> zzzw() { return Vec4<T>(z, z, z, w); }
	inline Vec4<T> zzwx() { return Vec4<T>(z, z, w, x); }
	inline Vec4<T> zzwy() { return Vec4<T>(z, z, w, y); }
	inline Vec4<T> zzwz() { return Vec4<T>(z, z, w, z); }
	inline Vec4<T> zzww() { return Vec4<T>(z, z, w, w); }
	inline Vec4<T> zwxx() { return Vec4<T>(z, w, x, x); }
	inline Vec4<T> zwxy() { return Vec4<T>(z, w, x, y); }
	inline Vec4<T> zwxz() { return Vec4<T>(z, w, x, z); }
	inline Vec4<T> zwxw() { return Vec4<T>(z, w, x, w); }
	inline Vec4<T> zwyx() { return Vec4<T>(z, w, y, x); }
	inline Vec4<T> zwyy() { return Vec4<T>(z, w, y, y); }
	inline Vec4<T> zwyz() { return Vec4<T>(z, w, y, z); }
	inline Vec4<T> zwyw() { return Vec4<T>(z, w, y, w); }
	inline Vec4<T> zwzx() { return Vec4<T>(z, w, z, x); }
	inline Vec4<T> zwzy() { return Vec4<T>(z, w, z, y); }
	inline Vec4<T> zwzz() { return Vec4<T>(z, w, z, z); }
	inline Vec4<T> zwzw() { return Vec4<T>(z, w, z, w); }
	inline Vec4<T> zwwx() { return Vec4<T>(z, w, w, x); }
	inline Vec4<T> zwwy() { return Vec4<T>(z, w, w, y); }
	inline Vec4<T> zwwz() { return Vec4<T>(z, w, w, z); }
	inline Vec4<T> zwww() { return Vec4<T>(z, w, w, w); }
	// starting with w
	inline Vec4<T> wxxx() { return Vec4<T>(w, x, x, x); }
	inline Vec4<T> wxxy() { return Vec4<T>(w, x, x, y); }
	inline Vec4<T> wxxz() { return Vec4<T>(w, x, x, z); }
	inline Vec4<T> wxxw() { return Vec4<T>(w, x, x, w); }
	inline Vec4<T> wxyx() { return Vec4<T>(w, x, y, x); }
	inline Vec4<T> wxyy() { return Vec4<T>(w, x, y, y); }
	inline Vec4<T> wxyz() { return Vec4<T>(w, x, y, z); }
	inline Vec4<T> wxyw() { return Vec4<T>(w, x, y, w); }
	inline Vec4<T> wxzx() { return Vec4<T>(w, x, z, x); }
	inline Vec4<T> wxzy() { return Vec4<T>(w, x, z, y); }
	inline Vec4<T> wxzz() { return Vec4<T>(w, x, z, z); }
	inline Vec4<T> wxzw() { return Vec4<T>(w, x, z, w); }
	inline Vec4<T> wxwx() { return Vec4<T>(w, x, w, x); }
	inline Vec4<T> wxwy() { return Vec4<T>(w, x, w, y); }
	inline Vec4<T> wxwz() { return Vec4<T>(w, x, w, z); }
	inline Vec4<T> wxww() { return Vec4<T>(w, x, w, w); }
	inline Vec4<T> wyxx() { return Vec4<T>(w, y, x, x); }
	inline Vec4<T> wyxy() { return Vec4<T>(w, y, x, y); }
	inline Vec4<T> wyxz() { return Vec4<T>(w, y, x, z); }
	inline Vec4<T> wyxw() { return Vec4<T>(w, y, x, w); }
	inline Vec4<T> wyyx() { return Vec4<T>(w, y, y, x); }
	inline Vec4<T> wyyy() { return Vec4<T>(w, y, y, y); }
	inline Vec4<T> wyyz() { return Vec4<T>(w, y, y, z); }
	inline Vec4<T> wyyw() { return Vec4<T>(w, y, y, w); }
	inline Vec4<T> wyzx() { return Vec4<T>(w, y, z, x); }
	inline Vec4<T> wyzy() { return Vec4<T>(w, y, z, y); }
	inline Vec4<T> wyzz() { return Vec4<T>(w, y, z, z); }
	inline Vec4<T> wyzw() { return Vec4<T>(w, y, z, w); }
	inline Vec4<T> wywx() { return Vec4<T>(w, y, w, x); }
	inline Vec4<T> wywy() { return Vec4<T>(w, y, w, y); }
	inline Vec4<T> wywz() { return Vec4<T>(w, y, w, z); }
	inline Vec4<T> wyww() { return Vec4<T>(w, y, w, w); }
	inline Vec4<T> wzxx() { return Vec4<T>(w, z, x, x); }
	inline Vec4<T> wzxy() { return Vec4<T>(w, z, x, y); }
	inline Vec4<T> wzxz() { return Vec4<T>(w, z, x, z); }
	inline Vec4<T> wzxw() { return Vec4<T>(w, z, x, w); }
	inline Vec4<T> wzyx() { return Vec4<T>(w, z, y, x); }
	inline Vec4<T> wzyy() { return Vec4<T>(w, z, y, y); }
	inline Vec4<T> wzyz() { return Vec4<T>(w, z, y, z); }
	inline Vec4<T> wzyw() { return Vec4<T>(w, z, y, w); }
	inline Vec4<T> wzzx() { return Vec4<T>(w, z, z, x); }
	inline Vec4<T> wzzy() { return Vec4<T>(w, z, z, y); }
	inline Vec4<T> wzzz() { return Vec4<T>(w, z, z, z); }
	inline Vec4<T> wzzw() { return Vec4<T>(w, z, z, w); }
	inline Vec4<T> wzwx() { return Vec4<T>(w, z, w, x); }
	inline Vec4<T> wzwy() { return Vec4<T>(w, z, w, y); }
	inline Vec4<T> wzwz() { return Vec4<T>(w, z, w, z); }
	inline Vec4<T> wzww() { return Vec4<T>(w, z, w, w); }
	inline Vec4<T> wwxx() { return Vec4<T>(w, w, x, x); }
	inline Vec4<T> wwxy() { return Vec4<T>(w, w, x, y); }
	inline Vec4<T> wwxz() { return Vec4<T>(w, w, x, z); }
	inline Vec4<T> wwxw() { return Vec4<T>(w, w, x, w); }
	inline Vec4<T> wwyx() { return Vec4<T>(w, w, y, x); }
	inline Vec4<T> wwyy() { return Vec4<T>(w, w, y, y); }
	inline Vec4<T> wwyz() { return Vec4<T>(w, w, y, z); }
	inline Vec4<T> wwyw() { return Vec4<T>(w, w, y, w); }
	inline Vec4<T> wwzx() { return Vec4<T>(w, w, z, x); }
	inline Vec4<T> wwzy() { return Vec4<T>(w, w, z, y); }
	inline Vec4<T> wwzz() { return Vec4<T>(w, w, z, z); }
	inline Vec4<T> wwzw() { return Vec4<T>(w, w, z, w); }
	inline Vec4<T> wwwx() { return Vec4<T>(w, w, w, x); }
	inline Vec4<T> wwwy() { return Vec4<T>(w, w, w, y); }
	inline Vec4<T> wwwz() { return Vec4<T>(w, w, w, z); }
	inline Vec4<T> wwww() { return Vec4<T>(w, w, w, w); }
};