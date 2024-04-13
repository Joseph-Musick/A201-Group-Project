#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include<iomanip>
#include<iostream>
#include<string>
#include<time.h>

using namespace std;

void employeemenu(float prices[10][2], int itemssold[10][2], int totalsales, int stock[10][2], string products[10][3], int columns, int rows, int productcol);
void sales_profit(float prices[10][2], int itemssold[10][2], string products[10][3]);
void remaining_stock(int stock[10][2], string products[10][3]);
void receipt(float prices[10][2], int itemssold[10][2], int totalsales, int stock[10][2], string products[10][3], int columns, int rows, int productcol);
int publicmenu(float prices[10][2], int itemssold[10][2], int stock[10][2], string products[10][3]);
void speakerOPT(float prices[10][2], int itemssold[10][2], int stock[10][2], int choice, string products[10][3]);
void mouseOPT(float prices[10][2], int itemssold[10][2], int stock[10][2], int choice, string products[10][3]);
void monitorOPT(float prices[10][2], int itemssold[10][2], int stock[10][2], int choice, string products[10][3]);
void laptopOPT(float prices[10][2], int itemssold[10][2], int stock[10][2], int choice, string products[10][3]);
void desktopOPT(float prices[10][2], int itemssold[10][2], int stock[10][2], int choice, string products[10][3]);
void memoryOPT(float prices[10][2], int itemssold[10][2], int stock[10][2], int choice, string products[10][3]);
void keyboardOPT(float prices[10][2], int itemssold[10][2], int stock[10][2], int choice, string products[10][3]);
void headphonesOPT(float prices[10][2], int itemssold[10][2], int stock[10][2], int choice, string products[10][3]);
void microphoneOPT(float prices[10][2], int itemssold[10][2], int stock[10][2], int choice, string products[10][3]);
void controllersOPT(float prices[10][2], int itemssold[10][2], int stock[10][2], int choice, string products[10][3]);

int main()
{
	const int columns = 2, rows = 10, productcol = 3;
	ifstream inputFile;
	string products[rows][productcol];
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
	inputFile.open("Products.txt");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < productcol; j++)
		{
			getline(inputFile, products[i][j]);
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
			employeemenu(prices, itemssold, totalsales, stock, products, columns, rows, productcol);
			break;
		case 2:
			totalsales += publicmenu(prices, itemssold, stock, products);
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

void employeemenu(float prices[10][2], int itemssold[10][2], int totalsales, int stock[10][2], string products[10][3], int columns, int rows, int productcol)
{
	int input;
	bool end = true;
	while (end) {
		cout << "Welcome to the Function Fanatics Employee Menu" << endl;
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
			sales_profit(prices, itemssold, products);
			break;
		case 2:
			remaining_stock(stock, products);
			break;
		case 3:
			receipt(prices, itemssold, totalsales, stock, products, columns, rows, productcol);
			break;
		case 4:
			end = false;
			break;
		default:
			break;
		}
	}
}
void sales_profit(float prices[10][2], int itemssold[10][2], string products[10][3]) {
	float total = 0, price;
	cout << endl << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			price = prices[i][j];
			total += price * itemssold[i][j];
			cout << products[i][0] << " " << products[i][j + 1] << ": $" << setprecision(2) << fixed << price * itemssold[i][j] << endl;
		}
		cout << endl;
	}
	cout << endl;
	cout << "Total Sales: $" << setprecision(2) << fixed << total << endl;
	cout << endl << "Press the Enter key to continue.";
	cin.ignore();
	cin.get();
	cin.clear();
}
void remaining_stock(int stock[10][2], string products[10][3]) {
	cout << "Remaining Stock" << endl << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << products[i][0] << " " << products[i][j + 1] << ": ";
			cout << stock[i][j] << endl;
		}
		cout << endl;
	}
	cout << endl << "Press the Enter key to continue.";
	cin.ignore();
	cin.get();
	cin.clear();
}
void receipt(float prices[10][2], int itemssold[10][2], int totalsales, int stock[10][2], string products[10][3], int columns, int rows, int productcol)
{
	int catagories = 0,
		subset = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < productcol; j++)
		{
			if (j == 0)
			{
				if (products[i][j].length() > catagories)
				{
					catagories = products[i][j].length();
				}
			}
			else
			{
				if (products[i][j].length() > subset)
				{
					subset = products[i][j].length();
				}
			}
		}
	}
	catagories++;
	subset++;
	ofstream outputFile;
	time_t rawtime = time(NULL);
	string curtime = ctime(&rawtime),
		receipt = "Receipt " + curtime;
	receipt.pop_back();
	outputFile.open((receipt + ".txt").c_str());
	if (outputFile.is_open())
	{
		cout << "GOood";
	}
	outputFile << endl << "\t\t\tRecepit" << endl
		<< endl
		<< endl
		<< "\tTotal Number of sales for " << curtime << "\twas " << totalsales << " items sold." << endl
		<< endl
		<< "\tSales by individual items: " << endl
		<< endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			outputFile << setw(catagories) << products[i][0] << " " << setw(subset) << products[i][j + 1] << "\t " << itemssold[i][j] << "\t$" << setprecision(2) << fixed << prices[i][j] * itemssold[i][j] << endl;
		}
		outputFile << endl;
	}
	outputFile << endl
		<< endl
		<< "Remaining stock for each item:"
		<< endl
		<< endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			outputFile << setw(catagories) << products[i][0] << " " << setw(subset) << products[i][j + 1] << "\t\t" << stock[i][j] << endl;
		}
		outputFile << endl;
	}
	outputFile.close();

	cout << endl << "\t\t\tRecepit" << endl
		<< endl
		<< endl
		<< "\tTotal Number of sales for " << curtime << "\twas " << totalsales << " items sold." << endl
		<< endl
		<< "\tSales by individual items: " << endl
		<< endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << setw(catagories) << products[i][0] << " " << setw(subset) << products[i][j + 1] << "\t " << itemssold[i][j] << "\t$" << setprecision(2) << fixed << prices[i][j] * itemssold[i][j] << endl;
		}
		cout << endl;
	}
	cout << endl
		<< endl
		<< "Remaining stock for each item:"
		<< endl
		<< endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << setw(catagories) << products[i][0] << " " << setw(subset) << products[i][j + 1] << "\t\t" << stock[i][j] << endl;
		}
		cout << endl;
	}

	cout << endl << "Press the Enter key to continue.";
	cin.ignore();
	cin.get();
	cin.clear();
}

int publicmenu(float prices[10][2], int itemssold[10][2], int stock[10][2], string products[10][3]) {
	int choice, sales = 0;
	bool end = true;
	while (end) {
		cout << "Hi there welcome to the Function Fanatics Electronics store" << endl;
		cout << "Please View our selection of items below and then Enter what you wish to purchase" << endl;
		for (int i = 0; i < 10; i++)
		{
			cout << i + 1 << "." << products[i][0] << endl;
		}
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
			speakerOPT(prices, itemssold, stock, choice, products);
			sales++;
			break;
		case 1:
			mouseOPT(prices, itemssold, stock, choice, products);
			sales++;
			break;
		case 2:
			monitorOPT(prices, itemssold, stock, choice, products);
			sales++;
			break;
		case 3:
			laptopOPT(prices, itemssold, stock, choice, products);
			sales++;
			break;
		case 4:
			desktopOPT(prices, itemssold, stock, choice, products);
			sales++;
			break;
		case 5:
			memoryOPT(prices, itemssold, stock, choice, products);
			sales++;
			break;
		case 6:
			keyboardOPT(prices, itemssold, stock, choice, products);
			sales++;
			break;
		case 7:
			headphonesOPT(prices, itemssold, stock, choice, products);
			sales++;
			break;
		case 8:
			microphoneOPT(prices, itemssold, stock, choice, products);
			sales++;
			break;
		case 9:
			controllersOPT(prices, itemssold, stock, choice, products);
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
void speakerOPT(float prices[10][2], int itemssold[10][2], int stock[10][2], int choice, string products[10][3]) {
	int input;
	cout << "1." << products[choice][1] << "$" << setprecision(2) << fixed << prices[choice][0];
	cout << " Stock: " << stock[choice][0] << endl;//Logitech z150
	cout << "2." << products[choice][2] << "$" << setprecision(2) << fixed << prices[choice][1];
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
void mouseOPT(float prices[10][2], int itemssold[10][2], int stock[10][2], int choice, string products[10][3]) {
	int input;
	cout << "1." << products[choice][1] << "$" << setprecision(2) << fixed << prices[choice][0];
	cout << " Stock: " << stock[choice][0] << endl;//G502 Wired
	cout << "2." << products[choice][2] << "$" << setprecision(2) << fixed << prices[choice][1];
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
void monitorOPT(float prices[10][2], int itemssold[10][2], int stock[10][2], int choice, string products[10][3]) {
	int input;
	cout << "1." << products[choice][1] << "$" << setprecision(2) << fixed << prices[choice][0];
	cout << " Stock: " << stock[choice][0] << endl;//Samsung under 27 inch 1080p 
	cout << "2." << products[choice][2] << "$" << setprecision(2) << fixed << prices[choice][1];
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
void laptopOPT(float prices[10][2], int itemssold[10][2], int stock[10][2], int choice, string products[10][3]) {
	int input;
	cout << "1." << products[choice][1] << "$" << setprecision(2) << fixed << prices[choice][0];
	cout << " Stock: " << stock[choice][0] << endl;//16inch macbook pro
	cout << "2." << products[choice][2] << "$" << setprecision(2) << fixed << prices[choice][1];
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
void desktopOPT(float prices[10][2], int itemssold[10][2], int stock[10][2], int choice, string products[10][3]) {
	int input;
	cout << "1." << products[choice][1] << "$" << setprecision(2) << fixed << prices[choice][0];
	cout << " Stock: " << stock[choice][0] << endl;//iMac desktop
	cout << "2." << products[choice][2] << "$" << setprecision(2) << fixed << prices[choice][1];
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
void memoryOPT(float prices[10][2], int itemssold[10][2], int stock[10][2], int choice, string products[10][3]) {
	int input;
	cout << "1." << products[choice][1] << "$" << setprecision(2) << fixed << prices[choice][0];
	cout << " Stock: " << stock[choice][0] << endl;//1tb 
	cout << "2." << products[choice][2] << "$" << setprecision(2) << fixed << prices[choice][1];
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
void keyboardOPT(float prices[10][2], int itemssold[10][2], int stock[10][2], int choice, string products[10][3]) {
	int input;
	cout << "1." << products[choice][1] << "$" << setprecision(2) << fixed << prices[choice][0];
	cout << " Stock: " << stock[choice][0] << endl;//full size black widow v3
	cout << "2." << products[choice][2] << "$" << setprecision(2) << fixed << prices[choice][1];
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
void headphonesOPT(float prices[10][2], int itemssold[10][2], int stock[10][2], int choice, string products[10][3]) {
	int input;
	cout << "1." << products[choice][1] << "$" << setprecision(2) << fixed << prices[choice][0];
	cout << " Stock: " << stock[choice][0] << endl;//Hyperx Cloud 2 wired
	cout << "2." << products[choice][2] << "$" << setprecision(2) << fixed << prices[choice][1];
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
void microphoneOPT(float prices[10][2], int itemssold[10][2], int stock[10][2], int choice, string products[10][3]) {
	int input;
	cout << "1." << products[choice][1] << "$" << setprecision(2) << fixed << prices[choice][0];
	cout << " Stock: " << stock[choice][0] << endl;//
	cout << "2." << products[choice][2] << "$" << setprecision(2) << fixed << prices[choice][1];
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
void controllersOPT(float prices[10][2], int itemssold[10][2], int stock[10][2], int choice, string products[10][3]) {
	int input;
	cout << "1." << products[choice][1] << "$" << setprecision(2) << fixed << prices[choice][0];
	cout << " Stock: " << stock[choice][0] << endl;//logitech 3d pro
	cout << "2." << products[choice][2] << "$" << setprecision(2) << fixed << prices[choice][1];
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