#pragma once 
#include "Vehicle.h"
#include "ManufacturerInfo.h"
#include <string>

namespace CarLibrary {
	Vehicle::Vehicle(int vin, int year, int weight, int original_msrp, int mileage, std::string make, std::string model, std::string color, ManufacturerInfo man_info, int lastOilChangeDate, int lastOilChangeMileage) {
		this->vin = vin;
		this->year = year;
		this->weight = weight;
		this->original_msrp = original_msrp;
		this->mileage = mileage;
		this->make = make;
		this->model = model;
		this->color = color;
		this->man_info = man_info;
		this->lastOilChangeDate = lastOilChangeDate;
		this->lastOilChangeMileage = lastOilChangeMileage;
	}

	int Vehicle::get_vin() {
		return vin;
	}
	int  Vehicle::get_year() {
		return year;
	}
	int  Vehicle::get_weight() {
		return weight;
	}
	int  Vehicle::get_original_msrp() {
		return original_msrp;
	}
	int  Vehicle::get_mileage() {
		return mileage;
	}
	void Vehicle::set_mileage(int new_mileage) {
		mileage = new_mileage;
	}
	std::string  Vehicle::get_make() {
		return make;
	}
	std::string  Vehicle::get_model() {
		return model;
	}
	std::string Vehicle::get_color() {
		return color;
	}
	ManufacturerInfo Vehicle::get_manufacturer_info() {
		return man_info;
	}
	bool Vehicle::dueForOilChange() {
		// Didn't get around to using actual dates, so I just hardcoded in an int to represent a day.
		int currentDay = 200;
		if (mileage - lastOilChangeMileage >= 3000 || currentDay - lastOilChangeDate >= 90) {
			return true;
		}
		return false;
	}

	std::string Vehicle::toString() {
		return "VIN: " + std::to_string(vin) + "\n"
			+ "Year: " + std::to_string(year) + "\n"
			+ "Weight: " + std::to_string(weight) + "\n"
			+ "Original MSRP: " + std::to_string(original_msrp) + "\n"
			+ "Mileage: " + std::to_string(mileage) + "\n"
			+ "Make: " + make + "\n"
			+ "Model: " + model + "\n"
			+ "Color: " + color + "\n"
			+ man_info.toString();
	}
}