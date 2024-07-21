#include <stdio.h>

#define MAX 20

// Function declarations

void create();

void insert();

void deletion();

void search();

void display();

int b[MAX]; // Array to hold elements

int n;      // Current number of elements in the array

int main() {

    int ch;

    char g = 'y';

    do {

        printf("\nMain Menu");

        printf("\n1. Create\n2. Delete\n3. Search\n4. Insert\n5. Display\n6. Exit\n");

        printf("\nEnter your Choice: ");

        scanf("%d", &ch);

        switch(ch) {

            case 1:

                create();

                break;

            case 2:

                deletion();

                break;

            case 3:

                search();

                break;

            case 4:

                insert();

                break;

            case 5:

                display();

                break;

            case 6:

                return 0; // Exiting the program

            default:

                printf("Enter the correct choice!\n");

        }

        printf("\nDo you want to continue? (y/n): ");

        scanf(" %c", &g);

    } while (g == 'y' || g == 'Y');

    return 0;

}

void create() {

    printf("\nEnter the number of elements: ");

    scanf("%d", &n);

    printf("\nEnter %d elements:\n", n);

    for (int i = 0; i < n; i++) {

        printf("Element %d: ", i + 1);

        scanf("%d", &b[i]);

    }

}

void deletion() {

    int pos;

    if (n == 0) {

        printf("List is empty. Nothing to delete.\n");

        return;

    }

    printf("\nEnter the position you want to delete: ");

    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {

        printf("Invalid position!\n");

        return;

    }

    for (int i = pos; i < n - 1; i++) {

        b[i] = b[i + 1];

    }

    n--;

    printf("Element at position %d deleted successfully.\n", pos);

}

void search() {

    int e, found = 0;

    if (n == 0) {

        printf("List is empty. Nothing to search.\n");

        return;

    }

    printf("\nEnter the element to be searched: ");

    scanf("%d", &e);

    for (int i = 0; i < n; i++) {

        if (b[i] == e) {

            printf("Element %d found at position %d.\n", e, i);

            found = 1;

            break;

        }

    }

    if (!found) {

        printf("Element %d not found in the list.\n", e);

    }

}

void insert() {

    int pos, p;

    if (n == MAX) {

        printf("List is full. Cannot insert more elements.\n");

        return;

    }

    printf("\nEnter the position to insert (0 to %d): ", n);

    scanf("%d", &pos);

    if (pos < 0 || pos > n) {

        printf("Invalid position!\n");

        return;

    }

    printf("Enter the element to insert: ");

    scanf("%d", &p);

    for (int i = n; i > pos; i--) {

        b[i] = b[i - 1];

    }

    b[pos] = p;

    n++;

    printf("Element inserted successfully.\n");

}

void display() {

    if (n == 0) {

        printf("List is empty.\n");

        return;

    }

    printf("\nThe elements in the list are:\n");

    for (int i = 0; i < n; i++) {

        printf("%d ", b[i]);

    }

    printf("\n");

}
