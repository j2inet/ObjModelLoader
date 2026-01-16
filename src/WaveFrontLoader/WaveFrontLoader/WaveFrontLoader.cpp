// WaveFrontLoader.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "WaveFront.h"

int main()
{
    auto data = LoadWaveFrontModel(L"models\\Fighter_Aircraft.obj_");
    return 0;
}
