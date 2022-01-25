//
// Created by Utilizador on 24/01/2022.
//

#ifndef TRABALHOAED2_STOP_H
#define TRABALHOAED2_STOP_H


#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class Stop {
private:
    std::string name, code, zone;
    long latitude, longitude;
public:
    Stop();
    Stop(std::string name, std::string code, std::string zone, long latitude, long longitude);

    std::vector<std::vector<std::string>> read(std::string filepath) const;
    std::vector<std::string> read_stop(std::string line) const;
};


#endif //TRABALHOAED2_STOP_H