//
// Created by mihajlo-stojanovic on 20.3.25..
//

#include "month.h"

#include <stdlib.h>
#include <string.h>

month *create_month(int ordinal, char* name, int ndays) {
    month *m = (month*) malloc(sizeof(month));
    m->month_ordinal = ordinal;
    strcpy(m->month_name, name);
    m->ndays = ndays;
    return m;
}

void delete_month(month* m) {
    free(m);
}