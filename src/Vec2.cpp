#include "common.h"

Vec2::Vec2() {}

Vec2::Vec2(float xin, float yin): x(xin), y(yin){}

void Vec2::operator*=(float rhs){
    x *= rhs;
    y *= rhs;
}

void Vec2::operator/=(float rhs){
    x /= rhs;
    y /= rhs;
}

void Vec2::operator+=(const Vec2 &rhs){
    x += rhs.x;
    y += rhs.y;
}

void Vec2::operator-=(const Vec2 &rhs){
    x -= rhs.x;
    y -= rhs.y;
}

bool Vec2::operator==(const Vec2 &rhs) const{
    return x == rhs.x && y == rhs.y;
}

bool Vec2::operator!=(const Vec2 &rhs) const{
    return x != rhs.x || y != rhs.y;
}

Vec2 Vec2::operator+(const Vec2 &rhs) const{
    return Vec2(x + rhs.x, y + rhs.y);
}

Vec2 Vec2::operator-(const Vec2 &rhs) const{
    return Vec2(x - rhs.x, y - rhs.y);
}

Vec2 Vec2::operator/(float rhs) const{
    return Vec2(x / rhs, y / rhs);
}

Vec2 Vec2::operator*(float rhs) const{
    return Vec2(x * rhs, y * rhs);
}

float Vec2::distance() const{
    return sqrtf((x*x) + (y*y));
}

void Vec2::normalise() {
    float d = this->distance();
    x /= d;
    y /= d;
}

std::ostream& operator << (std::ostream& stream, const Vec2& lhs)
{
    return stream << lhs.x <<  " " << lhs.y << "\n";
}