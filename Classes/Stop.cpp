//
// Created by Utilizador on 24/01/2022.
//

#include "Stop.h"

using namespace std;

Stop::Stop() {
    this->name = "";
    this->code = "";
    this->zone = "";

    this->latitude = 0;
    this->longitude = 0;
}

Stop::Stop(string name, string code, string zone, double latitude, double longitude) {
    this->name = name;
    this->code = code;
    this->zone = zone;

    this->latitude = latitude;
    this->longitude = longitude;
}

vector<vector<string>> Stop::read(string filepath) const{
    ifstream file(filepath);

    if(!file.good()){return {};}

    vector<vector<string>> all_stops;
    string line;
    getline(file, line); //clean header
    while(getline(file, line)){
        all_stops.push_back(read_stop(line));
    }

    return all_stops;

}

vector<string> Stop::read_stop(string line) const{

    vector<string> data;
    stringstream ss(line);
    string word;

    while (getline(ss, word, ',')){
        data.push_back(word);
    }

    return data;
}

std::string Stop::getName() {
    return this->name;
}

