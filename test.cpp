#include "airport.h"
#include <iostream>
#include <string>
using namespace std;

void displayMenu() {
    cout << "\nAirport Management System: " << endl;
    cout << "1. Add Flight" << endl;
    cout << "2. Display All Flights" << endl;
    cout << "3. Update Flight Status" << endl;
    cout << "4. Add Employee" << endl;
    cout << "5. Create Crew Team" << endl;
    cout << "6. Assign Crew to Flight" << endl;
    cout << "7. Add Passenger to Flight" << endl;
    cout << "8. Display Airport Summary" << endl;
    cout << "9. Display All Employees" << endl;
    cout << "10. Display All Crew Teams" << endl;
    cout << "0. Exit" << endl;
    cout << "Choose an option: ";
}

int main() {
    Airport airport("Karachi Airport", "Karachi", 4);
    int choice;
    
    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); 
        
        switch(choice) {
            case 1: {
                int flightID;
                string origin, destination, aircraft;
                
                cout << "Enter Flight ID: ";
                cin >> flightID;
                cin.ignore();
                
                cout << "Enter Origin: ";
                getline(cin, origin);
                
                cout << "Enter Destination: ";
                getline(cin, destination);
                
                cout << "Enter Aircraft Type: ";
                getline(cin, aircraft);
                
                airport.AddFlight(flightID, origin, destination, aircraft);
                break;
            }
            
            case 2: {
                cout << "\nALL FLIGHTS: " << endl;
                for (int i = 0; i < airport.getFlightCount(); i++) {
                    Flight* flight = airport.getFlight(i);
                    if (flight) {
                        flight->displayFlightInfo();
                    }
                }
                break;
            }
            
            case 3: {
                int flightID;
                string status;
                
                cout << "Enter Flight ID to update: ";
                cin >> flightID;
                cin.ignore();
                
                cout << "Enter new status (Scheduled/Boarding/Departed/Cancelled): ";
                getline(cin, status);
                
                airport.updateFlightStatus(flightID, status);
                break;
            }
            
            case 4: {
                string name, id, email, phone, empID, position;
                double salary;
                
                cout << "Enter Employee Name: ";
                getline(cin, name);
                
                cout << "Enter Employee ID: ";
                getline(cin, id);
                
                cout << "Enter Email: ";
                getline(cin, email);
                
                cout << "Enter Phone: ";
                getline(cin, phone);
                
                cout << "Enter Employee Number: ";
                getline(cin, empID);
                
                cout << "Enter Salary: ";
                cin >> salary;
                cin.ignore();
                
                cout << "Enter Position: ";
                getline(cin, position);
                
                Employee* emp=new Employee(name, id, email, phone, empID, salary, position);
                airport.assignEmployee(emp);
                break;
            }
            
            case 5: {
                string teamID, teamName;
                
                cout << "Enter Crew Team ID: ";
                getline(cin, teamID);
                
                cout << "Enter Crew Team Name: ";
                getline(cin, teamName);
                
                airport.createCrewTeam(teamID, teamName);
                break;
            }
            
            case 6: {
                int flightID;
                string teamID;
                
                cout << "Enter Flight ID: ";
                cin >> flightID;
                cin.ignore();
                
                cout << "Enter Crew Team ID: ";
                getline(cin, teamID);
                
                CrewTeam* crew=airport.findCrewTeam(teamID);
                if (crew) {
                    airport.AssignCrewToFlight(flightID, crew);
                } else {
                    cout << "Crew team not found!" << endl;
                }
                break;
            }
            
            case 7: {
                int flightID;
                string name, id, email, phone, passport, nationality, dob;
                
                cout << "Enter Flight ID: ";
                cin >> flightID;
                cin.ignore();
                
                cout << "Enter Passenger Name: ";
                getline(cin, name);
                
                cout << "Enter Passenger ID: ";
                getline(cin, id);
                
                cout << "Enter Email: ";
                getline(cin, email);
                
                cout << "Enter Phone: ";
                getline(cin, phone);
                
                cout << "Enter Passport Number: ";
                getline(cin, passport);
                
                cout << "Enter Nationality: ";
                getline(cin, nationality);
                
                cout << "Enter Date of Birth: ";
                getline(cin, dob);
                
                Passenger* passenger=new Passenger(name, id, email, phone, passport, nationality, dob);
                airport.addPassengerToFlight(flightID, passenger);
                break;
            }
            
            case 8:
                airport.displaySummary();
                break;
                
            case 9:
                airport.displayAllEmployees();
                break;
                
            case 10:
                airport.displayAllCrewTeams();
                break;
                
            case 0:
                cout << "Bye" << endl;
                break;
                
            default:
                cout << "Invalid option. Try again." << endl;
        }
        
    } while (choice!=0);
    
    return 0;
}