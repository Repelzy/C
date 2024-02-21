#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    char myDel[21];
    float L, W, H;
    float weight;
    int type;
} Deli;

void clear_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

bool valid_id(char *DeliveryCode);

void input(Deli delis[], int *numDeli) {
    // Nhap so kien hang
    do {
        printf("Nhap so kien hang: ");
        scanf("%d", numDeli);
        clear_buffer();
        if (*numDeli < 1 || *numDeli > 100) {
            printf("Nhap lai: \n");
        }
    } while (*numDeli < 1 || *numDeli > 100);

    // vong lap de in ra kien hang thu i+1 va thong tin
    for (int i = 0; i < *numDeli; i++) {
        printf("Kien hang thu: %d\n", i + 1);
        bool valid;
        do {
            printf("Nhap ma don hang(8 toi 20 ki tu): ");
            scanf("%s", delis[i].myDel);
            clear_buffer();
            valid = valid_id(delis[i].myDel);
            // Kiem tra tinh hop le cua ma
            if (!valid) {
                printf("Nhap lai.\n");
            }
        } while (!valid);

        printf("Nhap L W H(cm): ");
        scanf("%f %f %f", &delis[i].L, &delis[i].W, &delis[i].H);
        clear_buffer();

        printf("Nhap trong luong tinh: ");
        scanf("%f", &delis[i].weight);
        clear_buffer();

        // Nhap loai van chuyen
        int type;
        do {
            printf("Nhap loai van chuyen(0 hoac 1): ");
            scanf("%d", &type);
            clear_buffer();
            if (type != 0 && type != 1) {
                printf("Nhap lai(0 hoac 1).\n");
            }
        } while (type != 0 && type != 1);

        delis[i].type = type;
    }
}

bool valid_id(char *DeliveryCode) {
    int len = strlen(DeliveryCode);
    if (len < 8 || len > 20) {
        return false;
    }
    for (int i = 0; i < len; i++) {
        if (!isalnum(DeliveryCode[i])) {
            return false;
        }
    }
    return true;
}

int error(Deli deli) {
    if (deli.L < 10 || deli.W < 10 || deli.H < 10) {
        return 1;
    } else if (deli.L > 150 || deli.W > 150 || deli.H > 150) {
        return 2;
    } else if (deli.weight > 30) {
        return 3;
    }
    return 0;
}

float converted_weight(Deli deli) {
    float new_weight;
    int sum = deli.L + deli.W + deli.H;
    if (sum < 80) {
        new_weight = deli.weight;
    } else {
        float cv_weight;
        if (deli.type == 1) {
            cv_weight = (deli.L * deli.W * deli.H) / 6000;
        }
        if (deli.type == 0) {
            cv_weight = (deli.L * deli.W * deli.H) / 4000;
        }
        new_weight = (deli.weight > cv_weight) ? deli.weight : cv_weight;
    }
    float diff = new_weight - (int)new_weight;
    if (diff == 0) {
        return new_weight;
    } else if (diff > 0.5) {
        return (int)new_weight + 1;
    } else {
        return (int)new_weight + 0.5;
    }
}

float calculate(Deli deli) {
    float w = converted_weight(deli);
    int a;
    if (deli.type == 0) {
        if (w <= 3) {
            a = 16500;
        } else {
            a = 16500 + (w - 3) * 5000;
        }
    }
    if (deli.type == 1) {
        if (w <= 3) {
            a = 22000;
        } else {
            a = 22000 + (w - 3) * 5000;
        }
    }
    return a;
}

int main() {
    int choice;
    Deli delis[100];
    int numDeliveries;

    do {
        printf("Moi ban lua chon chuc nang\n");
        printf("==========================\n");
        printf("    1. Nhap thong tin kien hang: \n");
        printf("    2. Chi tiet kien hang bi tu choi: \n");
        printf("    3. Chi tiet kien hang hop le: \n");
        printf("    4. Tinh phi van chuyen: \n");
        printf("    5. Thoat: \n");

        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                input(delis, &numDeliveries);
                break;
            case 2:
                printf("Chi tiet kien hang bi tu choi\n");
                printf("=============================\n");
                printf("|%-20s|%-20s|\n", "Ma kien", "Li do tu choi");
                int count = 0;
                for (int i = 0; i < numDeliveries; i++) {
                    int err = error(delis[i]);
                    if (err != 0) {
                        count++;
                        if (err == 1) {
                            printf("|%-20s|%-20s|\n", delis[i].myDel, "ER1");
                        } else if (err == 2) {
                            printf("|%-20s|%-20s|\n", delis[i].myDel, "ER2");
                        } else if (err == 3) {
                            printf("|%-20s|%-20s|\n", delis[i].myDel, "ER3");
                        }
                    }
                }
                printf("Tong so: %d\n", count);
                if (count == 0) {
                    printf("Khong co kien hang nao bi loi\n");
                }
                break;
            case 3:
                printf("Chi tiet kien hang hop le\n");
                printf("=========================\n");
                printf("|%-20s|%-20s|%-20s|%-20s|\n", "Ma kien", "Can nang tinh phi", "Hinh thuc van chuyen", "thanh toan");
                for (int i = 0; i < numDeliveries; i++) {
                    int err = error(delis[i]);
                    if (err == 0) {
                        printf("|%-20s|", delis[i].myDel);
                        float w = converted_weight(delis[i]);
                        printf("%-20.2f|", w);
                        printf("%-20s|", delis[i].type == 0 ? "Chuyen phat nhanh" : "Chuyen phat thuong");
                        float cost = calculate(delis[i]);
                        printf("%-20.2f|\n", cost);
                    }
                }
                break;
            case 4:
                printf("Chi phi van chuyen\n");
                printf("==================\n");
                float totalCost = 0;
                int valid_count = 0;
                for (int i = 0; i < numDeliveries; i++) {
                    int err = error(delis[i]);
                    if (err == 0) {
                        float cost = calculate(delis[i]);
                        totalCost += cost;
                        valid_count++;
                    }
                }
                printf("So kien hang hop le: %d\n", valid_count);
                printf("Tong chi phi truoc VAT: %.2f\n", totalCost);
                float vat = totalCost * 0.08;
                printf("VAT (8%%): %.2f\n", vat);
                printf("Tong chi phi: %.2f\n", totalCost + vat);
                break;
            case 5:
                printf("Thoat.\n");
                exit(0);
                break;
            default:
                printf("Nhap lua chon tu 1 toi 5.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

