#ifndef SHAPE
#define SHAPE

#include "base-types.hpp"

namespace savenkova
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t& point) = 0;
    virtual void move(const double xOffset, const double yOffset) = 0;
    virtual void scale(const double coefficient) = 0;
  };
}
#endif 