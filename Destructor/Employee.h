#pragma once
#include <iostream>
#include <string>
#include "Date.h"
enum class Gender {
	male,
	famale,
};

class Emplyee {
private:
	std::string name;
	Gender gender;
	Date* birthday;
	static int numberOfObjects;
public:
	void setName(std::string name) { this->name = name; }
	void setGender(Gender gender) { this->gender = gender; }
	void setBirthday(Date birthday) { *(this->birthday) = birthday; }
	std::string getName() { return name; }
	Gender getGender() { return gender; }
	Date getBirthday() { return *birthday; }//
	std::string toString() {
		return (name + (gender == Gender::male ? std::string("male") : std::string("female")) + birthday->toString());
	}
	Emplyee(std::string name, Gender gender, Date birthday) :name{ name }, gender{ gender }{
		numberOfObjects++;
		this->birthday = new Date{ birthday};
		std::cout << "Now there are:" << numberOfObjects << "employees" << std::endl;
	};
	Emplyee() :Emplyee("HW", Gender::male, Date(2000, 4, 1)) {};
	~Emplyee() {
		numberOfObjects--;
		delete birthday;
		birthday = nullptr;
		std::cout << "Now there are:" << numberOfObjects << "employees" << std::endl;
	}
};
