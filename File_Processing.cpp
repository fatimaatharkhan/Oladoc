#include <iostream>
#include <fstream>
using namespace std;
#include "Appointment.h"
#include "Doctor.h"
#include "Patient.h"
#include "Payments.h"
#include "File_Processing.h"

void File_Processing::add_doctors(Doctor arr[], int size) {
	ofstream my_file("doctors.dat", ios::binary | ios::app);
	my_file.write((char*)&arr[size], sizeof(arr[size]));
	my_file.close();
}

void File_Processing::add_patients(Patient arr[], int size) {
	ofstream my_file("patients.dat", ios::binary | ios::app);
	my_file.write((char*)&arr[size], sizeof(arr[size]));
	my_file.close();
}

int File_Processing::load_doctors(Doctor* arr)
{
	Doctor temp;
	ifstream my_file("doctors.dat", ios::binary);
	int i = 0;
	while (my_file.read((char*)&temp, sizeof(temp)))
	{
		arr[i] = temp;
		i++;
	}
	my_file.close();
	return i;
}

int File_Processing::load_patients(Patient* arr)
{
	Patient temp;
	ifstream my_file("patients.dat", ios::binary);
	int i = 0;
	while (my_file.read((char*)&temp, sizeof(temp)))
	{
		arr[i] = temp;
		i++;
	}
	my_file.close();
	return i;
}

bool File_Processing::delete_doctor(char* cnic)
{
	string file = "doctors.dat";
	fstream my_file(file, ios::in | ios::out | ios::binary);
	fstream my_file2("temp.dat", ios::binary | ios::in | ios::out | ios::app);
	Doctor temp;
	bool done = false;
	while (my_file.read((char*)&temp, sizeof(temp))) {
		if (temp.get_cnic() == cnic) {
			done = false;
		}
		else {
			done = true;
			my_file2.write((char*)&temp, sizeof(temp));
		}
	}
	my_file.close();
	my_file2.close();
	remove(file.c_str());
	rename("temp.dat", file.c_str());
	return done;
}

bool File_Processing::delete_patient(char* cnic)
{
	string file = "patients.dat";
	fstream my_file(file, ios::in | ios::out | ios::binary);
	fstream my_file2("temp.dat", ios::binary | ios::in | ios::out | ios::app);
	Patient temp;
	bool done = false;
	while (my_file.read((char*)&temp, sizeof(temp))) {
		if (temp.get_cnic() == cnic) {
			done = false;
		}
		else {
			done = true;
			my_file2.write((char*)&temp, sizeof(temp));
		}
	}
	my_file.close();
	my_file2.close();
	remove(file.c_str());
	rename("temp.dat", file.c_str());
	return done;
}

bool File_Processing::update_doctor(char* cnic, Doctor update)
{
	string file = "doctors.dat";
	fstream my_file(file, ios::in | ios::out | ios::binary);
	fstream my_file2("temp.dat", ios::binary | ios::in | ios::out | ios::app);
	Doctor temp;
	bool done = false;
	while (my_file.read((char*)&temp, sizeof(temp))) {
		if (temp.get_cnic() == cnic) {
			my_file2.write((char*)&update, sizeof(update));
			done = false;
		}
		else {
			done = true;
			my_file2.write((char*)&temp, sizeof(temp));
		}
	}
	my_file.close();
	my_file2.close();
	remove(file.c_str());
	rename("temp.dat", file.c_str());
	return done;
}

bool File_Processing::update_patient(char* cnic, Patient update)
{
	string file = "patients.dat";
	fstream my_file(file, ios::in | ios::out | ios::binary);
	fstream my_file2("temp.dat", ios::binary | ios::in | ios::out | ios::app);
	Patient temp;
	bool done = false;
	while (my_file.read((char*)&temp, sizeof(temp))) {
		if (temp.get_cnic() == cnic) {
			my_file2.write((char*)&update, sizeof(update));
			done = false;
		}
		else {
			done = true;
			my_file2.write((char*)&temp, sizeof(temp));
		}
	}
	my_file.close();
	my_file2.close();
	remove(file.c_str());
	rename("temp.dat", file.c_str());
	return done;
}

void File_Processing::add_appointment(Appointment arr[], int size) {
	ofstream my_file("appointments.dat", ios::binary | ios::app);
	my_file.write((char*)&arr[size], sizeof(arr[size]));
	my_file.close();
}

int File_Processing::load_appointments(Appointment* arr)
{
	Appointment temp;
	ifstream my_file("appointments.dat", ios::binary);
	int i = 0;
	while (my_file.read((char*)&temp, sizeof(temp)))
	{
		arr[i] = temp;
		i++;
	}
	my_file.close();
	return i;
}

bool File_Processing::update_appointment(int id, Appointment update)
{
	string file = "appointments.dat";
	fstream my_file(file, ios::in | ios::out | ios::binary);
	fstream my_file2("temp.dat", ios::binary | ios::in | ios::out | ios::app);
	Appointment temp;
	bool done = false;
	while (my_file.read((char*)&temp, sizeof(temp))) {
		if (temp.get_appointment_id() == id) {
			my_file2.write((char*)&update, sizeof(update));
			done = false;
		}
		else {
			done = true;
			my_file2.write((char*)&temp, sizeof(temp));
		}
	}
	my_file.close();
	my_file2.close();
	remove(file.c_str());
	rename("temp.dat", file.c_str());
	return done;
}

void File_Processing::add_payments(Payments arr[], int size) {
	ofstream my_file("payments.dat", ios::binary | ios::app);
	my_file.write((char*)&arr[size], sizeof(arr[size]));
	my_file.close();
}

int File_Processing::load_payments(Payments* arr) {
	Payments temp;
	ifstream my_file("payments.dat", ios::binary);
	int i = 0;
	while (my_file.read((char*)&temp, sizeof(temp)))
	{
		arr[i] = temp;
		i++;
	}
	my_file.close();
	return i;
}