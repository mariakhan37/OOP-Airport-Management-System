#include "Schedule.h"
#include <iostream>

Schedule::Schedule(int maxFlights) 
    : maxFlights(maxFlights), currentcount(0) {
    flights=new Flight*[maxFlights];
    for (int i=0; i<maxFlights; i++) {
        flights[i]=nullptr;
    }
}
Schedule::~Schedule() {
    delete[] flights;
}

void Schedule::addFlight(Flight* flight) {
    if (currentcount < maxFlights) {
        for (int i=0; i<currentcount; i++) {
            if (flights[i]->getFlightID() == flight->getFlightID()) {
                cout << "Flight " << flight->getFlightID() << " already exists in schedule" << endl;
                return;
            }
        }
        
        flights[currentcount]=flight;
        currentcount++;
        cout << "Flight " << flight->getFlightID() << " added to schedule: " 
             << flight->getOrigin() << " → " << flight->getDestination() << endl;
    } else {
        cout << "Schedule is full! Cannot add more flights." << endl;
    }
}

bool Schedule::removeFlight(int flightID) {
    for (int i=0; i<currentcount; i++) {
        if (flights[i]->getFlightID()==flightID) {
            for (int j=i; j<currentcount-1; j++) {
                flights[j]=flights[j+1];
            }
            flights[currentcount-1]=nullptr;
            currentcount--;
            cout << "Flight " << flightID << " removed from schedule" << endl;
            return true;
        }
    }
    cout << "Flight " << flightID << " not found in schedule" << endl;
    return false;
}

Flight* Schedule::findFlight(int flightID) const {
    for (int i=0; i<currentcount; i++) {
        if (flights[i]->getFlightID() == flightID) {
            return flights[i];
        }
    }
    return nullptr;
}

void Schedule::updateFlightStatus(int flightID, const string& newStatus) {
    Flight* flight=findFlight(flightID);
    if (flight) {
        flight->updateStatus(newStatus);
        cout << "Flight " << flightID << " status updated to: " << newStatus << endl;
    } else {
        cout << "Flight " << flightID << " not found in schedule" << endl;
    }
}

Flight** Schedule::getFlightsByDestination(const string& destination, int& resultCount) const {
    resultCount=0;
    for (int i=0; i<currentcount; i++) {
        if (flights[i]->getDestination()==destination) {
            resultCount++;
        }
    }
    
    if (resultCount==0) {
        return nullptr;}
    
    Flight** result=new Flight*[resultCount];
    int index=0;
    for (int i=0; i<currentcount; i++) {
        if (flights[i]->getDestination() == destination) {
            result[index++]=flights[i];
        }
    }
    
    return result;
}

Flight** Schedule::getFlightsByStatus(const string& status, int& resultCount) const {
    resultCount=0;
    for (int i=0; i<currentcount; i++) {
        if (flights[i]->getStatus() == status) {
            resultCount++;
        }
    }
    
    if (resultCount==0) return nullptr;
    
    Flight** result=new Flight*[resultCount];
    int index=0;
    for (int i=0; i<currentcount; i++) {
        if (flights[i]->getStatus() == status) {
            result[index++] = flights[i];
        }
    }
    
    return result;
}

void Schedule::displayFullSchedule() const {
    cout << "\n FULL FLIGHT SCHEDULE" << endl;
    cout << "Total Flights: " << currentcount << "/" << maxFlights << endl;
    
    for (int i=0; i<currentcount; i++) {
        if (flights[i] != nullptr) {
            cout << "\nFlight " << flights[i]->getFlightID() << ": ";
            cout << flights[i]->getOrigin() << " → " << flights[i]->getDestination();
            cout << "Status: " << flights[i]->getStatus();
            cout << "Aircraft: " << flights[i]->getAircraft();
            cout << "Passengers: " << flights[i]->getPassengerCount();
        }
    }
}

void Schedule::displayFlightStatus(int flightID) const {
    Flight* flight=findFlight(flightID);
    if (flight) {
        flight->displayFlightInfo();
    } else {
        cout << "Flight " << flightID << " not found in schedule" << endl;
    }
}

int Schedule::getFlightCount() const {
    return currentcount;
}

bool Schedule::isFlightScheduled(int flightID) const {
    return findFlight(flightID) != nullptr;
}

void Schedule::clearSchedule() {
    for (int i=0; i<currentcount; i++) {
        flights[i]=nullptr;
    }
    currentcount=0;
    cout << "Schedule cleared" << endl;
}

Flight* Schedule::getFlight(int index) const {
    if (index>=0 && index<currentcount) {
        return flights[index];
    }
    return nullptr;
}