#ifndef FIRSTLAB_CIRCLE_HPP
#define FIRSTLAB_CIRCLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace konovalov
{
  class Circle : public Shape
  {
  public:
    explicit Circle(double radius, const point_t &center);

    double getArea() const override;

    rectangle_t getFrameRect() const override;

    void move(const point_t &point) override;

    void move(double dx, double dy) override;

    void scale(double coefficient) override;

  private:
    double radius_;
    point_t center_;
  };
}
#endif