//Day 2  celsius to Fahrenheit converter vice versa
#include <stdio.h>
#include <stdlib.h>
void sysclr()
{
    system("cls");
}
void loading(int duration)
{
    for (int i = 0; i < duration; i++)
    {
        fflush(stdout);
        sleep(1);
        printf(".");
       
    }
}
float fahrenheit(float c)
{
    return (9.0 / 5.0) * c + 32;
}
float celsius(float f)
{
    return (5.0 / 9.0) * (f - 32);
}
int main()
{   
    char o;
    sysclr();
    printf("Loading");
    fflush(stdout);
    sleep(1);
    loading(5);
    do
    {
        sysclr();
        int opt;
        printf("Choose an option:\n");
        fflush(stdout);
        sleep(1);
        printf("[1]Celsius to fahrenheit\n");
        fflush(stdout);
        sleep(1);
        printf("[2]Fahrenheit to celsius\n");
        fflush(stdout);
        sleep(1);
        printf("[3]Exit Program\n");
        fflush(stdout);
        sleep(1);
        printf("Enter your choice:");
        scanf("%d", &opt);
        sysclr();
        float f;
        float c;
        switch (opt)
        {
        case 1:
            printf("Enter celsius:");
            scanf("%f", &c);
            printf("\n-----------------------------------------------------------------------\n");
            printf("Converted:%f", fahrenheit(c));
            break;
        case 2:
            printf("Enter fahrenheit:");
            scanf("%f", &f);
            printf("\n-----------------------------------------------------------------------\n");
            printf("Converted:%f", celsius(f));
            break;
        case 3:
            break;
        default:
            printf("Invalid option");
            break;
        }
        if (opt == 3)
        {
            break;
        }
        printf("\n-----------------------------------------------------------------------\n");
        printf("Do you want to convert again(y/n):");
        scanf(" %c", &o);
    } while (o == 'y' || o == 'Y');
    sysclr();
    printf("Exited");
}
