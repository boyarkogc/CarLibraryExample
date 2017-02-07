#pragma once
#include "Subaru.h"

namespace CarLibrary {
	bool Subaru::dueForOilChange() {
		int currentDay = 200;
		if (get_mileage() - getLastOilChangeMileage() >= 7000 || currentDay - getLastOilChangeDate() >= 180) {
			return true;
		}
		return false;
	}
}