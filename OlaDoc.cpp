#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;
#include "OlaDoc.h"

OlaDoc::OlaDoc() {
	a_num = files.load_appointments(appointments);
	d_num = files.load_doctors(doctors);
	p_num = files.load_patients(patients);
	pay_num = files.load_payments(payments);
}

void OlaDoc::Register() {
	cout << endl << "----------------------------------" << endl;
	cout << "REGISTRATION" << endl;
	cout << "----------------------------------" << endl << endl;
	int choice = 0, count = 0;
	bool valid = false;
	while (valid == false && count < 3) {
		cout << "Press 1 to Register as a Doctor:" << endl;
		cout << "Press 2 to Register as a Patient:" << endl;
		cin >> choice;
		if (choice == 1) {
			register_doctor();
			valid = true;
		}
		else if (choice == 2) {
			register_patient();
			valid = true;
		}
		else {
			cout << "Invalid Option!" << endl;
			count++;
		}
	}
	if (count == 3) {
		cout << "Too many unsuccessful tries, please try again!" << endl;
	}
}

bool OlaDoc::verify_email(char* email, char choice) {
	bool valid = true;
	bool first = false;
	if (choice == 'd') {
		for (int i = 0; i < d_num; i++) {
			first = true;
			int x = 0;
			while (email[x] && valid == true) {
				if (email[x] != doctors[i].get_email()[x]) {
					valid = false;
					break;
				}
				x++;
			}
			if (valid == true) {
				cout << "This email address is already taken, please try again!" << endl;
				break;
			}
		}
		if (first == false) {
			return valid;
		}
		else
			return !valid;
	}
	else if (choice == 'p') {
		for (int i = 0; i < p_num; i++) {
			first = true;
			int x = 0;
			while (email[x] && valid == true) {
				if (email[x] != patients[i].get_email()[x]) {
					valid = false;
					break;
				}
				x++;
			}
			if (valid == true) {
				cout << "This email address is already taken, please try again!" << endl;
				break;
			}
		}
		if (first == false) {
			return valid;
		}
		else
			return !valid;
	}
}

bool OlaDoc::verify_cnic(char* cnic, char choice) {
	bool valid = true;
	bool first = false;
	if (choice == 'd') {
		for (int i = 0; i < d_num; i++) {
			first = true;
			int x = 0;
			while (cnic[x] && valid == true) {
				if (cnic[x] != doctors[i].get_cnic()[x]) {
					valid = false;
					break;
				}
				x++;
			}
			if (valid == true) {
				cout << "This cnic address is already taken, please try again!" << endl;
				break;
			}
		}
		if (first == false) {
			return valid;
		}
		else
			return !valid;
	}
	else if (choice == 'p') {
		for (int i = 0; i < p_num; i++) {
			first = true;
			int x = 0;
			while (cnic[x] && valid == true) {
				if (cnic[x] != patients[i].get_cnic()[x]) {
					valid = false;
					break;
				}
				x++;
			}
			if (valid == true) {
				cout << "This cnic address is already taken, please try again!" << endl;
				break;
			}
		}
		if (first == false) {
			return valid;
		}
		else
			return !valid;
	}
}

void OlaDoc::registration_info(char* cnic, char* name, char* email, char* password, char choice) {
	char c_password[100];
	cout << "Name: " << endl;
	cin >> name;
	bool valid = false;
	while (valid == false) {
		cout << "CNIC: ";
		cin >> cnic;
		valid = util.validate_cnic(cnic);
		if (valid == true) {
			valid = verify_cnic(cnic, choice);
		}
	}
	valid = false;
	while (valid == false) {
		cout << "Email: ";
		cin >> email;
		valid = verify_email(email, choice);
	}
	valid = false;
	while (valid == false) {
		cout << "Password: ";
		cin >> password;
		valid = util.validate_password(password);
	}
	bool same = false;
	while (same == false ) {
		cout << "Confirm Password: ";
		cin >> c_password;
		same = util.compare_password(password, c_password);
	}
}

void OlaDoc::add_doctor(int i, bool new_doc) {
	if (new_doc == true) {
		char cnic[100], name[100], password[100], email[100];
		registration_info(cnic, name, email, password, 'd');
		doctors[i].set_cnic(cnic);
		doctors[i].set_email(email);
		doctors[i].set_name(name);
		doctors[i].set_password(password);
	}
	char hospital[100], city[100];
	int years;
	float rate_i, rate_v;
	cout << "Hospital: ";
	cin >> hospital;
	doctors[i].set_hospital(hospital);
	cout << "City: ";
	cin >> city;
	doctors[i].set_city(city);
	cout << "Experience Years: ";
	cin >> years;
	doctors[i].set_experience_years(years);
	cout << "Rate for Appointments: ";
	cin >> rate_i;
	doctors[i].set_inperson_rate(rate_i);
	doctors[i].set_id(d_num);
	char s[10], e[10];
	bool correct = false;
	while (correct == false) {
		bool valid = false;
		while (valid == false) {
			cout << "Start Time (hhmm): ";
			cin >> s;
			valid = timings.validate_time(s);
		}
		valid = false;
		while (valid == false) {
			cout << "End Time (hhmm): ";
			cin >> e;
			valid = timings.validate_time(e);
		}
		correct = timings.validate_end_time(s, e);
	}
	doctors[i].set_start_time(s);
	doctors[i].set_end_time(e);
	doctors[i].set_time();
	//timings.divide_time(i, s, e, appointments, a_num);
}

void OlaDoc::display_doctor(int i) {
	cout << "|" << left << setw(23) << doctors[i].get_name() << setw(23) << doctors[i].get_hospital() << setw(26) << doctors[i].get_experience_years() << setw(24) << doctors[i].get_inperson_rate() << setw(19) << doctors[i].get_video_rate() << "|" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
	//cout << endl << "Name: " << doctors[i].get_name() << endl;
	//cout << "Hospital: " << doctors[i].get_hospital() << endl;
	//cout << "City: " << doctors[i].get_city() << endl;
	//cout << "Experience Years: " << doctors[i].get_experience_years() << endl;
	//cout << "Rate for Inperson Appointments: " << doctors[i].get_inperson_rate() << endl;
	//cout << "Rate for Video Appointments: " << doctors[i].get_video_rate() << endl << endl;
	//cout << "Start Time: " << doctors[i].get_start_time() << endl;
	//cout << "End Time: " << doctors[i].get_end_time() << endl;
}

void OlaDoc::register_doctor() {
	cout << endl << "----------------------------------" << endl;
	cout << "DOCTOR REGISTRATION" << endl;
	cout << "----------------------------------" << endl << endl;
	add_doctor(d_num, true);
	doctors[d_num].set_id(d_num + 1);
	files.add_doctors(doctors, d_num);
	d_num++;
	cout << "Doctor Registered Successfully."<<endl;
}

void OlaDoc::register_patient() {
	char cnic[100], name[100], password[100], email[100];
	cout << endl << "----------------------------------" << endl;
	cout << "PATIENT REGISTRATION" << endl;
	cout << "----------------------------------" << endl << endl;
	registration_info(cnic, name, email, password, 'p');
	patients[p_num].set_cnic(cnic);
	patients[p_num].set_email(email);
	patients[p_num].set_name(name);
	patients[p_num].set_password(password);
	patients[p_num].set_id(p_num+1);
	files.add_patients(patients, p_num);
	p_num++;
	cout << "Patient Registered Successfully." << endl;
}

void OlaDoc::Login() {
	cout << endl << "----------------------------------" << endl;
	cout << "LOGIN" << endl;
	cout << "----------------------------------" << endl << endl;
	int choice = 0, count = 0;
	//bool valid = false;
	while (choice != 4) {
		cout << "Press 1 to Login as a Admin:" << endl;
		cout << "Press 2 to Login as a Doctor:" << endl;
		cout << "Press 3 to Login as a Patient:" << endl;
		cout << "Press 4 to Leave:" << endl;
		cin >> choice;
		if (choice == 1) {
			login_admin();
		}
		else if (choice == 2) {
			login_doctor();
			//valid = true;
		}
		else if (choice == 3) {
			login_patient();
			//valid = true;
		}
		else if (choice != 4) {
			cout << "Invalid Option!" << endl;
		}
	}
}

int OlaDoc::verify_doctor(char* cnic, char* p) {
	for (int i = 0; i < d_num; i++) {
		int x = 0;
		bool valid = true;
		while (cnic[x] && valid == true) {
			if (cnic[x] != doctors[i].get_cnic()[x]) { 
				valid = false;
			}
			x++;
		}
		x = 0;
		while (p[x] && valid == true) {
			if (doctors[i].get_password()[x] != p[x]) {
				valid = false;
			}
			x++;
		}
		if (valid == true) {
			return i;
		}
	}
	return -1;
}

int OlaDoc::verify_patient(char* cnic, char* p) {
	for (int i = 0; i < p_num; i++) {
		int x = 0;
		bool valid = true;
		while (cnic[x] && valid == true) {
			if (cnic[x] != patients[i].get_cnic()[x]) {
				valid = false;
			}
			x++;
		}
		x = 0;
		if (util.findSize(p) == util.findSize(patients[i].get_password()))
		{
			while (p[x] && valid == true) {
				if (patients[i].get_password()[x] != p[x]) {
					valid = false;
				}
				x++;
			}
			if (valid == true) {
				return i;
			}
		}
		else
			valid = false;
	}
	return -1;
}

void OlaDoc::verify_info(char* cnic, char* p) {
	cout << "CNIC: ";
	cin >> cnic;
	cout << "Password: ";
	cin >> p;
}

void OlaDoc::login_admin() {
	char u[100], p[100];
	//verify_info(u, p);
	cout << "Username: ";
	cin >> u;
	cout << "Password: ";
	cin >> p;
	int x = 0;
	bool valid = true;
	while (p[x] && valid == true) {
		if (p[x] != admin.get_password()[x]) {
			valid = false;
		}
		x++;
	}
	x = 0;
	while (u[x] && valid == true) {
		if (u[x] != admin.get_username()[x]) {
			valid = false;
		}
		x++;
	}
	if (valid == true) {
		cout << "Logged In!" << endl << endl;
		admin_menu();
	}
	else
		cout << "Invalid CNIC or password, please try again!" << endl << endl;
}

void OlaDoc::admin_menu() {
	cout << endl << "----------------------------------" << endl;
	cout << "ADMIN MENU" << endl;
	cout << "----------------------------------" << endl << endl;
	int choice = 0;// , count = 0;
	//bool valid = false;
	while (choice != 6) {
		cout << "Press 1 to Add a Doctor:" << endl;
		cout << "Press 2 to View a Doctor's Information:" << endl;
		cout << "Press 3 to Edit a Doctor's Information:" << endl;
		cout << "Press 4 to Delete a Doctor's Information:" << endl;
		cout << "Press 5 to View a Patient's Information:" << endl;
		cout << "Press 6 to Logout" << endl;
		cin >> choice;
		if (choice == 1) {
			register_doctor();
			//valid = true;
		}
		else if (choice == 2) {
			char n[100];
			cout << "Doctor to View:" << endl;
			cout << "Name: ";
			cin >> n;
			int i = search_doctor_name(n);
			if (i != -1) {
				cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "| " << left << setw(20) << "Name" << setw(23) << "Hospital" << setw(26) << "Experience" << setw(25) << "Inperson Rate" << setw(20) << "Video Rate" << "|" << endl;
				cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
				display_doctor(i);
			}
			else
				cout << "We could not find a Doctor with the name you entered, please try again!" << endl << endl;
			//valid = true;
		}
		else if (choice == 3) {
			char n[100];
			cout << "Doctor to Update:" << endl;
			cout << "Name: ";
			cin >> n;
			int i = search_doctor_name(n);
			if (i != -1) {
				add_doctor(i, false);
				files.update_doctor(doctors[i].get_cnic(), doctors[i]);
			}
			else
				cout << "We could not find a Doctor with the name you entered, please try again!" << endl << endl;
			//valid = true;
		}
		else if (choice == 4) {
			char n[100];
			cout << "Doctor to Delete:" << endl;
			cout << "Name: ";
			cin >> n;
			int i = search_doctor_name(n);
			if (i != -1) {
				doctors[i].set_cnic("0");
				files.delete_doctor(doctors[i].get_cnic());
			}
			else
				cout << "We could not find a Doctor with the name you entered, please try again!" << endl << endl;
			//valid = true;
		}
		else if (choice == 5) {
			//valid = true;
		}
		else if (choice != 6) {
			cout << "Invalid Option!" << endl;
			//count++;
		}
	}
}

int OlaDoc::login_doctor() {
	char u[100], p[100];
	verify_info(u, p);
	int i = verify_doctor(u, p);
	if (i != -1) {
		cout << "Logged In!" << endl << endl;
		doctor_menu(i);
	}
	else
		cout << "Invalid CNIC or password, please try again!" << endl << endl;
	return i;
}

int OlaDoc::login_patient() {
	char u[100], p[100];
	verify_info(u, p);
	int i = verify_patient(u, p);
	if (i != -1) {
		cout << "Logged In!" << endl << endl;
		patient_menu(i);
	}
	else
		cout << "Invalid CNIC or password, please try again!" << endl << endl;
	return i;
}

int OlaDoc::search_doctor_name(char* n) {
	for (int i = 0; i < d_num; i++) {
		int x = 0;
		bool valid = true;
		while (n[x] && valid == true) {
			if (n[x] != doctors[i].get_name()[x]) {
				valid = false;
			}
			x++;
		}
		if (valid == true) {
			return i;
			break;
		}
	}
	return -1;
}

void OlaDoc::book_appointment(int x, int i) {
	cout << "Video Consultaion Rate: " << doctors[i].get_video_rate() << endl;
	cout << "Inperson Consultation: " << doctors[i].get_inperson_rate() << endl;
	cout << "Available Appointment Slots: " << endl;
	Slots* arr;
	arr = timings.divide_time(doctors[i].get_id(), doctors[i].get_start_time(), doctors[i].get_end_time(), appointments, a_num);
	int n = 0;
	bool valid = false;
	while (valid == false) {
		cout << "Which slot do you want to book: " << endl;
		cin >> n;
		if (arr[n].get_doctor_id() == -1) {
			cout << "Invalid! Please choose from the given options." << endl;
		}
		else {
			int type;
			cout << "Booked!" << endl;
			cout << "Press 1 for Video Consultation." << endl;
			cout << "Press 2 for In Person Consultation." << endl;
			cin >> type;
			appointments[a_num].set_doctor_id(doctors[i].get_id());
			appointments[a_num].set_patient_id(patients[x].get_id());
			appointments[a_num].set_status_id(0);
			appointments[a_num].set_start_time(arr[n].get_start_time());
			appointments[a_num].set_end_time(arr[n].get_end_time());
			appointments[a_num].set_appointment_id(a_num + 1);
			appointments[a_num].set_booking_date();
			appointments[a_num].set_doctor_cnic(doctors[i].get_cnic());
			appointments[a_num].set_date(arr[n].get_date());
			appointments[a_num].set_doctor_name(doctors[i].get_name());
			appointments[a_num].set_patient_cnic(patients[x].get_cnic());
			appointments[a_num].set_patient_name(patients[x].get_name());
			
			if (type == 1)
			{
				appointments[a_num].set_mode("video");
				appointments[a_num].set_payment(doctors[i].get_video_rate());

			}
			else if (type == 2)
			{
				appointments[a_num].set_mode("inperson");
				appointments[a_num].set_payment(doctors[i].get_inperson_rate());
			}
			files.add_appointment(appointments, a_num);
			a_num++;
			valid = true;
		}
	}
}

void OlaDoc::patient_menu(int x) {
	cout << endl << "----------------------------------" << endl;
	cout << "LOGIN MENU" << endl;
	cout << "----------------------------------" << endl << endl;
	int choice = 0;// , count = 0;
	//bool valid = false;
	while (choice != 8) {
		cout << "Press 1 to Edit Profile:" << endl;
		cout << "Press 2 to Search for a Doctor:" << endl;
		cout << "Press 3 to Reset Password:" << endl;
		cout << "Press 4 to Check Balance:" << endl;
		cout << "Press 5 to Recharge Account:" << endl;
		cout << "Press 6 to Make an Appointment:" << endl;
		cout << "Press 7 to Cancel an Appointment:" << endl;
		cout << "Press 8 to Logout:" << endl;
		cin >> choice;
		if (choice == 1) {
			
			//valid = true;
		}
		else if (choice == 2) {
			char n[100];
			cout << "Doctor to View:" << endl;
			cout << "Name: ";
			cin >> n;
			int i = search_doctor_name(n);
			if (i != -1) {
				cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "| " << left << setw(20) << "Name" << setw(23) << "Hospital" << setw(26) << "Experience" << setw(25) << "Inperson Rate" << setw(20) << "Video Rate" << "|" << endl;
				cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
				display_doctor(i);
			}
			else
				cout << "Doctor Not Found!" << endl;
			//valid = true;
		}
		else if (choice == 3) {
			char old[100], new_p[100], new_r[100];
			cout << "Old Password: ";
			cin >> old;
			int n = 0;
			bool correct = true;
			if (util.findSize(old) == util.findSize(patients[x].get_password())) {
				while (correct == true && n >= util.findSize(old)) {
					if (patients[x].get_password()[n] != old[n]) {
						correct = false;
					}
					n++;
				}
				if (correct == true) {
					bool v = false;
					while (v == false) {
						cout << "New Password: ";
						cin >> new_p;
						v = util.validate_password(new_p);
					}
					bool same = false;
					while (same == false) {
						cout << "Confirm Password: ";
						cin >> new_r;
						same = util.compare_password(new_p, new_r);
					}
					patients[x].set_password(new_p);
					files.update_patient(patients[x].get_cnic(), patients[x]);
				}
				else
					cout << "Wrong Password." << endl;
			}
			//valid = true;
		}
		else if (choice == 4) {
			cout << "Balance: " << patients[x].get_balance() << endl << endl;
			//valid = true;
		}
		else if (choice == 5) {
			patients[x].recharge_account();
			//valid = true;
		}
		else if (choice == 6) {
			char n[100];
			cout << "Doctor to Book an Appointment with:" << endl;
			cout << "Name: ";
			cin >> n;
			int i = search_doctor_name(n);
			if (i != -1) {
				//display_doctor(i);
				book_appointment(x, i);
			}
			else
				cout << "Doctor Not Found!" << endl;
		}
		else if (choice == 7) {
			cancel_appointment(x);
		}
		else if (choice != 8) {
			cout << "Invalid Option!" << endl;
			//count++;
		}
	}
}

void OlaDoc::display_appointment(int x) {
	struct tm b = appointments[x].get_booking_date();
	b = appointments[x].get_date();
	string status;
	if (appointments[x].get_status_id() == 0) {
		status = "Pending"; 
	}
	else if (appointments[x].get_status_id() == 1) {
		status = "Approved";
	}
	else if (appointments[x].get_status_id() == 2) {
		status = "Rejected";
	}
	
	cout << "| " << left << setw(20) << appointments[x].get_appointment_id() << setw(20) << appointments[x].get_doctor_name() << setw(20) << appointments[x].get_patient_name() << appointments[x].get_start_time() << " - " << setw(20) << appointments[x].get_end_time() << b.tm_year << "/" << b.tm_mon << "/" << setw(20) << b.tm_mday << setw(20) << appointments[x].get_mode() << setw(20) << appointments[x].get_payment() << setw(8) << status << " | " << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	//cout << endl << "Appointment ID: " << appointments[x].get_appointment_id() << endl;
	//cout << "Doctor: " << appointments[x].get_doctor_name() << endl;
	//cout << "Patient: " << appointments[x].get_patient_name() << endl;
	//cout << "Start Time: " << appointments[x].get_start_time() << endl;
	//cout << "End Time: " << appointments[x].get_end_time() << endl;
	//cout << "Date of Appointment: " << b.tm_year << "/" << b.tm_mon << "/" << b.tm_mday << endl;
	//cout << "Consultation Type: " << appointments[x].get_mode() << endl;
	//cout << "Payment: " << appointments[x].get_payment() << endl;
	//cout << "Appointment Booked On: " << b.tm_year << "/" << b.tm_mon << "/" << b.tm_mday << endl << endl;
	
}

int OlaDoc::find_patient(string cnic) {
	for (int i = 0; i < p_num; i++) {
		int x = 0;
		bool valid = true;
		while (cnic[x] && valid == true) {
			if (cnic[x] != patients[i].get_cnic()[x]) {
				valid = false;
			}
			x++;
		}
		if (valid == true) {
			return i;
		}
	}
	return -1;
}

bool OlaDoc::make_payment(int d, int id) {
	int p = find_patient(appointments[id].get_patient_cnic());
	if (p != -1) {
		if (patients[p].get_balance() < appointments[id].get_payment()) {
			cout << "The Patient's balance is not enough." << endl;
			return false;
		}
		else {
			cout << "Transaction done." << endl;
			payments[pay_num].set_doctor_cnic(doctors[d].get_cnic());
			payments[pay_num].set_patient_cnic(patients[p].get_cnic());
			payments[pay_num].set_patient_cnic(patients[p].get_cnic());
			payments[pay_num].set_payments_id(pay_num + 1);
			payments[pay_num].set_payment_time();
			patients[p].make_payment(appointments[id].get_payment());
			doctors[d].add_balance(appointments[id].get_payment());
			files.update_patient(patients[p].get_cnic(), patients[p]);
			files.update_doctor(doctors[d].get_cnic(), doctors[d]);
			files.add_payments(payments, pay_num);
			pay_num++;
			return true;
		}
	}
}

void OlaDoc::approve_appointments(int i) {
	bool again = false, valid = true;
	int id;
	do{
		cout << "Please enter the Appointment ID you want to approve: ";
		cin >> id;
		int a = 0;
		valid = true;
		while (appointments[id-1].get_doctor_cnic()[a] && valid == true) {
			if (appointments[id-1].get_doctor_cnic()[a] != doctors[i].get_cnic()[a]) {
				valid = false;
				break;
			}
			a++;
		}
		if (valid == true) {
			if (make_payment(i, id - 1) == true) {
				appointments[id - 1].set_status_id(1);
				cout << "Approved!" << endl;
				files.update_appointment(id, appointments[id - 1]);
			}
			else
				cout << "Unsuccessful!" << endl;
		}
		int x = 0;
		cout << "Press 1 if you want to approve another appointment and 2 to go back: " << endl;
		cin >> x;
		if (x == 1) {
			again = true;
		}
		else
			again = false;
	} while (again == true);
}

void OlaDoc::reject_appointments(int i) {
	bool again = false, valid = true;
	int id;
	do {
		cout << "Please enter the Appointment ID you want to Reject: ";
		cin >> id;
		int a = 0;
		valid = true;
		while (appointments[id - 1].get_doctor_cnic()[a] && valid == true) {
			if (appointments[id - 1].get_doctor_cnic()[a] != doctors[i].get_cnic()[a]) {
				valid = false;
				break;
			}
			a++;
		}
		if (valid == true) {
			appointments[id - 1].set_status_id(2);
			cout << "Rejected." << endl;
			files.update_appointment(id, appointments[id - 1]);
		}
		int x = 0;
		cout << "Press 1 if you want to reject another appointment and 2 to go back: " << endl;
		cin >> x;
		if (x == 1) {
			again = true;
		}
		else
			again = false;
	} while (again == true);
}

void OlaDoc::cancel_appointment(int p) {
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "| " << left << setw(20) << "ID" << setw(20) << "Doctor" << setw(23) << "Patient" << setw(26) << "Time" << setw(25) << "Date" << setw(20) << "Type" << setw(20) << "Payment" << setw(8) << "Status" << "|" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < a_num; i++) {
		bool valid = true;
		int a = 0;
		while (appointments[i].get_patient_cnic()[a] && valid == true) {
			if (appointments[i].get_patient_cnic()[a] != patients[p].get_cnic()[a]) {
				valid = false;
				break;
			}
			a++;
		}
		if (valid) {
			display_appointment(i);
		}
	}
	int id;
	cout << "Please enter the ID of the appointment you want to cancel: ";
	cin >> id;
	int a = 0;
	bool valid = true;
	while (appointments[id - 1].get_patient_cnic()[a] && valid == true) {
		if (appointments[id - 1].get_doctor_cnic()[a] != patients[p].get_cnic()[a]) {
			valid = false;
			break;
		}
		a++;
	}
	if (valid == true) {
		appointments[id - 1].set_status_id(2);
		cout << "Cancelled." << endl;
		payments[pay_num].set_doctor_cnic(appointments[id - 1].get_doctor_cnic());
		payments[pay_num].set_patient_cnic(appointments[id - 1].get_patient_cnic());
		payments[pay_num].set_payments_id(pay_num + 1);
		payments[pay_num].set_payment_time();
		int diff = payments[pay_num].get_payment_time().tm_mday - appointments[id - 1].get_date().tm_mday;
		if (diff == 0) {
			payments[pay_num].set_amount(-(appointments[id - 1].get_payment()));
		}
		else if (diff == 1) {
			payments[pay_num].set_amount(-((60.0 / 100.0) * appointments[id - 1].get_payment()));
		}
		else if (diff == 2) {
			payments[pay_num].set_amount(-((30.0 / 100.0)* appointments[id - 1].get_payment()));
		}
		patients[p].make_payment(payments[pay_num].get_amount());
		int i = search_doctor_name(appointments[id - 1].get_doctor_name());
		doctors[i].add_balance(-(appointments[id - 1].get_payment() - payments[pay_num].get_amount()));
		files.update_appointment(id, appointments[id - 1]);
		files.update_doctor(doctors[i].get_cnic(), doctors[i]);
		files.update_patient(patients[p].get_cnic(), patients[p]);
	}
}
void OlaDoc::doctor_menu(int i) {
	cout << endl << "----------------------------------" << endl;
	cout << "LOGIN MENU" << endl;
	cout << "----------------------------------" << endl << endl;
	int choice = 0;// , count = 0;
	//bool valid = false;
	while (choice != 5) {
		cout << "Press 1 to Edit Profile:" << endl;
		//cout << "Press 2 to hi:" << endl;
		cout << "Press 2 to Reset Password:" << endl;
		cout << "Press 3 to View Today's Appointments:" << endl;
		cout << "Press 4 to View Pending Appointments:" << endl;
		cout << "Press 5 to Logout:" << endl;
		cin >> choice;
		if (choice == 1) {
			//valid = true;
		}
		//else if (choice == 2) {
		//	//valid = true;
		//}
		else if (choice == 2) {
			char old[100], new_p[100], new_r[100];
			cout << "Old Password: ";
			cin >> old;
			int n = 0;
			bool correct = true;
			if (util.findSize(old) == util.findSize(doctors[i].get_password())) {
				while (correct == true && n >= util.findSize(old)) {
					if (doctors[i].get_password()[n] != old[n]) {
						correct = false;
					}
					n++;
				}
				if (correct == true) {
					bool v = false;
					while (v == false) {
						cout << "New Password: ";
						cin >> new_p;
						v = util.validate_password(new_p);
					}
					bool same = false;
					while (same == false) {
						cout << "Confirm Password: ";
						cin >> new_r;
						same = util.compare_password(new_p, new_r);
					}
					doctors[i].set_password(new_p);
					files.update_doctor(doctors[i].get_cnic(), doctors[i]);
				}
				else
					cout << "Wrong Password." << endl;
			}
			//valid = true;
		}
		else if (choice == 3) {
			struct tm buf;
			time_t t = time(NULL);
			localtime_s(&buf, &t);
			buf.tm_year += 1900;
			buf.tm_mon += 1;
			buf.tm_mday;
			bool correct = true;
			cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "| " << left << setw(20) << "ID" << setw(20) << "Doctor" << setw(23) << "Patient" << setw(26) << "Time" << setw(25) << "Date" << setw(20) << "Type" << setw(20) << "Payment" << setw(8) << "Status" << " | " << endl;
			cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			for (int x = 0; x < a_num; x++) {
				int a = 0;
				while (appointments[x].get_doctor_cnic()[a] && correct == true) {
					if (appointments[x].get_doctor_cnic()[a] != doctors[i].get_cnic()[a]) {
						correct = false;
						break;
					}
					a++;
				}
				if (correct == true && appointments[x].get_status_id() == 1 && appointments[x].get_date().tm_year == buf.tm_year && appointments[x].get_date().tm_mday == buf.tm_mday && appointments[x].get_date().tm_mon == buf.tm_mon) {
					display_appointment(x);
				}
			}
			//valid = true;
		}
		else if (choice == 4) {
			cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "| " << left << setw(20) << "ID" << setw(20) << "Doctor" << setw(23) << "Patient" << setw(26) << "Time" << setw(25) << "Date" << setw(20) << "Type" << setw(20) << "Payment" << setw(8) << "Status" << " | " << endl;
			cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			for (int x = 0; x < a_num; x++) {
				int a = 0;
				bool valid = true;
				while (appointments[x].get_doctor_cnic()[a] && valid == true) {
					if (appointments[x].get_doctor_cnic()[a] != doctors[i].get_cnic()[a]) {
						valid = false;
						break;
					}
					a++;
				}
				if (valid == true && appointments[x].get_status_id() == 0) {
					display_appointment(x);
				}
			}
			string choice;
			cout << "Type A if you want to approve an appointment:" << endl;
			cout << "Type R if you want to reject an appointment: " << endl;
			cin >> choice;
			if (choice == "A" || choice == "a") {
				approve_appointments(i);
			}
			else if (choice == "r" || choice == "R") {
				reject_appointments(i);
			}
			//valid = true;
		}
		else if (choice != 5) {
			cout << "Invalid Option!" << endl;
			//count++;
		}
	}
}

void OlaDoc::set_specialization() {
	char x[100] = "Gynaecologist";
	char x1[100] = "Dermatologist";
	char x2[100] = "Oncologist";
	char x3[100] = "Orthopedic";
	int i = util.findSize(x);
	specialization[0].set_description(x, i);
	specialization[0].set_ID(1);
	i = util.findSize(x1);
	specialization[1].set_description(x1, i);
	specialization[1].set_ID(2);
	i = util.findSize(x2);
	specialization[2].set_description(x2, i);
	specialization[2].set_ID(3);
	i = util.findSize(x3);
	specialization[3].set_description(x3, i);
	specialization[3].set_ID(4);
}