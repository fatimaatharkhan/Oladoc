#include <iostream>
using namespace std;
#include "Appointment.h"


Appointment::Appointment() {
	//Doctor_ID = -1;
	Patient_ID = -1;
	status_id = -1;
	id = -1;
	payment = 0.0;
}

void Appointment::set_appointment_id(int i) {
	id = i;
}

void Appointment::set_patient_id(int id) {
	Patient_ID = id;
}

void Appointment::set_status_id(int id) {
	status_id = id;
}

int Appointment::get_appointment_id() {
	return id;
}

int Appointment::get_patient_id() {
	return Patient_ID;
}

int Appointment::get_status_id() {
	return status_id;
}

void Appointment::set_booking_date() {
	time_t t = time(NULL);
	localtime_s(&selected_date, &t);
	selected_date.tm_year += 1900;
	selected_date.tm_mon += 1;
	selected_date.tm_mday;
}

void Appointment::set_payment(float p) {
	payment = p;
}

float Appointment::get_payment() {
	return payment;
}

//void Appointment::set_date() {
//	time_t t = time(NULL);
//	localtime_s(&selected_date, &t);
//	selected_date.tm_year += 1900;
//	selected_date.tm_mon += 1;
//	selected_date.tm_mday + 1;
//}

tm Appointment::get_date() {
	return selected_date;
}

tm Appointment::get_booking_date() {
	return buf;
}

void Appointment::set_mode(string c) {
	strcpy_s(this->mode, c.c_str());
}

void Appointment::set_patient_cnic(string c) {
	strcpy_s(this->patient_cnic, c.c_str());
}

void Appointment::set_doctor_name(string n) {
	strcpy_s(this->doctor_name, n.c_str());
}

void Appointment::set_doctor_cnic(string c) {
	strcpy_s(this->doctor_cnic, c.c_str());
}

void Appointment::set_patient_name(string n) {
	strcpy_s(this->patient_name, n.c_str());
}

char* Appointment::get_patient_cnic() {
	return patient_cnic;
}

char* Appointment::get_patient_name() {
	return patient_name;
}

char* Appointment::get_doctor_cnic() {
	return doctor_cnic;
}

char* Appointment::get_doctor_name() {
	return doctor_name;
}

char* Appointment::get_mode() {
	return mode;
}

void Appointment::set_date(tm b) {
	buf = b;
}