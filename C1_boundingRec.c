#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int min_x = 1e9;
    int min_y = 1e9;
    int max_x = 0;
    int max_y = 0;

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        min_x = (x1 < x2) ? (min_x < x1 ? min_x : x1) : (min_x < x2 ? min_x : x2);
        min_y = (y1 < y2) ? (min_y < y1 ? min_y : y1) : (min_y < y2 ? min_y : y2);
        max_x = (x1 > x2) ? (max_x > x1 ? max_x : x1) : (max_x > x2 ? max_x : x2);
        max_y = (y1 > y2) ? (max_y > y1 ? max_y : y1) : (max_y > y2 ? max_y : y2);
    }

    int width = max_x - min_x;
    int height = max_y - min_y;
    int min_area = width * height;

    printf("%d\n", min_area);

    return 0;
}
