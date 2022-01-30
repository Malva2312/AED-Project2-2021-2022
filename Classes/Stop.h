
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
    /**
     * Creates a default object of the class Stop
     */
    Stop();
    /**
     * Creates an object of the class Stop
     * @param name
     * @param code
     * @param zone
     * @param latitude
     * @param longitude
     */
    Stop(std::string name, std::string code, std::string zone, double latitude, double longitude);
    /**
     * Creates an object of the class Stop
     * @param name
     * @param code
     * @param zone
     * @param coord
     */
    Stop(std::string name, std::string code, std::string zone, Coordinates coord);

    /**
     * Reads all Stop's files and returns them in a vector
     * @param filepath
     * @return
     */
    std::vector<std::vector<std::string>> read_stops(std::string filepath) const;

    /**
     * Reads a Stop and puts its information in a vector
     * @param line
     * @return
     */
    std::vector<std::string> read_stop(std::string line) const;

    /**
     * Returns a Stop's name
     * @return
     */
    std::string getName();

    /**
     * Adds a new line
     * @param newLine_
     */
    void addLine(std::string newLine_);

    /**
     * Checks if two Stops are equal by comparing their code
     * @param A
     * @return
     */
    bool operator == (Stop A);

    /**
     * Sets the Stop's code
     * @param basicString
     */
    void setCode(std::string basicString);

    /**
     * Returns the Stop's code
     * @return
     */
    std::string getCode();

    /**
     * Returns the Stop's zone
     * @return
     */
    std::string getZone();

    /**
     * Returns the Stop's lines
     * @return
     */
    std::vector<std::string> getLines();

    /**
     * Returns the Stop's coordinates
     * @return
     */
    Coordinates getCoordinates() const;
};


#endif //TRABALHOAED2_STOP_H
