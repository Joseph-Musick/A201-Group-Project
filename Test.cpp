// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include <fstream>
#include<iomanip>
using namespace std;

void employeemenu(float prices[10][2], int itemssold[10][2],int totalsales,int stock[10][2]);
void sales_profit(float prices[10][2],int itemssold[10][2]);
void remaining_stock(int stock[10][2]);
void receipt(float prices[10][2], int itemssold[10][2], int totalsales, int stock[10][2]);
int publicmenu(float prices[10][2], int itemssold[10][2], int stock[10][2]);
void speakerOPT(float prices[10][2], int itemssold[10][2], int stock[10][2],int choice);
void mouseOPT(float prices[10][2], int itemssold[10][2], int stock[10][2],int choice);
void monitorOPT(float prices[10][2], int itemssold[10][2], int stock[10][2],int choice);
void laptopOPT(float prices[10][2], int itemssold[10][2], int stock[10][2],int choice);
void desktopOPT(float prices[10][2], int itemssold[10][2], int stock[10][2],int choice);
void memoryOPT(float prices[10][2], int itemssold[10][2], int stock[10][2],int choice);
void keyboardOPT(float prices[10][2], int itemssold[10][2], int stock[10][2],int choice);
void headphonesOPT(float prices[10][2], int itemssold[10][2], int stock[10][2],int choice);
void microphoneOPT(float prices[10][2], int itemssold[10][2], int stock[10][2],int choice);
void controllersOPT(float prices[10][2], int itemssold[10][2], int stock[10][2],int choice);

int main()
{
	const int columns = 2, rows = 10;
	ifstream inputFile;
	float prices[rows][columns];
	int stock[rows][columns];
	inputFile.open("Stock&Prices.txt");
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			inputFile >> prices[i][j];
		}
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			inputFile >> stock[i][j];
		}
	}
	inputFile.close();
	int input, totalsales = 0, itemssold[rows][columns];
	bool end = true;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			itemssold[i][j] = 0;
		}
	}
	while (end) {
		cout << "1.Employee Menu" << endl;
		cout << "2.Public Menu" << endl;
		cout << "3.Shut Down" << endl;
		cin >> input;
		switch (input)
		{
		case 1:
			employeemenu(prices, itemssold,totalsales,stock);
			break;
		case 2:
			totalsales += publicmenu(prices,itemssold,stock);
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

void employeemenu(float prices[10][2], int itemssold[10][2], int totalsales, int stock[10][2]) {
	int input;
	bool end = true;
	while (end) {
		cout << "Welcome to the Employee Menu" << endl;
		cout << "1.Total sales and profit" << endl;
		cout << "2.Current Stock" << endl;
		cout << "3.Export to File" << endl;
		cout << "4.Exit" << endl;
		cin >> input;
		while (input < 1 || input >4) {//Input validation
			cin.clear();
			cin.ignore();
			cout << "Your choice must be between 1 and 4" << endl;
			cin >> input;
		}
		switch (input) {
		case 1:
			sales_profit( prices, itemssold);
			break;
		case 2:
			remaining_stock(stock);
			break;
		case 3:
			receipt(prices, itemssold, totalsales, stock);
			break;
		case 4:
			end = false;
			break;
		default:
			break;
		}
	}
}
void sales_profit(float prices[10][2], int itemssold[10][2]) {
	float total=0,price;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			price = prices[i][j];
			total += price * itemssold[i][j];
		}
	}
	cout << endl;
	cout << endl;
	cout << "Total Sales: $" << setprecision(2) << total << endl;
	cout << endl << "Press the Enter key to continue.";
	cin.ignore();
	cin.get();
	cin.clear();
}
void remaining_stock(int stock[10][2]) {
	cout << "Remaining Stock" << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << stock[i][j] << endl;
		}
	}
	cout << endl << "Press the Enter key to continue.";
	cin.ignore();
	cin.get();
	cin.clear();
}
void receipt(float prices[10][2], int itemssold[10][2], int totalsales, int stock[10][2]) {
	ofstream outputFile;
	sales_profit(prices, itemssold);

	outputFile.open("Receipt");
	outputFile.close();

	cout << endl << "Press the Enter key to continue.";
	cin.ignore();
	cin.get();
	cin.clear();
}

int publicmenu(float prices[10][2], int itemssold[10][2], int stock[10][2]) {
	int choice, items[10][2],sales = 0;
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
		cin >> choice;
		while (choice < 0 || choice >10) {//Input validation
			cin.clear();
			cin.ignore();
			cout << "Your choice must be between 0 and 10" << endl;
			cin >> choice;
		}
		choice--;
		switch (choice) {
		case 0:
			speakerOPT(prices, itemssold, stock, choice);
			sales++;
			break;
		case 1:
			mouseOPT(prices, itemssold, stock, choice);
			sales++;
			break;
		case 2:
			monitorOPT(prices, itemssold, stock, choice);
			sales++;
			break;
		case 3:
			laptopOPT(prices, itemssold, stock, choice);
			sales++;
			break;
		case 4:
			desktopOPT(prices, itemssold, stock, choice);
			sales++;
			break;
		case 5:
			memoryOPT(prices, itemssold, stock, choice);
			sales++;
			break;
		case 6:
			keyboardOPT(prices, itemssold, stock, choice);
			sales++;
			break;
		case 7:
			headphonesOPT(prices, itemssold, stock, choice);
			sales++;
			break;
		case 8:
			microphoneOPT(prices, itemssold, stock, choice);
			sales++;
			break;
		case 9:
			controllersOPT(prices, itemssold, stock, choice);
			sales++;
			break;
		case -1:

			end = false;
			break;
		default:
			break;
		}
	}
	return sales;
}
void speakerOPT(float prices[10][2], int itemssold[10][2], int stock[10][2], int choice) {
	int input;
	cout << "1.Wired $" << setprecision(2) << fixed << prices[choice][0]; 
	cout << " Stock: " << stock[choice][0] << endl;//Logitech z150
	cout << "2.Wireless $" << setprecision(2) << fixed << prices[choice][1];
	cout << " Stock: " << stock[choice][1] << endl;//ANKER soundcore
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
		itemssold[choice][0]++;
		stock[choice][0]--;
		break;
	case 2:
		itemssold[choice][1]++;
		stock[choice][1]--;
		break;
	default:
		break;
	}
}
void mouseOPT(float prices[10][2], int itemssold[10][2], int stock[10][2], int choice) {
	int input;
	cout << "1.Wired $" << setprecision(2) << fixed << prices[choice][0];
	cout << " Stock: " << stock[choice][0] << endl;//G502 Wired
	cout << "2.Wireless $" << setprecision(2) << fixed << prices[choice][1];
	cout << " Stock: " << stock[choice][1] << endl;//G502 Wireless
	cout << "Choose an option" << endl;
	cin >> input;
	while (input < 1 || input >2) {//Input validation
		cin.clear();
		cin.ignore();
		cout << "Your choice must be between 1 or 2" << endl;
		cin >> input;
	}
	cout << endl;
	switch (input) {
	case 1:
		itemssold[choice][0]++;
		stock[choice][0]--;
		break;
	case 2:
		itemssold[choice][1]++;
		stock[choice][1]--;
		break;
	default:
		break;
	}

}
void monitorOPT(float prices[10][2], int itemssold[10][2], int stock[10][2], int choice) {
	int input;
	cout << "1.Flat $" << setprecision(2) << fixed << prices[choice][0];
	cout << " Stock: " << stock[choice][0] << endl;//Samsung under 27 inch 1080p 
	cout << "2.Curved $" << setprecision(2) << fixed << prices[choice][1];
	cout << " Stock: " << stock[choice][1] << endl;//Samsung under 27 inch 1080p 
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
		itemssold[choice][0]++;
		stock[choice][0]--;
		break;
	case 2:
		itemssold[choice][1]++;
		stock[choice][1]--;
		break;
	default:
		break;
	}
}
void laptopOPT(float prices[10][2], int itemssold[10][2], int stock[10][2], int choice) {
	int input;
	cout << "1.Mac $" << setprecision(2) << fixed << prices[choice][0];
	cout << " Stock: " << stock[choice][0] << endl;//16inch macbook pro
	cout << "2.Windows $" << setprecision(2) << fixed << prices[choice][1];
	cout << " Stock: " << stock[choice][1] << endl;//16inch asus ROG i9,32gb,1tb ssd 
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
		itemssold[choice][0]++;
		stock[choice][0]--;
		break;
	case 2:
		itemssold[choice][1]++;
		stock[choice][1]--;
		break;
	default:
		break;
	}
}
void desktopOPT(float prices[10][2], int itemssold[10][2], int stock[10][2], int choice) {
	int input;
	cout << "1.Mac $" << setprecision(2) << fixed << prices[choice][0];
	cout << " Stock: " << stock[choice][0] << endl;//iMac desktop
	cout << "2.Windows $" << setprecision(2) << fixed << prices[choice][1];
	cout << " Stock: " << stock[choice][1] << endl;//Dell optiplex 3000
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
		itemssold[choice][0]++;
		stock[choice][0]--;
		break;
	case 2:
		itemssold[choice][1]++;
		stock[choice][1]--;
		break;
	default:
		break;
	}
}
void memoryOPT(float prices[10][2], int itemssold[10][2], int stock[10][2], int choice) {
	int input;
	cout << "1.SSD $" << setprecision(2) << fixed << prices[choice][0];
	cout << " Stock: " << stock[choice][0] << endl;//1tb 
	cout << "2.Hardrive $" << setprecision(2) << fixed << prices[choice][1];
	cout << " Stock: " << stock[choice][1] << endl;//1tb 
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
		itemssold[choice][0]++;
		stock[choice][0]--;
		break;
	case 2:
		itemssold[choice][1]++;
		stock[choice][1]--;
		break;
	default:
		break;
	}
}
void keyboardOPT(float prices[10][2], int itemssold[10][2], int stock[10][2], int choice) {
	int input;
	cout << "1.Wired $" << setprecision(2) << fixed << prices[choice][0];
	cout << " Stock: " << stock[choice][0] << endl;//full size black widow v3
	cout << "2.Wireless $" << setprecision(2) << fixed << prices[choice][1];
	cout << " Stock: " << stock[choice][1] << endl;//65% black widow v3
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
		itemssold[choice][0]++;
		stock[choice][0]--;
		break;
	case 2:
		itemssold[choice][1]++;
		stock[choice][1]--;
		break;
	default:
		break;
	}
}
void headphonesOPT(float prices[10][2], int itemssold[10][2], int stock[10][2], int choice) {
	int input;
	cout << "1.Wired $" << setprecision(2) << fixed << prices[choice][0];
	cout << " Stock: " << stock[choice][0] << endl;//Hyperx Cloud 2 wired
	cout << "2.Wireless $" << setprecision(2) << fixed << prices[choice][1];
	cout << " Stock: " << stock[choice][1] << endl;//Hyper Cloud 2 Wireless
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
		itemssold[choice][0]++;
		stock[choice][0]--;
		break;
	case 2:
		itemssold[choice][1]++;
		stock[choice][1]--;
		break;
	default:
		break;
	}
}
void microphoneOPT(float prices[10][2], int itemssold[10][2], int stock[10][2], int choice) {
	int input;
	cout << "1.Blue Yeti $" << setprecision(2) << fixed << prices[choice][0];
	cout << " Stock: " << stock[choice][0] << endl;//
	cout << "2.Blue Snowball Ice $" << setprecision(2) << fixed << prices[choice][1];
	cout << " Stock: " << stock[choice][1] << endl;//
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
		itemssold[choice][0]++;
		stock[choice][0]--;
		break;
	case 2:
		itemssold[choice][1]++;
		stock[choice][1]--;
		break;
	default:
		break;
	}
}
void controllersOPT(float prices[10][2], int itemssold[10][2], int stock[10][2], int choice) {
	int input;
	cout << "1.Joystick $" << setprecision(2) << fixed << prices[choice][0];
	cout << " Stock: " << stock[choice][0] << endl;//logitech 3d pro
	cout << "2.Twin Stick $" << setprecision(2) << fixed << prices[choice][1];
	cout << " Stock: " << stock[choice][1] << endl;//Xbox Wireless Contoller
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
		itemssold[choice][0]++;
		stock[choice][0]--;
		break;
	case 2:
		itemssold[choice][1]++;
		stock[choice][1]--;
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
