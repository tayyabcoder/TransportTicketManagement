//Transport header File
#include <string>
#include <iostream>
#include <fstream>

using namespace std;



class Bus {
	public:
		int bookedSeatsIndex=0;
		int bookedSeats[50];
		int totalAvailableSeats;
		int busNumber;
		int busType;
		int fare;

		int getBookedSeatsCount() {
			return bookedSeatsIndex+1;
		}
		Bus() {

		}
		Bus(int busNumber, int totalAvailableSeats) {
			this->busNumber=busNumber;
			this->totalAvailableSeats=totalAvailableSeats;
		}

		int getTotalAvailableSeats() {
			return totalAvailableSeats;
		}

		int getBusNumber() {
			return busNumber;
		}

		bool bookSeat(int seatNumber) {
			if (seatNumber>=1 && seatNumber<=totalAvailableSeats) {
				bool isNotBooked=true;
				for(int i=0; i<50; i++) {
					if(bookedSeats[i]==seatNumber) {
						isNotBooked=false;
						cout<<"The seat is already booked"<<endl;
						break;
					}
				}
				if(isNotBooked) {
					bookedSeats[bookedSeatsIndex]=seatNumber;
					bookedSeatsIndex++;
				}
				return isNotBooked;
			}
			return false;
		}

		int getAvailableSeatsCount() {
			return totalAvailableSeats-getBookedSeatsCount();
		}

		void getAvailableSeats() {
			int availableSeats[getAvailableSeatsCount()];
			int index=0;
			for(int i=0; i<totalAvailableSeats; i++) {
				for(int j=0; j<getBookedSeatsCount(); j++) {
					if(i!=bookedSeats[j]) {
						bool isAlreadyAdded=false;
						for(int k=0; k<index; k++) {
							if(availableSeats[k]==i) {
								isAlreadyAdded=true;
								break;
							}
						}
						if(!isAlreadyAdded) {
							availableSeats[index]=i;
							index++;
						}
					}
				}
			}
			for(int i = 0; i<getAvailableSeatsCount(); i++) {
				cout<<availableSeats[i];
				if((i+1)%4==0) {
					cout<<endl;
				} else if((i+1)%2==0) {
					cout<<'\t';
				} else {
					cout<<",";
				}
			}
		}

		int getFare() {
			//shall be implemented in the derived class
			return 0;
		}

		int getBusType() { //0 for Premium Cruise and 1 for President Cruise
			//shall be implemented in derived class
			return -1;
		}
};

class PremiumBus:public Bus {
	public:
		PremiumBus(int busNumber):Bus(busNumber,50) {
			busType=0;
			fare=1700;
		}
		int getFare() {
			return fare;
		} int getBusType() {
			return busType;
		}
};

class PresidentCruise:public Bus {
	public:
		PresidentCruise(int busNumber):Bus(busNumber,45) {
			busType=1;
			fare=2200;
		}
		int getFare() {
			return fare;
		}
		int getBusType() {
			return busType;
		}
};


Bus createNewBus() {
	int busNumber, seatsCapacity, busType;
	Bus *pBus;
	cout<<"Please Enter the Bus Number: ";
	cin>>busNumber;

	do {
		cout<<"Please Enter Bus Type (0 for Premium Cruise and 1 for President Cruise): ";
		cin>>busType;
		if(busType!=0 && busType!= 1) {
			cout<<"Error: Please enter valid bus type."<<endl;
		}
	} while(busType!=0 && busType!= 1);

	if(busType==0) {
		PremiumBus b(busNumber);
		pBus=&b;
	} else if(busType==1) {
		PresidentCruise b(busNumber);
		pBus=&b;
	}
	//writing into file
	fstream wrt;
	wrt.open("TRANSPPORT_DATA.dat",ios::out|ios::app);
	wrt.write((char*)pBus,sizeof(Bus));
	wrt.close(); //finished writing
	return *pBus;
}

void showAllBuses() {
	Bus *pBus =new Bus();
	cout<<"Bus number\t\tBus Type"<<endl;
	//reading from file
	fstream file;
	file.open("TRANSPPORT_DATA.dat");
	while(file.read((char*)pBus,sizeof(Bus))) {
		string busType="";
		if(pBus->busType==0) {
			busType="Premium Cruise";
		} else if(pBus->busType==1) {
			busType="President Cruise";
		}
		cout<<pBus->busNumber<<"\t\t\t"<<busType<<endl;
	}
	file.close();
}

Bus getBusByBusNumber(int busNumber) {
	Bus *pBus=new Bus();
	//reading from file
	fstream file;
	file.open("TRANSPPORT_DATA.dat");
	while(file.read((char*)pBus, sizeof(Bus))) {
		if(pBus->busNumber==busNumber)
			break;
	}
	file.close();
	return *pBus;
}


