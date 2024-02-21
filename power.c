#include <stdio.h>

double power(double x, int n);

int main(){
 	double x;
    int n;
    scanf("%lf", &x);
    scanf("%d", &n);

    double result = power(x, n);

    printf("%.2lf^%d = %.2lf\n", x, n, result);

    return 0;
}

double power(double x, int n) {
    if (n == 0) {
        return 1;
    }

    if (n < 0) {
        x = 1 / x;
        n = -n;
    }

    double result = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            result *= x;
            n--; // decrement n by 1 when it is odd
        } else {
            x *= x;
            n /= 2;
        }
    }

    return result;
}
