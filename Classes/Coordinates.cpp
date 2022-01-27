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

string Coordinates::toString() const {
    ostringstream resLat;
    resLat << fixed;
    resLat << setprecision(10);
    resLat << latitude;
    ostringstream resLong;
    resLat << fixed;
    resLat << setprecision(10);
    resLat << latitude;
    return resLat.str() + " " + resLong.str();
}

int Coordinates::operator-(Coordinates coord) {
    long double lat1 = this->getLatitude();
    long double long1 = this->getLongitude();
    long double lat2 = coord.getLatitude();
    long double long2 = coord.getLongitude();

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

bool Coordinates::operator==(Coordinates coord) {
    if (this->latitude != coord.getLatitude()) return false;
    if (this->longitude != coord.getLongitude()) return false;
    return true;
}


double Coordinates::getLatitude() const {return this->latitude;}

double Coordinates::getLongitude() const {return this->longitude;}