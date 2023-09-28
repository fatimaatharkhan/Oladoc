#include <iostream>
using namespace std; 
#include "Patient.h"

Patient::Patient() {
	balance = 3500.0;
}

void Patient::add_balance(float b) {
	balance += b;
}

float Patient::get_balance() {
	return balance;
}

void Patient::make_payment(float b) {
	balance -= b;
}

bool Patient::recharge_account() {
	int choice;
	bool again = true;
	while (again == true) {
		cout << "Press 1 to pay through Bank" << endl;
		cout << "Press 2 to pay through EasyPaisa" << endl;
		cout << "Press 3 to pay through PayPak" << endl;
		cout << "Press 4 to pay through JazzCash" << endl;
		cout << "Press 5 to pay through Union" << endl;
		cin >> choice;
		if (choice == 1) {
			BankTransfer bank;
			recharge = &bank;
			again = false;
		}
		else if (choice == 2) {
			EasyPaisa easypaisa;
			recharge = &easypaisa;
			again = false;
		}
		else if (choice == 3) {
			PayPak paypak;
			recharge = &paypak;
			again = false;
		}
		else if (choice == 4) {
			JazzCash jazzcash;
			recharge = &jazzcash;
			again = false;
		}
		else if (choice == 5) {
			UnionPay unionpay;
			recharge = &unionpay;
			again = false;
		}
		else {
			cout << "Invalid Option" << endl;
			again = true;
		}
	}
	recharge->recharge_balance(balance);
	return true;
}