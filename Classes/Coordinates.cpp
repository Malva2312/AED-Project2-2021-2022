//
// Created by asus on 18/12/2021.
//

#include <iomanip>
#include <sstream>
#include <iostream>
#include "Coordinates.h"


using namespace std;

Coordinates::Coordinates(double latitude_, double longitude_) {
    this->latitude = latitude_;
    this->longitude = longitude_;
}

string Coordinates::toString(int precision) const {
    ostringstream resLat;
    resLat << fixed;
    resLat << setprecision(precision);
    resLat << latitude;
    ostringstream resLong;
    resLat << fixed;
    resLat << setprecision(10);
    resLat << longitude;
    return resLat.str() + ", " + resLong.str();
}

double Coordinates::operator-(Coordinates coord) {
    double lat1 = this->getLatitude();
    double long1 = this->getLongitude();
    double lat2 = coord.getLatitude();
    double long2 = coord.getLongitude();

    // Haversine Formula
    /*
    double dlong = long2 - long1;
    double dlat = lat2 - lat1;

    double ans = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlong / 2), 2);

    ans = 2 * asin(sqrt(ans));

    // Radius of Earth in
    // Kilometers, R = 6371
    double R = 6371;

    ans = ans * R;
    return int(ans);*/
    double dLat = (lat2 - lat1) *
                  M_PI / 180.0;
    double dLon = (long2 - long1) *
                  M_PI / 180.0;

    // convert to radians
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    // apply formulae
    double a = pow(sin(dLat / 2), 2) +
               pow(sin(dLon / 2), 2) *
               cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return (rad * c) * 1000;
}

bool Coordinates::operator==(Coordinates coord) {
    if (this->latitude != coord.getLatitude()) return false;
    if (this->longitude != coord.getLongitude()) return false;
    return true;
}


double Coordinates::getLatitude() const {return this->latitude;}

double Coordinates::getLongitude() const {return this->longitude;}

bool Coordinates::operator!=(Coordinates coord) {
    return !(*this == coord);
}
