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
    char name[100], mobile[100], address[100], email[100], skills[1000], experience[100], projects_num[100], unique[100], job_role[100];
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
    
    do
    {
    	printf("Enter 1 to view project documentation\n");
    	printf("Enter 2 to view database of applicants and employees\n");
    	printf("Enter 3 to apply for the company and open selection process\n");
    	printf("Enter any other number to terminate the program\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("PROJECT DOCUMENTATION:\nJob Roles and Corresponding Preffered Skills:\n");
            printf("CEO:\n");
printf("- Strategic Planning\n");
printf("- Leadership Development\n");
printf("- Financial Management\n");
printf("- Decision Making\n");
printf("- Public Speaking\n\n");

printf("CTO:\n");
printf("- Software Development\n");
printf("- Project Management\n");
printf("- Technology Innovation\n");
printf("- Team Leadership\n");
printf("- Cloud Computing\n\n");

printf("VP of Engineering:\n");
printf("- Software Architecture\n");
printf("- Agile Methodologies\n");
printf("- Technical Leadership\n");
printf("- System Design\n");
printf("- Continuous Integration or Continuous Deployment\n\n");

printf("Chief Architect:\n");
printf("- Enterprise Architecture\n");
printf("- Solution Design\n");
printf("- Scalability Planning\n");
printf("- System Integration\n");
printf("- API Design\n\n");

printf("Technical Lead:\n");
printf("- Software Design Patterns\n");
printf("- Code Review\n");
printf("- Mentoring and Coaching\n");
printf("- Technical Documentation\n");
printf("- Problem Solving\n\n");

printf("Principal Software Engineer:\n");
printf("- Software Architecture\n");
printf("- System Design\n");
printf("- Object Oriented Programming\n");
printf("- Test-Driven Development\n");
printf("- Debugging\n\n");

printf("Senior Software Engineer:\n");
printf("- Object Oriented Programming\n");
printf("- Test Driven Development\n");
printf("- Version Control\n");
printf("- Debugging\n");
printf("- Software Optimization\n\n");

printf("VP of Marketing:\n");
printf("- Digital Marketing Strategy\n");
printf("- Brand Management\n");
printf("- Market Research\n");
printf("- Campaign Management\n");
printf("- Content Marketing\n\n");

printf("Product Manager:\n");
printf("- Product Lifecycle Management\n");
printf("- User Experience Design\n");
printf("- Market Analysis\n");
printf("- Product Roadmapping\n");
printf("- Agile Product Development\n\n");

printf("HR Director:\n");
printf("- Talent Acquisition\n");
printf("- Employee Relations\n");
printf("- Performance Management\n");
printf("- Diversity and Inclusion\n");
printf("- HR Compliance\n\n");

printf("Recruiting Director:\n");
printf("- Candidate Sourcing\n");
printf("- Interviewing Techniques\n");
printf("- Recruitment Metrics Analysis\n");
printf("- Employer Branding\n");
printf("- Applicant Tracking Systems\n\n");


            break;
        case 2:
            
            int choice1;
            do
            {
           	printf("\tEnter 1 to view sql inspired query syntax documentation\n");
           	printf("\tEnter 2 to view any employee or applicant details\n");
           	printf("\tEnter any other number to go back\n");
                printf("\tEnter your choice:\n");
                scanf("%d", &choice1);
                if (choice1 == 1)
                {
                    printf("\tIf you want to view applicant's details based on unique id of applicant,the SQL inspired command is:\n");
                    printf("\t\tselect * from <table name> where unique=<unique id of applicant>;\n");
                    printf("\tFor example, if applicant has a unique id = 100, then command will be:\n");
                    printf("\t\tselect * from applicants where unique=100;\n");
                    
                    printf("\n\tIf you want to view employees' details based on a particular job role,the SQL inspired command is:\n");
		    printf("\t\tselect * from <table name> where job_role=<job_role>;\n");
		    printf("\tFor example, if applicants to be searched has a job role of CEO, then command will be:\n");
		    printf("\t\tselect * from applicants where job_role=CEO;\n");
		    printf("\n\tImportant: The entire command must be in lowercase\n");
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
            
            int choice2;
            do
            {
            	printf("\tEnter 1 to view documentation related to insertion into database\n");
            printf("\tEnter 2 to insert your details into the applicant's database\n");
            printf("\tEnter 3 to check how many positions are vacant for a post\n");
            printf("\tEnter 4 to open Selection Process\n");
            printf("\tEnter any other number to go back\n"); 
                printf("\tEnter your choice:\n");
                scanf("%d", &choice2);
                if(choice2==1){
                	printf("\tThe syntax of the SQL inspired insert command is:\n");
                	printf("\tinsert into <table name> values(<name>, <mobile number>, <address>, <email id>, <skills>, <experience years>, <no. of projects>, <unique id>, <job role>)\n");
                	printf("\n\tFor example:\n");
                	printf("\tinsert into applicants values(James Roy,1234,Pune,james@gmail.com,Programming,5,3,100,CEO);\n");
                	printf("\tImportant: The entire command must be in lowercase\n");
                }
                else if (choice2 == 2)
                {
                    printf("\tQuery Mode entered\n");
                    int operation = 2;
                    sql(&r, &r1, &root, &root1, operation);
                    printf("\tQuery mode exited\n");
                }
                else if (choice2 == 3)
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
                else if (choice2 == 4)
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
            } while (choice2 >= 1 && choice2 <= 4);
            break;
        }
    } while (choice >= 1 && choice <= 3);
    printf("Code terminated\n");
    free(root);
    free(root1);
    return 0;
}
