#include <stdio.h>

void duaraketqua(char* input);

int main() {
	char input[100];
	printf("Nhap vao string: ");
	scanf("%s", input);
	duaraketqua(input);
}

void duaraketqua(char* input) {
	int sochucai = 0;
	int sochuso = 0;
	int sokitu = 0;
	while (*input != '\0') {
		if (*input >= 'A' && *input <= 'Z' || *input >= 'a' && *input <= 'z') {
			sochucai++;
		} else {
			if (*input >= '0' && *input <= '9') {
			sochuso++;
			} else {
				sokitu++;
			}
		}
				input++;
	}
	printf("so chu cai la: %d \n", sochucai);
	printf("so chu so la: %d \n", sochuso);
	printf("so ki tu la: %d \n", sokitu);
}
