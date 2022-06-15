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
		int discount, optionId;
		string fromCity, toCity;
		Schedule() {

		}
		Schedule(Bus bus, int day, int month, int year, int depHour, int depMin, int arHour, int arMin, int discount, string fromCity, string toCity) {
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
		int getOptionNumber() {
			return optionId;
		}
		int setOptionNumber() {
			int n=1;
			int *pN=&n;
			int number;

			//reading from file
			fstream file;
			file.open("OPTION_NUMBERS.dat");
			while(file.read((char*)pN,sizeof(int))) {
				number=*pN;
			}
			file.close();
			number++;
			optionId=number;
			n=number;
			//writing into file
			fstream wrt;
			wrt.open("OPTION_NUMBERS.dat",ios::out|ios::app);
			wrt.write((char*)pN,sizeof(int));
			wrt.close(); //finished writing

			return number;
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

	Schedule *s=new Schedule(bus, day, month, year, depHour, depMin, arHour, arMin, discount,fromCity, toCity);
	s->setOptionNumber();

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

	Schedule *s=new Schedule(bus, day, month, year, depHour, depMin, arHour,arMin,discount, fromCity, toCity);
	s->setOptionNumber();
	//writing into file
	fstream wrt;
	wrt.open("SCHEDULE_DATA.dat",ios::out|ios::app);
	wrt.write((char*)s,sizeof(Schedule));
	wrt.close(); //finished writing
	return *s;
}

void showBusSchedules() {
	Schedule *pSchedule= new Schedule();
	cout<<"Option no.\t\t"<<"Bus Route\t\t\t"<<"Bus Type\t\t"<<"Date\t"<<"Departure Time\t"<<"Arrival Time\t"<<"Fare\t\t"<<"Discount\t\t"<<"Total"<<endl;
	//reading from file
	fstream file;
	file.open("SCHEDULE_DATA.dat");
	while(file.read((char*)pSchedule,sizeof(Schedule))) {
		string busType="";
		if(pSchedule->getBus().busType==0) {
			busType="Premium Cruise";
		} else if(pSchedule->getBus().busType==1) {
			busType="President Cruise";
		}
		cout<<pSchedule->optionId<<"\t\t\t"<<pSchedule->getFromCity()<<" to "<<pSchedule->getToCity()<<" \t"<<busType<<"\t"<<pSchedule->day<<"/"<<pSchedule->month<<"/"<<pSchedule->year<<"\t"<<pSchedule->depHour<<":"<<pSchedule->depMin<<"\t\t"<<pSchedule->arHour<<":"<<pSchedule->arMin<<"\t\t"<<pSchedule->bus.getFare()<<"\t\t\t"<<pSchedule->discount<<"\t\t"<<pSchedule->bus.getFare()+pSchedule->discount<<endl;
	}
	file.close();
}

void showBusSchedules(string fromCity, string toCity) {
	Schedule *pSchedule= new Schedule();
	cout<<"Option no.\t\t"<<"Bus Route\t\t\t"<<"Bus Type\t\t"<<"Date\t"<<"Departure Time\t"<<"Arrival Time\t"<<"Fare\t\t"<<"Discount\t\t"<<"Total"<<endl;
	//reading from file
	fstream file;
	file.open("SCHEDULE_DATA.dat");
	while(file.read((char*)pSchedule,sizeof(Schedule))) {
		try {
			if(pSchedule->fromCity==fromCity && pSchedule->toCity==toCity) {
				string busType="";
				if(pSchedule->getBus().busType==0) {
					busType="Premium Cruise";
				} else if(pSchedule->getBus().busType==1) {
					busType="President Cruise";
				}
				cout<<pSchedule->optionId<<"\t\t\t"<<pSchedule->fromCity<<" to "<<pSchedule->toCity<<" \t"<<busType<<"\t"<<pSchedule->day<<"/"<<pSchedule->month<<"/"<<pSchedule->year<<"\t"<<pSchedule->depHour<<":"<<pSchedule->depMin<<"\t\t"<<pSchedule->arHour<<":"<<pSchedule->arMin<<"\t\t"<<pSchedule->bus.getFare()<<"\t\t\t"<<pSchedule->discount<<"\t\t"<<pSchedule->bus.getFare()+pSchedule->discount<<endl;
			}
		} catch(...) {
		}

	}
	file.close();
}



int getNextOptionNumber() {
	static int number=0;
	return ++number;
}

Schedule getSchedule(int optionNumber) {
	Schedule *pSchedule=new Schedule();
	fstream file;
	file.open("SCHEDULE_DATA.dat");
	while(file.read((char*)pSchedule, sizeof(Schedule))) {
		if(pSchedule->optionId==optionNumber)
			break;
	}
	file.close();
	return *pSchedule;
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

