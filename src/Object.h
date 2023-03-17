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

  virtual void Move(const Point* diff) = 0;

  virtual size_t GetH() const = 0;
  virtual size_t GetW() const = 0;
  virtual Point* GetPos() const = 0;

  virtual ~Object() = 0;
};

class NPO : public Object {
 public:
  NPO(Point* pos, const Point* speed,
      size_t width, size_t height);

  bool Intersects(const Object& other) const override;

  bool isOutOfBorder() const override;

  void Boost() override;

  void Move(const Point* diff) override;

  size_t GetH() const override;
  size_t GetW() const override;
  Point* GetPos() const override;

  ~NPO() override;

 private:
  Point* pos;
  const Point* speed;
  const size_t width;
  const size_t height;
};

class PlayableObj : public Object {
 public:
  PlayableObj(Point* pos, size_t width, size_t height);

  bool Intersects(const Object& other) const override;

  bool isOutOfBorder() const override;

  size_t GetH() const override;
  size_t GetW() const override;
  Point* GetPos() const override;

  void Move(const Point* diff);

  void Boost() override;

  ~PlayableObj() override;

 private:
  Point* pos;
  const size_t width;
  const size_t height;
};

class CarCreator {
 public:
  static Object* CreateObj(Point* pos);
};

class TreeCreator {
 public:
  static Object* CreateObj(Point* pos);
};

class Pl_ObjCreator {
 public:
  static Object* CreateObj(Point* pos);
};

#endif //SRC_OBJECT_H
