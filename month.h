//
// Created by mihajlo-stojanovic on 20.3.25..
//

#ifndef MONTHS_ON_A_CLOCK_MONTH_H
#define MONTHS_ON_A_CLOCK_MONTH_H

typedef struct month {
    int month_ordinal;
    char month_name[20];
    int ndays;
} month;

month *create_month(int ordinal, char* name, int ndays);
void delete_month(month* m);

#endif //MONTHS_ON_A_CLOCK_MONTH_H
