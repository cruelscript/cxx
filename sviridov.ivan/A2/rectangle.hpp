#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "base-types.hpp"
#include "shape.hpp"

namespace sviridov
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t &centre, double width, double height);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &point) override;
    void move(const double dx, const double dy) override;
    void scale(const double scaleRate) override;
  private:
    double width_;
    double height_;
    point_t centre_;
  };
}

#endif