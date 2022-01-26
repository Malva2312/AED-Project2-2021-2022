//
// Created by asus on 18/12/2021.
//

#include "Coordinates.h"


using namespace std;

Coordinates::Coordinates(int latDegrees, int latMinutes, double latSeconds, int longDegrees, int longMinutes, double longSeconds) {
    this->latDegrees = latDegrees;
    this->latMinutes = latMinutes;
    this->latSeconds = latSeconds;
    this->longDegrees = longDegrees;
    this->longMinutes = longMinutes;
    this->longSeconds = longSeconds;
}

string Coordinates::toString() const {
    string res = to_string(abs(latDegrees));
    res.append("\xA7");
    res = res + to_string(latMinutes) + "'" + to_string(latSeconds).substr(0, to_string(latSeconds).find(".")+3) + "\"" + ((latDegrees < 0)? "S" : "N") + " " + to_string(abs(longDegrees));
    res.append("\xA7");
    res = res + to_string(longMinutes) + "'" + to_string(longSeconds).substr(0, to_string(longSeconds).find(".")+3) + "\"" + ((longDegrees < 0) ? "W" : "E");
    return res;
}

double Coordinates::convertDegreeAngleToDouble(double degrees, double minutes, double seconds) {
    return degrees + (minutes/60) + (seconds/3600);
}

long double Coordinates::toRadians(const long double degree) {
    long double one_deg = (M_PI) / 180;
    return (one_deg * degree);
}

int Coordinates::operator-(Coordinates coord) {
    long double lat1 = this->getLatitudeInRadians();
    long double long1 = this->getLongitudeInRadians();
    long double lat2 = coord.getLatitudeInRadians();
    long double long2 = coord.getLongitudeInRadians();

    // Haversine Formula
    long double dlong = long2 - long1;
    long double dlat = lat2 - lat1;

    long double ans = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlong / 2), 2);

    ans = 2 * asin(sqrt(ans));

    // Radius of Earth in
    // Kilometers, R = 6371
    long double R = 6371;

    ans = ans * R;
    return int(ans);
}

long double Coordinates::getLatitudeInRadians() {
    return toRadians(convertDegreeAngleToDouble(this->latDegrees, this->latMinutes, this->latSeconds));
}

long double Coordinates::getLongitudeInRadians() {
    return toRadians(convertDegreeAngleToDouble(this->longDegrees, this->longMinutes, this->longSeconds));
}

bool Coordinates::operator==(Coordinates coord) {
    if (this->latDegrees != coord.latDegrees) return false;
    if (this->latMinutes != coord.latMinutes) return false;
    if (this->latSeconds != coord.latSeconds) return false;
    if (this->longDegrees != coord.longDegrees) return false;
    if (this->longMinutes != coord.longMinutes) return false;
    if (this->longSeconds != coord.longSeconds) return false;
    return true;
}

int Coordinates::getLatDegrees() const {return this->latDegrees;}
int Coordinates::getLatMinutes() const {return this->latMinutes;}
double Coordinates::getLatSeconds() const {return this->latSeconds;}

int Coordinates::getLongDegrees() const {return this->longDegrees;}
int Coordinates::getLongMinutes() const {return this->longMinutes;}
double Coordinates::getLongSeconds() const {return this->longSeconds;}

void Coordinates::setLatDegrees(int value) {this->latDegrees = value;}
void Coordinates::setLatMinutes(int value) {this->latMinutes = value;}
void Coordinates::setLatSeconds(double value) {this->latSeconds = value;}

void Coordinates::setLongDegrees(int value) {this->longDegrees = value;}
void Coordinates::setLongMinutes(int value) {this->longMinutes = value;}
void Coordinates::setLongSeconds(double value) {this->longSeconds = value;}