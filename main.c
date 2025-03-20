#include <stdio.h>

#include "clock.h"

void clock_it(int february) {
    printf("February has %d days\n", february);
    clock c;
    create_all(c, february);
    fill_all(c);
    for (int i = 0; i < 12; ++i) {
        printf("%s begins at %d:%d:%d.%lf\n", c[i]->m->month_name,
               c[i]->hour, c[i]->minute, c[i]->second, c[i]->remainder);
    }
    printf("\n");
    delete_all(c);
}

int main() {
    clock_it(28);
    clock_it(29);
    return 0;
}
