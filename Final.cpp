#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<fstream>
#include<sstream> 
#include<conio.h>
using namespace std;

class employee{
	public:
		int add_employee();//-------------------------function for adding employee record
		int update_employee();//----------------------function for updating employee record
		int search_employee();//----------------------function for searching employee record
		int computeS();//-----------------------------function for computing salary of employee
		int display_payrollR();//---------------------function for the display of all records
		int searchrecord(string tsid);//--------------function call by value for system generated or checking if the number is already available
		fstream record;//-----------------------------file stream for storing employee records
		fstream update;//-----------------------------file stream for updating purposes
		string searchkey;//---------------------------variable for over all searching of employee number
		int c; //choice in main menu
		char ans, save; 
	private:int flag;//-------------------------------for switch purpose to finding employee id 
			int flg;//--------------------------------returning variable in getting the system generated value
			int sg;//-----------------------------starting point of employee number
			int nValid;//---------------------------variable for checking if employee number is existing
			float netInt, total;//---netInt is float value of string netpay
			string str_id, srec;
			string name, address, contactN, dep, position, date, rpd, rph, otr, ndate, net; // use for geting the string value per line in txt file
		struct records{
			string name;
			string address;
			string contactN;
			string dep;
			string position;
			string date;
			string payrollD;//-------payroll date
			float workedD;//---------days of work
			float rateD;//-----------equals to rate per day
			float rateH;//-----------equals to rate per hour
			float otRate;//----------equals to overtime rate
			float totalOH;//---------total overtime hour
			float grossS, sss, pagibig, incomeT, totalD;//------totalD is for total deduction
			float netpay; }rec;//-------------------------------name of structure records		
};	

int main(){
	employee rec;
		system("cls");
		system("color B");
		cout << "\n\n\n\n\n\t\t\t\t\t========================================" << endl;
		cout << "\t\t\t\t\t|                                      |" << endl;	
		cout << "\t\t\t\t\t|          M A I N  M E N U            |" << endl;
		cout << "\t\t\t\t\t|                                      |" << endl;	
		cout << "\t\t\t\t\t+======================================+" << endl;
		cout << "\t\t\t\t\t+======================================+" << endl;
		cout << "\t\t\t\t\t|                                      |" << endl;
		cout << "\t\t\t\t\t|       [1] - ADD EMPLOYEE             |" << endl;
		cout << "\t\t\t\t\t|       [2] - UPDATE EMPLOYEE          |" << endl;
		cout << "\t\t\t\t\t|       [3] - SEARCH EMPLOYEE          |" << endl;
		cout << "\t\t\t\t\t|       [4] - COMPUTE SALARY           |" << endl;
		cout << "\t\t\t\t\t|       [5] - DISPLAY PAYROLLREPORT    |" << endl;
		cout << "\t\t\t\t\t|       [6] - QUIT PROGRAM             |" << endl;
		cout << "\t\t\t\t\t|                                      |" << endl;
		cout << "\t\t\t\t\t+--------------------------------------+\n"<<endl;
		cout << "\n\t\t\t\t\t            ENTER CHOICE: ";
		cin >> rec.c;
			if(cin.fail()){//----------------------------------for input of non type variables
				cin.clear(); cin.ignore();
			system("color 4");
			cout<< "\t\t\t\t\t----------------------------------------\n";
			cout<< "\t\t\t\t\t|            INVALID INPUT!!           |\n";
			cout<< "\t\t\t\t\t|       requires (1-6) for input       |\n";
			cout<< "\t\t\t\t\t----------------------------------------\n\n\t\t\t\t\t";
				system("pause");
				main();}
		switch (rec.c) {
		case 1: rec.add_employee();		break;
		case 2: rec.update_employee();	break;
		case 3: rec.search_employee();	break;
		case 4: rec.computeS();			break;
		case 5: rec.display_payrollR();	break;
		case 6: 
			exit(0); system("pause");
			break;
		default: 
		system("color 4");//----------------------------------additional design for font color
			cout<< "\t\t\t\t\t----------------------------------------\n";
			cout<< "\t\t\t\t\t|            INVALID INPUT!!           |\n";
			cout<< "\t\t\t\t\t|       requires (1-6) for input       |\n";
			cout<< "\t\t\t\t\t----------------------------------------\n\n\t\t\t\t\t";
			system("pause"); main();break;}
	return 0;
}
	
int employee::add_employee(){
	fstream record("record.txt", ios::out | ios::app | ios::in);
	record.close();
	flag=0;
	sg=100;
	do{Home:
	system("cls");
	cout << "\n   ===============================================================================================================" << endl;
	cout << "   |                                 E N T E R   E M P L O Y E E   R E C O R D S                                 |" << endl;
	cout << "   ===============================================================================================================\n\n" << endl;
		if(sg>109){															// limit of the input record
			cout<<"\n\n\n\t\t\t\t\tALREADY REACH THE MAXIMUM EMPLOYEE!\n";  // up to 10 records only
			cout<<"\n\n\n\t\t\t\t\t";
			system("pause");
			main();	}
		cout <<left<<setw(18)<< "\t    Employee Number "<<"    : "<<"E"<<sg<<endl; 	// system generated
		stringstream ss;
		ss<<sg;	ss>>str_id;
		flag= searchrecord(str_id);
		
		if(flag==0){	cin.ignore();
			cout<< "\t  +---------------------+----------------------------------------------------+\n";
			cout <<"\t  | "<< left << setw(18)<<"Name "<<"  : "; 
			getline(cin,rec.name); cout<< "\t  +---------------------+----------------------------------------------------+\n";		
			cout <<"\t  | "<< left << setw(18)<<"Address "<<"  : ";
			getline(cin,rec.address); cout<< "\t  +---------------------+----------------------------------------------------+\n";
			cout <<"\t  | "<< left << setw(18)<<"Contact Number "<<"  : "; 
			getline(cin,rec.contactN); cout<< "\t  +---------------------+----------------------------------------------------+\n";
			cout <<"\t  | "<< left << setw(18)<<"Department "<<"  : "; 
			getline(cin,rec.dep);  cout<< "\t  +---------------------+----------------------------------------------------+\n";
			cout <<"\t  | "<< left << setw(18)<<"Position "<<"  : ";
			getline(cin,rec.position);  cout<< "\t  +---------------------+----------------------------------------------------+\n";
			cout <<"\t  | "<< left << setw(18)<<"Date Started "<<"  : "; 
			getline(cin,rec.date);  cout<< "\t  +---------------------+----------------------------------------------------+\n";
			cout <<"\t  | "<< left << setw(18)<<"Rate per Day "<<"  : "; 
			cin>>rec.rateD; cout<< "\t  +---------------------+----------------------------------------------------+\n";
			rec.rateH=rec.rateD/8.0;				//computation for rate per hour
			cout <<"\t  | "<< left << setw(18)<<"Rate per Hour " <<"  : "<<rec.rateH<<"\n"; cout<< "\t  +---------------------+----------------------------------------------------+\n";
			rec.otRate=rec.rateH*1.5;				//computation for over time rate
			cout <<"\t  | "<< left << setw(18)<<"Overtime Rate " <<"  : "<<	rec.otRate<<"\n"; cout<< "\t  +---------------------+----------------------------------------------------+\n";
			cout << endl;		
				cout << "\t\tSAVE THE RECORD? [Y/N] : ";
				cin >> save;
			if (toupper(save)== 'Y') {
				record.open("record.txt", ios::out | ios::app);		
				record << "E"<<sg <<endl;
				record <<rec.name <<endl;
				record <<rec.address << endl;
				record <<rec.contactN <<endl; 
				record <<rec.dep  <<endl;
				record <<rec.position <<endl;
				record <<rec.date <<endl; 
				record <<rec.rateD <<endl;
				record <<rec.rateH <<endl;
				record <<rec.otRate << endl;
				record <<endl;
				record <<"    N/A"<<endl<<endl;
				record.close();	
				sg++;		
			}
			else if(toupper(save)=='N'){
				goto back;
			}
		}
		else{
		sg++;
		goto Home;}
		back:					//for base in jump
		cout <<"\n\t\tWOULD YOU LIKE TO ADD ANOTHER EMPLOYEE? [Y/N] : ";
		cin >> ans;
			if(toupper(ans)=='N'){
				main();}
			else if(toupper(ans)!='Y' && toupper(ans)!='N'){
				cout<< "\n\t-------------------------------------------------\n";
				cout<< "\t                   Invalid Input   \n";
				cout<< "\t-------------------------------------------------\n"<<endl;
				goto back;	}
}while(toupper(ans) == 'Y');
}

int employee::searchrecord(string tsid){
 	flg=0;
	string id= 'E'+tsid;
	record.open("record.txt", ios::in);					//for reading the text file
	if(!record.is_open()){
		cout<< "\n\t---------------------------\n";
		cout<< "\t   File cannot be found!   \n";
		cout<< "\t---------------------------\n"<<endl;}
	else
	{	while(!record.eof())
		{getline(record, srec); 
		if(srec.substr(0,4)==id)
		{	
			flg=1; break;	}
		}
	}
	record.close();
	return flg;
}

int employee::update_employee(){	//for overwriting Employee's rate per day
	nValid=0;
	do{
	record.close();
	update.close();
	record.open("record.txt", ios::in);
	update.open("update.txt", ios::out);
	system("cls");
	cout << " ===============================================================================================================" << endl;
	cout << " |                                U P D A T E D   E M P L O Y E E   R E C O R D                                |" << endl;
	cout << " ===============================================================================================================" << endl;
	if(!record.is_open()){
		cout << "UNABLE TO OPEN FILE" << endl;
		system("pause");
		main();}
	else{	cout <<left<<setw(18)<<"\n\tEmployee Number  "<<": | ";
			cin >> searchkey;
			cout << endl;
	while (getline(record, srec, '\n')){
		cout << "Value of srec: " << srec << endl;
		if (srec == searchkey)
		{	
			getline(record, name, '\n');						//recieving string variables from the txt file record 
			getline(record, address, '\n');						//each line implies specific string value
			getline(record, contactN, '\n');
			getline(record, dep, '\n');
			getline(record, position, '\n');
			getline(record, date, '\n');
			getline(record, rpd, '\n');
			getline(record, rph, '\n');
			getline(record, otr, '\n');
			getline(record, ndate, '\n');
			getline(record, net, '\n');
			cout<< "\t  +---------------------+----------------------------------------------------+\n";
			cout <<"\t  | " <<left << setw(18) <<"Name " <<": | "<<setw(50)<<name <<" |"<<endl<< "\t  +---------------------+----------------------------------------------------+\n";
			cout <<"\t  | " << left << setw(18) <<"Address " <<": | "<<setw(50)<< address <<" |"<< endl<< "\t  +---------------------+----------------------------------------------------+\n";
			cout <<"\t  | " << left << setw(18) <<"Contact Number " <<": | "<<setw(50)<< contactN <<" |"<<endl<< "\t  +---------------------+----------------------------------------------------+\n";
			cout <<"\t  | " << left << setw(18) <<"Department " <<": | "<<setw(50)<< dep  <<" |"<<endl<< "\t  +---------------------+----------------------------------------------------+\n";				
			cout <<"\t  | " << left << setw(18) <<"Position " <<": | "<<setw(50)<< position <<" |"<<endl<< "\t  +---------------------+----------------------------------------------------+\n";
			cout <<"\t  | " << left << setw(18) <<"Date Started " <<": | "<<setw(50)<< date <<" |"<<endl<< "\t  +---------------------+----------------------------------------------------+\n";
			cout <<"\t  | " << left << setw(18) <<"Rate per Day " <<": | "; cin>>left>>setw(50)>> rec.rateD;
			rec.rateH=rec.rateD/8.0; rec.otRate=rec.rateH*1.5;cout<< "\t  +---------------------+----------------------------------------------------+\n";
			cout <<"\t  | " << left << setw(18) <<"Rate per Hour " <<": | "<<setw(50)<<rec.rateH <<" |"<<endl<< "\t  +---------------------+----------------------------------------------------+\n";
			cout <<"\t  | " << left << setw(18) <<"Overtime Rate " <<": | "<<setw(50)<<rec.otRate<<" |"<<endl<< "\t  +---------------------+----------------------------------------------------+\n";
			cout<<endl;
			update <<searchkey<<endl;
			update <<name <<endl;
			update <<address << endl;
			update <<contactN <<endl; 
			update <<dep  <<endl;
			update <<position <<endl;
			update <<date <<endl; 
			update <<rec.rateD <<endl;
			update <<rec.rateH <<endl;
			update <<rec.otRate << endl;
			update <<ndate << endl;
			update <<net << endl;
			nValid=1;
		}
		else{	cout << "Pasok ako sa else " << endl; update << srec << endl;	}
		}
		update.close();
		record.close();
		remove("record.txt");							//for deleting temporary file named "update.txt"
		rename("update.txt", "record.txt");	
		}
			
		if(!nValid){
		cout<< "\n\t-------------------------------------------------\n";
		cout<< "\t          EMPLOYEE NUMBER DOES NOT EXIST   \n";
		cout<< "\t-------------------------------------------------\n"<<endl; }
			back:
		cout << endl;
		cout << "\t\tUpdate another Employee? [Y/N] : ";
		cin >> ans;
		if(toupper(ans)=='N'){
			main();	}
		else if(toupper(ans)!='Y' && toupper(ans)!='N'){
			cout<< "\n\t-------------------------------------------------\n";
			cout<< "\t                   INVALID INPUT   \n";
			cout<< "\t-------------------------------------------------\n"<<endl;
			goto back;}
	}while(toupper(ans)=='Y'); 
	}
	
int employee::search_employee(){
	ifstream record;
	nValid=0;
	do{
	record.close();							//closing for file safety
	record.open("record.txt");				//opening txt file
	system("cls");
	cout << " ===============================================================================================================" << endl;
	cout << " |                                 S E A R C H   E M P L O Y E E   R E C O R D                                 |" << endl;
	cout << " ===============================================================================================================" << endl;

	if (!record.is_open()) {
		cout << "UNABLE TO OPEN FILE" << endl;
		system("pause");
		main();
	}
	else {
		cout <<left<<setw(18)<<"\n\t    Employee Number  "<<": | ";   //"left" is use as a margin for each output. it is printed left from a specific width
		cin >> searchkey;
		cout<<endl;

		while (!record.eof()) {//------------------------------------reading until the end of file
			getline(record, srec);//---------------------------------each line's string value 
			if (srec.substr(0, 4) != searchkey) {
				nValid = 0;
			}
			else {
				while(!srec.empty()){
				getline(record, name);//-----------------------------new value of string when conditions been met
				getline(record, address);//--------------------------each line holds specific string value for putting desired line  
				getline(record, contactN);//-------------------------to display
				getline(record, dep);
				getline(record, position);
				getline(record, date);
				getline(record, rpd);
				getline(record, rph);
				getline(record, otr);
				cout<< "\t  +---------------------+----------------------------------------------------+\n";
				cout <<"\t  | "<< left << setw(18) <<"Name " <<": | "<<setw(50)<<name <<" |"<<endl<< "\t  +---------------------+----------------------------------------------------+\n";
				cout <<"\t  | "<<  left << setw(18) <<"Address " <<": | "<<setw(50)<< address <<" |"<< endl<< "\t  +---------------------+----------------------------------------------------+\n";
				cout <<"\t  | "<<  left << setw(18) <<"Contact Number " <<": | "<<setw(50)<< contactN <<" |"<<endl<< "\t  +---------------------+----------------------------------------------------+\n";
				cout <<"\t  | "<<  left << setw(18) <<"Department " <<": | "<<setw(50)<< dep  <<" |"<<endl<< "\t  +---------------------+----------------------------------------------------+\n";
				cout <<"\t  | "<<  left << setw(18) <<"Position " <<": | "<<setw(50)<< position <<" |"<<endl<< "\t  +---------------------+----------------------------------------------------+\n";
				cout <<"\t  | "<<  left << setw(18) <<"Date Started " <<": | "<<setw(50)<< date <<" |"<<endl<< "\t  +---------------------+----------------------------------------------------+\n";
				cout <<"\t  | "<<  left << setw(18) <<"Rate per Day " <<": | "<<setw(50)<< rpd <<" |"<<endl<< "\t  +---------------------+----------------------------------------------------+\n";
				cout <<"\t  | "<<  left << setw(18) <<"Rate per Hour " <<": | "<<setw(50)<< rph <<" |"<<endl<< "\t  +---------------------+----------------------------------------------------+\n";
				cout <<"\t  | "<<  left << setw(18) <<"Overtime Rate " <<": | "<<setw(50)<< otr <<" |"<< endl<< "\t  +---------------------+----------------------------------------------------+";
				cout<<endl;
				break;//---------------------------------------------end loop while loop
				}
				nValid = 1;
				break;
				record.close();//------------------------------------closing text file
			}
		}
	}
		if (!nValid) {
			cout<< "\n\t-------------------------------------------------\n";
			cout<< "\t          EMPLOYEE NUMBER DOES NOT EXIST   \n";
			cout<< "\t-------------------------------------------------\n"<<endl;}
			cout << endl;
		back:
		cout << "\t\t  Search another Employee? [Y/N] : ";
		cin >> ans;
		record.close();
		if(toupper(ans)== 'N'){
			main();}
		else if(toupper(ans)!='Y' && toupper(ans)!='N'){
			cout<< "\n\t-------------------------------------------------\n";
			cout<< "\t                   INVALID INPUT   \n";
			cout<< "\t-------------------------------------------------\n"<<endl;
			goto back;}
	}while(toupper(ans) == 'Y');
}


int employee::computeS(){
	fstream record("record.txt", ios::out | ios::app | ios::in);			//declaring the stream record
	fstream update("update.txt", ios::out | ios::app | ios::in);			//declaring the stream update
	nValid=0;
	do{
	record.close();
	update.close();
	record.open("record.txt", ios::in);
	update.open("update.txt", ios::out);
	system("cls");
	cout << " ===============================================================================================================" << endl;
	cout << " |                                         C O M P U T E   S A L A R Y                                         |" << endl;
	cout << " ===============================================================================================================" << endl;
	if(!record.is_open()){
		cout << "Unable to open file" << endl;
		system("pause");
		main();	}
	else{
		cout <<left<<setw(18)<<"\n\t     Employee Number  "<<": | ";
		cin >> searchkey; 	cout << endl;
	while (getline(record, srec, '\n')){
		if (srec == searchkey)
		{	getline(record, name, '\n');
			getline(record, address, '\n');
			getline(record, contactN, '\n');
			getline(record, dep, '\n');
			getline(record, position, '\n');
			getline(record, date, '\n');
			getline(record, rpd, '\n');
			getline(record, rph, '\n');
			getline(record, otr, '\n');
			getline(record, ndate, '\n');
			getline(record, net, '\n');
				cout<< "\t  +---------------------+----------------------------------------------------+\n";
				cout << "\t  | "<< left << setw(18) <<"Name " <<": | "<<setw(50)<<name <<" |"<<endl<< "\t  +---------------------+----------------------------------------------------+\n";
				cout << "\t  | "<<  left << setw(18) <<"Address " <<": | "<<setw(50)<< address <<" |"<< endl<< "\t  +---------------------+----------------------------------------------------+\n";
				cout << "\t  | "<<  left << setw(18) <<"Contact Number " <<": | "<<setw(50)<< contactN <<" |"<<endl<< "\t  +---------------------+----------------------------------------------------+\n";
				cout << "\t  | "<<  left << setw(18) <<"Department " <<": | "<<setw(50)<< dep  <<" |"<<endl<< "\t  +---------------------+----------------------------------------------------+\n";
				cout << "\t  | "<<  left << setw(18) <<"Position " <<": | "<<setw(50)<< position <<" |"<<endl<< "\t  +---------------------+----------------------------------------------------+\n";
				cout << "\t  | "<<  left << setw(18) <<"Date Started " <<": | "<<setw(50)<< date <<" |"<<endl<< "\t  +---------------------+----------------------------------------------------+\n";
				cout << "\t  | "<<  left << setw(18) <<"Rate per Day " <<": | "<<setw(50)<< rpd <<" |"<<endl<< "\t  +---------------------+----------------------------------------------------+\n";
				cout << "\t  | "<<  left << setw(18) <<"Rate per Hour " <<": | "<<setw(50)<< rph <<" |"<<endl<< "\t  +---------------------+----------------------------------------------------+\n";
				cout << "\t  | "<<  left << setw(18) <<"Overtime Rate " <<": | "<<setw(50)<< otr <<" |"<< endl<< "\t  +---------------------+----------------------------------------------------+";
				cout<<endl;
				stringstream dd(rpd);//--------------------------convertion of string rate per date into int-----
				dd >> rec.rateD;
				stringstream hh(rph);//--------------------------convertion of string rate per hour into int      use stringstream for convertion
				hh >> rec.rateH;
				stringstream oo(otr);//--------------------------convertion of string overtime rate into int-----
				oo >> rec.otRate;
				cin.ignore();
				cout<<endl;
				cout << "\t    "<<  left << setw(18) <<"PAYROLLDATE "<<":   ";
				getline(cin,rec.payrollD);
				cout <<endl;
				cout << "\t    "<<  left << setw(18) <<"EARNINGS: " <<endl;
				cout << "\t    "<<  left << setw(18) <<"Total Days Worked "<<":   ";
				cin >> rec.workedD;
				cout << "\t    "<<  left << setw(18) <<"Total O-time Hours"<<":   ";
				cin >> rec.totalOH;
				rec.grossS = (rec.workedD*rec.rateD)+(rec.otRate*rec.totalOH);//----------------computing gross salary
				rec.sss = rec.grossS*0.15;//----------------------------------------------------computing sss
				rec.pagibig = rec.grossS*0.02;//------------------------------------------------computing pagibig
				rec.incomeT = rec.grossS*0.20;//------------------------------------------------computing income tax
				rec.totalD = rec.sss+rec.pagibig+rec.incomeT;//---------------------------------computing total Deduction
				rec.netpay = rec.grossS - rec.totalD;//-----------------------------------------computing sss
				cout<< "\t  +---------------------+----------------------------------------------------+\n";
				cout << "\t  | "<<  left << setw(18) << "Gross Salary "<<": | "<<setw(50)<<fixed<<setprecision(2) << rec.grossS <<" |"<<endl<< "\t  +---------------------+----------------------------------------------------+\n\n";
				cout << "\t    "<<  left << setw(18) << "DEDUCTIONS: "<<endl<< "\t  +---------------------+----------------------------------------------------+\n";
				cout << "\t  | "<<  left << setw(18) << "SSS (15%) "<<": | "<<setw(50)<<fixed<<setprecision(2) << rec.sss <<" |"<<endl<< "\t  +---------------------+----------------------------------------------------+\n";
				cout << "\t  | "<<  left << setw(18) << "Pagibig (2%) "<<": | "<<setw(50)<<fixed<<setprecision(2) << rec.pagibig <<" |"<<endl<< "\t  +---------------------+----------------------------------------------------+\n";
				cout << "\t  | "<<  left << setw(18) << "Income Tax (20%) "<<": | "<<setw(50)<<fixed<<setprecision(2) << rec.incomeT <<" |"<<endl<< "\t  +---------------------+----------------------------------------------------+\n";
				cout << "\t  | "<<  left << setw(18) << "Total Deductions "<<": | "<<setw(50)<<fixed<<setprecision(2) << rec.totalD <<" |"<<endl<< "\t  +---------------------+----------------------------------------------------+\n";
				cout << "\t  | "<<  left << setw(18) << "NET PAY "<<": | "<<setw(50)<<fixed<<setprecision(2)<< rec.netpay <<" |"<<endl<< "\t  +---------------------+----------------------------------------------------+\n";
																		//-------------------------------
				update <<searchkey<<endl;								//this part is for updating new computed netpay 
				update <<name <<endl;									//putting new netpay value to text file "update.txt"
				update <<address << endl;								
				update <<contactN <<endl; 
				update <<dep  <<endl;
				update <<position <<endl;
				update <<date <<endl; 
				update <<rec.rateD <<endl;
				update <<rec.rateH <<endl;
				update <<rec.otRate << endl;
				update <<rec.payrollD <<endl;
				update <<fixed << setprecision(2)<< rec.netpay <<endl;
				nValid=1;
				break;
		}
		else{	update << srec << endl;	}								//putting all lines that are not equal to the searchkey. 
		}
		update.close();
		record.close();
		remove("record.txt");											//for removing older file
		rename("update.txt", "record.txt");								//renaming updated files in to original name of "record.txt". 
		}	
		record.close();
		if(!nValid){													//if search employee number does not find
		cout<< "\n\t-------------------------------------------------\n";
		cout<< "\t          EMPLOYEE NUMBER DOES NOT EXIST   \n";
		cout<< "\t-------------------------------------------------\n"<<endl; }
			back:
		cout << endl;
		cout << "\t\tCOMPUTE ANOTHER EMPLOYEE? [Y/N] : ";
		cin >> ans;
		if(toupper(ans)=='N'){
			main();}
		else if(toupper(ans)!='Y' && toupper(ans)!='N'){
			cout<< "\n\t-------------------------------------------------\n";
			cout<< "\t                   INVALID INPUT   \n";
			cout<< "\t-------------------------------------------------\n"<<endl;
			goto back; }
	}while(toupper(ans)=='Y'); 
	}

int employee::display_payrollR(){
	ifstream record("record.txt", ios::in);					//reading feom the text file
	record.close();
	total=0;
	system("cls");
	cout << "    ===============================================================================================================" << endl;
	cout << "    |                              J & E  C O M P A N Y  P A Y R O L L   R E P O R T                              |" << endl;
	cout << "    ===============================================================================================================" << endl;
	cout <<" +--------------+----------------------------+------------------------------------+-------------------+--------------+\n";
	cout <<" |EMPLOYEE No.  |         POSITION           |             DEPARTMENT             |    PAYROLLDATE    |    NETPAY    |\n"; 
	record.open("record.txt", ios::in);							//opening the txt file "record.txt".
	if (record.is_open()) {
		while (!record.eof()){
			getline(record, srec);
			if(srec.substr(0,2)=="E1"){							//searching the first 2 value of employee number;
				getline(record, name);							
				getline(record, address);				
				getline(record, contactN);						//putting string value for each line after reading the first line "E10".	
				getline(record, dep);
				getline(record, position);
				getline(record, date);
				getline(record, rpd);
				getline(record, rph);
				getline(record, otr);
				getline(record, ndate);
				getline(record, net);													
				cout <<" +--------------+----------------------------+------------------------------------+-------------------+--------------+\n";
				cout <<" | "<< left <<setw(13)<<srec <<"| "<< setw(27)<< position <<"| "<<setw(35) << dep <<"| "<< setw(18)<< ndate<<"| " << setw(13) << net <<"|"<<endl;
			}	
		}
		record.close();
		record.open("record.txt", ios::in);
		while (!record.eof()){									//this section is for computing the netpay for each employee
			getline(record, srec);
			if(srec.substr(0,2)=="E1"){							// searching the initial value of string srec
				getline(record, name);
				getline(record, address);
				getline(record, contactN);
				getline(record, dep);
				getline(record, position);
				getline(record, date);
				getline(record, rpd);
				getline(record, rph);
				getline(record, otr);
				getline(record, ndate);
				getline(record, net);
				stringstream n(net);//--------------------------//converting string netpay into float
				n >> netInt;									//new float value for netpay 
				while(!net.empty()){//--------------------------//condition for computing no net values 
					total+=netInt; break;}						//getting the total netpay
			}	
		}
	cout <<" +--------------+----------------------------+------------------------------------+-------------------+--------------+\n";
	cout <<"                                                                                                      +--------------+\n";
	cout<< " "<<left <<setw(91)<<" " <<"TOTAL :   | "<<setw(13)<<fixed<<setprecision(2)<<total<<"|"<<endl;	
	cout <<"                                                                                                      +--------------+\n";
			record.close();	}
	else {	cout << "\n\tCANNOT OPEN FILE ";	}
	back:
	cout<<"\n\tWOULDL YOU LIKE TO GO BACK TO MAIN MENU? [Y/N] : ";
	cin>> ans;
	if(toupper(ans)=='Y'){
		main();}
	else if(toupper(ans)=='N'){
			exit(1);}
	else if(toupper(ans)!='Y' && toupper(ans)!='N'){
			cout<< "\n\t-------------------------------------------------\n";
			cout<< "\t                  INVALID INPUT   \n";
			cout<< "\t-------------------------------------------------\n"<<endl;
			goto back;	}
}
