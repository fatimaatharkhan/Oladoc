#pragma once
class Payments {
private:
	char patient_cnic[100];
	char doctor_cnic[100];
	//char doctor_id[100];
	int id;
	//int Patient_ID;
	float payment;
	//char patient_name[100];
	//char doctor_name[100];
	struct tm payment_time;
	float amount;
public:
	void set_amount(float);
	float get_amount();
	void set_payments_id(int);
	//void set_patient_id(int);
	int get_payments_id();
	//int get_patient_id();
	void set_patient_cnic(string c);
	void set_doctor_cnic(string c);
	char* get_doctor_cnic();
	char* get_patient_cnic();
	//void set_patient_name(string n);
	//void set_doctor_name(string n);
	//char* get_doctor_name();
	//char* get_patient_name();
	void set_payment_time();
	tm get_payment_time();
};

