#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cmh_functions.c"
int main()
{

    char filename[] = "applicants.txt";
    char filename1[] = "employees.txt";
    FILE *file = fopen("applicants.txt", "a+");
    if (file == NULL)
    {
        perror("Error opening file.");
        return 1;
    }
    FILE *file1 = fopen("employees.txt", "a+");
    if (file1 == NULL)
    {
        perror("Error opening file.");
        return 1;
    }

    roles r;
    init_roles(&r);
    roles r1;
    init_roles(&r1);

    node *root = NULL;
    node *root1 = NULL;
    int key;
    char name[100], mobile[100], address[100], email[100], skills[100], experience[100], projects_num[100], unique[100], job_role[100];
    char line[1000]; // Adjust the size according to your needs

    // Read the file and build the binary search tree
    while (fgets(line, sizeof(line), file) != NULL)
    {
        sscanf(line, "%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
               &key, name, mobile, address, email, skills, experience, projects_num, unique, job_role);
        root = insert(&r, root, key, name, mobile, address, email, skills, experience, projects_num, unique, job_role);
    }
    while (fgets(line, sizeof(line), file1) != NULL)
    {
        sscanf(line, "%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
               &key, name, mobile, address, email, skills, experience, projects_num, unique, job_role);
        root1 = insert(&r1, root1, key, name, mobile, address, email, skills, experience, projects_num, unique, job_role);
    }

    fclose(file);
    fclose(file1);
    int choice;
    printf("****CORPORATE MANAGEMENT HUB****\n");
    printf("1. View project documentation\n");
    printf("2. View database\n");
    printf("3. Apply for the company\n");
    do
    {
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("You can view documentation here-->\n");
            break;
        case 2:
            printf("\t1. view query syntax documentation\n");
            printf("\t2. perform display operation\n");
            int choice1;
            do
            {
                printf("\tEnter your choice1:\n");
                scanf("%d", &choice1);
                if (choice1 == 1)
                {
                    printf("query syntax documentation can be viewed here\n");
                }
                else if (choice1 == 2)
                {
                    printf("\tQuery Mode entered\n");
                    int operation = 1;
                    sql(&r, &r1, &root, &root1, operation);
                    printf("\tQuery mode exited\n");
                }
            } while (choice1 >= 1 && choice1 <= 2);
            break;
        case 3:
            printf("\t1. apply for company\n");
            printf("\t2. Check how many positions are vacant for a post\n");
            printf("\t3. Open Selection Process\n");
            int choice2;
            do
            {
                printf("\tenter your choice2\n");
                scanf("%d", &choice2);
                if (choice2 == 1)
                {
                    printf("\tQuery Mode entered\n");
                    int operation = 2;
                    sql(&r, &r1, &root, &root1, operation);
                    printf("\tQuery mode exited\n");
                }
                else if (choice2 == 2)
                {
                    printf("\tFor which post do to want to check vacancy?\n");
                    char *check = (char *)malloc(sizeof(char) * 100);
                    int i = 0;
                    int c;
                    while ((c = getchar()) != '\n')
                        ;
                    while ((c = getchar()) != '\n')
                    {
                        check[i++] = c;
                    }
                    check[i] = '\0';
                    int x = vacancy(check, &r1);
                    if (x > 0)
                    {
                        printf("\tThere are %d positions vacant for this position\n", x);
                    }
                    else
                        printf("\tThere are no positions vacant for this position\n");
                    free(check);
                }
                else if (choice2 == 3)
                {
                    printf("\tFor which post do you want to open selection process?\n");
                    char *check = (char *)malloc(sizeof(char) * 100);
                    int i = 0;
                    int c;
                    while ((c = getchar()) != '\n')
                        ;
                    while ((c = getchar()) != '\n')
                    {
                        check[i++] = c;
                    }
                    check[i] = '\0';
                    int x = vacancy(check, &r1);
                    if (x <= 0)
                    {
                        printf("\tThere are no positions vacant for this position\n");
                    }
                    else
                    {

                        selection_process(&root, &root1, &r, &r1, check);
                    }
                    free(check);
                }
            } while (choice2 >= 1 && choice2 <= 3);
            break;
        }
    } while (choice >= 1 && choice <= 3);
    printf("Code terminated\n");
    free(root);
    free(root1);
    return 0;
}
