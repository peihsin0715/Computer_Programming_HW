//
//  main.c
//  week2_whatday
//
//  Created by 林沛忻 on 2023/8/4.
//

#include <stdio.h>

int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int days_in_month(int year, int month) {
    int days_per_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && is_leap_year(year))
        return 29;
    return days_per_month[month];
}

int day_of_week(int year, int first_day, int month, int day) {
    int days = 0;

    for (int m = 1; m < month; m++) {
        days += days_in_month(year, m);
    }

    days += day-1  ;

    return (days + first_day) % 7;
}


int main(void) {
    int year, first_day;
    scanf("%d %d", &year, &first_day);

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int month, day;
        scanf("\n%d %d", &month, &day);

        if (month < 1 || month > 12) {
            printf("-1 ");
        } else if (day < 1 || day > days_in_month(year, month)) {
            printf("-2 ");
        } else {
            int day_idx = day_of_week(year, first_day, month, day);
            printf("%d ", day_idx);
        }
    }

    return 0;
}
