#ifndef MAIN_H
#define MAIN_H

#include "raylib.h"
#include <time.h>
#include <stdio.h>

// zaman verilerimizi tuttugumuz struct yapisi 
typedef struct DateTime
{
    long long int currentSecond;
    long long int currentMinute;
    long long int currentHour;
    long long int totalDays;
    long long int currentMonth;
    long long int currentYear;

} DateTime;

void updateTime(DateTime *dateTimePtr);

#endif