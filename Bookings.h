//Header file for bookings
#include <string>
#include <iostream>
#include "Transport.h"
#include "Persons.h"

using namespace std;

class Schedule {
	private:
		Bus bus;
		int day, month, year, depHour, depMin, arHour, arMin;
		int discount;
		string fromCity, toCity;
	public:
		Schedule(){
			
		}
		Schedule(Bus bus, int day, int month, int year, int depHour, int depMin, int arHour, int arMin, string fromCity, string toCity) {
			this->arHour=arHour;
			this->arMin=arMin;
			this->bus=bus;
			this->day=day;
			this->depHour=depHour;
			this->depMin=depMin;
			this->discount=discount;
			this->fromCity=fromCity;
			this->month=month;
			this->toCity=toCity;
			this->year=year;
		}
		Bus getBus() {
			return bus;
		}
		int getScheduleDay() {
			return day;
		}
		int getScheduleMonth() {
			return month;
		}
		int getScheduleYear() {
			return year;
		}
		int getDepartureHour() {
			return depHour;
		}
		int getDepartureMinute() {
			return depMin;
		}
		string getFromCity() {
			return fromCity;
		}
		string getToCity() {
			return toCity;
		}
};

class Booking {
	private:
		Rider rider;
		Schedule schedule;
		int seatNumbers[10];
	public:
		Booking(Rider rider, Schedule schedule, int seatNumbers[]) {
			this->rider=rider;
			this->schedule=schedule;
			for(int i=0; i<10; i++){
				this->seatNumbers[i]=seatNumbers[i];
			}
		}
		Rider getRider() {
			return rider;
		}
		Schedule getSchedule() {
			return schedule;
		}
		void getSeatNumbers() {
			for(int i=0; i<10; i++){
				cout<<seatNumbers[i];
			}
			cout<<endl;
		}
};

Schedule CreateNewSchedule(Bus* buses, int arrLength) {
	Bus bus;
	int day, month, year, depHour, depMin, arHour, arMin;
	int discount, busNumber;
	string fromCity, toCity;
	bool isFound=false;
	do {
		cout<<"Please enter bus number: ";
		cin>>busNumber;
		for(int i=0; i<arrLength; i++) {
			if(buses[i].getBusNumber()==busNumber) {
				bus=buses[i];
				isFound=true;
				break;
			}
		}
		if(!isFound) {
			cout<<"Error: The Specified Bus is not found"<<endl;
		}
	} while(!isFound);
	cout<<"Please enter departure city: ";
	cin>>fromCity;
	cout<<"Please enter destination city: ";
	cin>>toCity;
	cout<<"Please Enter date of departure (dd MM yyyy): ";
	cin>>day>>month>>year;
	cout<<"Please Enter time of deaparture (HH mm): ";
	cin>>depHour>>depMin;
	cout<<"Please Enter time of arrival at the destination (HH mm): ";
	cin>>arHour>>arMin;
	cout<<"Please Enter discount on the ride: ";
	cin>>discount;

	Schedule s(bus, day, month, year, depHour, depMin, arHour, arMin, fromCity, toCity);
	return s;
}

Schedule CreateNewSchedule(Bus bus) {
	int day, month, year, depHour, depMin, arHour, arMin;
	int discount, busNumber;
	string fromCity, toCity;
	cout<<"Please enter departure city: ";
	cin>>fromCity;
	cout<<"Please enter destination city: ";
	cin>>toCity;
	cout<<"Please Enter date of departure (dd MM yyyy): ";
	cin>>day>>month>>year;
	cout<<"Please Enter time of deaparture (HH mm): ";
	cin>>depHour>>depMin;
	cout<<"Please Enter time of arrival at the destination (HH mm): ";
	cin>>arHour>>arMin;
	cout<<"Please Enter discount on the ride: ";
	cin>>discount;

	Schedule s(bus, day, month, year, depHour, depMin, arHour, arMin, fromCity, toCity);
	return s;
}