#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(const point_t &center, const double radius);
  virtual double getArea() const override;
  virtual rectangle_t getFrameRect() const override;
  virtual void move(const point_t &positionNew) override;
  virtual void move(const double &deltaX, const double &deltaY) override;
  virtual void print() const override;

private:
  point_t center_;
  double radius_;

};

#endif

