#pragma once

#include <iostream>
#include <list>

#include "Vehicle.h"
#include "VehicleInventory.h"
#include "BMW.h"
#include "Subaru.h"
#include "Volkswagon.h"
#include "Tesla.h"

using namespace std;

int main()
{
	CarLibrary::ManufacturerInfo toyotaMan("Toyota", "9999 Main St", "555-555-5555");
	CarLibrary::ManufacturerInfo subaruMan("Subaru", "9999 Main St", "555-555-5555");
	CarLibrary::ManufacturerInfo volkswagonMan("Volkswagon", "9999 Main St", "555-555-5555");
	CarLibrary::ManufacturerInfo teslaMan("Tesla", "9999 Main St", "555-555-5555");
	CarLibrary::ManufacturerInfo bmwMan("BMW", "9999 Main St", "555-555-5555");

	CarLibrary::BMW bmw(0, 1992, 0, 0, 0, "bmw", "", "", bmwMan, 0, 50000);
	CarLibrary::Vehicle toyota(1, 1994, 0, 0, 0, "bmw", "", "", toyotaMan, 0, 50000);
	CarLibrary::Subaru subaru(2, 1999, 0, 0, 0, "bmw", "", "", subaruMan, 0, 50000);
	CarLibrary::Volkswagon volkswagon(3, 1998, 0, 0, 0, "bmw", "", "", volkswagonMan, 0, 50000);
	CarLibrary::Tesla tesla(4, 1999, 0, 0, 0, "bmw", "", "", teslaMan, 0, 50000);

	CarLibrary::VehicleInventory vi;
	vi.addVehicle(bmw);
	vi.addVehicle(toyota);
	vi.addVehicle(tesla);
	vi.addVehicle(subaru);
	vi.addVehicle(volkswagon);

	cout << vi.toString() << endl;
	
	std::list<CarLibrary::Vehicle*> mylist;
	std::list<CarLibrary::Vehicle*> mylist2;
	std::list<CarLibrary::Vehicle*> mylist3;

	vi.populateListBy(mylist, 'v');
	vi.populateListBy(mylist2, 'y');

	std::cout << "list sorted by vin" << endl;
	std::cout << endl;
	for (auto v : mylist)
		std::cout << (*v).toString() << "\n";
	std::cout << endl;

	std::cout << "list sorted by year" << endl;
	std::cout << endl;
	for (auto v : mylist2)
		std::cout << (*v).toString() << "\n";
	std::cout << endl;

	vi.populateListYearEquals(mylist3, 1990);
	std::cout << "cars made in 1999: " << endl;
	std::cout << endl;
	for (auto v : mylist3)
		std::cout << (*v).toString() << "\n";
	std::cout << endl;

	std::cout << "Num vehicles that need oil change: " << endl;
	std::cout << endl;
	std::cout << vi.numVehiclesDueForOilChange() << endl;

	vi.removeVehicleByVin(toyota.get_vin());
	cout << "Toyota has been removed: " << endl;
	std::cout << endl;
	cout << vi.toString() << endl;
	
	return 0;
}