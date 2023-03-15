//
// Created by bukvar on 16.03.23.
//

#include "Object.h"

NPO::NPO(Point* pos, Point* center, Point* speed,
         size_t width, size_t height, int tic_count)
         : pos(pos), center(center), speed(speed),
           width(width), height(height), tic_count(tic_count) {}

bool NPO::Intersects(const Object& other) const {
  return std::abs(pos->x - other.GetPos()->x) < (width + other.GetW()) ||
         std::abs(pos->y - other.GetPos()->y) < (height + other.GetH());
}

void NPO::Boost() {
  ++tic_count;
  pos->x += speed->x;
  pos->y += speed->y;
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

Capybara::Capybara(Point* pos, Point* center, Point* speed,
         size_t width, size_t height, int tic_count)
        : pos(pos), center(center), speed(speed),
          width(width), height(height), tic_count(tic_count) {}

bool Capybara::Intersects(const Object& other) const {
  return std::abs(pos->x - other.GetPos()->x) < (width + other.GetW()) ||
         std::abs(pos->y - other.GetPos()->y) < (height + other.GetH());
}

bool Capybara::isOutOfBorder() const {
  return std::abs(pos->x) >= constants::width ||
         std::abs(pos->y) >= constants::height;
}

void Capybara::Move(const Point& diff) {
  pos->x += diff.x;
  pos->y += diff.y;
}

size_t Capybara::GetH() const {
  return height;
}
size_t Capybara::GetW() const {
  return width;
}
Point* Capybara::GetPos() const {
  return pos;
}