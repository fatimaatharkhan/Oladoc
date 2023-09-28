#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include "DateTime.h"

int DateTime::find_size(char* s) {
	for (int i = 0; ; i++)
		if (s[i] == 0)
			return i;
	return 0;
}

bool DateTime::validate_time(char* t) {
	if (find_size(t) == 4) {
		string h, m;
		h = string(1,t[0]) + t[1];
		m = string(1, t[2]) + t[3];
		int hrs = stoi(h);
		int min = stoi(m);
		if (hrs >= 0 && hrs <= 23 && min >= 0 && min <= 59)
		{
			return true;
		}
		else { 
			cout << "Invalid Time!" << endl;
			return false;
		}
	}
	else {
		cout << "Invalid Format: " << endl;
		return false;
	}
}

bool DateTime::validate_end_time(char* s, char* e) {
	string s_h, s_m;
	s_h = string(1, s[0]) + s[1];
	s_m = string(1, s[2]) + s[3];
	int s_hrs = stoi(s_h);
	int s_min = stoi(s_m);
	string e_h, e_m;
	e_h = string(1, e[0]) + e[1];
	e_m = string(1, e[2]) + e[3];
	int e_hrs = stoi(e_h);
	int e_min = stoi(e_m);
	if (e_hrs < s_hrs) {
		cout << "The End time cannot be lesser than start time, please try again!" << endl;
		return false;
	}
	else {
		return true;
	}
}

Slots* DateTime::divide_time(int doctor_id, char* st, char* et, Appointment appointments[], int a_num) {
	Slots arr[50];
	int a = 1;
	cout << "------------------------------------------" << endl;
	cout << "|" << left << setw(15) << "Slot No." << setw(18) << "Date" << setw(7) << "Time" << "|" << endl;
	cout << "------------------------------------------" << endl;
	for (int x = 0; x < 2; x++) {
		string s_h, s_m;
		s_h = string(1, st[0]) + st[1];
		s_m = string(1, st[2]) + st[3];
		int s_hrs = stoi(s_h);
		int s_min = stoi(s_m);
		string e_h, e_m;
		e_h = string(1, et[0]) + et[1];
		e_m = string(1, et[2]) + et[3];
		int e_hrs = stoi(e_h);
		int e_min = stoi(e_m);
		int i = 0;
		while (s_hrs <= e_hrs) {
			if (s_hrs + 1 > e_hrs && s_min >= e_min) {
				break;
			}
			
			string s;
			if (s_hrs > 9 && s_min > 9)
				s = to_string(s_hrs) + to_string(s_min);
			else if (s_hrs > 9 && s_min <= 9)
				s = to_string(s_hrs) + '0' + to_string(s_min);
			else if (s_hrs <= 9 && s_min <= 9)
				s = '0' + to_string(s_hrs) + '0' + to_string(s_min);
			
			s_min += 15;
			if (s_min > 59) {
				s_min -= 60;
				s_hrs++;
			}
			
			string e;
			if (s_hrs > 9 && s_min > 9)
				e = to_string(s_hrs) + to_string(s_min);
			else if (s_hrs > 9 && s_min <= 9)
				e = to_string(s_hrs) + '0' + to_string(s_min);
			else if (s_hrs <= 9 && s_min <= 9)
				e = '0' + to_string(s_hrs) + '0' + to_string(s_min);
			arr[a].set_doctor_id(doctor_id);
			arr[a].set_start_time(s);
			arr[a].set_end_time(e);
			arr[a].set_date(x);
			struct tm buf;
			buf = arr[a].get_date();
			bool check = true, valid = true;
			for (int num = 0; num < a_num; num++) {
				check = true;
				valid = true;
				if (appointments[num].get_booking_date().tm_year == arr[a].get_date().tm_year && appointments[num].get_booking_date().tm_mday == arr[a].get_date().tm_mday && appointments[num].get_booking_date().tm_mon == arr[a].get_date().tm_mon)
				{
					int k = 0;
					while (e[k] && valid == true) {
						if (e[k] != appointments[num].get_end_time()[k]) {
							valid = false;
							break;
						}
						k++;
					}
					k = 0;
					while (s[k] && valid == true) {
						if (appointments[num].get_start_time()[k] != s[k]) {
							valid = false;
							break;
						}
						k++;
					}
					if (valid == true) {
						check = false;
						break;
					}
					
				}				
			}
 			if (check == true) {
				cout << "|" << left << setw(12) << a << buf.tm_year << "/" << buf.tm_mon << "/" << setw(10) << buf.tm_mday /*<< right << setw(10)*/ << s << " - " << e << "|" << endl;
				cout << "------------------------------------------" << endl;
				//cout << a << ". " << endl << "Date: " << buf.tm_year << "/" << buf.tm_mon << "/" << buf.tm_mday << endl << "Time: " << s << " - " << e << endl;
				a++;
			}
			//i++;
		}
	}
	return arr;
}