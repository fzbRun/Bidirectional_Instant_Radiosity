#pragma once

#include "structSet.h"

#ifndef BASE_FUNCTION
#define BASE_FUNCTION

//µÕ≤Ó“Ï–Ú¡–
float RadicalInverse_VdC(uint32_t bits)
{
    bits = (bits << 16u) | (bits >> 16u);
    bits = ((bits & 0x55555555u) << 1u) | ((bits & 0xAAAAAAAAu) >> 1u);
    bits = ((bits & 0x33333333u) << 2u) | ((bits & 0xCCCCCCCCu) >> 2u);
    bits = ((bits & 0x0F0F0F0Fu) << 4u) | ((bits & 0xF0F0F0F0u) >> 4u);
    bits = ((bits & 0x00FF00FFu) << 8u) | ((bits & 0xFF00FF00u) >> 8u);
    return float(bits) * 2.3283064365386963e-10; // / 0x100000000
}

glm::vec2 Hammersley(uint32_t i, uint32_t N)
{
    return glm::vec2(float(i) / float(N), RadicalInverse_VdC(i));
}

#endif