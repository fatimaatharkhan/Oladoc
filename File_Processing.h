#pragma once
class Appointment;
class Payments;

class File_Processing {
private:
	//Doctor doctors[100];
	//Patient patients[100];
	//Appointment appointments[100];
public:
	void add_doctors(Doctor arr[], int size);
	void add_patients(Patient arr[], int size);
	int load_doctors(Doctor* arr);
	int load_patients(Patient* arr);
	bool delete_doctor(char* cnic);
	bool delete_patient(char* cnic);
	bool update_doctor(char* cnic, Doctor update);
	bool update_patient(char* cnic, Patient update);
	void add_appointment(Appointment arr[], int size);
	int load_appointments(Appointment* arr);
	//bool cancel_appointments();
	bool update_appointment(int id, Appointment update);
	void add_payments(Payments arr[], int size);
	int load_payments(Payments* arr);
};