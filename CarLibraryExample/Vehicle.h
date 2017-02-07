#pragma once 
#include <string>
#include "ManufacturerInfo.h"

namespace CarLibrary
{
	class Vehicle 
	{
	private:
		int vin;
		int year;
		//weight in pounds
		int weight;
		int original_msrp;
		int mileage;
		std::string make;
		std::string model;
		std::string color;
		ManufacturerInfo man_info;

		int lastOilChangeDate;
		int lastOilChangeMileage;

	public:
		Vehicle(int vin, int year, int weight, int original_msrp, int mileage, std::string make, std::string model, std::string color, ManufacturerInfo man_info, int lastOilChangeDate, int lastOilChangeMileage);
		int get_vin();
		int get_year();
		int get_weight();
		int get_original_msrp();
		int get_mileage();
		void set_mileage(int new_mileage);
		std::string get_make();
		std::string get_model();
		std::string get_color();
		ManufacturerInfo get_manufacturer_info();

		int getLastOilChangeDate();
		int getLastOilChangeMileage();

		bool dueForOilChange();
		virtual std::string toString();
	};
}