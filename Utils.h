//Utils Header File
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>

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

void showLoadingDots(int n) {
	for(int i=0; i<n; i++) {
		Sleep(800);
		cout<<".";
	}
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
		_password=takePasswdFromUser();
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