#include <stdio.h>
#include <math.h>

void solve(int a, int b, int c) {
    double delta = b * b - 4 * a * c;
    
    if (delta < 0) {
        printf("NO SOLUTION\n");
    } else if (delta == 0) {
        double x = -b / (2.0 * a);
        printf("%.2lf\n", x);
    } else {
        double x1 = (-b + sqrt(delta)) / (2.0 * a);
        double x2 = (-b - sqrt(delta)) / (2.0 * a);
        printf("%.2lf %.2lf\n", x2, x1);
    }
}

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    solve(a, b, c);

    return 0;
}
