#pragma once
#include "Volkswagon.h"

namespace CarLibrary {
	bool Volkswagon::dueForOilChange() {
		// Didn't get around to using actual dates, so I just hardcoded in an int to represent a day.
		int currentDay = 200;
		if (get_mileage() - getLastOilChangeMileage() >= 8000 || currentDay - getLastOilChangeDate() >= 210) {
			return true;
		}
		return false;
	}
}