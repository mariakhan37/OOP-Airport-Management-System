#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
private:
    string name;
    string id;
    string email;
    string phoneNumber;

public:
    Person(const string& name, const string& id, const string& email, const string& phoneNumber);
    virtual ~Person() {}
    
    virtual void displayInfo() const = 0;
    void updateContactInfo(const string& newEmail, const string& newPhone);
    
    string getName() const;
    string getId() const;
    string getEmail() const;
    string getPhoneNumber() const;
};

class Employee : public Person {
private:
    string employeeID;
    double salary;
    string position;

public:
    Employee(const string& name, const string& id, const string& email, const string& phoneNumber, const string& employeeID, double salary, const string& position);
    virtual ~Employee() {}
    
    virtual void displayInfo() const override;
    
    string bookFlight() const;
    string cancelBooking() const;
    string checkIn() const;
    
    string getEmployeeID() const;
    double getSalary() const;
    string getPosition() const;
};

class Passenger : public Person {
private:
    string passportNumber;
    string nationality;
    string dateOfBirth;

public:
    Passenger(const string& name, const string& id, const string& email, const string& phoneNumber, const string& passportNumber, const string& nationality, const string& dateOfBirth);
    virtual ~Passenger() {}
    
    virtual void displayInfo() const override;
    void performDuty() const;
    double calculatePay() const;
    
    string getPassportNumber() const;
    string getNationality() const;
    string getDateOfBirth() const;
};

#endif