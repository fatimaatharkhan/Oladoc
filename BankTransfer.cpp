#include <iostream>
using namespace std;
#include "BankTransfer.h"

bool BankTransfer::recharge_balance(float& amount) {
	cout << "Recharging Accounts using Bank Transfer. " << endl;
	return Recharge::recharge_balance(amount);
}