#include <iostream>
#include <stdlib.h>
#include <strings.h>
#include "Bookings.h"
#include "Utils.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int role;
	do {
		cout<<"Press 1 for Admin\nPress 2 for Rider\nPress 3 to Exit the program"<<endl;
		cin>>role;
		system("CLS");
		if(role==1) {
			//Admin
			if(checkUserNameAndPassword("admin", "admin")) {
				int menu;
				do {
					cout<<"Press 1 to Add a Bus"<<endl;
					cout<<"Press 2 to View all Buses"<<endl;
					cout<<"Press 3 to Schedule a Bus"<<endl;
					cout<<"Press 0 to go back"<<endl;
					cin>>menu;
					system("CLS");
					if(menu==1){
						//Add Bus
					}
					else if(menu==2){
						//View all Buses
					}
					else if(menu==3){
						//Schedule Bus
					}
					if(menu<0 || menu>3)
						cout<<"Error: Please Enter a Valid Option"<<endl;
				} while(menu!=0);
			}

		} else if(role==2) {
			//Rider/user
			int menu;
			do {
				cout<<"Press 1 to Book a Bus"<<endl;
				cout<<"Press 0 to go back"<<endl;
				cin>>menu;
				system("CLS");
				if(menu<0 || menu>2)
					cout<<"Error: Please Enter a Valid Option"<<endl;
			} while(menu!=0);
		}
		if(role!=1 && role !=2 && role !=3) {
			cout<<"Error: Invalid Command"<<endl<<endl;
		}
	} while(role!=3);

	return 0;
}