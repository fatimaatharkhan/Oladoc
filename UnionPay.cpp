#include <iostream>
using namespace std;
#include "UnionPay.h"

bool UnionPay::recharge_balance(float& amount) {
	cout << "Recharging Accounts using Bank Transfer. " << endl;
	return Recharge::recharge_balance(amount);
}
