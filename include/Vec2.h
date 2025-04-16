#pragma once
#include "common.h"

class Vec2{
public:
    float x{0};
    float y{0};

    Vec2();

    Vec2(float xin, float yin);

    Vec2 operator + (const Vec2 &rhs) const;
    Vec2 operator - (const Vec2 &rhs) const;
    Vec2 operator / (float rhs) const;
    Vec2 operator * (float rhs) const;

    bool operator == (const Vec2 &rhs) const;
    bool operator != (const Vec2 &rhs) const;

    void operator += (const Vec2 &rhs);
    void operator -= (const Vec2 &rhs);
    void operator *= (float rhs);
    void operator /= (float rhs);

    void normalise();
    float distance() const;
    static Vec2 normalise(Vec2 vec);

    friend std::ostream& operator << (std::ostream& stream, const Vec2& lhs);
};