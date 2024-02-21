#include <stdio.h>

void generate_bit_strings(int *bits, int n, int pos);
int is_valid(int *bits, int n);

int main() {
    int n;
    printf("Enter length of bit string: ");
    scanf("%d", &n);

    int bits[n];
    generate_bit_strings(bits, n, 0);

    return 0;
}

void generate_bit_strings(int *bits, int n, int pos) {
    if (pos == n) {
    	int i;
        for (i = 0; i < n; i++) {
            printf("%d", bits[i]);
        }
        printf("\n");
        return;
    }
    bits[pos] = 0;
    generate_bit_strings(bits, n, pos+1);
    bits[pos] = 1;
    if (is_valid(bits, pos+1)) {
        generate_bit_strings(bits, n, pos+1);
    }
}

int is_valid(int *bits, int n) {
	int i;
    for (i = 1; i < n; i++) {
        if (bits[i] == 1 && bits[i-1] == 1) {
            return 0;
        }
    }
    return 1;
}

