#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

class Shape
{
public:
  Shape(const point_t& pos);
  virtual ~Shape() = default;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void print() const = 0;
  virtual void move(const double x, const double y) final;
  virtual void move(const point_t& point) final;
protected:
  point_t pos_;
};
#endif //! SHAPE_HPP__