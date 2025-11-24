#include "airport.h"
#include <iostream>
using namespace std;

Airport::Airport(const string& name, const string& location, int runways) 
    :Name(name), Location(location), Runways(runways),
        employeeCapacity(50), employeeCount(0),
        crewTeamCapacity(20), crewcount(0),  //allocating memory
        flightCapacity(30), flightCount(0) {
    
    Employees=new Employee*[employeeCapacity];
    CrewTeams=new CrewTeam*[crewTeamCapacity];  //dynamically allocates memory for arrays of pointers
    Flights=new Flight*[flightCapacity];
    
    for (int i=0; i<employeeCapacity; i++) {
        Employees[i]=nullptr;}
    for (int i=0; i<crewTeamCapacity; i++) {
        CrewTeams[i]=nullptr;}
    for (int i=0; i<flightCapacity; i++) {
        Flights[i]=nullptr;}
    
    cout << "Airport " << Name << " created with " << Runways << " runways" << endl;
}

Airport::~Airport() {
    delete[] Employees;
    delete[] CrewTeams;
    delete[] Flights;
}

void Airport::AddFlight(int flightID, const string& origin, const string& destination, const string& aircraft) {
    if (flightCount < flightCapacity) {
        Flights[flightCount]= new Flight(flightID, origin, destination, aircraft);
        flightCount++;
        cout << "Flight " << flightID << " added to " << Name << " airport" << endl;
    } else {
        cout << "Can't add more flights airport capacity reached" << endl;
    }
}

void Airport::updateFlightStatus(int flightID, const string& newStatus) {
    for (int i=0; i<flightCount; i++) {
        if (Flights[i]->getFlightID()==flightID) {
            Flights[i]->updateStatus(newStatus);
            cout << "Flight " << flightID << " status updated to: " << newStatus << endl;
            return;
        }
    }
    cout << "Flight " << flightID << " not found" << endl;
}

void Airport::AssignCrewToFlight(int flightID, CrewTeam* crew) {
    for (int i=0; i<flightCount; i++) {
        if (Flights[i]->getFlightID() == flightID) {
            Flights[i]->assignCrew(crew);
            return;
        }
    }
    cout << "Flight " << flightID << " not found" << endl;
}

void Airport::addPassengerToFlight(int flightID, Passenger* passenger) {
    for (int i=0; i<flightCount; i++) {
        if (Flights[i]->getFlightID() == flightID) {
            Flights[i]->addPassenger(passenger);
            return;
        }
    }
    cout << "Flight " << flightID << " not found" << endl;
}

void Airport::assignEmployee(Employee* employee, const string& teamID) {
    if (employeeCount<employeeCapacity) {
        Employees[employeeCount]=employee;
        employeeCount++;
        cout << "Employee " << employee->getName() << " assigned to " << Name << endl;
        
        if (!teamID.empty()) {
            for (int i=0; i<crewcount; i++) {
                if (CrewTeams[i]->getTeamID()==teamID) {   
                    CrewTeams[i]->addMember(employee);
                    break;
                }
            }
        }
    } else {
        cout << "Airport " << Name << " is full! Cannot hire more employees." << endl;
    }
}

void Airport::displayAllEmployees() const {
    cout << "\nEMPLOYEES AT: " << Name << " " << endl;
    for (int i=0; i<employeeCount; i++) {
        if (Employees[i] != nullptr) {
            cout << i+1 << ". " << Employees[i]->getName() << " - " << Employees[i]->getPosition() << endl;
        }
    }
}

void Airport::createCrewTeam(const string& teamID, const string& teamName) {
    if (crewcount<crewTeamCapacity) {
        CrewTeams[crewcount] =new CrewTeam(teamID, teamName);
        crewcount++;
        cout << "Crew team " << teamName << " created at " << Name << " airport" << endl;
    } else {
        cout << "cannot create more crew teams capacity reached" << endl;
    }
}

CrewTeam* Airport::findCrewTeam(const string& teamID) const {
    for (int i=0; i<crewcount; i++) {
        if (CrewTeams[i]->getTeamID() == teamID) {
            return CrewTeams[i];
        }
    }
    return nullptr;
}

void Airport::displayAllCrewTeams() const {
    cout << "\nCREW TEAMS AT: " << Name << " " << endl;
    for (int i=0; i<crewcount; i++) {
        if (CrewTeams[i] != nullptr) {
            CrewTeams[i]->displayTeam();
        }
    }
}

void Airport::displaySummary() const {
    cout << "\nAirport summary: " << endl;
    cout << "Name: " << Name << endl;
    cout << "Location: " << Location << endl;
    cout << "Runways: " << Runways << endl;
    cout << "Employees: " << employeeCount << endl;
    cout << "Crew Teams: " << crewcount << endl;
    cout << "Flights: " << flightCount << endl;
}

//getters
string Airport::getName() const {
    return Name;
}

int Airport::getFlightCount() const { 
    return flightCount; 
}

Flight* Airport::getFlight(int index) const { 
    if (index>=0 && index<flightCount) return Flights[index];
    return nullptr;
}

Employee* Airport::getEmployee(int index) const { 
    if (index >= 0 && index < employeeCount) return Employees[index];
    return nullptr;
}

int Airport::getEmployeeCount() const { 
    return employeeCount;}

CrewTeam* Airport::getCrewTeam(int index) const { 
    if (index>=0 && index<crewcount) return CrewTeams[index];
    return nullptr;
}

int Airport::getCrewCount() const {
    return crewcount; 
}