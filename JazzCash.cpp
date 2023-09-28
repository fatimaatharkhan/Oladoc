#include <iostream>
using namespace std;
#include "JazzCash.h"

bool JazzCash::recharge_balance(float& amount) {
	cout << "Recharging Accounts using Bank Transfer. " << endl;
	return Recharge::recharge_balance(amount);
}