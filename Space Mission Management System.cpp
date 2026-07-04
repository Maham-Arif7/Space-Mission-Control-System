#include <iostream>
#include<string>
using namespace std;

// Base class representing a spacecraft
class Spacecraft {
protected:
    string name;
    double fuelLevel;  // Fuel percentage (0-100)
    double speed;      // Speed in km/h
    string missionType;

public:
    Spacecraft(string n, double f, double s, string m) 
        : name(n), fuelLevel(f), speed(s), missionType(m) {}

    // Virtual function for launching the spacecraft
    virtual void launch() {
        cout << name << " is launching for a " << missionType << " mission."<<endl;
    }

    // Virtual function for controlling the spacecraft with fuel consumption
    virtual void control() {
        if (fuelLevel > 0) {
            fuelLevel -= 5;  // Reduce fuel by 5% per operation
            speed -= (speed * 0.05);  // Slow down due to fuel loss
            cout << name << " is in operation at speed: " << speed << " km/h. Remaining fuel: " << fuelLevel << "%"<<endl;
        } else {
            cout << name << " has run out of fuel! Emergency shutdown initiated."<<endl;
        }
    }

    // Displays spacecraft details
    void displayInfo() {
        cout << "\nSpacecraft Name: " << name 
             << "\nFuel Level: " << fuelLevel << "%"
             << "\nSpeed: " << speed << " km/h"
             << "\nMission Type: " << missionType << endl;
    }
};

// Satellite class inheriting from Spacecraft
class Satellite : public Spacecraft {
public:
    Satellite(string n, double f, double s) 
        : Spacecraft(n, f, s, "Earth Observation") {}

    void launch() override {
        cout << name << " is being placed into orbit."<<endl;
    }
};

// Rover class inheriting from Spacecraft
class Rover : public Spacecraft {
public:
    Rover(string n, double f, double s) 
        : Spacecraft(n, f, s, "Planetary Exploration") {}

    void launch() override {
        cout << name << " is landing on the planetary surface."<<endl;
    }
};

// Manned mission class inheriting from Spacecraft
class MannedMission : public Spacecraft {
private:
    int astronauts;

public:
    MannedMission(string n, double f, double s, int a) 
        : Spacecraft(n, f, s, "Human Spaceflight"), astronauts(a) {}

    void launch() override {
        cout << name << " is lifting off with " << astronauts << " astronauts onboard."<<endl;
    }

    void displayCrew() {
        cout << "Crew Members: " << astronauts << endl;
    }
};

// Mission Control Class
class MissionControl {
private:
    static const int MAX_SPACECRAFTS = 3;   // can be enhanced to more than 3 spacecrafts 
    Spacecraft* spacecrafts[MAX_SPACECRAFTS];  // Array for number of spacecrafts  

public:
    void addSpacecraft(Spacecraft* sc, int index) {
        if (index < MAX_SPACECRAFTS) {
            spacecrafts[index] = sc;
        }
    }

    void launchAll() {
        cout << "\nInitiating Launch Sequence:"<<endl;
        for (int i = 0; i < MAX_SPACECRAFTS; i++) {
            spacecrafts[i]->launch();
        }
    }

    void controlAll() {
        cout << "\nMission Control Active:\n";
        for (int i = 0; i < MAX_SPACECRAFTS; i++) {
            spacecrafts[i]->control();
        }
    }

    void displayAll() {
        cout << "\nCurrent Spacecraft Status:\n";
        for (int i = 0; i < MAX_SPACECRAFTS; i++) {
            spacecrafts[i]->displayInfo();
            cout << "---------------------------\n";
        }
    }
};

// Main function 
int main() {
    MissionControl controlCenter;

    for (int i = 0; i < 3; i++) {
        string name, type;
        double fuel, speed;
        int astronauts = 0;

        cout << "\nEnter details for spacecraft " << i+1 << ":"<<endl;
        cout << "Name: ";
        cin >> name;
        cout << "Fuel Level (%): ";
        cin >> fuel;
        cout << "Speed (km/h): ";
        cin >> speed;
        cout << "Type (Satellite/Rover/MannedMission): ";
        cin >> type;

        if (type == "Satellite") {
            controlCenter.addSpacecraft(new Satellite(name, fuel, speed), i);
        } else if (type == "Rover") {
            controlCenter.addSpacecraft(new Rover(name, fuel, speed), i);
        } else if (type == "MannedMission") {
            cout << "Number of astronauts onboard: ";
            cin >> astronauts;
            controlCenter.addSpacecraft(new MannedMission(name, fuel, speed, astronauts), i);
        } else {
            cout << "Invalid spacecraft type. Please restart and enter correct details."<<endl;
            return 1;
        }
    }

    // Mission Control Operations
    controlCenter.displayAll();
    controlCenter.launchAll();
    controlCenter.controlAll();

    return 0;
}