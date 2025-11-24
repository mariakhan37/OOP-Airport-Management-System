#include "crew.h"
#include <iostream>

CrewTeam::CrewTeam(string id, string name) 
    : teamID(id), teamName(name), capacity(10), count(0) {
    crewMembers=new Employee*[capacity];
    for (int i=0; i<capacity; i++) {
        crewMembers[i] = nullptr;
    }
}

CrewTeam::~CrewTeam() {
    delete[] crewMembers;
}

void CrewTeam::addMember(Employee* employee) {
    if (count<capacity) {
        crewMembers[count]=employee;
        count++;
        cout << "Added " << employee->getName() << " to team " << teamName << endl;
    } else {
        cout << "Team " << teamName << " is full. Cannot add more members." << endl;
    }
}

void CrewTeam::removeMember(Employee* employee) {
    for (int i=0; i<count; i++) {
        if (crewMembers[i]==employee) {
            for (int j=i; j<count-1; j++) {
                crewMembers[j] =crewMembers[j+1];
            }
            crewMembers[count-1]=nullptr;
            count--;
            cout << "Removed " << employee->getName() << " from team " << teamName << endl;
            return;
        }
    }
    cout << "Employee " << employee->getName() << " not found in team " << teamName << endl;
}

void CrewTeam::displayTeam() const {
    cout << "\nCrew Team: " << teamName << " (" << teamID << ") " << endl;
    cout << "Members: " << count << "/" << capacity << endl;
    
    for (int i=0; i<count; i++) {
        if (crewMembers[i] != nullptr) {
            cout << i+1 << ". " << crewMembers[i]->getName() << endl;
        }
    }
    cout << "                 " << endl;
}

int CrewTeam::getMemberCount() const { 
    return count; 
}

string CrewTeam::getTeamID() const { 
    return teamID; 
}

string CrewTeam::getTeamName() const { 
    return teamName; 
}