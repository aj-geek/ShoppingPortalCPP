#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

string loginCheck = "";

struct items {
	int itemno;
	char itemname[50];
	float mrp;
	float gst;

};

struct signup {
	char name[30];
	char address[90];
	char phoneno[11];
	char username[20];
	char email[30];
	char password[25];
};

struct signin {
	char username[20];
	char password[25];
};

void displayItem(){
	cout << "Display Items \n";
	fstream fi;
	fi.open("itemslist.txt", ios::in);
	string word;
	if (!fi) {
		cout << "Not found\n";
	}
	else {
		while (fi >> word) {
			cout << word << " \n";
		}
	}

	_getch();
}


void signup() {
	cout << "\n\tSIGNUP\n";
	struct signup s1;
	cout << "\nEnter Name "; cin >> s1.name;
	cout << "\nEnter address "; cin >> s1.address;
	cout << "\nEnter username "; cin >> s1.username;
	cout << "\nEnter email "; cin >> s1.email;
	cout << "\nEnter password "; cin >> s1.password;
	fstream fi;
	fi.open("signupdetail.txt", ios::app);
	fi << endl;
	fi << s1.username << " " << s1.password << " " << s1.email << " " << s1.name << " " << s1.address;
	fi.close();

	cout << endl;


	cout << "\n Press any key to go back";
	_getch();

	cout << endl;

}

void signin() {
	cout << " \n \t*** Provide Credentials \n";
	struct signin s1;
	cout << "\n \t ENTER USERNAME : "; cin >> s1.username;
	cout << "\n \t ENTER PASSWORD : "; cin >> s1.password;

	fstream fi;
	bool cred_bool = false;
	fi.open("signupdetail.txt", ios::in);
	if (!fi) {
		cout << "No User";
	}
	else {
		string word;
		
		while (fi >> word) {
			if (word == s1.username) {
				fi >> word;
				if(word == s1.password){
					cout << "\n Logged in ";
					cred_bool = true;
					cout << endl;
					loginCheck = s1.username;
					cout << "\n Press any key to go back";
					_getch();
					cout << endl;
					return;
				}
				
				
			}
			
		}
	}
	if (!cred_bool) {
		cout << "\n Invalid Credential";
		signin();
	}

	
}

void contactus() {
	cout << "Contact us";
	fstream st; 
	st.open("contactus.txt", ios::in);  
	if (!st) // Checking whether file exist
	{
		cout << "Contact us details doesn't exist";
	}
	else
	{
		char ch;
		cout << endl;
		while (!st.eof()) {
			st >> ch;
			cout << ch;
		}
		st.close();
	}
	
	cout << "\n Press any key to go back";
	_getch();
	cout << endl;
}



int main() {
	
	/*	
		MENU:
			Display Items
			Signup
			Sign In
			Contact Us 
	*/
	int option;

	


	do {
		system("cls");
		cout << "\t\t\t\t\t\t\t\t " << loginCheck;
		cout << endl << endl ;
		cout << "*****************";
		cout << "\n\t\tMenu\n";
		cout << " 1. Display Items \n 2. Signup \n 3. Sign In \n 4. Contact Us \n 5. Exit \n\n";
		cout << "*****************\n";
		cout << "Enter Choice:\t ";
		cin >> option;
		cout << endl;


		switch (option) {

		case 1:
			displayItem();
			break;

		case 2:
			signup();
			break;

		case 3:
			signin();
			break;

		case 4:
			contactus();
			break;

		case 5:
			exit(0);

		default:
			cout << "Enter valid option";

		}
	} while (option != 5);


	return 0;
}