#pragma once

class User {
protected:
	char CNIC[100];
	char password[100];
	char email[100];
	char name[100];
	char username[100];
	int id;
public:
	User();
	void set_id(int);
	void set_cnic(string);
	void set_password(string);
	void set_name(string);
	void set_email(string);
	void set_username(string);
	int get_id();
	char* get_cnic();
	char* get_password();
	char* get_email();
	char* get_name();
	char* get_username();
	~User();
};

