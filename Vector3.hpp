#include "Vector2.hpp"

class Vector3 : public Vector2
{
protected:
    float m_Z = 0.0f;

public:
    const static Vector3 Zero;
    const static Vector3 One;

    static float Distance(const Vector3& a, const Vector3& b);
    static float DotProduct(const Vector3& a, const Vector3& b);
    static Vector3 CrossProduct(const Vector3& a, const Vector3& b);

    Vector3 operator+(void);
    Vector3 operator-(void);

    Vector3 operator+(const Vector3& rhs) const;
    Vector3 operator-(const Vector3& rhs) const;
    Vector3 operator*(const Vector3& rhs) const;
    Vector3 operator/(const Vector3& rhs) const;

    Vector3 operator+(const float rhs) const;
    Vector3 operator-(const float rhs) const;
    Vector3 operator*(const float rhs) const;
    Vector3 operator/(const float rhs) const;

    Vector3& operator+=(const Vector3& rhs);
    Vector3& operator-=(const Vector3& rhs);
    Vector3& operator*=(const Vector3& rhs);
    Vector3& operator/=(const Vector3& rhs);

    Vector3& operator+=(const float rhs);
    Vector3& operator-=(const float rhs);
    Vector3& operator*=(const float rhs);
    Vector3& operator/=(const float rhs);

    Vector3 GetNormalized(void) const;
    virtual float GetSquareMagnitude(void) const override;

    float GetZ(void) const;

    Vector3(const float x, const float y, const float z);
    Vector3(const Vector2& other);
    Vector3(const Vector3& other);
    Vector3(void);
};
