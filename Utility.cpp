#include <iostream>
using namespace std;
#include "Utility.h"

int Utility::findSize(char* s) {
	for (int i = 0; ; i++)
		if (s[i] == 0)
			return i;
	return 0;
}

bool Utility::validate_cnic(char* cnic) {
	int size = findSize(cnic);
	if (size == 13) {
		for (int i = 0; i < 13; i++) {
			if (int(cnic[i]) < 48 || int(cnic[i]) > 57) {
				cout << "The CNIC can only be 13 digits, please try again!" << endl;
				return false;
			}
		}
		//cout << "Valid Input!" << endl;
		return true;
	}
	else {
		cout << "The CNIC can only be 13 digits, please try again!" << endl;
		return false;
	}
}

bool Utility::validate_password(char* password) {
	int size = findSize(password);
	bool special = false, digit = false, u_alpha = false, l_alpha = false;
	if (size >= 8) {
		for (int i = 0; i < size; i++) {
			if ((int(password[i]) >= 32 && int(password[i]) <= 47) || (int(password[i]) >= 58 && int(password[i]) <= 64) || (int(password[i]) >= 91 && int(password[i]) <= 96) || (int(password[i]) >= 123 && int(password[i]) <= 126)) {
				special = true;
			}
			else if (int(password[i]) >= 48 && int(password[i]) <= 57) {
				digit = true;
			}
			else if (int(password[i]) >= 65 && int(password[i]) <= 90) {
				u_alpha = true;
			}
			else if (int(password[i]) >= 97 && int(password[i]) <= 122) {
				l_alpha = true;
			}
		}
		if (special == true && digit == true && u_alpha == true && l_alpha == true) {
			//cout << "Valid Input!" << endl;
			return true;
		}
	}
	cout << "The password should contain at least one special character, one digit, one lowercase and one uppercase. Please try again!" << endl;
	return false;
}

bool Utility::compare_password(char* first, char* second) {
	int f_size = findSize(first);
	int s_size = findSize(second);
	if (f_size == s_size) {
		for (int i = 0; i < f_size; i++) {
			if (first[i] != second[i]){
				cout << "The passwords do not match. Please try again!" << endl;
				return false;
			}
		}
		//cout << "Valid Inputs!" << endl;
		return true;
	}
	cout << "The passwords do not match. Please try again!" << endl;
	return false;
}