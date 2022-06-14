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
			if(checkUserNameAndPassword("admin", "admin")) { //change username & password
				int menu;
				do {
					cout<<"Press 1 to Schedule a Bus"<<endl;
					cout<<"Press 0 to go back"<<endl;
					cin>>menu;
					system("CLS");
					if(menu==1) {
						//Schedule Bus
						int menu2;
						do {
							cout<<"Press 1 to Add with new Bus"<<endl;
							cout<<"Press 2 to Add with existing Bus"<<endl;
							cout<<"Press 0 to go back"<<endl;
							cin>>menu2;
							system("CLS");
							if(menu2==1){
								//Add with new bus
								Bus bus=createNewBus();
								cout<<"Adding new bus";
								showLoadingDots(5);
								cout<<endl;
								cout<<"New Bus has been added with bus no: "<<bus.getBusNumber()<<".\n";
								cout<<endl;
								CreateNewSchedule(bus);
								cout<<"Schedule has been added successfully";
								showLoadingDots(3);
								cout<<endl;
								waitAnyKey();
							}
							else if(menu2==2){
								//add with existing bus
								int busNumber;
								cout<<"Loading all available buses";
								showLoadingDots(5);
								cout<<endl;
								showAllBuses();
								cout<<endl;
								cout<<endl;
								cout<<"Please select a bus number to add schedule"<<endl;
								cin>>busNumber;
								Bus bus= getBusByBusNumber(busNumber);
								CreateNewSchedule(bus);
								cout<<"Schedule has been added successfully";
								showLoadingDots(3);
								cout<<endl;
								waitAnyKey();
							}
							system("CLS");
							showValidOptionError(menu2, 0,2);
						} while(menu2!=0);
					}
					system("CLS");
					showValidOptionError(menu,0,1);
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
				showValidOptionError(menu,0,1);
			} while(menu!=0);
		}
		showValidOptionError((role!=1 && role !=2 && role !=3));
	} while(role!=3);

	return 0;
}