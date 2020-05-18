#include "circle.hpp"

#define _USE_MATH_DEFINES
#include <cmath>
#include <stdexcept>
#include <ostream>
#include "base-types.hpp"

vinokurov::Circle::Circle(double radius, const point_t& center) :
  radius_(radius),
  center_(center)
{
  if (radius_ <= 0)
  {
    throw std::invalid_argument("Circle: Error. Radius cannot be less than zero.");
  }
}

double vinokurov::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

vinokurov::rectangle_t vinokurov::Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
}

void vinokurov::Circle::move(const point_t& newCenter)
{
  center_ = newCenter;
}

void vinokurov::Circle::move(double deltaX, double deltaY)
{
  center_.x += deltaX;
  center_.y += deltaY;
}

void vinokurov::Circle::print(std::ostream& out) const
{
  out << "\nRadius of the circle is " << radius_
    << ". The center of the circle is at x: " << center_.x << ", y: " << center_.y << "\n";
}

void vinokurov::Circle::scale(double coefficient)
{
  if(coefficient <= 0)
  {
    throw std::invalid_argument("Circle: Error. Scaling coefficient cannot be less than zero.");
  }
  radius_ *= coefficient;
}