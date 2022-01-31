

#include "Stop.h"

using namespace std;

Stop::Stop() {
    this->name = "";
    this->code = "";
    this->zone = "";

    this->coord = Coordinates(0, 0);
}

Stop::Stop(string name, string code, string zone, double latitude, double longitude) {
    this->name = name;
    this->code = code;
    this->zone = zone;

    this->coord = Coordinates(latitude, longitude);
}

Stop::Stop(string name, string code, string zone, Coordinates coord){
    this->name = name;
    this->code = code;
    this->zone = zone;

    this->coord = coord;
}

vector<vector<string>> Stop::read_stops(string filepath) const{

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
    //Code,Name,Zone,Latitude,Longitude
    //Reads this: 1AL2,AV.ALIADOS,PRT1,41.14954216,-8.610023615
    vector<string> data;
    stringstream ss(line);
    string word;

    while (getline(ss, word, ',')){
        data.push_back(word);
    }
    return data;
}

std::string Stop::getName() {
    return name;
}

bool Stop::operator==(Stop A) {
    return code == A.code;
}

bool Stop::operator!=(Stop A) {
    return code != A.code;
}

void Stop::addLine(std::string newLine_){
    for (auto existentLine : line)
        if (existentLine == newLine_)
            return;
    this->line.push_back(newLine_);
}

void Stop::setCode(std::string newCode_) {
    this->code = newCode_;
}

Coordinates Stop::getCoordinates() const {
    return this->coord;
}

std::string Stop::getCode() {
    return this->code;
}

std::string Stop::getZone() {
    return this->zone;
}

std::vector<std::string>Stop:: getLines() {
    return this->line;
}
