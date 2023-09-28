#include <iostream>
using namespace std;
#include "EasyPaisa.h"

bool EasyPaisa::recharge_balance(float& amount) {
	cout << "Recharging Accounts using EasyPaisa. " << endl;
	return Recharge::recharge_balance(amount);
}