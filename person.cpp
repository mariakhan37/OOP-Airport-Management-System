#include "Person.h"
#include <iostream>
using namespace std;

Person::Person(const string& name, const string& id, const string& email, const string& phoneNumber)
    :name(name), id(id), email(email), phoneNumber(phoneNumber) {}

void Person::updateContactInfo(const string& newEmail, const string& newPhone) {
    email=newEmail;
    phoneNumber=newPhone;
    cout << "Contact info updated for " << name << endl;
}

string Person::getName() const 
{
    return name; 
}
string Person::getId() const {
    return id; 
}
string Person::getEmail() const { 
    return email; 
}
string Person::getPhoneNumber() const {
    return phoneNumber; 
}

Employee::Employee(const string& name, const string& id, const string& email, const string& phoneNumber, const string& employeeID, double salary, const string& position)
    :Person(name, id, email, phoneNumber), employeeID(employeeID), salary(salary), position(position) {}

void Employee::displayInfo() const {
    cout << "\nEmployee Info: " << endl;
    cout << "Name: " << getName() << endl;
    cout << "ID: " << getId() << endl;
    cout << "Email: " << getEmail() << endl;
    cout << "Phone: " << getPhoneNumber() << endl;
    cout << "Employee ID: " << employeeID << endl;
    cout << "Position: " << position << endl;
    cout << "Salary: " << salary << endl;
}

string Employee::bookFlight() const {
    return "Employee " + employeeID + " booked a flight for a passenger";
}

string Employee::cancelBooking() const {
    return "Employee " + employeeID + " canceled a booking";
}

string Employee::checkIn() const {
    return "Employee " + employeeID + " checked in a passenger";
}

string Employee::getEmployeeID() const { 
    return employeeID; }
double Employee::getSalary() const { 
    return salary; }
string Employee::getPosition() const { 
    return position; }

Passenger::Passenger(const string& name, const string& id, const string& email, const string& phoneNumber, const string& passportNumber, const string& nationality, const string& dateOfBirth)
    :Person(name, id, email, phoneNumber), passportNumber(passportNumber), 
      nationality(nationality), dateOfBirth(dateOfBirth) {}

void Passenger::displayInfo() const {
    cout << "\nPasseneger info: " << endl;
    cout << "Name: " << getName() << endl;
    cout << "ID: " << getId() << endl;
    cout << "Email: " << getEmail() << endl;
    cout << "Phone: " << getPhoneNumber() << endl;
    cout << "Passport: " << passportNumber << endl;
    cout << "Nationality: " << nationality << endl;
    cout << "Date of Birth: " << dateOfBirth << endl;
}

void Passenger::performDuty() const {
    cout << "Passenger " << getName() << " is traveling with passport " << passportNumber << endl;
}

double Passenger::calculatePay() const {
    double baggageFee = 50.0;
    cout << "Passenger " << getName() << " paid baggage fee: " << baggageFee << endl;
    return baggageFee;
}

string Passenger::getPassportNumber() const {
    return passportNumber; 
}
string Passenger::getNationality() const {
    return nationality; 
}
string Passenger::getDateOfBirth() const { 
    return dateOfBirth; 
}