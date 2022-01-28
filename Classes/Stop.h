
#ifndef TRABALHOAED2_STOP_H
#define TRABALHOAED2_STOP_H


#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class Stop {
private:
    std::string name, code, zone;
    double latitude, longitude;
public:
    Stop();
    Stop(std::string name, std::string code, std::string zone, double latitude, double longitude);

    std::vector<std::vector<std::string>> read_stops(std::string filepath) const;
    std::vector<std::string> read_stop(std::string line) const;

    std::string getName();
};


#endif //TRABALHOAED2_STOP_H
