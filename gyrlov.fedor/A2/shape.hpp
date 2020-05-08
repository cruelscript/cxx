#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <ostream>
#include "base-types.hpp"

namespace gyrlov 
{
  class Shape 
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const double dx, const double dy) = 0;
    virtual void move(const point_t&) = 0;
    virtual void scale(const double) = 0;
    virtual void print(std::ostream&) const = 0;
  };
}
#endif