#ifndef _INCLUDE_ANIMAL_HPP
#define _INCLUDE_ANIMAL_HPP

#include "Geometry.hpp"

namespace world {

class World;


enum class Sex {
    MALE, FEMALE
};

enum class Action {
    EAT, DIE, GO, REPRODUCE, NOTHING
};

class Animal {
public:
    Vector direction_;
    Action nextAction_;
    double velocity_;
    int vision_;
    Point position_;
    int hunger_;
    int age_;
    int reprodCd_;
    Sex sex_;

    Animal();
    Animal(const Animal &other) = default;
  //  virtual void create_child(World&) = 0;
    Animal& operator=(const Animal& other) = default;
    void make_move();
};

void swap(Animal &a, Animal &b);

} //namespace world

#endif // _INCLUDE_ANIMAL_HPP