#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>
#include "base-types.hpp"

namespace kubov
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t &positionNew) = 0;
    virtual void move(const double deltaX, const double deltaY) = 0;
    virtual void print(std::ostream &out) const = 0;
    virtual void scale(const double coefficient) = 0;
  };
}
#endif

