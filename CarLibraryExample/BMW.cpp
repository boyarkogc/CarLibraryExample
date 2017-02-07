#pragma once
#include "BMW.h"

namespace CarLibrary {
	std::string BMW::toString() {
		return Vehicle::toString() + copyright;
	}
}