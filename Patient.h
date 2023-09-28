#pragma once
#include "User.h"
#include "Recharge.h"
#include "EasyPaisa.h"
#include "JazzCash.h"
#include "PayPak.h"
#include "UnionPay.h"
#include "BankTransfer.h"

class Patient : public User {
private:
	Recharge* recharge;
	float balance;
public:
	Patient();
	void add_balance(float);
	float get_balance();
	void make_payment(float b);
	bool recharge_account();
};