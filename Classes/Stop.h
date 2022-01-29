
#ifndef TRABALHOAED2_STOP_H
#define TRABALHOAED2_STOP_H


#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Coordinates.h"

class Stop {
private:
    std::string name, code, zone;
    Coordinates coord = Coordinates(0, 0);
    std::vector<std::string> line;
public:
    Stop();
    Stop(std::string name, std::string code, std::string zone, double latitude, double longitude);
    Stop(std::string name, std::string code, std::string zone, Coordinates coord);

    std::vector<std::vector<std::string>> read_stops(std::string filepath) const;
    std::vector<std::string> read_stop(std::string line) const;

    std::string getName();

    void addLine(std::string newLine_);

    bool operator == (Stop A);

    void setCode(std::string basicString);

    std::string getCode();

    std::string getZone();

    std::vector<std::string> getLines();

    Coordinates getCoordinates() const;
};


#endif //TRABALHOAED2_STOP_H
