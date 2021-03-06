#include "matrix-shape.hpp"

#include <stdexcept>
#include <ostream>
#include <cmath>

#include "base-types.hpp"
#include "layer.hpp"
#include "composite-shape.hpp"

vinokurov::MatrixShape::MatrixShape() :
  rows_(1),
  cols_(1),
  array_(std::make_unique<shapePtr[]>(1))
{}

vinokurov::MatrixShape::MatrixShape(const MatrixShape& rhs) :
  rows_(rhs.rows_),
  cols_(rhs.cols_),
  array_(std::make_unique<shapePtr[]>(cols_ * rows_))
{
  for (size_t i = 0 ; i < cols_ * rows_; i++)
  {
    array_[i] = rhs.array_[i];
  }
}

vinokurov::MatrixShape::MatrixShape(MatrixShape&& rhs) noexcept :
  rows_(rhs.rows_),
  cols_(rhs.cols_),
  array_(std::move(rhs.array_))
{
  rhs.cols_ = 0;
  rhs.rows_ = 0;
}

vinokurov::MatrixShape::MatrixShape(CompositeShape& compositeShape) :
  MatrixShape()
{
  if (compositeShape.size() == 0)
  {
    throw std::invalid_argument("MatrixShape: Error. Unable to create matrix from empty composite shape.");
  }
  for (size_t i = 0; i < compositeShape.size(); i++)
  {
    add(compositeShape[i]);
  }
}

vinokurov::MatrixShape& vinokurov::MatrixShape::operator=(const MatrixShape& rhs)
{
  if (this != &rhs)
  {
    rows_ = rhs.rows_;
    cols_ = rhs.cols_;
    shapeArray temp(std::make_unique<shapePtr[]>(rows_ * cols_));

    for (size_t i = 0; i < rows_ * cols_; i++)
    {
      temp[i] = rhs.array_[i];
    }
    array_.swap(temp);
  }
  return *this;
}

vinokurov::MatrixShape& vinokurov::MatrixShape::operator=(MatrixShape&& rhs) noexcept
{
  if (this != &rhs)
  {
    rows_ = rhs.rows_;
    cols_ = rhs.cols_;
    array_ = std::move(rhs.array_);
    rhs.cols_ = 0;
    rhs.rows_ = 0;
  }
  return *this;
}

vinokurov::Layer vinokurov::MatrixShape::operator[](unsigned int index) const
{
  if (index >= rows_)
  {
    throw std::out_of_range("MatrixShape: Error. Index is out of range.");
  }
  size_t size = 0;

  for (size_t i = 0; i < cols_; i++)
  {
    if (array_[index * cols_ + i])
    {
      size++;
    }
    else break;
  }
  shapeArray temp(std::make_unique<shapePtr[]>(size));

  for (size_t i = 0; i < size; i++)
  {
    temp[i] = array_[index * cols_ + i];
  }
  return Layer(temp, size);
}

void vinokurov::MatrixShape::add(const shapePtr& shape)
{
  if (!shape)
  {
    throw std::invalid_argument("MatrixShape: Error. Pointer of added element cannot be nullptr.");
  }
  size_t row = 0;

  for (size_t i = 0; i < rows_; i++)
  {
    for (size_t j = 0; j < cols_; j++)
    {
      if (!array_[i * cols_ + j])
      {
        break;
      }
      if (isOverlapped(array_[i * cols_ + j], shape))
      {
        row = i + 1;
        break;
      }
    }
  }
  if (row == rows_)
  {
    shapeArray temp = std::make_unique<shapePtr[]>(cols_ * (rows_ + 1));
    rows_++;

    for (size_t i = 0; i < (rows_ - 1) * cols_; i++)
    {
      temp[i] = array_[i];
    }
    for (size_t i = (rows_ - 1) * cols_; i < rows_ * cols_; i++)
    {
      temp[i] = nullptr;
    }
    array_.swap(temp);
  }
  bool isAdded = false;

  for (size_t j = 0; j < cols_; j++)
  {
    if (!array_[row * cols_ + j])
    {
      array_[row * cols_ + j] = shape;
      isAdded = true;
      break;
    }
  }
  if (!isAdded)
  {
    shapeArray temp = std::make_unique<shapePtr[]>((cols_ + 1) * rows_);
    cols_++;

    for (size_t i = 0; i < rows_; i++)
    {
      for (size_t j = 0; j < cols_ - 1; j++)
      {
        temp[i * cols_ + j] = array_[i * (cols_ - 1) + j];
      }
      temp[(i + 1) * cols_ - 1] = nullptr;
    }
    array_.swap(temp);
    array_[row * cols_ + (cols_ - 1)] = shape;
  }
}

bool vinokurov::MatrixShape::isOverlapped(const shapePtr& shape1, const shapePtr& shape2)
{
  return !shape1 || !shape2 ? false :
    (std::fabs(shape1->getFrameRect().pos.x - shape2->getFrameRect().pos.x)
    < (shape1->getFrameRect().width / 2 + shape2->getFrameRect().width / 2))
    && (std::fabs(shape1->getFrameRect().pos.y - shape2->getFrameRect().pos.y)
    < (shape1->getFrameRect().height / 2 + shape2->getFrameRect().height / 2));
}

void vinokurov::MatrixShape::print(std::ostream& out) const
{
  out << "\nMatrix of shapes: \n";

  for (size_t i = 0; i < rows_; i++)
  {
    for (size_t j = 0; j < cols_; j++)
    {
      if (array_[i * cols_ + j])
      {
        out << "Layer " << i + 1 << ":\nShape " << j + 1;
        array_[i * cols_ + j]->print(out);        
      }
    }
  }
}

size_t vinokurov::MatrixShape::getCols() const noexcept
{
  return cols_;
}

size_t vinokurov::MatrixShape::getRows() const noexcept
{
  return rows_;
}
