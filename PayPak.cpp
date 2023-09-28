#include <iostream>
using namespace std;
#include "PayPak.h"

bool PayPak::recharge_balance(float& amount) {
	cout << "Recharging Accounts using Bank Transfer. " << endl;
	return Recharge::recharge_balance(amount);
}