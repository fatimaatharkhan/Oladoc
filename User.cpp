#include <iostream>
using namespace std;
#include "User.h"

User::User() {
	//CNIC = '\0';
	//email = '\0';
	//name = '\0';
	//password = '\0';
	//username = '\0';
}

void User::set_id(int i) {
	id = i;
}

void User::set_cnic(string c) {
	strcpy_s(this->CNIC, c.c_str());
}

void User::set_email(string e) {
	strcpy_s(this->email, e.c_str());
}

void User::set_name(string n) {
	strcpy_s(this->name, n.c_str());
}

void User::set_password(string p) {
	strcpy_s(this->password, p.c_str());
}

void User::set_username(string u) {
	strcpy_s(this->username, u.c_str());
}

int User::get_id() {
	return id;
}

char* User::get_cnic() {
	return CNIC;
}

char* User::get_email() {
	return email;
}

char* User::get_name() {
	return name;
}

char* User::get_password() {
	return password;
}

char* User::get_username() {
	return username;
}

User::~User() {

}