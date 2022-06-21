//Persons Header File
#include <string>
#include <iostream>

using namespTace std;

class Person {
	public:
		string firstName, lastName, cnic, mobileNumber, email;
		int gender; //0 Female and 1 for male
		string getFristName() {
			return firstName;
		}
		string getLastName() {
			return lastName;
		}
		string getCNIC() {
			return cnic;
		}
		string getMobileNumber() {
			return mobileNumber;
		}
		string getEmail() {
			return email;
		}
		int getGender() {
			return gender;
		}
		void setFirstName(string firstName) {
			this->firstName=firstName;
		}
		void setLastName(string lastName) {
			this->lastName=lastName;
		}
		void setCNIC(string cnic) {
			this->cnic=cnic;
		}
		void setMobileNumber(string mobileNumber) {
			this->mobileNumber=mobileNumber;
		}
		void setEmail(string email) {
			this->email=email;
		}
		void setGender(int gender) {
			this->gender=gender;
		}
};

class Rider:public Person {
	public:
		string startCity, destinationCity;
		string getStartCity() {
			return startCity;
		}
		string getDestinationCity() {
			return destinationCity;
		}
		void setStartCity(string startCity) {
			this->startCity=startCity;
		}
		void setDestinationCity(string destinationCity) {
			this->destinationCity=destinationCity;
		}
};

Rider CreateNewRider() {
	string firstName, lastName, cnic, mobileNumber, email, startCity, destinationCity;
	int gender;
	cout<<"Enter First Name: ";
	cin>>firstName;
	cout<<"Enter Last Name: ";
	cin>>lastName;
	cout<<"Enter CNIC: ";
	cin>>cnic;
	cout<<"Enter Mobile Number: ";
	cin>>mobileNumber;
	cout<<"Enter Email: ";
	cin>>email;
	cout<<"Enter Start City: ";
	cin>>startCity;
	cout<<"Enter Destination City: ";
	cin>>destinationCity;
	do {
		cout<<"Enter Gender (0 for Female and 1 for Male): ";
		cin>>gender;
		if(gender!=0 && gender!=1) {
			cout<<"Error: Please enter a valid gender."<<endl;
		}
	} while(gender!=0 && gender!=1);
	Rider r;
	r.setCNIC(cnic);
	r.setDestinationCity(destinationCity);
	r.setEmail(email);
	r.setFirstName(firstName);
	r.setLastName(lastName);
	r.setMobileNumber(mobileNumber);
	r.setStartCity(startCity);
	r.setGender(gender);
	
	Rider *pRider=&r;
	
	//writing into file
	fstream wrt;
	wrt.open("PERSON_DATA.dat",ios::out|ios::app);
	wrt.write((char*)pRider,sizeof(Rider));
	wrt.close(); //finished writing
	
	return r;
}