#include <iostream>
using namespace std;
#include "Doctor.h"
//#include "Schedule.h"

Doctor::Doctor() {
	inperson_rate = 0.0;
	video_rate = 0.0;
	experience_years = 0;
	id = 0;
}

void Doctor::set_time() {
	time_t t = time(NULL);
	localtime_s(&buf, &t);
}

void Doctor::set_city(string c) {
	strcpy_s(this->city, c.c_str());
}

void Doctor::set_experience_years(int e) {
	experience_years = e;
}

void Doctor::set_hospital(string h) {
	strcpy_s(this->hospital, h.c_str());
}

void Doctor::set_inperson_rate(float i) {
	inperson_rate = i;
	set_video_rate();
}

void Doctor::set_video_rate() {
	video_rate = (70.0 / 100.0) * inperson_rate;
}

void Doctor::add_balance(float b) {
	balance += b;
}

char* Doctor::get_city() {
	return city;
}

char* Doctor::get_hospital() {
	return hospital;
}

int Doctor::get_experience_years() {
	return experience_years;
}

float Doctor::get_inperson_rate() {
	return inperson_rate;
}

float Doctor::get_video_rate() {
	return video_rate;
}

float Doctor::get_balance() {
	return balance;
}

void Doctor::set_start_time(string s) {
	strcpy_s(this->start_time, s.c_str());
}

void Doctor::set_end_time(string e) {
	strcpy_s(this->end_time, e.c_str());
}


char* Doctor::get_start_time() {
	return start_time;
}

char* Doctor::get_end_time() {
	return end_time;
}