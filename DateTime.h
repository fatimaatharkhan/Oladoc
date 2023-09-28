#pragma once
#include "Slots.h"
#include "Appointment.h"

class DateTime {
	int find_size(char*);
public:
	bool validate_time(char*);
	bool validate_end_time(char*, char*);
	Slots* divide_time(int doctor_id, char*, char*, Appointment appointments[], int a_num);
};