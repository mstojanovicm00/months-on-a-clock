//
// Created by mihajlo-stojanovic on 20.3.25..
//

#ifndef MONTHS_ON_A_CLOCK_CLOCK_H
#define MONTHS_ON_A_CLOCK_CLOCK_H

#include "month.h"

typedef struct clocked_month {
    month *m;
    int hour, minute, second;
    double remainder;
} clocked_month;

clocked_month *create_clocked_month(month* m);
clocked_month *fill_clocked_month(clocked_month* cm, int h, int min, int s, double rem);
void delete_clocked_month(clocked_month* cm);

typedef clocked_month* clock[12];

void create_all(clock c, int february);
void fill_all(clock c);
void delete_all(clock c);

#endif //MONTHS_ON_A_CLOCK_CLOCK_H
