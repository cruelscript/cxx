#include "circle.hpp"
#include <cassert>
#include <cmath>

Circle::Circle(double radius, double x, double y) :
  Circle(radius, {x, y})
{}

Circle::Circle(double radius, const point_t &center) :
  radius_(radius),
  center_(center)
{
  assert(radius > 0.0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  double side = radius_ * 2;
  return {side, side, center_};
}

void Circle::move(const point_t &point)
{
  center_ = point;
}

void Circle::move(double deltaX, double deltaY)
{
  center_.x += deltaX;
  center_.y += deltaY;
}