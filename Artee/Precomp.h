#pragma once

// Predefined variables
constexpr unsigned SCREEN_WIDTH = 1280;
constexpr unsigned SCREEN_HEIGHT = 720;
constexpr unsigned TILE_SIZE = 32;

constexpr unsigned MAX_SAMPLES = 16;
constexpr unsigned MAX_BOUNCES = 64;

// EXPERIMENTAL
// Enables SIMD operations for vectors, where applicable
#define EXP_SIMD_VEC 1

// Basic shizzle
#include <iostream>
#include <string>
#include <vector>

// SIMD
#include "nmmintrin.h"
#include "immintrin.h"

// Windows and things to put images to the screen with
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

// Own code
#include "Vec.h"
#include "Ray.h"
#include "Hit.h"
#include "AABB.h"
#include "BVH.h"
#include "Primitive.h"
#include "Object.h"
#include "Scene.h"
#include "Tile.h"
#include "Renderer.h"