#include "Employee.h"

void Emplyee::setName(std::string name) {
	this -> name = name;
}

void Emplyee::setGender(Gender gender) {
	this->gender = gender;
}

void Emplyee::setBirthday(Date Birthday) {
	this->birthday = birthday;
}

std::string Emplyee::getName() {
	return name;
}

Gender Emplyee::getGender() {
	return gender;
}

Date Emplyee::getBirthday() {
	return *birthday;
}

std::string Emplyee::toString() {
	return (name + (gender == Gender::male ? std::string("male") : std::string("female")) + birthday->toString());
}

Emplyee::Emplyee(std::string name, Gender gender, Date birthday) :name{ name }, gender{ gender }{
	numberOfObjects++;
	this->birthday = new Date{ birthday };
	std::cout << "Now there are:" << numberOfObjects << "employees" << std::endl;
};

Emplyee::Emplyee()
	: Emplyee("Alan", Gender::male, Date(2000, 4, 1)) {};

Emplyee::Emplyee(const Emplyee& e) {
	this->birthday = new Date{ *(e.birthday) };
	numberOfObjects++;
}

Emplyee::~Emplyee() {
	numberOfObjects--;
	delete birthday;
	birthday = nullptr;
	std::cout << "Now there are:" << numberOfObjects << "employees" << std::endl;
}