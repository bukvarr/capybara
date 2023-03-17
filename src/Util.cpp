//
// Created by sergey on 16.03.23.
//

#include "Util.h"

Point::Point() : x(0), y(0) {}

Point::Point(int x, int y) : x(x), y(y) {}

Point::operator std::pair<int, int>() { return std::make_pair(x, y); }

LineStruct::LineStruct() : indicator(LineIndicators::freeline_ind), index(0) {}

LineStruct::LineStruct(int indicator, int index) : indicator(indicator), index(index) {}

ConstantPoints::ConstantPoints() : up(new Point(0, 228)), down(new Point(0, -228)),
                                   left(new Point(-228, 0)), right(new Point(228, 0)),
                                   car_speed(new Point(228, 228)), zero_speed(new Point(0, 0)) {}
ConstantPoints::~ConstantPoints() {
  delete up;
  delete down;
  delete left;
  delete right;
  delete car_speed;
  delete zero_speed;
}