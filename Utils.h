//Utils Header File
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>

enum IN {

	// 13 is ASCII for carriage
	// return
	IN_BACK = 8,
	IN_RET = 13

};


string takePasswdFromUser() {
	string ipt = "";
	char ipt_ch;
	while (true) {
		ipt_ch = getch();

		// Check whether user enters
		// a special non-printable
		// character
		if (ipt_ch < 32) {
			cout << endl;
			return ipt;
		}
		ipt.push_back(ipt_ch);
	}
}


string takePasswdFromUser(char sp) {
	// Stores the password
	string passwd = "";
	char ch_ipt;

	// Until condition is true
	while (true) {

		ch_ipt = getch();

		// if the ch_ipt
		if (ch_ipt == IN::IN_RET) {
			cout << endl;
			return passwd;
		} else if (ch_ipt == IN::IN_BACK
		           && passwd.length() != 0) {
			passwd.pop_back();

			// Cout statement is very
			// important as it will erase
			// previously printed character
			cout << "\b \b";

			continue;
		}

		// Without using this, program
		// will crash as \b can't be
		// print in beginning of line
		else if (ch_ipt == IN::IN_BACK
		         && passwd.length() == 0) {
			continue;
		}

		passwd.push_back(ch_ipt);
		cout << sp;
	}
}

void showValidOptionError(int menu,int from, int to) {
	if(menu<from || menu>to)
		cout<<"Error: Please Enter a Valid Option"<<endl;
}

void showValidOptionError(bool condition) {
	if(condition)
		cout<<"Error: Please Enter a Valid Option"<<endl;
}

void showLoadingDots(int n) {
	for(int i=0; i<n; i++) {
		Sleep(800);
		cout<<".";
	}
}

void waitAnyKey() {
	cout << "Press Any key to continue...";
	getch();
}


bool checkUserNameAndPassword(string username, string password) {
	string _username, _password;
	for(int attempt=1; attempt<=3; attempt++) {
		system("CLS");
		cout<<"(Login Attempt "<<attempt<<" of 3)   \n"<<endl;
		cout<<endl;
		cout<<endl;
		cout<<"\nPlease enter username: ";
		cin>>_username;
		cout<<"Please enter password: ";
		_password=takePasswdFromUser('*');
		cout<<"Please Wait While we are authenticating you.";
		showLoadingDots(5);
		system("CLS");
		if(_username==username && _password==password) {
			cout<<"Login Successfull"<<endl;
			Sleep(1300);
			system("CLS");
			return true;
		} else {
			cout<<"Invalid Login Attempt";
			showLoadingDots(3);
			cout<<endl;
		}
	}
	return false;
}