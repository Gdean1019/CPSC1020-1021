
#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <string>
#include "Date.h"
using namespace std;


Date::Date(){ //default constructor
    mth = 1;
    dy = 1;
    year = 2021;
}

Date::Date(int d, int m, int y){
    setMonth(m);
    setDay(d);
    setYear(y);
    if(!(setMonth(m))){
        mth = 1;
        dy = 1;
        year = 2021;
    }
    if(!(setDay(d))){
        mth = 1;
        dy = 1;
        year = 2021;
    }
    if(!(setYear(y))){
        mth = 1;
        dy = 1;
        year = 2021;
    }
}

//Setter Functions
bool Date::setDay(int d){
    if((d <= 0) || (d >= 32)){
        return false;
    }
    else if(mth == 2 && d >= 28){
        return false;
    }
    else{
        dy = d;
        return true;
    }
}

bool Date::setMonth(int m){
    if((m <= 0) || (m >= 13)){
        return false;
    }
    else{
        mth = m;
        return true;
    }
}

bool Date::setYear(int y){
    if((y <= 2020) || (y >= 2023)){
        return false;
    }
    else{
        year = y;
        return true;
    }
}

//Getter Functions
int Date::getDay(){
    return dy;
}

int Date::getMonth(){
    return mth;
}


int Date::getYear(){
    return year;
}

string Date::showDate(){ //for showing result date
    string userDate;
    cout << std::setw(2) << std::setfill('0') << mth
        << "/" << std::setw(2) << std::setfill('0') << dy << "/" << year << endl;
    return userDate;
}