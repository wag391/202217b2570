#include <stdio.h>

// Define structure for a polynomial term
struct poly {
    int coeff;  // coefficient
    int expo;   // exponent
};

// Declare arrays p1, p2, p3 of type structure poly
struct poly p1[10], p2[10], p3[10];

// Function prototypes
int readPoly(struct poly []);
int addPoly(struct poly [], struct poly [], int, int, struct poly []);
void displayPoly(struct poly [], int);

int main() {
    int t1, t2, t3;

    // Read and display first polynomial (p1)
    printf("\nEnter the first polynomial:\n");
    t1 = readPoly(p1);
    printf("\nFirst polynomial : ");
    displayPoly(p1, t1);

    // Read and display second polynomial (p2)
    printf("\n\nEnter the second polynomial:\n");
    t2 = readPoly(p2);
    printf("\nSecond polynomial : ");
    displayPoly(p2, t2);

    // Add two polynomials (p1 and p2) and display resultant polynomial (p3)
    t3 = addPoly(p1, p2, t1, t2, p3);
    printf("\n\nResultant polynomial after addition : ");
    displayPoly(p3, t3);
    printf("\n");

    return 0;
}

// Function to read a polynomial from user input
int readPoly(struct poly p[10]) {
    int t1, i;

    printf("\nEnter the total number of terms in the polynomial: ");
    scanf("%d", &t1);

    printf("\nEnter the COEFFICIENT and EXPONENT in DESCENDING ORDER\n");
    for (i = 0; i < t1; i++) {
        printf("Enter the Coefficient(%d): ", i + 1);
        scanf("%d", &p[i].coeff);
        printf("Enter the exponent(%d): ", i + 1);
        scanf("%d", &p[i].expo);
    }

    return t1;  // Return the number of terms in the polynomial
}

// Function to add two polynomials p1 and p2
int addPoly(struct poly p1[10], struct poly p2[10], int t1, int t2, struct poly p3[10]) {
    int i = 0, j = 0, k = 0;

    while (i < t1 && j < t2) {
        if (p1[i].expo == p2[j].expo) {
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            p3[k].expo = p1[i].expo;
            i++;
            j++;
            k++;
        } else if (p1[i].expo > p2[j].expo) {
            p3[k].coeff = p1[i].coeff;
            p3[k].expo = p1[i].expo;
            i++;
            k++;
        } else {
            p3[k].coeff = p2[j].coeff;
            p3[k].expo = p2[j].expo;
            j++;
            k++;
        }
    }

    // Copy remaining terms of polynomial p1
    while (i < t1) {
        p3[k].coeff = p1[i].coeff;
        p3[k].expo = p1[i].expo;
        i++;
        k++;
    }

    // Copy remaining terms of polynomial p2
    while (j < t2) {
        p3[k].coeff = p2[j].coeff;
        p3[k].expo = p2[j].expo;
        j++;
        k++;
    }

    return k;  // Return the number of terms in the resultant polynomial p3
}

// Function to display a polynomial
void displayPoly(struct poly p[10], int term) {
    int k;

    for (k = 0; k < term - 1; k++) {
        printf("%dx^%d + ", p[k].coeff, p[k].expo);
    }
    printf("%dx^%d", p[term - 1].coeff, p[term - 1].expo);
}
