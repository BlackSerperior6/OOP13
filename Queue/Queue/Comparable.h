#pragma once

#include "Pair.h"

class Comparable
{
public:

	bool operator()(Pair& one, Pair& two) { return one < two; }
};
