//
// Created by asus on 18/12/2021.
//

#ifndef PROJETO_COORDINATES_H
#define PROJETO_COORDINATES_H


#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <iostream>

class Coordinates {
private:
    double latitude;
    double longitude;

public:
    /**
     * Creates an object of the class Coordinates.
     * @param latitude
     * @param longitude
     */
    Coordinates(double latitude_, double longitude_);

    /**
     * Puts the coordinates in string form.
     * @return
     */
    std::string toString(int precison = 10) const;

    /**
     * Subtraction between two Coordinates objects in meters.
     * @param coord
     * @return
     */
    double operator-(Coordinates coord);

    /**
     * Checks if two coordinates are equal.
     * @param coord
     * @return
     */
    bool operator==(Coordinates coord);

    /**
     * Returns the latitude.
     * @return
     */
    double getLatitude() const;

    /**
     * Returns the longitude.
     * @return
     */
    double getLongitude() const;

    bool operator!= (Coordinates coord);
};


#endif //PROJETO_COORDINATES_H
