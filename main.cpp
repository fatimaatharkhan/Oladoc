#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;
#include "OlaDoc.h"

int main() {
	int choice = 0;
	OlaDoc oladoc;
	while (choice != 3) {
		cout << endl << "----------------------------------" << endl;
		cout << "MAIN MENU: " << endl;
		cout << "----------------------------------" << endl << endl;
		cout << "Press 1 to Register:" << endl;
		cout << "Press 2 to Login:" << endl;
		cout << "Press 3 to Leave:" << endl;
		cin >> choice;
		if (choice == 1) {
			oladoc.Register();
		}
		else if (choice == 2) {
			oladoc.Login();
		}
		else if (choice != 3)
			cout << "Invalid Input, Please try again!" << endl << endl;
	}
	return 0;
}