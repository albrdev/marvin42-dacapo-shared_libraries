#include "Vector3.hpp"
#include <cmath>

const Vector3 Vector3::Zero(0.0f, 0.0f, 0.0f);
const Vector3 Vector3::One(1.0f, 1.0f, 1.0f);

float Vector3::Distance(const Vector3& a, const Vector3& b)
{
    return (float)sqrt((a - b).GetMagnitude());
}

float Vector3::DotProduct(const Vector3& a, const Vector3& b)
{
    return Vector2::DotProduct(a, b) + (a.m_Z * b.m_Z);
}

Vector3 Vector3::CrossProduct(const Vector3& a, const Vector3& b)
{
    return Vector3((a.m_Y * b.m_Z) - (a.m_Z * b.m_Y), (a.m_Z * b.m_X) - (a.m_X * b.m_Z), Vector2::CrossProduct(a, b));
}

Vector3 Vector3::operator+(void)
{
    return Vector3(+m_X, +m_Y, +m_Z);
}

Vector3 Vector3::operator-(void)
{
    return Vector3(-m_X, -m_Y, -m_Z);
}

Vector3 Vector3::operator+(const Vector3& rhs) const
{
    return Vector3(m_X + rhs.m_X, m_Y + rhs.m_Y, m_Z + rhs.m_Z);
}

Vector3 Vector3::operator-(const Vector3& rhs) const
{
    return Vector3(m_X - rhs.m_X, m_Y - rhs.m_Y, m_Z - rhs.m_Z);
}

Vector3 Vector3::operator*(const Vector3& rhs) const
{
    return Vector3(m_X * rhs.m_X, m_Y * rhs.m_Y, m_Z * rhs.m_Z);
}

Vector3 Vector3::operator/(const Vector3& rhs) const
{
    return Vector3(m_X / rhs.m_X, m_Y / rhs.m_Y, m_Z / rhs.m_Z);
}

Vector3 Vector3::operator+(const float rhs) const
{
    return Vector3(m_X + rhs, m_Y + rhs, m_Z + rhs);
}

Vector3 Vector3::operator-(const float rhs) const
{
    return Vector3(m_X - rhs, m_Y - rhs, m_Z - rhs);
}

Vector3 Vector3::operator*(const float rhs) const
{
    return Vector3(m_X * rhs, m_Y * rhs, m_Z * rhs);
}

Vector3 Vector3::operator/(const float rhs) const
{
    return Vector3(m_X / rhs, m_Y / rhs, m_Z / rhs);
}

Vector3& Vector3::operator+=(const Vector3& rhs)
{
    m_X += rhs.m_X;
    m_Y += rhs.m_Y;
    m_Z += rhs.m_Z;

    return *this;
}

Vector3& Vector3::operator-=(const Vector3& rhs)
{
    m_X -= rhs.m_X;
    m_Y -= rhs.m_Y;
    m_Z -= rhs.m_Z;

    return *this;
}

Vector3& Vector3::operator*=(const Vector3& rhs)
{
    m_X *= rhs.m_X;
    m_Y *= rhs.m_Y;
    m_Z *= rhs.m_Z;

    return *this;
}

Vector3& Vector3::operator/=(const Vector3& rhs)
{
    m_X /= rhs.m_X;
    m_Y /= rhs.m_Y;
    m_Z /= rhs.m_Z;

    return *this;
}

Vector3& Vector3::operator+=(const float rhs)
{
    m_X += rhs;
    m_Y += rhs;
    m_Z += rhs;

    return *this;
}

Vector3& Vector3::operator-=(const float rhs)
{
    m_X -= rhs;
    m_Y -= rhs;
    m_Z -= rhs;

    return *this;
}

Vector3& Vector3::operator*=(const float rhs)
{
    m_X *= rhs;
    m_Y *= rhs;
    m_Z *= rhs;

    return *this;
}

Vector3& Vector3::operator/=(const float rhs)
{
    m_X /= rhs;
    m_Y /= rhs;
    m_Z /= rhs;

    return *this;
}

Vector3 Vector3::GetNormalized(void) const
{
    Vector3 result = *this;
    float magnitude = GetMagnitude();
    if(magnitude > 0.0f)
    {
        result /= magnitude;
    }

    return result;

}

float Vector3::GetSquareMagnitude(void) const
{
    return Vector2::GetSquareMagnitude() + (m_Z * m_Z);
}

float Vector3::GetZ(void) const
{
    return m_Z;
}

Vector3::Vector3(const float x, const float y, const float z) : Vector2(x, y)
{
    m_Z = z;
}

Vector3::Vector3(const Vector2& other)
{
    m_X = other.GetX();
    m_Y = other.GetY();
}

Vector3::Vector3(const Vector3& other) : Vector3(other.m_X, other.m_Y, other.m_Z) { }

Vector3::Vector3(void) : Vector2() { }
