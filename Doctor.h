#pragma once
#include "User.h"
//#include "Schedule.h"

class Doctor : public User {
private:
	float inperson_rate;
	float video_rate;
	int experience_years;
	char hospital[100];
	char city[100];
	float balance;
	char start_time[100];
	char end_time[100];
	struct tm buf;
	void set_video_rate();
public:
	Doctor();
	void set_time();
	void set_inperson_rate(float);
	void set_experience_years(int);
	void set_hospital(string);
	void set_city(string);
	void add_balance(float);
	float get_inperson_rate();
	float get_video_rate();
	int get_experience_years();
	char* get_hospital();
	char* get_city();
	float get_balance();
	void set_start_time(string);
	void set_end_time(string);
	char* get_start_time();
	char* get_end_time();
};