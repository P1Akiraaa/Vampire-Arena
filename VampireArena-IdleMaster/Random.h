#pragma once
#include "CoreMinimal.h"

static int GetRandomNumberInRange(const int _min, const int _max)
{
    random_device _rSeed;
    mt19937 _gen(_rSeed());
    uniform_int_distribution<> distr(_min, _max);

    return distr(_gen);
}
