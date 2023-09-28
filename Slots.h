#pragma once
class Slots {
protected:
	int Doctor_ID;
	char start_time[100];
	char end_time[100];
	struct tm buf;
public:
	Slots();
	void set_date(int x);
	void set_doctor_id(int);
	int get_doctor_id();
	void set_start_time(string);
	void set_end_time(string);
	char* get_start_time();
	char* get_end_time();
	tm get_date();
};

