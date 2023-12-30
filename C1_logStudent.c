#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000

typedef struct {
    char date[11];
    int count;
} Info;


int compare(const void *a, const void *b) {
    return strcmp(((Info *)a)->date, ((Info *)b)->date);
}

int binary_search(Info *info, int n, char *date) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        int tmp = strncmp(info[m].date, date, 10);
        if (tmp == 0) {
            return m;
        } else if (tmp < 0) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1; 
}

void insert(Info *info, int n, char *date) {
    int i = n - 1;
    while (i >= 0 && strncmp(info[i].date, date, 10) > 0) {
        info[i + 1] = info[i];
        i--;
    }
    i++;
    strncpy(info[i].date, date, 10);
    info[i].date[10] = '\0';
    info[i].count = 1;
}

int main() {
    freopen("data.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    clock_t start_time = clock();
    char cmd[50];
    Info info[MAX];
    int n = 0;

    while (fgets(cmd, sizeof(cmd), stdin)) {
        if (cmd[0] == '*')
            break;
        int idx = binary_search(info, n, cmd);
        if(idx != -1){
            info[idx].count ++;
        }
        else{
            insert(info, n, cmd);
            n++;
        }
    }

    clock_t end_time = clock();
    double execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    for (int i = 0; i < n; i++) {
        printf("%s %d\n", info[i].date, info[i].count);
    }

    printf("Execution Time: %f seconds\n", execution_time);

    return 0;
}
