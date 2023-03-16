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

  virtual bool isOutOfBorder() const = 0;

  virtual void Boost() = 0;

  virtual size_t GetH() const = 0;
  virtual size_t GetW() const = 0;
  virtual Point* GetPos() const = 0;
};

class NPO : public Object {
 public:
  NPO(Point* pos, Point* center, const Point* speed,
      size_t width, size_t height, int tic_count);

  bool Intersects(const Object& other) const override;

  bool isOutOfBorder() const override;

  void Boost() override;

  size_t GetH() const override;
  size_t GetW() const override;
  Point* GetPos() const override;

 private:
  Point* pos;
  Point* center;
  const Point* speed;
  const size_t width;
  const size_t height;
  int tic_count;
};

class PlayableObj : public Object {
 public:
  PlayableObj(Point* pos, Point* center, const Point* speed,
  size_t width, size_t height, int tic_count);

  bool Intersects(const Object& other) const override;

  bool isOutOfBorder() const override;

  size_t GetH() const override;
  size_t GetW() const override;
  Point* GetPos() const override;

  void Move(const Point& diff);

  void Boost() override;

 private:
  Point* pos;
  Point* center;
  const Point* speed;
  const size_t width;
  const size_t height;
  int tic_count;
};

class Creator {
 protected:
  virtual Object* CreateObj(Point* pos) const = 0;
};

class CarCreator : protected Creator {
 public:
  static Object* CreateObj(Point* pos, Point* center);
};

class TreeCreator : protected Creator {
 public:
  static Object* CreateObj(Point* pos, Point* center);
};

class Pl_ObjCreator : protected Creator {
 public:
  static Object* CreateObj(Point* pos, Point* center);
};

#endif //SRC_OBJECT_H
