/****************************************************/
/*			Name:				                    */
/*			Class: CSCE A201 MWF					*/
/*			File: Group Project						*/
/*			Date:									*/
/****************************************************/
//Store Inventory Tracking System 
//Function: Allows the user to input items and amount of items purchased by the customers and then shows how many of those items need to be restocked and 
//then shows how much that will cost to restock and then calculate the net profit and prints those numbers to an external file as a receipt 


// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<fileapi.h>
#include<iomanip>

using namespace std;

void employeemenu();
int publicmenu();
void speakerOPT();
void mouseOPT();
void monitorOPT();
void laptopOPT();
void desktopOPT();
void memoryOPT();
void keyboardOPT();
void headphonesOPT();
void microphoneOPT();
void controllersOPT();

int main()
{
	int input, totalsales = 0, items[10][2];
	float prices[10][2];
	bool end = true;
	while (end) {
		cout << "1.Employee Menu" << endl;
		cout << "2.Public Menu" << endl;
		cout << "3.Shut Down" << endl;
		cin >> input;
		switch (input)
		{
		case 1:
			employeemenu();
			break;
		case 2:
			totalsales += publicmenu();
			break;
		case 3:
			end = false;
			break;
		default:
			break;
		}
	}
	return 0;
}
void employeemenu() {
	cout << "Welcome to the Employee Menu" << endl;
	cout << "1.Total sales and profit" << endl;
	cout << "2.Current Stock" << endl;
	cout << "3.Export to File" << endl;
	cout << "4.Exit" << endl;

}
int publicmenu() {
	int input1, item[10][2], sales = 0;
	bool end = true;
	while (end) {
		cout << "Hi there welcome to the TBD Electronics store" << endl;
		cout << "Please View our selection of items below and then Enter what you wish to purchase" << endl;
		cout << "1.Speakers" << endl;
		cout << "2.Mouse" << endl;
		cout << "3.Monitor" << endl;
		cout << "4.Laptop" << endl;
		cout << "5.Desktop" << endl;
		cout << "6.Memory" << endl;
		cout << "7.Keyboard" << endl;
		cout << "8.Headphones" << endl;
		cout << "9.Microphone" << endl;
		cout << "10.Controllers" << endl;
		cout << "Enter what you wish to purchase,Press 0 to exit" << endl;
		cin >> input1;
		while (input1 < 0 || input1 >10) {//Input validation
			cin.clear();
			cin.ignore();
			cout << "Your choice must be between 0 and 10" << endl;
			cin >> input1;
		}
		switch (input1) {
		case 1:
			speakerOPT();
			sales++;
			break;
		case 2:
			mouseOPT();
			sales++;
			break;
		case 3:
			monitorOPT();
			sales++;
			break;
		case 4:
			laptopOPT();
			sales++;
			break;
		case 5:
			desktopOPT();
			sales++;
			break;
		case 6:
			memoryOPT();
			sales++;
			break;
		case 7:
			keyboardOPT();
			sales++;
			break;
		case 8:
			headphonesOPT();
			sales++;
			break;
		case 9:
			microphoneOPT();
			sales++;
			break;
		case 10:
			controllersOPT();
			sales++;
			break;
		case 0:

			end = false;
			break;
		default:
			break;
		}
	}
	return sales;
}
void speakerOPT() {
	int input;
	cout << "1.Wired" << endl;
	cout << "2.Wireless" << endl;
	cout << "Choose an option" << endl;
	cin >> input;
	while (input < 1 || input >2) {//Input validation
		cin.clear();
		cin.ignore();
		cout << "Your choice must be between 1 or 2" << endl;
		cin >> input;
	}
	switch (input) {
	case 1:

		break;
	case 2:

		break;
	default:
		break;
	}
}
void mouseOPT() {
	int input;
	cout << "1.Wired" << endl;
	cout << "2.Wireless" << endl;
	cout << "Choose an option" << endl;
	cin >> input;
	while (input < 1 || input >2) {//Input validation
		cin.clear();
		cin.ignore();
		cout << "Your choice must be between 1 or 2" << endl;
		cin >> input;
	}
	switch (input) {
	case 1:

		break;
	case 2:

		break;
	default:
		break;
	}

}
void monitorOPT() {
	int input;
	cout << "1.Flat" << endl;
	cout << "2.Curved" << endl;
	cout << "Choose an option" << endl;
	cin >> input;
	while (input < 1 || input >2) {//Input validation
		cin.clear();
		cin.ignore();
		cout << "Your choice must be between 1 or 2" << endl;
		cin >> input;
	}
	switch (input) {
	case 1:

		break;
	case 2:

		break;
	default:
		break;
	}
}
void laptopOPT() {
	int input;
	cout << "1.Mac" << endl;
	cout << "2.Windows" << endl;
	cout << "Choose an option" << endl;
	cin >> input;
	while (input < 1 || input >2) {//Input validation
		cin.clear();
		cin.ignore();
		cout << "Your choice must be between 1 or 2" << endl;
		cin >> input;
	}
	switch (input) {
	case 1:

		break;
	case 2:

		break;
	default:
		break;
	}
}
void desktopOPT() {
	int input;
	cout << "1.Mac" << endl;
	cout << "2.Windows" << endl;
	cout << "Choose an option" << endl;
	cin >> input;
	while (input < 1 || input >2) {//Input validation
		cin.clear();
		cin.ignore();
		cout << "Your choice must be between 1 or 2" << endl;
		cin >> input;
	}
	switch (input) {
	case 1:

		break;
	case 2:

		break;
	default:
		break;
	}
}
void memoryOPT() {
	int input;
	cout << "1.SSD" << endl;
	cout << "2.Hardrive" << endl;
	cout << "Choose an option" << endl;
	cin >> input;
	while (input < 1 || input >2) {//Input validation
		cin.clear();
		cin.ignore();
		cout << "Your choice must be between 1 or 2" << endl;
		cin >> input;
	}
	switch (input) {
	case 1:

		break;
	case 2:

		break;
	default:
		break;
	}
}
void keyboardOPT() {
	int input;
	cout << "1.Wired" << endl;
	cout << "2.Wireless" << endl;
	cout << "Choose an option" << endl;
	cin >> input;
	while (input < 1 || input >2) {//Input validation
		cin.clear();
		cin.ignore();
		cout << "Your choice must be between 1 or 2" << endl;
		cin >> input;
	}
	switch (input) {
	case 1:

		break;
	case 2:

		break;
	default:
		break;
	}
}
void headphonesOPT() {
	int input;
	cout << "1.Wired" << endl;
	cout << "2.Wireless" << endl;
	cout << "Choose an option" << endl;
	cin >> input;
	while (input < 1 || input >2) {//Input validation
		cin.clear();
		cin.ignore();
		cout << "Your choice must be between 1 or 2" << endl;
		cin >> input;
	}
	switch (input) {
	case 1:

		break;
	case 2:

		break;
	default:
		break;
	}
}
void microphoneOPT() {
	int input;
	cout << "1.Wired" << endl;
	cout << "2.Wireless" << endl;
	cout << "Choose an option" << endl;
	cin >> input;
	while (input < 1 || input >2) {//Input validation
		cin.clear();
		cin.ignore();
		cout << "Your choice must be between 1 or 2" << endl;
		cin >> input;
	}
	switch (input) {
	case 1:

		break;
	case 2:

		break;
	default:
		break;
	}
}
void controllersOPT() {
	int input;
	cout << "1.Joystick" << endl;
	cout << "2.Twin Stick" << endl;
	cout << "Choose an option" << endl;
	cin >> input;
	while (input < 1 || input >2) {//Input validation
		cin.clear();
		cin.ignore();
		cout << "Your choice must be between 1 or 2" << endl;
		cin >> input;
	}
	switch (input) {
	case 1:

		break;
	case 2:

		break;
	default:
		break;
	}
}






// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
