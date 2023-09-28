#include <iostream>
using namespace std;
#include "Specialization_Area.h"

Specialization_Area::Specialization_Area() {
	ID = 0;
	//description = "";
}

void Specialization_Area::set_description(char* d,int x) {
	for (int i = 0; i < x; i++) {
		description[i] = d[i];
	}
}

void Specialization_Area::set_ID(int id) {
	ID = id;
}

char* Specialization_Area::get_description() {
	return description;
}

int Specialization_Area::get_ID() {
	return ID;
}