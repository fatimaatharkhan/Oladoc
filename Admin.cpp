#include <iostream>
using namespace std;
#include "Admin.h"

Admin::Admin() {
	strcpy_s(username, sizeof(username), "admin123");
	strcpy_s(password, sizeof(password), "Admin123!");
	//   ((username.c_str(), "test12");
	//username = "admin123";
	//password = "Admin123!";
}

char* Admin::get_password() {
	return password;
}

char* Admin::get_username() {
	return username;
}