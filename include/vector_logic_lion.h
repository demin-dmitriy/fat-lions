#include "World.hpp"

using namespace world;

struct VectorLogicLion {
    bool ready_for_sex(const Lion& curLion);
    int dist(Point a, Point b);
    Vector find_correct_vec(const Lion& curLion, Vector resVector, const World& curWorld);
    void find_target(Lion& curLion, World& curWorld);
};