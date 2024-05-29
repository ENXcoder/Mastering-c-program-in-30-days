//CONTACTS APP 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

void add_contacts()
{
    FILE *f1;
    char name[50], no[50], c_name[50], c_no[50];

    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; 
    int is_duplicate = 0;
    f1 = fopen("contacts.txt", "r");
    if (f1)
    {
        while (fscanf(f1, "%s %s", c_name, c_no) != EOF)
        {
            if (strcmp(name, c_name) == 0)
            {
                printf("Contact name already exists\n");
                fclose(f1);
                is_duplicate = 1;
                break;
            }
        }
        fclose(f1);
    }

    if (is_duplicate)
    {
        return;
    }

    printf("Enter number: ");
    fgets(no, sizeof(no), stdin);
    no[strcspn(no, "\n")] = '\0';

    f1 = fopen("contacts.txt", "a");
    if (!f1)
    {
        printf("Unable to open file\n");
        return;
    }
    fprintf(f1, "%s %s\n", name, no);
    fclose(f1);
    printf("Contact saved successfully\n");
}

void display()
{
    FILE *f1;
    char name[50], no[50];

    f1 = fopen("contacts.txt", "r");
    if (!f1)
    {
        printf("Unable to open file\n");
        return;
    }
    printf("Contact list:\n");
    while (fscanf(f1, "%s %s", name, no) != EOF)
    {
        printf("Name: %s, Phone: %s\n", name, no);
    }
    fclose(f1);
}

void search()
{
    FILE *f1;
    char s_name[50], name[50], no[50];
    int found = 0;

    printf("Enter the name to search: ");
    fgets(s_name, sizeof(s_name), stdin);
    s_name[strcspn(s_name, "\n")] = '\0'; 

    f1 = fopen("contacts.txt", "r");
    if (!f1)
    {
        printf("Unable to open file\n");
        return;
    }

    while (fscanf(f1, "%s %s", name, no) != EOF)
    {
        if (strcmp(name, s_name) == 0)
        {
            printf("Name: %s, Phone: %s\n", name, no);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Contact not found\n");
    }

    fclose(f1);
}

void delete_c()
{
    FILE *f1, *f2;
    char del_name[50], name[50], no[50];
    int found = 0;

    printf("Enter name: ");
    fgets(del_name, sizeof(del_name), stdin);
    del_name[strcspn(del_name, "\n")] = '\0'; 

    f1 = fopen("contacts.txt", "r");
    if (!f1)
    {
        printf("Unable to open file\n");
        return;
    }

    f2 = fopen("temp.txt", "w");
    if (!f2)
    {
        printf("Unable to open file\n");
        fclose(f1);
        return;
    }

    while (fscanf(f1, "%s %s", name, no) != EOF)
    {
        if (strcmp(name, del_name) == 0)
        {
            found = 1;
            continue;
        }
        fprintf(f2, "%s %s\n", name, no);
    }

    fclose(f1);
    fclose(f2);

    if (found)
    {
        remove("contacts.txt");
        rename("temp.txt", "contacts.txt");
        printf("Contact successfully deleted\n");
    }
    else
    {
        remove("temp.txt");
        printf("Contact not found\n");
    }
}

void sl(int duration)
{
    fflush(stdout);
    Sleep(duration * 1000);
}

int main()
{
    system("cls");
    int opt;
    do
    {
        printf("ENX CONTACT APP\n");
        printf("Choose an option\n");
        sl(1);
        printf("[1] Add contact\n");
        sl(1);
        printf("[2] Display Contact\n");
        sl(1);
        printf("[3] Search Contact\n");
        sl(1);
        printf("[4] Delete contact\n");
        sl(1);
        printf("[5] Exit program\n");
        sl(1);
        printf(">> ");
        scanf("%d", &opt);
        getchar(); // Clear newline from input buffer

        switch (opt)
        {
        case 1:
            system("cls");
            add_contacts();
            break;
        case 2:
            system("cls");
            display();
            break;
        case 3:
            system("cls");
            search();
            break;
        case 4:
            system("cls");
            delete_c();
            break;
        case 5:
            system("cls");
            printf("Exiting program\n");
            exit(EXIT_SUCCESS);
        default:
            printf("Invalid option, try again\n");
        }
        printf("\nPress enter to continue.......");
        getchar();
        system("cls");
    } while (opt != 5);

    return 0;
}
