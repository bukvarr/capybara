//
// Created by bukvar on 16.03.23.
//

#include "Object.h"

ConstantPoints const_points2;

NPO::NPO(Point* pos, const Point* speed,
         size_t width, size_t height)
         : pos(pos), speed(speed),
           width(width), height(height) {}

bool NPO::Intersects(const Object& other) const {
  return std::abs(pos->x - other.GetPos()->x) < (width + other.GetW()) &&
         std::abs(pos->y - other.GetPos()->y) < (height + other.GetH());
}

bool NPO::isOutOfBorder() const {
  return std::abs(pos->x) >= GameConstants::play_zone_h ||
         std::abs(pos->y) >= GameConstants::play_zone_w;
}

void NPO::Boost() {
  pos->x += speed->x;
  pos->y += speed->y;
}

void NPO::Move(const Point* diff) {
    std::ignore = nullptr;
}

size_t NPO::GetH() const {
  return height;
}
size_t NPO::GetW() const {
  return width;
}
Point* NPO::GetPos() const {
  return pos;
}

NPO::~NPO() {
  delete pos;
}

PlayableObj::PlayableObj(Point* pos, size_t width, size_t height)
        : pos(pos), width(width),
          height(height) {}

bool PlayableObj::Intersects(const Object& other) const {
  return std::abs(pos->x - other.GetPos()->x) < (width + other.GetW()) &&
         std::abs(pos->y - other.GetPos()->y) < (height + other.GetH());
}

bool PlayableObj::isOutOfBorder() const {
  return std::abs(pos->x) >= GameConstants::play_zone_w ||
         std::abs(pos->y) >= GameConstants::play_zone_h;
}

void PlayableObj::Boost() {
  std::ignore = nullptr;
}

void PlayableObj::Move(const Point* diff) {
  pos->x += diff->x;
  pos->y += diff->y;
}

size_t PlayableObj::GetH() const {
  return height;
}
size_t PlayableObj::GetW() const {
  return width;
}
Point* PlayableObj::GetPos() const {
  return pos;
}

PlayableObj::~PlayableObj() {
  delete pos;
}

Object* CarCreator::CreateObj(Point* pos) {
  return new NPO(pos, const_points2.car_speed, ObjConstants::car_w,
             ObjConstants::car_h);
}

Object* TreeCreator::CreateObj(Point* pos) {
  return new NPO(pos, const_points2.zero_speed, ObjConstants::tree_w,
                 ObjConstants::tree_h);
}

Object* Pl_ObjCreator::CreateObj(Point* pos) {
  return new PlayableObj(pos, ObjConstants::Pl_Obj_w,
                 ObjConstants::Pl_Obj_h);
}