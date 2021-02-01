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
	void setName(std::string name);
	void setGender(Gender gender);
	void setBirthday(Date birthday);
	std::string getName();
	Gender getGender();
	Date getBirthday();//
	std::string toString();
	Emplyee(std::string name, Gender gender, Date birthday);
	Emplyee();
	Emplyee(const Emplyee& e);
	~Emplyee();
};
