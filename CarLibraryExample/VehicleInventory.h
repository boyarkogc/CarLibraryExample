#pragma once
#include <string>
#include <vector>
#include <list>
#include "ManufacturerInfo.h"
#include "Vehicle.h"

namespace CarLibrary
{
	class VehicleInventory
	{
	private:
		std::vector<Vehicle*> inventory;
	public:
		void addVehicle(Vehicle &v);
		void removeVehicleByVin(int vin);
		// sortType can be 'v' for vin, 'm' for make, or 'y' for year; default is 'v'
		// Both of these methods get a list reference passed in which they populate, rather than returning a new list.
		// To be honest, I don't have a great reason for doing it this way other than a bit of reading that this is the preferred way to do this sort of thing,
		// rather than copying an entire list or creating a new one.
		void populateListBy(std::list<Vehicle*> &toPopulate, char sortType);
		void populateList(std::list<Vehicle*> &toPopulate);

		void populateListYearEquals(std::list<Vehicle*> &toPopulate, int year);
		void populateListMakeEquals(std::list<Vehicle*> &toPopulate, std::string make);

		void addToMileage(Vehicle v, int milegeIncrease);
		void addToMileage(std::list<Vehicle*> &list, int milegeIncrease);

		int avgMSRP();
		int maxMSRP();
		int minMSRP();
		int avgMileage();
		int maxMileage();
		int minMileage();
		int numVehiclesDueForOilChange();

		std::string toString();
	};
}