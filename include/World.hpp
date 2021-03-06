#ifndef _INCLUDE_WORLD_HPP
#define _INCLUDE_WORLD_HPP

#include "../include/Geometry.hpp"
#include "../include/Lion.hpp"
#include "../include/Zebra.hpp"
#include "../include/Grass.hpp"
#include "../include/Obstacle.hpp"

#include <vector>

namespace world {

constexpr int AGE_FOR_REPROD = 1;
constexpr int MAX_AGE = 1000;
constexpr int HUNGER_FOR_REPROD = 500;
constexpr int CD_REPROD_TIME = 100;
constexpr int MAX_HUNGER = 1000;
constexpr int GRASS_NUTRITION = 10;
constexpr double START_VELOCITY = 5;
constexpr int START_HUNGER = 2;
constexpr int START_VISION = 50;
constexpr int ZEBRAS_NUTRITION = 20;
constexpr size_t X_FIELD_SIZE = 672;
constexpr size_t Y_FIELD_SIZE = 472;
constexpr int FREQUENCY = 29;

class World final {
public:
    std::vector<Lion> lionsArray_;
    std::vector<Zebra> zebrasArray_;
    std::vector<Grass> grassArray_;
    std::vector<Polygon> obstaclesArray_;

    bool can_move(const Point &from, const Point &to) const;

    template <typename ANIMAL, typename FOOD>
    void update_species(std::vector<ANIMAL>&, std::vector<FOOD>&, int nutrition); 
    template<typename ANIMAL, typename FOOD>
    void eating(ANIMAL&, std::vector<FOOD>&, int nutrition);

    template<typename ANIMAL>
    void reproduce(std::vector<ANIMAL>&);
    void update();
};

} //namespace world

#endif // _INCLUDE_WORLD_HPP