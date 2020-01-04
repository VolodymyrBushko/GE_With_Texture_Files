#include "object.h"

Object::Object(std::vector<Point> _points): points(_points) , color(0.0, 0.0, 0.0) {}

Object::Object(Object* _parent): parent{_parent} {}

Object::Object(std::vector<Point> _points, const Color& _color): points(_points), color(_color) {}

void Object::addChild(Object* _child)
{
   childs.push_back(_child);
}
