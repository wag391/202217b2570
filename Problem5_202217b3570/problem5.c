#include<stdio.h>
#include<stdlib.h> // Include <stdlib.h> for exit() function
//#include<conio.h> // This is typically used in old compilers, not necessary here
#define MAX_SIZE 5 // Define MAX_SIZE instead of using 'n' directly

void main() {
    int queue[MAX_SIZE], ch=1, front=0, rear=0, i, j=1;

    printf("Queue using Array");
    printf("\n1. Insertion\n2. Deletion\n3. Display\n4. Exit");

    while(ch) {
        printf("\n\nEnter the Choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                if(rear == MAX_SIZE)
                    printf("\nQueue is Full");
                else {
                    printf("\nEnter number %d: ", j++);
                    scanf("%d", &queue[rear++]);
                }
                break;
            case 2:
                if(front == rear) {
                    printf("\nQueue is empty");
                } else {
                    printf("\nDeleted Element is %d", queue[front++]);
                    // x++; // This seems unnecessary and incorrect
                }
                break;
            case 3:
                printf("\nQueue Elements are:\n");
                if(front == rear)
                    printf("\nQueue is Empty");
                else {
                    for(i = front; i < rear; i++) {
                        printf("%d\n", queue[i]);
                    }
                }
                break;
            case 4:
                exit(0); // Exit the program
            default:
                printf("Wrong Choice: please see the options");
        }
    }
    // getch(); // Not necessary in standard C
}
