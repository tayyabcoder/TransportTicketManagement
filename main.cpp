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
							if(menu2==1) {
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
							} else if(menu2==2) {
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
				if(menu==1) {
					//Book a ride
					int optionNumber;
					Rider rider=CreateNewRider();
					cout<<"Please wait we are searching the options for you";
					showLoadingDots(5);
					cout<<endl;
					cout<<"Available Buses:"<<endl<<endl;
					showAllBuses();
					cout<<"Please enter the desired option number: ";
					cin>>optionNumber;
					cout<<"Loading available seats";
					showLoadingDots(3);
					cout<<endl;
					Schedule schedule=getSchedule(optionNumber);
					cout<<"Available Seats: "<<endl;
					schedule.getBus().getAvailableSeats();
					cout<<endl;
					int availableSeatsCount=schedule.getBus().getAvailableSeatsCount();
					int selectedSeats[availableSeatsCount];
					int index=0;
					for(int i=0; i<availableSeatsCount; i++) {
						selectedSeats[i]=0;
					}
					for(int i=0; i<availableSeatsCount; i++) {
						int n;
						cout<<"Please enter seat number: ";
						cin>>n;
						selectedSeats[index]=n;
						index++;
						char yesNo='y';
						cout<<"Do you want to select more?(y/n): ";
						cin>>yesNo;
						if(yesNo!='y')
							break;
					}
					Booking booking=bookSeats(schedule,rider, selectedSeats, index);
					cout<<"Please wait while we are generating your E-Ticket";
					showLoadingDots(5);
					system("CLS");
					cout<<"******************///E-TICKET\\\\\\********************"<<endl<<endl;
					cout<<"Rider Name: "<<booking.getRider().getFristName()<<" "<<booking.getRider().getLastName()<<endl;
					cout<<"Seats: ";
					booking.getSeatNumbers();
					cout<<endl;
					cout<<"Fare: "<<booking.getTotalFare()<<" Discount: "<<booking.getTotalDiscount()<<" G.Total: "<<booking.getGrandTotal()<<endl;
					cout<<"*************************************************************************";
					waitAnyKey();
				}
				system("CLS");
				showValidOptionError(menu,0,1);
			} while(menu!=0);
		}
		showValidOptionError((role!=1 && role !=2 && role !=3));
	} while(role!=3);

	return 0;
}