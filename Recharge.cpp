#include <iostream>
using namespace std;
#include "Recharge.h"

bool Recharge::recharge_balance(float& amount) {
	float b;
	cout << "Please enter the amount you want to recharge: " << endl;
	cin >> b;
	amount += b;
	return true;
}