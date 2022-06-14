//Transport header File
#include <string>
#include <iostream>
#include <fstream>

using namespace std;



class Bus {
	private:
		int bookedSeatsIndex=0;
		int bookedSeats[50];
	protected:
		int totalAvailableSeats;
		int busNumber;

		int getBookedSeatsCount() {
			return bookedSeatsIndex+1;
		}

	public:
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

		}
		int getFare() {
			return 1100;
		}
		int getBusType() {
			return 0;
		}
};

class PresidentCruise:public Bus {
	public:
		PresidentCruise(int busNumber):Bus(busNumber,45) {

		}
		int getFare() {
			return 2200;
		}
		int getBusType() {
			return 1;
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
	return *pBus;
}


