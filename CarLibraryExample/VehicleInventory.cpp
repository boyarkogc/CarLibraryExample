#pragma once 
#include "Vehicle.h"
#include "VehicleInventory.h"
#include "ManufacturerInfo.h"
#include <string>
#include <algorithm>
#include <iterator>
#include <set>
#include <limits>

namespace CarLibrary {
	struct {
		bool operator()(Vehicle *a, Vehicle *b)
		{
			return a->get_vin() < b->get_vin();
		}
	} sortByVin;

	struct {
		bool operator()(Vehicle *a, Vehicle *b)
		{
			if (a->get_make() == b->get_make()) {
				return a->get_model() < b->get_model();
			}
			return a->get_make() < b->get_make();
		}
	} sortByMakeThenModel;

	struct {
		bool operator()(Vehicle *a, Vehicle *b)
		{
			return a->get_year() < b->get_year();
		}
	} sortByYear;

	void VehicleInventory::addVehicle(Vehicle &v) {
		inventory.push_back(&v);
	}

	void VehicleInventory::removeVehicleByVin(int vin) {
		for (std::vector<Vehicle*>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
			if ((*it)->get_vin() == vin) {
				inventory.erase(it);
				//delete *it;
				break;
			}
		}
	}

	std::string VehicleInventory::toString() {
		std::string output;
		for (std::vector<Vehicle*>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
			output = output + (*it)->toString();
		}
		return output;
	}
	void VehicleInventory::populateList(std::list<Vehicle*> &toPopulate) {
		std::copy(inventory.begin(), inventory.end(), std::back_inserter(toPopulate));
	}
	void VehicleInventory::populateListBy(std::list<Vehicle*> &toPopulate, char sortType) {
		switch (sortType) {
		case 'm':
			std::sort(inventory.begin(), inventory.end(), sortByMakeThenModel);
			break;
		case 'y':
			std::sort(inventory.begin(), inventory.end(), sortByYear);
			break;
		default:
			std::sort(inventory.begin(), inventory.end(), sortByVin);
			break;
		}
		std::copy(inventory.begin(), inventory.end(), std::back_inserter(toPopulate));
	}
	void VehicleInventory::populateListYearEquals(std::list<Vehicle*> &toPopulate, int year) {
		std::copy_if(inventory.begin(), inventory.end(), std::back_inserter(toPopulate), [year](Vehicle *i) { return (*i).get_year() == year; });
	}
	void VehicleInventory::populateListMakeEquals(std::list<Vehicle*> &toPopulate, std::string make) {
		std::copy_if(inventory.begin(), inventory.end(), std::back_inserter(toPopulate), [make](Vehicle *i) { return (*i).get_make() == make; });
	}
	void VehicleInventory::addToMileage(Vehicle v, int milegeIncrease) {
		for (std::vector<Vehicle*>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
			if ((*it)->get_vin() == v.get_vin()) {
				(*it)->set_mileage(milegeIncrease);
			}
		}
	}
	void VehicleInventory::addToMileage(std::list<Vehicle*> &list, int milegeIncrease) {
		std::set<int> vins;
		for (std::list<Vehicle*>::iterator it = list.begin(); it != list.end(); ++it) {
			vins.insert((*it)->get_vin());
		}
		for (std::vector<Vehicle*>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
			if (vins.count((*it)->get_vin())) {
				(*it)->set_mileage(milegeIncrease);
			}
		}
	}
	int VehicleInventory::avgMSRP() {
		int count = 0;
		int total = 0;
		for (std::vector<Vehicle*>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
			count += 1;
			total += (*it)->get_original_msrp();
		}
		return total / count;
	}
	int VehicleInventory::maxMSRP() {
		int max = 0;
		for (std::vector<Vehicle*>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
			if ((*it)->get_original_msrp() > max) {
				max = (*it)->get_original_msrp();
			}
		}
		return max;
	}
	int VehicleInventory::minMSRP() {
		int min = std::numeric_limits<int>::max();
		for (std::vector<Vehicle*>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
			if ((*it)->get_original_msrp() < min) {
				min = (*it)->get_original_msrp();
			}
		}
		return min;
	}
	int VehicleInventory::avgMileage() {
		int count = 0;
		int total = 0;
		for (std::vector<Vehicle*>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
			count += 1;
			total += (*it)->get_mileage();
		}
		return total / count;
	}
	int VehicleInventory::maxMileage() {
		int max = 0;
		for (std::vector<Vehicle*>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
			if ((*it)->get_mileage() > max) {
				max = (*it)->get_mileage();
			}
		}
		return max;
	}
	int VehicleInventory::minMileage() {
		int min = std::numeric_limits<int>::max();
		for (std::vector<Vehicle*>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
			if ((*it)->get_mileage() < min) {
				min = (*it)->get_mileage();
			}
		}
		return min;
	}
	int VehicleInventory::numVehiclesDueForOilChange() {
		int num = 0;
		for (std::vector<Vehicle*>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
			if ((*it)->dueForOilChange()) {
				num += 1;
			}
		}
		return num;
	}
}