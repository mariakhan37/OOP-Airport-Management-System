#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
#include "Flight.h"
using namespace std;

class Schedule {
private:
    Flight** flights;
    int maxFlights;
    int currentcount;

public:
    Schedule(int maxlights=50);
    ~Schedule();
    
    void addFlight(Flight* flight);
    bool removeFlight(int flightID);
    Flight* findFlight(int flightID) const;
    void updateFlightStatus(int flightID, const string& newStatus);
    
    Flight** getFlightsByDestination(const string& destination, int& resultCount) const;
    Flight** getFlightsByStatus(const string& status, int& resultCount) const;
    
    void displayFullSchedule() const;
    void displayFlightStatus(int flightID) const;
    
    int getFlightCount() const;
    bool isFlightScheduled(int flightID) const;
    void clearSchedule();
    
    Flight* getFlight(int index) const;
};

#endif