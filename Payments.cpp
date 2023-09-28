#include <iostream>
using namespace std;
#include "Payments.h"

void Payments::set_patient_cnic(string c) {
	strcpy_s(this->patient_cnic, c.c_str());
}

//void Payments::set_doctor_name(string n) {
//	strcpy_s(this->doctor_name, n.c_str());
//}

void Payments::set_doctor_cnic(string c) {
	strcpy_s(this->doctor_cnic, c.c_str());
}

//void Payments::set_patient_name(string n) {
//	strcpy_s(this->patient_name, n.c_str());
//}

char* Payments::get_patient_cnic() {
	return patient_cnic;
}

//char* Payments::get_patient_name() {
//	return patient_name;
//}

char* Payments::get_doctor_cnic() {
	return doctor_cnic;
}

//char* Payments::get_doctor_name() {
//	return doctor_name;
//}

void Payments::set_payments_id(int i) {
	id = i;
}

//void Payments::set_patient_id(int id) {
//	Patient_ID = id;
//}

int Payments::get_payments_id() {
	return id;
}

//int Payments::get_patient_id() {
//	return Patient_ID;
//}

void Payments::set_payment_time() {
	time_t t = time(NULL);
	localtime_s(&payment_time, &t);
	payment_time.tm_year += 1900;
	payment_time.tm_mon += 1;
	payment_time.tm_mday;
}

tm Payments::get_payment_time() {
	return payment_time;
}

void Payments::set_amount(float a) {
	amount = a;
}

float Payments::get_amount() {
	return amount;
}