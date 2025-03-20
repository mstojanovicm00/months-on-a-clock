//
// Created by mihajlo-stojanovic on 20.3.25..
//

#include "clock.h"
#include <stdio.h>

#include <stdlib.h>
#include <math.h>

clocked_month *create_clocked_month(month* m) {
    clocked_month *cm = (clocked_month*) malloc(sizeof(clocked_month));
    cm->m = m;
    cm->hour = cm->minute = cm->second = -1;
    cm->remainder = 0;
    return cm;
}

clocked_month *fill_clocked_month(clocked_month* cm, int h, int min, int s, double rem) {
    if (cm->hour < 0) {
        cm->hour = h;
        cm->minute = min;
        cm->second = s;
        if (rem >= 0)
            cm->remainder = rem;
        return cm;
    }
    return NULL;
}

void delete_clocked_month(clocked_month* cm) {
    delete_month(cm->m);
    free(cm);
}

static int days_in_a_year(clock c) {
    int days = 0;
    for (int i = 0; i < 12; ++i)
        days += c[i]->m->ndays;
    return days;
}

static double days_for_a_second(clock c) {
    int days = days_in_a_year(c);
    int hours = 24;
    int minutes = 60;
    int seconds = 60;
    return 1.0 * days / (hours * minutes * seconds);
}

void create_all(clock c, int february) {
    c[0] = create_clocked_month(create_month(1, "January", 31));
    c[1] = create_clocked_month(create_month(2, "February", february));
    c[2] = create_clocked_month(create_month(3, "March", 31));
    c[3] = create_clocked_month(create_month(4, "April", 30));
    c[4] = create_clocked_month(create_month(5, "May", 31));
    c[5] = create_clocked_month(create_month(6, "June", 30));
    c[6] = create_clocked_month(create_month(7, "July", 31));
    c[7] = create_clocked_month(create_month(8, "August", 31));
    c[8] = create_clocked_month(create_month(9, "September", 30));
    c[9] = create_clocked_month(create_month(10, "October", 31));
    c[10] = create_clocked_month(create_month(11, "November", 30));
    c[11] = create_clocked_month(create_month(12, "December", 31));
}

void fill_all(clock c) {
    double days_a_sec = days_for_a_second(c);
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    double remainder = 0;
    for (int i = 0; i < 12; ++i) {
        int days = c[i]->m->ndays;
        double _seconds = days / days_a_sec;
        int seconds_no_rem = (int) _seconds;
        int h = seconds_no_rem / (60 * 60);
        int min = (seconds_no_rem / 60) % 60;
        int s = seconds_no_rem % 60;
        double rem = _seconds - seconds_no_rem;
        c[i] = fill_clocked_month(c[i], hours, minutes, seconds, remainder);
        remainder += rem;
        if (remainder >= 1.0) {
            remainder -= 1;
            ++seconds;
        }
        seconds += s;
        if (seconds >= 60) {
            seconds -= 60;
            ++minutes;
        }
        minutes += min;
        if (minutes >= 60) {
            minutes -= 60;
            ++hours;
        }
        hours += h;
    }
}

void delete_all(clock c) {
    for (int i = 0; i < 12; ++i)
        delete_clocked_month(c[i]);
}
