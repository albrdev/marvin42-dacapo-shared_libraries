class Vector2
{
protected:
    float m_X;
    float m_Y;

public:
    const static Vector2 Zero;
    const static Vector2 One;

    static float Distance(const Vector2& a, const Vector2& b);
    static float DotProduct(const Vector2& a, const Vector2& b);
    static float CrossProduct(const Vector2& a, const Vector2& b);
    static Vector2 PerpendicularCW(const Vector2& value);
    static Vector2 PerpendicularCCW(const Vector2& value);

    Vector2 operator+(void);
    Vector2 operator-(void);

    Vector2 operator+(const Vector2& rhs) const;
    Vector2 operator-(const Vector2& rhs) const;
    Vector2 operator*(const Vector2& rhs) const;
    Vector2 operator/(const Vector2& rhs) const;

    Vector2 operator+(const float rhs) const;
    Vector2 operator-(const float rhs) const;
    Vector2 operator*(const float rhs) const;
    Vector2 operator/(const float rhs) const;

    Vector2& operator+=(const Vector2& rhs);
    Vector2& operator-=(const Vector2& rhs);
    Vector2& operator*=(const Vector2& rhs);
    Vector2& operator/=(const Vector2& rhs);

    Vector2& operator+=(const float rhs);
    Vector2& operator-=(const float rhs);
    Vector2& operator*=(const float rhs);
    Vector2& operator/=(const float rhs);

    Vector2 GetNormalized(void) const;
    virtual float GetMagnitude(void) const;
    virtual float GetSquareMagnitude(void) const;

    float GetX(void) const;
    float GetY(void) const;

    Vector2(const float x, const float y);
    Vector2(const Vector2& other);
    Vector2(void);
};
