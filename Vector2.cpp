#include "Vector2.hpp"
#ifdef __AVR__
#include <math.h>
#else
#include <cmath>
#endif

const Vector2 Vector2::Zero(0.0f, 0.0f);
const Vector2 Vector2::One(1.0f, 1.0f);

float Vector2::Distance(const Vector2& a, const Vector2& b)
{
    return (float)sqrt((a - b).GetMagnitude());
}

float Vector2::DotProduct(const Vector2& a, const Vector2& b)
{
    return (a.m_X * b.m_X) + (a.m_Y * b.m_Y);
}

float Vector2::CrossProduct(const Vector2& a, const Vector2& b)
{
    return (a.m_X * b.m_Y) - (a.m_Y * b.m_X);
}

Vector2 Vector2::PerpendicularCW(const Vector2& value)
{
    return Vector2(value.m_Y, -value.m_X);
}

Vector2 Vector2::PerpendicularCCW(const Vector2& value)
{
    return Vector2(-value.m_Y, value.m_X);
}

Vector2 Vector2::operator+(void)
{
    return Vector2(+m_X, +m_Y);
}

Vector2 Vector2::operator-(void)
{
    return Vector2(-m_X, -m_Y);
}

Vector2 Vector2::operator+(const Vector2& rhs) const
{
    return Vector2(m_X + rhs.m_X, m_Y + rhs.m_Y);
}

Vector2 Vector2::operator-(const Vector2& rhs) const
{
    return Vector2(m_X - rhs.m_X, m_Y - rhs.m_Y);
}

Vector2 Vector2::operator*(const Vector2& rhs) const
{
    return Vector2(m_X * rhs.m_X, m_Y * rhs.m_Y);
}

Vector2 Vector2::operator/(const Vector2& rhs) const
{
    return Vector2(m_X / rhs.m_X, m_Y / rhs.m_Y);
}

Vector2 Vector2::operator+(const float rhs) const
{
    return Vector2(m_X + rhs, m_Y + rhs);
}

Vector2 Vector2::operator-(const float rhs) const
{
    return Vector2(m_X - rhs, m_Y - rhs);
}

Vector2 Vector2::operator*(const float rhs) const
{
    return Vector2(m_X * rhs, m_Y * rhs);
}

Vector2 Vector2::operator/(const float rhs) const
{
    return Vector2(m_X / rhs, m_Y / rhs);
}

Vector2& Vector2::operator+=(const Vector2& rhs)
{
    m_X += rhs.m_X;
    m_Y += rhs.m_Y;

    return *this;
}

Vector2& Vector2::operator-=(const Vector2& rhs)
{
    m_X -= rhs.m_X;
    m_Y -= rhs.m_Y;

    return *this;
}

Vector2& Vector2::operator*=(const Vector2& rhs)
{
    m_X *= rhs.m_X;
    m_Y *= rhs.m_Y;

    return *this;
}

Vector2& Vector2::operator/=(const Vector2& rhs)
{
    m_X /= rhs.m_X;
    m_Y /= rhs.m_Y;

    return *this;
}

Vector2& Vector2::operator+=(const float rhs)
{
    m_X += rhs;
    m_Y += rhs;

    return *this;
}

Vector2& Vector2::operator-=(const float rhs)
{
    m_X -= rhs;
    m_Y -= rhs;

    return *this;
}

Vector2& Vector2::operator*=(const float rhs)
{
    m_X *= rhs;
    m_Y *= rhs;

    return *this;
}

Vector2& Vector2::operator/=(const float rhs)
{
    m_X /= rhs;
    m_Y /= rhs;

    return *this;
}

Vector2 Vector2::GetNormalized(void) const
{
    Vector2 result = *this;
    float magnitude = GetMagnitude();
    if(magnitude > 0.0f)
    {
        result /= magnitude;
    }

    return result;

}

float Vector2::GetMagnitude(void) const
{
    return (float)sqrt(GetSquareMagnitude());
}

float Vector2::GetSquareMagnitude(void) const
{
    return (m_X * m_X) + (m_Y * m_Y);
}

float Vector2::GetX(void) const
{
    return m_X;
}

float Vector2::GetY(void) const
{
    return m_Y;
}

Vector2::Vector2(const float x, const float y)
{
    m_X = x;
    m_Y = y;
}

Vector2::Vector2(const Vector2& other)
{
    m_X = other.m_X;
    m_Y = other.m_Y;
}

Vector2::Vector2(void) { }
