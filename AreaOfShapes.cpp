#include <iostream>
#include <iomanip>
#include <math.h>
#include <string.h>
#define PI 3.14159
using namespace std;

void Menu();

class Lahat {
	public:
	double num,result,numnum;
	
	void Circle() {
	system("cls");
	cout << "Enter radius: ";
	cin >> num;
	result = PI*pow(num,2);
	cout << "Area is " << fixed << setprecision(2) << result << endl;
	system("pause");
	Menu();
}

void Rectangle() {
	system("cls");
	cout << "Enter length: ";
	cin >> num;
	cout << "Enter width: ";
	cin >> numnum;
	result = num*numnum;
	cout << "Area is " << fixed << setprecision(2) << result << endl;
	system("pause");
	Menu();
}

void Cylinder() {
	system("cls");
	cout << "Enter radius: ";
	cin >> num;
	cout << "Enter height: ";
	cin >> numnum;
	result = PI * pow(num,2) * numnum;
	cout << "Area is " << fixed << setprecision(2) << result << endl;
	system("pause");
	Menu();
}

};


void Menu() {
	system("cls");
	Lahat lht;
	int choice;
	improper:
	cout << "Area of shapes" << endl << "[1] Circle" << endl << "[2] Rectangle" << endl << "[3] Cylinder" << endl << "Enter your choice: ";
	cin >> choice;
	switch (choice) {
		case 1:
			lht.Circle();
			break;
		case 2:
			lht.Rectangle();
			break;
		case 3:
			lht.Cylinder();
			break;
		default:
			cout << "Invalid input. Please try again." << endl;
			break;
	}
}

int main() {	
	Menu();
}
