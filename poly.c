#include<stdio.h>
#include<stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* make_node(int coeff, int exp) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->coeff = coeff;
    node->exp = exp;
    node->next = NULL;
    return node;
}

void insert(struct Node** head, int coeff, int exp) {
    struct Node* node = make_node(coeff, exp);
    if(node -> coeff == 0) return;
    if (*head == NULL) {
        *head = node;
        return;
    }
    struct Node* curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = node;
}

struct Node* add_polynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* p1 = poly1;
    struct Node* p2 = poly2;
    struct Node* result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            insert(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            insert(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            insert(&result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        insert(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        insert(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    insert(&poly1, 3, 4);
    insert(&poly1, 2, 2);
    insert(&poly1, 5, 0);

    insert(&poly2, -3, 3);
    insert(&poly2, 1, 2);
    insert(&poly2, 2, 0);

    struct Node* result = add_polynomials(poly1, poly2);

    struct Node* curr = result;
    while (curr != NULL) {
        printf("%dx^%d ", curr->coeff, curr->exp);
        if (curr->next != NULL) {
            printf("+ ");
        }
        curr = curr->next;
    }
    printf("\n");

    return 0;
}
