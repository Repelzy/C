#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100


struct Product {
    char code[6];  
    int price;    
};


int findPrice(struct Product products[], int numProducts, char code[]) {
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i].code, code) == 0) {
            return products[i].price;
        }
    }
    return 0;  
}

int main() {
    struct Product products[MAX_PRODUCTS];
    int numProducts = 0;


    while (1) {
        char code[6];
        int price;
        
        printf("Enter product code and price (or -1 to stop): ");
        scanf("%s", code);
        
        if (strcmp(code, "-1") == 0) {
            break;
        }
        
        scanf("%d", &price);
        
        strcpy(products[numProducts].code, code);
        products[numProducts].price = price;
        
        numProducts++;
    }


    int numCartItems;
    int total = 0;
    
    printf("Enter number of items in cart: ");
    scanf("%d", &numCartItems);

    for (int i = 0; i < numCartItems; i++) {
        char cartCode[6];
        int amount;

        scanf("%s %d", cartCode, &amount);

        int price = findPrice(products, numProducts, cartCode);
        total += price * amount;
    }


    printf("Total price of the cart: %d\n", total);

    return 0;
}
