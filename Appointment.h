#pragma once
#include "Slots.h"

class Appointment : public Slots {
private:
	char patient_cnic[100];
	char doctor_cnic[100];
	char doctor_id[100];
	int id;
	int Patient_ID;
	int status_id;
	float payment;
	char mode[100];
	char patient_name[100];
	char doctor_name[100];
	tm selected_date;
public:
	Appointment();
	void set_appointment_id(int);
	void set_patient_id(int);
	void set_status_id(int);
	int get_appointment_id();
	int get_patient_id();
	int get_status_id();
	void set_booking_date();
	void set_payment(float);
	float get_payment();
	void set_date(tm b);
	tm get_booking_date();
	tm get_date();
	void set_patient_cnic(string c);
	void set_doctor_cnic(string c);
	char* get_doctor_cnic();
	char* get_patient_cnic();
	void set_patient_name(string n);
	void set_doctor_name(string n);
	char* get_doctor_name();
	char* get_patient_name();
	void set_mode(string m);
	char* get_mode();
};