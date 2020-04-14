#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle: public Shape
{
public:
  Circle(const point_t &centre, double radius);
  void move(const point_t &point) override;
  void move(double  dx, double dy) override;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
private:
  double radius_;
  point_t centre_;
};

#endif