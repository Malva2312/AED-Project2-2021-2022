//
// Created by Utilizador on 24/01/2022.
//

#ifndef MANAGER_H_STOP_H
#define MANAGER_H_STOP_H

#include <vector>
#include <fstream>
#include <sstream>

class Stop {
private:
    std::string code, name, zone;
    long latitude,longitude;

public:
    Stop();
    Stop(std::string name, std::string code, std::string zone, long latitude, long longitude);

    std::vector<std::vector<std::string>> read(std::string filepath) const;
    std::vector<std::string> read_stop(std::string line) const;

};


#endif //MANAGER_H_STOP_H
