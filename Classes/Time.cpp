//
// Created by asus on 16/12/2021.
//

#include "Time.h"
#include <string>

using namespace std;

Time::Time(int min, int hour, int day, int month, int year){
    this->min = min;
    this->hour = hour;
    this->day = day;
    this->month = month;
    this->year = year;
}


void Time::setMin(int min) { this->min = min;}
void Time::setHour(int hour) { this->hour = hour;}
void Time::setDay(int day) { this->day = day;}
void Time::setMonth(int month) { this->month = month;}
void Time::setYear(int year) { this->year = year;}

int Time::getMin() const { return this->min; }
int Time::getHour() const { return this->hour; }
int Time::getDay() const { return this->day; }
int Time::getMonth() const { return this->month; }
int Time::getYear() const { return this->year; }

bool Time::isLeapYear(int year) const {
    if ( ( year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0 ) return true;
    return false;
}

bool Time::isValid() const{
    if ((month < 1) || (month > 12)) return false;
    if (day < 1 || day > getMonthMaxDays(this->month, this->year)) return false;
    if(hour < 0 || hour >= 24) return false;
    if(min < 0 || min >= 60) return false;
    return true;
}

void Time::setToValid() {
    while (min >= 60){min -= 60; hour++;}
    while (hour >= 24){hour -= 24; day++;}
    while (day > getMonthMaxDays(this->month, this->year)){
        day -= getMonthMaxDays(this->month, this->year);
        month++;
    }
    while (month >12){month -= 12; year++;}

    while (min < 0){min += 60; hour--;}
    while (hour < 0){hour += 24; day--;}
    while (day < 1){
        month--;
        day += getMonthMaxDays(this->month, this->year);
    }
    while (month < 1){month += 12; year--;}
}

int Time::getMonthMaxDays(int month, int year) const{
    switch (month) {
        case 1:
            return 31;
        case 2:
            return (isLeapYear(year)) ? 29 : 28;
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
        default:
            return 0;
    }
}

Time Time::operator-(Time time1) const{
    Time res(this->min - time1.getMin(),
             this->hour - time1.getHour(),
             this->day - time1.getDay(),
             this->month - time1.getMonth(),
             this->year - time1.getYear());
    res.setToValid();
    return res;
}

Time Time::operator+(Time time1) const{
    Time res(this->min + time1.getMin(),
             this->hour + time1.getHour(),
             this->day + time1.getDay(),
             this->month + time1.getMonth(),
             this->year + time1.getYear());
    res.setToValid();
    return res;
}

bool Time::operator<(Time time1) {
    setToValid(); time1.setToValid();

    if (this->year != time1.getYear()) return this->year < time1.getYear();

    if (this->month != time1.getMonth()) return this->month < time1.getMonth();

    if (this->day != time1.getDay()) return this->day < time1.getDay();

    if (this->hour != time1.getMonth()) return this->hour < time1.getHour();

    if (this->min != time1.getMin()) return this->min < time1.getMin();

    return false;
}

bool Time::operator>(Time time1){
    setToValid(); time1.setToValid();

    if (this->year != time1.getYear()) return this->year > time1.getYear();

    if (this->month != time1.getMonth()) return this->month > time1.getMonth();

    if (this->day != time1.getDay()) return this->day > time1.getDay();

    if (this->hour != time1.getMonth()) return this->hour > time1.getHour();

    if (this->min != time1.getMin()) return this->min > time1.getMin();

    return false;
}


string Time::toString() const{
    string hour = (to_string(this->hour).length() > 1) ? to_string(this->hour) : "0" + to_string(this->hour);
    string minute = (to_string(this->min).length() > 1) ? to_string(this->min) : "0" + to_string(this->min);
    return hour + ":" + minute + " " + to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}

Time Time::operator+(int delta) {
    int newMin = this->min;
    int newHour = this->hour;
    int newDay = this->day;
    int newMonth = this->month;
    int newYear = this->year;
    newMin += delta;
    if (newMin >= 60) {
        newHour += (newMin - (newMin % 60)) / 60;
        newMin = newMin % 60;
    }
    if (newHour >= 24) {
        newDay += (newHour - (newHour % 24)) / 24;
        newHour = newHour % 24;
    }
    int monthMax = getMonthMaxDays(newMonth, newYear);
    while (newMonth > monthMax) {
        monthMax = getMonthMaxDays(newMonth, newYear);
        newDay -= monthMax;
        newMonth += 1;
        if (newMonth > 12){
            newMonth = 1;
            newYear += 1;
        }
    }
    return Time(newMin, newHour, newDay, newMonth, newYear);
}

Time Time::operator-(int delta) {
    int newMin = this->min;
    int newHour = this->hour;
    int newDay = this->day;
    int newMonth = this->month;
    int newYear = this->year;

    while (delta > 0) {
        if (delta >= 60) {
            delta -= 60;
            if (newHour == 0) {
                newHour = 23;
                if (newDay == 1) {
                    if (newMonth == 1) {
                        newMonth = 12;
                        newYear -= 1;
                        newDay = getMonthMaxDays(newMonth, newYear);
                    } else {
                        newMonth -= 1;
                        newDay = getMonthMaxDays(newMonth, newYear);
                    }
                } else {
                    newDay -= 1;
                }
            } else {
                newHour -= 1;
            }
            continue;
        }
        else delta -= 1;
        if (newMin == 0) {
            newMin = 59;
            if (newHour == 0) {
                newHour = 23;
                if (newDay == 1) {
                    if (newMonth == 1) {
                        newMonth = 12;
                        newYear -= 1;
                        newDay = getMonthMaxDays(newMonth, newYear);
                    } else {
                        newMonth -= 1;
                        newDay = getMonthMaxDays(newMonth, newYear);
                    }
                } else {
                    newDay -= 1;
                }
            } else {
                newHour -= 1;
            }
        } else {
            newMin -= 1;
        }
    }
    return Time(newMin, newHour, newDay, newMonth, newYear);
}

bool Time::operator==(Time time1) {
    if (this->year != time1.getYear()) return false;

    if (this->month != time1.getMonth()) return false;

    if (this->day != time1.getDay()) return false;

    if (this->hour != time1.getMonth()) return false;

    if (this->min != time1.getMin()) return false;

    return true;
}
