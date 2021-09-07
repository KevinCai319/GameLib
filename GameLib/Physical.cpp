#include "Physical.hpp"

const bool Physical::isColliding(Physical& other)
{
    //estimate collision
    bool est = other.getShape().getGlobalBounds().intersects(getShape().getGlobalBounds());
    if (est) {
        //if close, do GJK or SAT.
        //FIX: GJK or SAT
        return true;
    }
    return false;
}
