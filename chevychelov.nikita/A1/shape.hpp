#ifndef SHAPE_HPP_
#define SHAPE_HPP_
#include <iosfwd>
#include "base-types.hpp"

class Shape
{
public:
  virtual ~Shape() = default;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(const double dx, const double dy) = 0;
  virtual void move(const point_t& position) = 0;
  virtual void print(std::ostream &out) const = 0;
};
#endif // !SHAPE_HPP_