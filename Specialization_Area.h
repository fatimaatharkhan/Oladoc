#pragma once
class Specialization_Area {
private:
	int ID;
	char description[100];
public:
	Specialization_Area();
	void set_ID(int);
	void set_description(char*, int);
	int get_ID();
	char* get_description();
};