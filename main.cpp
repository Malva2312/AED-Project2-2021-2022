#include <iostream>


#include "Classes/Stop.h"

class Stop;
using namespace std;

int main(){
    vector<vector<string>> test = Stop().read("../dataset/stops.csv");

    for (auto it = test.begin(); it != test.end(); it++){
        for (auto ii = it->begin(); ii!= it->end(); ii++){
            cout << (*ii) << " , ";
        }
        cout << endl;
    }

}