#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace vinokurov
{
  class Circle : public Shape
  {
  public:
    Circle(double radius, const point_t& center);
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(const point_t& newCenter) noexcept override;
    void move(double deltaX, double deltaY) noexcept override;
    void print(std::ostream& out) const override;
    void scale(double coefficient) override;
    void rotate(double angle) noexcept override;
  private:
    double radius_;
    point_t center_;
  };
}

#endif
