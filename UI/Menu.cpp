//
// Created by asus on 25/01/2022.
//

#include "Menu.h"
#include "../Classes/Stop.h"
#include "../Classes/Program.h"

//CRUD (Create, Read, Update, Delete)

bool Menu::inVector(char sel,  vector<char> options){
    for(auto opt: options){
        if (opt == sel) return true;
    }
    return false;
}

double Menu::readDoubleInput() {
    double res;
    cin >> res;
    cout << endl;
    return res;
}

Coordinates Menu::readCoordInput() {
    cout << "Latitude Degrees (integer): ";
    int newLatDegrees = readIntInput();
    cout << "Latitude Minutes (integer): ";
    int newLatMinutes = readIntInput();
    cout << "Latitude Seconds (integer):  ";
    double newLatSeconds = readDoubleInput();
    cout << "Longitude Degrees (integer): ";
    int newLongDegrees = readIntInput();
    cout << "Latitude Minutes (integer): ";
    int newLongMinutes = readIntInput();
    cout << "Latitude Seconds (integer):  ";
    double newLongSeconds = readDoubleInput();
    return Coordinates(newLatDegrees, newLatMinutes, newLatMinutes, newLongDegrees, newLongMinutes, newLongSeconds);
}

string Menu::readTextInput() {
    string res;
    getline(cin, res);
    cout << endl;
    return res;
}

int Menu::readIntInput() {
    int res;
    cin >> res;
    while(cin.fail()) {
        cout << "Error, not an integer." << std::endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> res;
    }
    cout << endl;
    return res;
}

Time Menu::readTimeInput() {
    Time newTime(0,0, 1, 0, 1);
    cout << endl << "Year: ";
    newTime.setYear(readIntInput());
    newTime.setMonth(-1);
    while(!newTime.isValid()){
        cout << "Month: ";
        newTime.setMonth(readIntInput());
    }
    newTime.setDay(-1);
    while(!newTime.isValid()){
        cout << "Day: ";
        newTime.setDay(readIntInput());
    }
    newTime.setHour(-1);
    while(!newTime.isValid()){
        cout << "Hour: ";
        newTime.setHour(readIntInput());
    }
    newTime.setMin(-1);
    while(!newTime.isValid()){
        cout << "Minute: ";
        newTime.setMin(readIntInput());
    }
    return newTime;
}

Time Menu::readDateInput() {
    Time newTime(0,10, 1, 0, 1);
    cout << endl << "Year: ";
    newTime.setYear(readIntInput());
    newTime.setMonth(-1);
    while(!newTime.isValid()){
        cout << "Month: ";
        newTime.setMonth(readIntInput());
    }
    newTime.setDay(-1);
    while(!newTime.isValid()){
        cout << "Day: ";
        newTime.setDay(readIntInput());
    }
    return newTime;
}

char Menu::readOptionInput(const vector<char>& options) {
    char sel = -1;
    while (!inVector(sel, options)) {
        bool validInput = true;
        do
        {
            validInput = true;
            cin >> sel;
            if (cin.fail())
            {
                validInput = false;
                if (cin.eof()) {
                    exit(EXIT_SUCCESS);
                }
                else
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
            else
                cin.ignore(10000, '\n');
        } while (!validInput);
    };
    return sel;
}

Menu::Menu(Program *program_) {
    this->program = program_;
}


void Menu::askForLocation() {
    cout << "Please insert your coordinates." << endl;
    Coordinates location = readCoordInput();
    this->program->setUserLocation(location);
}

void Menu::programMenu() {
    askForLocation();
    bool running = true;
    while(running) {
        cout << endl;
        cout << "   SCTP   " << endl;
        cout << endl;
        cout << "[1] Travel" << endl;
        cout << "[2] See Map" << endl;
        cout << "[3] Stops Nearby" << endl;
        cout << "[4] Update Location" << endl;
        cout << "[0] Exit Program" << endl;
        vector<char> opts = {'1', '2', '3', '4', '0'};
        char sel = readOptionInput(opts);
        switch (sel) {
            case '1':
                //if (!Menu())
                    //running = false;
                break;
            case '2':
                //map();
                break;
            case '3':
                stopsNearLocation();
                break;
            case '4':
                askForLocation();
                break;
            case '0':
                running = false;
                break;
        }
    }
}

// TODO: This
void Menu::stopsNearLocation() {
    vector<Stop> list;
    cout << "AYO";
    //TODO: Calculate every stop distance to user and put them in order to this list.
    int order = 0;
    while(true) {
        cout << endl << endl << "   NEARBY STOPS   " << endl << endl;
        vector<char> opts;
        int max = list.size();
        for (int i = 0;  i < max; i++) {
            cout << "[" << i << "] " << list[order + i].getName() << endl;
            opts.push_back(48 + i);
        }
        if (list.size() > 10) cout << endl << "<" << to_string(order / 10) << "/" << to_string(list.size() / 10) << ">" << endl << endl;
        if (order != 0){
            opts.push_back('B');
            opts.push_back('b');
            cout << "B - Previous page " << endl;
        }
        if (list.size() - order > 10){
            opts.push_back('N');
            opts.push_back('n');
            cout << "N - Next page " << endl;
        }
        cout << "Press the number to select a stop." << endl;
        opts.push_back('X');
        opts.push_back('x');
        cout << "X - Back to Menu" << endl;

        char sel = readOptionInput(opts);
        if (sel > 47 && sel < 58){
            while (true) {
                cout << endl << "[0] Travel To " << list[order + (sel-48)].getName()<< endl;
                cout << "[1] Travel From " << list[order + (sel-48)].getName() << endl;
                cout << "[X] Back to Modify List" << endl;
                cout << endl << "Select what you would like to modify";
                char sel2 = readOptionInput({'0', '1', 'X', 'x'});
                if (sel2 == '0') {
                    cout << "Work in progress" << endl;
                } else if (sel2 == '1') {
                    cout << "Work in progress" << endl;
                } else if (sel2 == 'X' || sel2 == 'x') break;
            }
        }
        if (sel == 'x' || sel == 'X') {
            return;
        }
        else if (sel == 'b' || sel == 'B') {
            order -= 10;
        }
        else if (sel == 'n' || sel == 'N') {
            order += 10;
        }
    };
}

