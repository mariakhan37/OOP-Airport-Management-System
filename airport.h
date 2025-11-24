#ifndef AIRPORT_H
#define AIRPORT_H

#include <string>
#include "person.h"
#include "crew.h"
#include "flight.h"
using namespace std;

class Airport {
private:
    string Name;
    string Location;
    int Runways;
    
    Employee** Employees;  
    CrewTeam** CrewTeams;
    Flight** Flights;
    
    int employeeCapacity;
    int employeeCount;
    int crewTeamCapacity;
    int crewcount;
    int flightCapacity;
    int flightCount;

public:
    Airport(const string& name, const string& location, int runways);
    ~Airport();
    
    void AddFlight(int flightID, const string& origin, const string& destination, const string& aircraft);
    void updateFlightStatus(int flightID, const string& newStatus);
    void AssignCrewToFlight(int flightID, CrewTeam* crew);
    void addPassengerToFlight(int flightID, Passenger* passenger);
    
    void assignEmployee(Employee* employee, const string& teamID = "");
    void displayAllEmployees() const;
    
    void createCrewTeam(const string& teamID, const string& teamName);
    CrewTeam* findCrewTeam(const string& teamID) const;
    void displayAllCrewTeams() const;
    
    void displaySummary() const;
    
    string getName() const;
    int getFlightCount() const;
    Flight* getFlight(int index) const;
    Employee* getEmployee(int index) const;
    int getEmployeeCount() const;
    CrewTeam* getCrewTeam(int index) const;
    int getCrewCount() const;
};

#endif