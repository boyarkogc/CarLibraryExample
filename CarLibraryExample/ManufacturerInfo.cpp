#pragma once 
#include "ManufacturerInfo.h"
#include <string>

namespace CarLibrary {
	ManufacturerInfo::ManufacturerInfo(std::string name, std::string address, std::string phone_number) {
		this->name = name;
		this->address = address;
		this->phone_number = phone_number;
	}
	ManufacturerInfo::ManufacturerInfo() {
		this->name = "";
		this->address = "";
		this->phone_number = "";
	}
	std::string ManufacturerInfo::getName() {
		return name;
	}
	std::string ManufacturerInfo::getAddress() {
		return address;
	}
	std::string ManufacturerInfo::getPhoneNumber() {
		return phone_number;
	}
	std::string ManufacturerInfo::toString() {
		return "Manufacturer: " + name + "\n"
			+ "Address: " + address + "\n"
			+ "Phone number: " + phone_number + "\n";
	}
}