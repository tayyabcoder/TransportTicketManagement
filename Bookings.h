//Header file for bookings
#include <string>
#include <iostream>
#include "Transport.h"
#include "Persons.h"

using namespace std;

class Schedule {
	public:
		Bus bus;
		int day, month, year, depHour, depMin, arHour, arMin;
		int discount;
		string fromCity, toCity;
		Schedule() {

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
		int getDiscount() {
			return discount;
		}
};

class Booking {
	public:
		Rider rider;
		Schedule schedule;
		int seatNumbers[10];
		int arrLength;
		Booking(Rider rider, Schedule schedule, int* seatNumbers, int arrLength) {
			this->rider=rider;
			this->schedule=schedule;
			this->arrLength=arrLength;
			for(int i=0; i<arrLength; i++) {
				this->seatNumbers[i]=*seatNumbers;
				seatNumbers++;
			}
		}
		Rider getRider() {
			return rider;
		}
		Schedule getSchedule() {
			return schedule;
		}
		int getArrLength() {
			return arrLength;
		}
		void getSeatNumbers() {
			for(int i=0; i<10; i++) {
				cout<<seatNumbers[i];
			}
			cout<<endl;
		}
		int getTotalFare() {
			return schedule.getBus().getFare()*arrLength;
		}
		int getTotalDiscount() {
			return schedule.getDiscount()*arrLength;
		}
		int getGrandTotal() {
			return getTotalFare()-getTotalDiscount();
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

	Schedule *s=new Schedule(bus, day, month, year, depHour, depMin, arHour, arMin, fromCity, toCity);
	
	//writing into file
	fstream wrt;
	wrt.open("SCHEDULE_DATA.dat",ios::out|ios::app);
	wrt.write((char*)s,sizeof(Schedule));
	wrt.close(); //finished writing
	return *s;
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

	Schedule *s=new Schedule(bus, day, month, year, depHour, depMin, arHour, arMin, fromCity, toCity);
	//writing into file
	fstream wrt;
	wrt.open("SCHEDULE_DATA.dat",ios::out|ios::app);
	wrt.write((char*)s,sizeof(Schedule));
	wrt.close(); //finished writing
	return *s;
}

void showBusSchedules() {
	cout<<"Option no.\t\t"<<"Bus Route\t\t\t"<<"Bus Type\t\t"<<"Date\t\t\t"<<"Departure Time\t"<<"Arrival Time\t"<<"Fare\t\t\t"<<"Discount\t\t"<<"Total"<<endl;
	cout<<"1\t\t\t"<<"Lahore to Islamabad\t"<<"Premium\t"<<"15/6/2022\t"<<"14:30\t\t"<<"15:00\t\t"<<"1100\t\t\t"<<"100\t\t"<<"1000"<<endl;
	cout<<"2\t\t\t"<<"Lahore to Multan\t"<<"President\t"<<"15/6/2022\t"<<"15:00\t\t"<<"18:24\t\t"<<"1700\t\t\t"<<"200\t\t"<<"1500"<<endl;
	cout<<"3\t\t\t"<<"Islamabad to Peshawar\t"<<"Premium\t"<<"15/6/2022\t"<<"18:24\t\t"<<"22:30\t"<<"1100\t\t\t"<<"0\t\t"<<"1100"<<endl;
	cout<<"4\t\t\t"<<"Rawalpindi to Muzafarabad\t"<<"President\t"<<"15/6/2022\t"<<"12:10\t\t"<<"6:20\t"<<"1800\t\t\t"<<"230\t\t"<<"1570"<<endl;
}

int getNextOptionNumber() {
	static int number=0;
	return ++number;
}

Schedule getSchedule(int optionNumber) {
	Schedule s(getBusByBusNumber(100), 14, 6, 2022, 15, 30, 22, 30, "Lahore", "Islamabad");
	return s;
}

Booking bookSeats(Schedule schedule, Rider rider,int *pSeats, int arrLength) {
	Booking *b=new Booking(rider,schedule, pSeats, arrLength);
	//writing into file
	fstream wrt;
	wrt.open("BOOKING_DATA.dat",ios::out|ios::app);
	wrt.write((char*)b,sizeof(Booking));
	wrt.close(); //finished writing
	return *b;
}

