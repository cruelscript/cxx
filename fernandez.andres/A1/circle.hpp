#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"
#include <iosfwd>

class Circle : public Shape
{
public:
  Circle(const point_t& position, const double radius);

  virtual double getArea() const override;

  virtual rectangle_t getFrameRect() const override;

  virtual void print(std::ostream & out) const override;

private:
  double radius_;
};

#endif
