#pragma once

constexpr auto SCREEN_WIDTH = 1280;
constexpr auto SCREEN_HEIGHT = 720;
constexpr auto TILE_SIZE = 32;

constexpr auto MAX_SAMPLES = 16;
constexpr auto MAX_BOUNCES = 64;

// Basic shizzle
#include <iostream>
#include <string>
#include <vector>

// SIMD
#include "nmmintrin.h"
#include "immintrin.h"

// Windows and things to put images to the screen with
#include <SFML/Graphics.hpp>

// Own code
#include "Vec.h"
#include "Ray.h"
#include "Tile.h"
#include "Renderer.h"