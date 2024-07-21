#include<stdio.h>
//#include<conio.h> // Not necessary in standard C
//void main() // Instead of void main(), use int main()
int main() // Corrected to use int main() for standard compliance
{
    int n, a[10], b[10], t[10], w[10], g[10], i, m;
    float att = 0, awt = 0;

    //clrscr(); // Not necessary in standard C

    for(i = 0; i < 10; i++)
    {
        a[i] = 0; b[i] = 0; w[i] = 0; g[i] = 0;
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst times:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &b[i]);

    printf("\nEnter the arrival times:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    g[0] = 0;
    for(i = 0; i < n; i++)
        g[i + 1] = g[i] + b[i];

    for(i = 0; i < n; i++)
    {
        w[i] = g[i] - a[i];
        t[i] = g[i + 1] - a[i];
        awt = awt + w[i];
        att = att + t[i];
    }

    awt = awt / n;
    att = att / n;

    printf("\n\tProcess\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++)
    {
        printf("\tP%d\t\t%d\t\t%d\n", i, w[i], t[i]);
    }

    printf("The average waiting time is %f\n", awt);
    printf("The average turnaround time is %f\n", att);

    //getch(); // Not necessary in standard C
    return 0; // Return 0 to indicate successful execution
}
