#include <iostream>
using namespace std;
#include "Slots.h"

Slots::Slots() {
	Doctor_ID = -1;
}

void Slots::set_date(int x) {
	time_t t = time(NULL);
	localtime_s(&buf, &t);
	buf.tm_year += 1900;
	buf.tm_mon += 1;
	buf.tm_mday += x + 1;// += x;
}

void Slots::set_start_time(string s) {
	strcpy_s(this->start_time, s.c_str());
}

void Slots::set_end_time(string e) {
	strcpy_s(this->end_time, e.c_str());
}


char* Slots::get_start_time() {
	return start_time;
}

char* Slots::get_end_time() {
	return end_time;
}

void Slots::set_doctor_id(int id) {
	Doctor_ID = id;
}

int Slots::get_doctor_id() {
	return Doctor_ID;
}

tm Slots::get_date() {
	return buf;
}