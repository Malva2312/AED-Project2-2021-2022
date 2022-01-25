//
// Created by asus on 16/12/2021.
//

#ifndef PROJETO_TIME_H
#define PROJETO_TIME_H

#include <string>

class Time{
private:
    int min;
    int hour;
    int day;
    int month;
    int year;

public:
    /**
     * Creates an object of the class Time.
     * @param min
     * @param hour
     * @param day
     * @param month
     * @param year
     */
    Time(int min, int hour, int day, int month, int year);

    /**
     * Sets the minutes to a certain value.
     * @param min
     */
    void setMin(int min);
    /**
     * Sets the hours to a certain value.
     * @param hour
     */
    void setHour(int hour);
    /**
     * Sets the day to a certain value.
     * @param day
     */
    void setDay(int day);
    /**
     * Sets the month to a certain value.
     * @param month
     */
    void setMonth(int month);
    /**
     * Sets the year to a certain value.
     * @param year
     */
    void setYear(int year);

    /**
     * Returns the minutes of a given time.
     * @return
     */
    int getMin() const;
    /**
     * Returns the hours of a given time.
     * @return
     */
    int getHour() const;
    /**
     * Returns the day of a given time.
     * @return
     */
    int getDay() const;
    /**
     * Returns the month of a given time.
     * @return
     */
    int getMonth() const;
    /**
     * Returns the year of a given time.
     * @return
     */
    int getYear() const;


    //aux
    /**
     * Checks if a certain year is a leap year.
     * @param year
     * @return
     */
    bool isLeapYear(int year) const;

    /**
     * Sets the values given to the class constructor into a valid object.
     */
    void setToValid();
    /**
     * Checks if the created Time object is valid.
     * @return
     */
    bool isValid() const;

    /**
     * Returns the maximum days a specific month can have.
     * @param month
     * @param year
     * @return
     */
    int getMonthMaxDays(int month, int year) const;

    /**
     * Subtracts one Time object to another.
     * @param time1
     * @return
     */
    Time operator-(Time time1) const;
    /**
     * Adds one Time object to another.
     * @param time1
     * @return
     */
    Time operator+(Time time1) const;
    /**
     * Adds a certain amount of minutes to a Time object.
     * @param delta
     * @return
     */
    Time operator+(int delta);
    /**
    * Adds a certain amount of minutes to a Time object.
    * @param delta
    * @return
    */
    Time operator-(int delta);
    /**
     * Checks if one Time object is smaller than another.
     * @param time1
     * @return
     */
    bool operator<(Time time1);
    /**
     * Checks if one Time object is greater than another.
     * @param time1
     * @return
     */
    bool operator>(Time time1);

    /**
     * Checks if two Time objects are equal.
     * @param time1
     * @return
     */
    bool operator==(Time time1);

    /**
     * Transforms a Time object into a string.
     * @return
     */
    std::string toString() const;
};


#endif //PROJETO_TIME_H
