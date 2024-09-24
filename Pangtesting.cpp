#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <sstream>

using namespace std;

struct employee{
	int empnum;
	//char empname[25];
	string empname;
	int address;
	string contactnum;
	int department;
	int position;
	int datestarted;
	float rateperday;
	float rateperhour;
	float overtimerate;
};
void menu();
void add_emp();
int search_exist(string emp_num);
//void update_emp();
//void search_emp();
//void com_sal();
//void display_p_rol();
//void quit();

char save; int temp;
string searchrec, srec; int flg=0;
string empnum, del_line;

fstream payroll("payroll.txt", ios::out | ios::app | ios::in);

int main() {
	bool loop = true;
	char ans = ' ';
	do {
		menu();
		cout << "Go to Main Menu? [Y/N]";
		cin >> ans;
		if (ans == 'Y' || ans == 'y') {
			loop = true;
			system("cls");
		}
		else if (ans == 'N' || ans == 'n') {
			loop = false;
		}
		else {
			cout << "wrong input";
		}
	} while (loop == true);
	system("pause");
}

void menu() {
	int choice;
	cout << "Main Menu" << endl;
	cout << "[1] Add Employee" << endl;
	cout << "[2] Update Employee" << endl;
	cout << "[3] Search Employee" << endl;
	cout << "[4] Compute salary" << endl;
	cout << "[5] Display payroll report" << endl;
	cout << "[6] Quit program" << endl;
	cout << "Choice : ";
	cin >> choice;

	switch (choice) {
	case 1: {
		add_emp();
		break;
	}
	case 2: {
		//update_emp();
		break;
	}
	case 3: {
		//search_emp();
		break;
	}
	case  4: {
		//com_sal();
		break;
	}
	case  5: {
		//display_p_rol();
		break;
	}
	case  6: {
		exit(0);
		break;
	}
	}
}

void add_emp() {
	employee emprec;
	string str_empnum;
	string str_rateperhour;
	payroll.close();
	do {
		system("cls");
		cout << "Enter Employee number: ";
		cin >> emprec.empnum;
		stringstream ss;
		ss << emprec.empnum; ss >> str_empnum;
		temp = search_exist(str_empnum);
		
		if (temp==0)
		{
			cout << "Enter Employee name: ";
			cin.ignore();
			getline(cin,emprec.empname);
			cout << "Enter Address : ";
			cin >> emprec.address;
			cout << "Enter Contact Number : ";
			cin >> emprec.contactnum;
			cout << "Enter Department : ";
			cin >> emprec.department;
			cout << "Enter Position: ";
			cin >> emprec.position;
			cout << "Enter Date Started :";
			cin >> emprec.datestarted;
			cout << "Enter Rate per Day:";
			cin >> emprec.rateperday;
			cout << "Enter Rate per Hour:";
			cin >> emprec.rateperhour;
			cout << "overtime Rate:" <<  emprec.rateperday + emprec.rateperhour << endl;	
			cout << "Save the record? Y/N: ";
			cin >> save;

			if (save == 'y' || save == 'Y')
			{
				payroll.open("payroll.txt", ios::app);
				payroll << str_empnum << ' ' << emprec.empname << ' '
					<< emprec.address << ' ' << emprec.contactnum << ' '
					<< emprec.department << ' ' << emprec.position << ' '
					<< emprec.datestarted << ' ' << emprec.rateperday << ' '
					<< emprec.rateperhour << ' ' << emprec.overtimerate << ' ' << endl;
				payroll.close();
			}
		}
		cout << "Enter another record? ";
		cin >> save;
	} while (save == 'y' || save == 'Y');
	payroll.close();
}

int search_exist(string emp_num) {
	string searchkey; int flag = 0;
	payroll.open("payroll.txt", ios::in);
	if (!payroll.is_open())
		cout << "File error!";
	else {
		while (!payroll.eof())
		{
			getline(payroll, searchkey);
			if (searchkey.substr(0,4) == emp_num)
			{
				cout << "Employee number already exist!" << endl;
				flag = 1; break;
			}
		}
	}
	payroll.close();
	return flag;
}

void search_rec() {
	ifstream payroll;
	int flg = 0;
	//string searchrec, srec; int flg = 0;
	payroll.open("payroll.txt", ios::in);
	if (!payroll.is_open()) {
		cout << "File error!";
	}
	else {
		system ("cls");
		cout << "Enter Employee number to search : ";
		cin.ignore();
		getline(cin,searchrec);
		
		size_t pos;
		while (payroll.good())
		{
			getline(payroll,srec);
			pos=srec.find(searchrec);
			
			if (pos != string::npos)
			{
				cout << srec << endl;
				flg = 1; break;
			}
		}
		if (flg == 0){
		cout << "Record not found!" << endl;
	}
	}
	payroll.close();
}

bool isExisting(string sid){
			
			payroll.close();
			bool flag = false;
			
			payroll.open("payroll.txt", ios::in|ios::out);
			if(payroll.is_open()){
				string searchkey;
			
				while(!payroll.eof()){
					getline(payroll, searchkey);
					if(sid == searchkey.substr(0,4)){
						flag = true;
						break;
					}
					else{
						flag = false;
					}
				}
				payroll.close();
			}
			else{
				return NULL;
			}
			return flag;
		}
void delete_rec() {
//	string del_line, empordernum;

		char ans;
			fstream tempfile("tmp.txt",ios::in);
			char resp = ' ';
			do{
			payroll.close();
			tempfile.close();
			cin.ignore();
			cout << "Enter Employee number to remove : ";
			getline(cin, empnum);
			bool flag = isExisting(empnum);
	//		bool flag =true;// isExisting(search);
			if(flag == true){
			payroll.open("payroll.txt",ios::in|ios::out);
			tempfile.open("tmp.txt", ios::app);
				if(payroll.is_open()){
				//	cout<<"it is open";		
					while(!payroll.eof()){
						getline(payroll,del_line);
						if(empnum == del_line.substr(0,4)){
							continue;
						}
						else{
							if(del_line == ""){
								continue;
							}
							else{
								tempfile << del_line << endl;
							}
						}
					}
					payroll.close();
					tempfile.close();
					remove("payroll.txt");
					rename("tmp.txt","shop.txt");
				}
				else{
				cout<<"File error!" << endl;	
				}
			}
			else{
				cout<< endl << "Record not found!";
			}
			cout << endl << "Delete other Record? ";
			cin>>ans;
			}while(ans == 'Y' || ans == 'y');
			
			if(payroll.is_open() and tempfile.is_open()){
			payroll.close();
			tempfile.close();
			}
}

void display_rec() {
	ifstream payroll;
	cin.ignore();
	cout << endl << "Employee record from file" << endl;
	payroll.open("payroll.txt");
	if(payroll.is_open()) {
		while(!payroll.eof()) {
			getline(payroll,srec);
			cout << srec << endl;
		}
		payroll.close();
	}
	else {
		cout << "File error!";
	}
}
