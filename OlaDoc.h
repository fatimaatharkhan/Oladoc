#pragma once
#include "Utility.h"
#include "Admin.h"
#include "Doctor.h"
#include "Patient.h"
#include "Specialization_Area.h"
#include "File_Processing.h"
#include "DateTime.h"
#include "Appointment.h"
#include "Payments.h"

class OlaDoc {
private:
	DateTime timings;
	Utility util;
	File_Processing files;
	Admin admin;
	Doctor doctors[100];
	Patient patients[100];
	Specialization_Area specialization[4];
	Appointment appointments[100];
	Payments payments[100];
	int pay_num;
	int a_num;
	void set_specialization();
	int d_num;
	int p_num;
	void add_doctor(int, bool);
	int search_doctor_name(char*);
	void register_doctor();
	void register_patient();
	void registration_info(char* cnic, char* name, char* email, char* password, char choice);
	void login_admin();
	int login_doctor();
	int login_patient();
	int verify_doctor(char*, char*);
	int verify_patient(char*, char*);
	void verify_info(char*, char*);
	void admin_menu();
	void patient_menu(int);
	void doctor_menu(int);
	void display_doctor(int);
	void book_appointment(int doctor, int patient);
	void display_appointment(int x);
	void approve_appointments(int i);
	void reject_appointments(int i);
	bool make_payment(int d, int a_id);
	int find_patient(string cnic);
	void cancel_appointment(int p);
	bool verify_email(char* email, char x);
	bool verify_cnic(char* cnic, char x);
public:
	OlaDoc();
	void Register();
	void Login();
	//void Logout();
};