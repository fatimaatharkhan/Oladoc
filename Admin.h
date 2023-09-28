#pragma once

class Admin {
private:
	char username[100];
	char password[100];
public:
	Admin();
	//void set_password(char*);
	char* get_password();
	//void set_username(char*);
	char* get_username();
};