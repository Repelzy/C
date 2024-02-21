#include <stdio.h>

int main() {
    float uvIndex;
    scanf("%f", &uvIndex);
    if (uvIndex < 3.0) {
        printf("muc thap\n");
    } else if (uvIndex < 6.0) {
        printf("muc trung binh\n");
    } else if (uvIndex < 8.0) {
        printf("muc cao\n");
    } else if (uvIndex <= 11.0) {
        printf("muc rat cao\n");
    } else {
        printf("muc nguy hiem\n");
    }

    return 0;
}
