//
// Created by asus on 18/12/2021.
//

#ifndef PROJETO_COORDINATES_H
#define PROJETO_COORDINATES_H


#include <string>

class Coordinates {
private:
    int latDegrees;
    int latMinutes;
    double latSeconds;
    int longDegrees;
    int longMinutes;
    double longSeconds;

public:
    /**
     * Creates an object of the class Coordinates.
     * @param latDegrees
     * @param latMinutes
     * @param latSeconds
     * @param longDegrees
     * @param longMinutes
     * @param longSeconds
     */
    Coordinates(int latDegrees, int latMinutes, double latSeconds, int longDegrees, int longMinutes, double longSeconds);

    /**
     * Puts the coordinates in string form.
     * @return
     */
    std::string toString() const;

    /**
     * Tranforms the coordinates's degree angle to double form.
     * @param degrees
     * @param minutes
     * @param seconds
     * @return
     */
    double convertDegreeAngleToDouble( double degrees, double minutes, double seconds);

    /**
     * Converts degrees to radians.
     * @param degree
     * @return
     */
    long double toRadians(const long double degree);

    /**
     * Returns the latitude in radians.
     * @return
     */
    long double getLatitudeInRadians();

    /**
     * Returns the longitude in radians.
     * @return
     */
    long double getLongitudeInRadians();

    /**
     * Subtraction between two Coordinates objects.
     * @param coord
     * @return
     */
    int operator-(Coordinates coord);

    /**
     * Checks if two coordinates are equal.
     * @param coord
     * @return
     */
    bool operator==(Coordinates coord);

    //////////////////////
    /**
     * Returns latitude degrees.
     * @return
     */
    int getLatDegrees() const;
    /**
     * Returns latitude minutes.
     * @return
     */
    int getLatMinutes() const;
    /**
     * Returns latitude seconds.
     * @return
     */
    double getLatSeconds() const;

    /**
     * Returns longitude degrees.
     * @return
     */
    int getLongDegrees() const;
    /**
     * Returns longitude minutes.
     * @return
     */
    int getLongMinutes() const;
    /**
     * Returns longitude seconds.
     * @return
     */
    double getLongSeconds() const;

    /**
     * Sets the latitude degrees to a certain value.
     * @param value
     */
    void setLatDegrees(int value);
    /**
     * Sets the latitude minutes to a certain value.
     * @param value
     */
    void setLatMinutes(int value);
    /**
     * Sets the latitude seconds to a certain value.
     * @param value
     */
    void setLatSeconds(double value);

    /**
     * Sets the longitude degrees to a certain value.
     * @param value
     */
    void setLongDegrees(int value);
    /**
     * Sets the longitude minutes to a certain value.
     * @param value
     */
    void setLongMinutes(int value);
    /**
     * Sets the longitude seconds to a certain value.
     * @param value
     */
    void setLongSeconds(double value);
};


#endif //PROJETO_COORDINATES_H
