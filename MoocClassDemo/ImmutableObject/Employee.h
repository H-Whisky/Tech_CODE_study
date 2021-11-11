#pragma once
#include <iostream>
#include <string>
enum class Gender {
	male,
	famale,
};

class Emplyee {
private:
	std::string name;
	Gender gender;
	Date birthday;
public:
	void setName(std::string name) { this->name = name; }
	void setGender(Gender gender) { this->gender = gender; }
	void setBirthday(Date birthday) { this->birthday = birthday; }
	std::string getName() { return name; }
	Gender getGender() { return gender; }
	Date* getBirthday() { return &birthday; }//
	std::string toString() {
		return (name + (gender == Gender::male ? std::string("male") : std::string("female")) + birthday.toString());
	}
	Emplyee(std::string name, Gender gender, Date birthday) :name{ name }, gender{ gender }, birthday{ birthday }{};
	Emplyee() :Emplyee("HW", Gender::male, Date(2000, 4, 1)){};
};