#pragma once

#include <SFML/Graphics.hpp>

namespace core {
    using Vec2 = sf::Vector2f;
    
    inline Vec2 operator+(Vec2 a, Vec2 b) { return {a.x+b.x, a.y+b.y}; }
    inline Vec2 operator-(Vec2 a, Vec2 b) { return {a.x-b.x, a.y-b.y}; }
    inline Vec2 operator*(Vec2 v, float s)    { return {v.x*s,   v.y*s  }; }
    inline Vec2 operator/(Vec2 v, float s)    { return {v.x/s,   v.y/s  }; }
}