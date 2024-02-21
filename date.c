#include <stdio.h>
#include <string.h>

#define MAX_DATES 100

typedef struct {
    int year;
    int month;
    int day;
} Date;

int compareDates(Date date1, Date date2) {
    if (date1.year != date2.year) {
        return date1.year - date2.year;
    } else if (date1.month != date2.month) {
        return date1.month - date2.month;
    } else {
        return date1.day - date2.day;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Date dates[MAX_DATES];

    for (int i = 0; i < n; i++) {
        scanf("%d-%d-%d", &dates[i].year, &dates[i].month, &dates[i].day);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (compareDates(dates[i], dates[j]) > 0) {
                Date temp = dates[i];
                dates[i] = dates[j];
                dates[j] = temp;
            }
        }
    }

    int maxDuration = -1;
    int beginIndex = -1, endIndex = -1;

    for (int i = 0; i < n - 1; i++) {
        int duration = 0;
        for (int j = i + 1; j < n; j++) {
            int diff = (dates[j].year - dates[i].year) * 365 +
                       (dates[j].month - dates[i].month) * 30 +
                       (dates[j].day - dates[i].day);
            if (diff > duration) {
                duration = diff;
                beginIndex = i;
                endIndex = j;
            }
        }
    }

    if (beginIndex == -1 || endIndex == -1) {
        printf("NaN\n");
    } else {
        printf("%d-%02d-%02d\n", dates[beginIndex].year, dates[beginIndex].month, dates[beginIndex].day);
        printf("%d-%02d-%02d\n", dates[endIndex].year, dates[endIndex].month, dates[endIndex].day);
    }

    return 0;
}
