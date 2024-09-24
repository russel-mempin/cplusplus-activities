#include <iostream>
using namespace std;
int main() {
	int mainmenu, ticketclass; //lahat ng input para sa choices nubmer lang
	char seatplan[10][6];
	char tryagainanswer;
	int x,y,rowcounter = 1;
	//para default value ng array asterisk
	for  (int i = 0; i <= 10; i++) {
		for (int j = 0; j <=6; j++) {
			seatplan [i][j] = '*';  
		}
	}
	do {
		cout << "[1] Seat Reservation" << endl;
		cout << "[2] Display Seat Plan" << endl;
		cin >> mainmenu;
		if (mainmenu == 1) {
			ulitlahat:
			cout << "Choose a ticket class [1] First class [2] Business Class [3] Economy Class" << endl;
			cin >> ticketclass;
			switch (ticketclass) {
				case 1: 
					cout << "You have chosen first class. Please pick a seat. You can sit in rows 1 and 2.";
					ulit:
					cin >> x;
					switch (x) {
						case 1 ... 2:
							cout << "You have chosen row " << x << "." << endl << "Please pick the column of your seat. Pick from 1 to 6. ";
							yulit:
							cin >> y;
							if (y <= 6) {
								--x;
								--y;
								if(seatplan[x][y] == '*') {
									seatplan[x][y] = 'X';
								}
								else {
									cout << "This seat is already taken. Please pick another one. You can sit in rows 1 and 2.";
									goto ulit;
								}
							}
							else {
								cout << "Please pick a number from 1 to 6.";
								goto yulit;
							}
							break;
						default:
							cout << "Please pick a number between 1 and 2 only.";
							goto ulit;
							break;
					}	
					goto display;	
					break;
				case 2:
					cout << "You have chosen business class. Please pick a seat. You can sit in rows 3 and 4. ";
					businessulit:
					cin >> x;
					switch (x) {
						case 3 ... 4:
							cout << "You have chosen row " << x << "." << endl << "Please pick the column of your seat. Pick from 1 to 6. ";
							businessyulit:
							cin >> y;
							if (y <= 6) {
								--x;
								--y;
								if(seatplan[x][y] == '*') {
									seatplan[x][y] = 'X';
								}
								else {
									cout << "This seat is already taken. Please pick another one. You can sit in rows 3 and 4.";
									goto businessulit;
								}
							}
							else {
								cout << "Please pick a number from 1 to 6.";
								goto businessyulit;
							}
							break;
						default:
							cout << "Please pick a number between 3 and 4 only.";
							goto businessulit;
							break;
					}	
					goto display;
					break;
				case 3:
					cout << "You have chosen economy class. Please pick a seat. You can sit in rows 5 to 10. ";
					economyulit:
					cin >> x;
					switch (x) {
						case 5 ... 10:
							cout << "You have chosen row " << x << "." << endl << "Please pick the column of your seat. Pick from 1 to 6. ";
							economyyulit:
							cin >> y;
							if (y <= 6) {
								--x;
								--y;
								if(seatplan[x][y] == '*') {
									seatplan[x][y] = 'X';
								}
								else {
									cout << "This seat is already taken. Please pick another one. You can sit in rows 5 to 10.";
									goto economyulit;
								}
							}
							else {
								cout << "Please pick a number from 1 to 6.";
								goto economyyulit;
							}
							break;
						default:
							cout << "Please pick a number between 5 to 10 only.";
							goto economyulit;
							break;
					}
					goto display;
					break;
				default:
					cout << "Please pick among the choices." << endl;
					goto ulitlahat;
					break;
			}	
		}
		else if (mainmenu == 2) {
			display:
			cout << "An * means the seat is available while an X means its already taken." << endl << endl;
			cout << "\tA \tB \tC \tD \tE \tF" << endl;
			for (int i = 0; i < 10;i++) {
				cout << "Row " << rowcounter << "\t";
				rowcounter++;
				for (int j = 0; j < 6; j++) {
					cout << seatplan[i][j] << "\t";
				}
				cout << endl;
			}
			cout << endl << "Would you like to return to the main menu? Y/N ";
			cin >> tryagainanswer;
		}
		system("CLS");
	}
	while(tryagainanswer == 'Y' || tryagainanswer == 'y');	
}
