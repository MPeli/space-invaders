#include "Vector2D.h"

#include <cmath>

Vector2D::Vector2D(const float x, const float y) noexcept : x(x), y(y)
{

}

Vector2D Vector2D::operator+(const Vector2D& vector)
{
    return { this->x + vector.x, this->y + vector.y };
}

Vector2D Vector2D::operator-(const Vector2D& vector)
{
    return { this->x - vector.x, this->y - vector.y };
}

Vector2D& Vector2D::operator+=(const Vector2D& vector)
{
    this->x += vector.x;
    this->y += vector.y;

    return *this;
}

Vector2D& Vector2D::operator-=(const Vector2D& vector)
{
    this->x -= vector.x;
    this->y -= vector.y;

    return *this;
}

Vector2D Vector2D::operator*(const float scalar)
{
    return { this->x * scalar, this->y * scalar };
}

void Vector2D::normalize()
{
    double magnitude = std::sqrt((this->x * this->x) + (this->y * this->y));
    this->x /= magnitude;
    this->y /= magnitude;
}

void Vector2D::rotate(const Vector2D& center, const float angle)
{
    Vector2D old = *this - center;
    this->x = old.x * std::cos(angle) - old.y * std::sin(angle) + center.x;
    this->y = old.x * std::sin(angle) + old.y * std::cos(angle) + center.y;
}

float Vector2D::getAngle() const
{
    return std::atan2(this->x, this->y);
}

Size::Size(const int width, const int height) noexcept : width(width), height(height)
{

}