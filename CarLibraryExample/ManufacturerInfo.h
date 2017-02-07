#pragma once
#include <string>

namespace CarLibrary
{
	class ManufacturerInfo {
	private:
		std::string name;
		std::string address;
		std::string phone_number;
	public:
		ManufacturerInfo(std::string name, std::string address, std::string phone_number);
		ManufacturerInfo();
		std::string getName();
		std::string getAddress();
		std::string getPhoneNumber();
		std::string toString();
	};
}
