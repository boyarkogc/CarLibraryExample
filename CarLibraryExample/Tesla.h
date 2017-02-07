#pragma once
#include "Vehicle.h"

namespace CarLibrary
{
	class Tesla : public Vehicle
	{
	public:
		Tesla(int vin, int year, int weight, int original_msrp, int mileage, std::string make, std::string model, std::string color, ManufacturerInfo man_info, int lastOilChangeDate, int lastOilChangeMileage)
			: Vehicle(vin, year, weight, original_msrp, mileage, make, model, color, man_info, lastOilChangeDate, lastOilChangeMileage) {}
		bool dueForOilChange();
	};
}