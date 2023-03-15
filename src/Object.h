//
// Created by bukvar on 16.03.23.
//

#ifndef SRC_OBJECT_H
#define SRC_OBJECT_H

#include "Project.h"
#include "Util.h"

class Object {
 public:
  virtual bool Intersects(const Object& other) const = 0;

  virtual size_t GetH() const = 0;
  virtual size_t GetW() const = 0;
  virtual Point* GetPos() const = 0;
};

class NPO : protected Object {
 public:
  NPO(Point* pos, Point* center, Point* speed,
      size_t width, size_t height, int tic_count);

  bool Intersects(const Object& other) const;

  void Boost();

  size_t GetH() const;
  size_t GetW() const;
  Point* GetPos() const;

 private:
  Point* pos;
  Point* center;
  Point* speed;
  size_t width;
  size_t height;
  int tic_count;
};

class Capybara : protected Object {
 public:
  Capybara(Point* pos, Point* center, Point* speed,
  size_t width, size_t height, int tic_count);

  bool Intersects(const Object& other) const;

  bool isOutOfBorder() const;

  size_t GetH() const;
  size_t GetW() const;
  Point* GetPos() const;

  void Move(const Point& diff);

 private:
  Point* pos;
  Point* center;
  Point* speed;
  size_t width;
  size_t height;
  int tic_count;
};

#endif //SRC_OBJECT_H
