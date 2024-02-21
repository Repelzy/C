#include <stdio.h>
#include <string.h>

#define MAX_MINTERMS 16
#define MAX_VARIABLES 4

typedef struct {
    int mintermValue;
    int isChecked;
} Minterm;

typedef struct {
    int numberOfOnes;
    char minterm[MAX_VARIABLES + 1];
} PrimeImplicant;

void getInput(Minterm minterms[], int *numberOfMinterms);
void simplifyBooleanFunction(Minterm minterms[], int numberOfMinterms);

int main() {
    Minterm minterms[MAX_MINTERMS];
    int numberOfMinterms;

    getInput(minterms, &numberOfMinterms);
    simplifyBooleanFunction(minterms, numberOfMinterms);

    return 0;
}

void getInput(Minterm minterms[], int *numberOfMinterms) {
    printf("Enter the number of minterms: ");
    scanf("%d", numberOfMinterms);

    printf("Enter the minterms (separated by spaces): ");
    for (int i = 0; i < *numberOfMinterms; i++) {
        scanf("%d", &minterms[i].mintermValue);
        minterms[i].isChecked = 0;
    }
}

void simplifyBooleanFunction(Minterm minterms[], int numberOfMinterms) {
    printf("Simplified function: ");

    for (int i = 0; i < numberOfMinterms; i++) {
        int mintermValue = minterms[i].mintermValue;
        char binaryRepresentation[MAX_VARIABLES + 1];
        for (int j = MAX_VARIABLES - 1; j >= 0; j--) {
            binaryRepresentation[MAX_VARIABLES - 1 - j] = (mintermValue & (1 << j)) ? '1' : '0';
        }
        binaryRepresentation[MAX_VARIABLES] = '\0';

        for (int j = 0; j < MAX_VARIABLES; j++) {
            if (binaryRepresentation[j] == '1') {
                printf("%c", 'A' + j);
            } else if (binaryRepresentation[j] == '0') {
                printf("%c'", 'A' + j);
            }
        }

        if (i != numberOfMinterms - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}
