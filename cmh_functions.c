#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cmh_bptrees.c"
node *insert(roles *ptr, node *root, int key, char *name, char *mobile, char *address, char *email, char *skills, char *experience, char *projects_num, char *unique, char *job_role)
{
    record *record_pointer = NULL;
    node *leaf = NULL;

    record_pointer = find(root, key, false, NULL);
    if (record_pointer != NULL)
    {
        // Update the existing record
        // Allocate memory for each string field and copy the content
        free(record_pointer);
        record_pointer = (record *)malloc(sizeof(record));
        record_pointer->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
        record_pointer->mobile = (char *)malloc(sizeof(char) * (strlen(mobile) + 1));
        record_pointer->address = (char *)malloc(sizeof(char) * (strlen(address) + 1));
        record_pointer->email = (char *)malloc(sizeof(char) * (strlen(email) + 1));
        record_pointer->skills = (char *)malloc(sizeof(char) * (strlen(skills) + 1));
        record_pointer->experience = (char *)malloc(sizeof(char) * (strlen(experience) + 1));
        record_pointer->unique = (char *)malloc(sizeof(char) * (strlen(unique) + 1));
        record_pointer->projects_num = (char *)malloc(sizeof(char) * (strlen(projects_num) + 1));
        record_pointer->job_role = (char *)malloc(sizeof(char) * (strlen(job_role) + 1));
        if (record_pointer == NULL)
        {
            perror("Record creation.");
            exit(EXIT_FAILURE);
        }
        else
        {
            strcpy(record_pointer->name, name); // recordptr->name=name;
            strcpy(record_pointer->mobile, mobile);
            strcpy(record_pointer->address, address);
            strcpy(record_pointer->email, email);
            strcpy(record_pointer->skills, skills);
            strcpy(record_pointer->experience, experience);
            strcpy(record_pointer->projects_num, projects_num);
            strcpy(record_pointer->unique, unique);
            strcpy(record_pointer->job_role, job_role);
        }

        return root;
    }

    record_pointer = makeRecord(name, mobile, address, email, skills, experience, projects_num, unique, job_role);

    insert_role(&ptr, record_pointer);
    // printf("bp2\n");
    if (root == NULL)
        return startNewTree(key, record_pointer);

    leaf = findLeaf(root, key, false);

    if (leaf->num_keys < order - 1)
    {

        leaf = insertIntoLeaf(leaf, key, record_pointer);

        return root;
    }

    return insertIntoLeafAfterSplitting(root, leaf, key, record_pointer);
}
void init_roles(roles *ptr)
{
    ptr->vertices = (rolenode **)malloc(sizeof(rolenode *) * ROLE_SIZE);
    ptr->numvertices = ROLE_SIZE;
    ptr->roleid = (int *)malloc(sizeof(int) * ROLE_SIZE);
    ptr->max = (int *)malloc(sizeof(int) * ROLE_SIZE);
    for (int i = 0; i < ROLE_SIZE; i++)
    {
        ptr->vertices[i] = NULL;
        ptr->roleid[i] = 0;
    }
    ptr->max[0] = 1;
    ptr->max[1] = 1;
    ptr->max[2] = 3;
    ptr->max[3] = 1;
    ptr->max[4] = 5;
    ptr->max[5] = 10;
    ptr->max[6] = 20;
    ptr->max[7] = 1;
    ptr->max[8] = 5;
    ptr->max[9] = 1;
    ptr->max[10] = 1;
}
rolenode *create_role_node(record **recptr)
{
    rolenode *nn = (rolenode *)malloc(sizeof(rolenode));
    if (nn)
    {
        nn->recptr = *recptr;
        nn->next = NULL;
    }
    return nn;
}
int get_role_code(record *recptr)
{
    int i;
    if (strcmp(recptr->job_role, "CEO") == 0)
    {
        i = 0;
    }
    else if (strcmp(recptr->job_role, "CTO") == 0)
    {
        i = 1;
    }
    else if (strcmp(recptr->job_role, "VP of Engineering") == 0)
    {
        i = 2;
    }
    else if (strcmp(recptr->job_role, "Chief Architect") == 0)
    {
        i = 3;
    }
    else if (strcmp(recptr->job_role, "Technical Lead") == 0)
    {
        i = 4;
    }
    else if (strcmp(recptr->job_role, "Principal Software Engineer") == 0)
    {
        i = 5;
    }
    else if (strcmp(recptr->job_role, "Senior Software Engineer") == 0)
    {
        i = 6;
    }
    else if (strcmp(recptr->job_role, "VP of Marketing") == 0)
    {
        i = 7;
    }
    else if (strcmp(recptr->job_role, "Product Manager") == 0)
    {
        i = 8;
    }
    else if (strcmp(recptr->job_role, "HR Director") == 0)
    {
        i = 9;
    }
    else if (strcmp(recptr->job_role, "Recruiting Director") == 0)
    {
        i = 10;
    }
    else
        i = -1;
    return i;
}
int vacancy(char *job_role, roles *r)
{
    int i;
    if (strcmp(job_role, "CEO") == 0)
    {
        i = 0;
    }
    else if (strcmp(job_role, "CTO") == 0)
    {
        i = 1;
    }
    else if (strcmp(job_role, "VP of Engineering") == 0)
    {
        i = 2;
    }
    else if (strcmp(job_role, "Chief Architect") == 0)
    {
        i = 3;
    }
    else if (strcmp(job_role, "Technical Lead") == 0)
    {
        i = 4;
    }
    else if (strcmp(job_role, "Principal Software Engineer") == 0)
    {
        i = 5;
    }
    else if (strcmp(job_role, "Senior Software Engineer") == 0)
    {
        i = 6;
    }
    else if (strcmp(job_role, "VP of Marketing") == 0)
    {
        i = 7;
    }
    else if (strcmp(job_role, "Product Manager") == 0)
    {
        i = 8;
    }
    else if (strcmp(job_role, "HR Director") == 0)
    {
        i = 9;
    }
    else if (strcmp(job_role, "Recruiting Director") == 0)
    {
        i = 10;
    }

    return (r->max[i] - r->roleid[i]);
}
int get_role_code2(char *job_role)
{

    int i;
    if (strcmp(job_role, "CEO") == 0)
    {
        i = 0;
    }
    else if (strcmp(job_role, "CTO") == 0)
    {
        i = 1;
    }
    else if (strcmp(job_role, "VP of Engineering") == 0)
    {
        i = 2;
    }
    else if (strcmp(job_role, "Chief Architect") == 0)
    {
        i = 3;
    }
    else if (strcmp(job_role, "Technical Lead") == 0)
    {
        i = 4;
    }
    else if (strcmp(job_role, "Principal Software Engineer") == 0)
    {
        i = 5;
    }
    else if (strcmp(job_role, "Senior Software Engineer") == 0)
    {
        i = 6;
    }
    else if (strcmp(job_role, "VP of Marketing") == 0)
    {
        i = 7;
    }
    else if (strcmp(job_role, "Product Manager") == 0)
    {
        i = 8;
    }
    else if (strcmp(job_role, "HR Director") == 0)
    {
        i = 9;
    }
    else if (strcmp(job_role, "Recruiting Director") == 0)
    {
        i = 10;
    }
    return i;
}
void display_role_wise(roles *r, char *check, node *root)
{
    int i = get_role_code2(check);
    rolenode *p = r->vertices[i];
    while (p)
    {
        findAndPrint(root, atoi(p->recptr->unique), 'a');

        p = p->next;
    }
}
void selection_process(node **root, node **root1, roles *r, roles *r1, char *check)
{
    FILE *file;

    int i = get_role_code2(check);
    Heap a;

    initHeap(&a, r->roleid[i]);
    trieNode *t = fill_trie(i);

    // printf("%d\n",i);

    rolenode *p = r->vertices[i];
    // printf("%d\n", r->roleid[i]);
    char *token;
    int looper = 1;
    char *tempskills;
    while (p)
    {
        int count = 0;
        // printf("bp\n");
        tempskills = (char *)malloc(sizeof(char) * (strlen(p->recptr->skills) + 1));
        strcpy(tempskills, p->recptr->skills);
        // printf("%s\n", p->recptr->skills);
        token = strtok(tempskills, "_");
        // printf("%s\n", p->recptr->skills);
        while (token != NULL)
        {
            // printf("%s\n", token);
            if (search(t, token))
            {

                count++;
            }

            token = strtok(NULL, "_");
        }
        count = count + atoi(p->recptr->experience) + atoi(p->recptr->projects_num);
        insert_heap(&a, atoi(p->recptr->unique), count, p->recptr);
        free(tempskills);
        p = p->next;
    }
    // printf("vacancy check=%d\n", vacancy(check,r1));
    // printf("Applicants for this=%d\n", r->roleid[i]);
    printf("The following applicants are hired:\n");
    int initial = (r->roleid[i]);
    while (vacancy(check, r1) != 0 && looper <= initial)
    {
        // printf("upper: %d\n", looper);
        priority *max = Remove(&a);

        int key;
        char name[100], mobile[100], address[100], email[100], skills[1000], experience[100], projects_num[100], unique[100], job_role[100];
        key = max->unique_no;
        strcpy(name, max->ptr->name);
        strcpy(mobile, max->ptr->mobile);
        strcpy(address, max->ptr->address);
        strcpy(email, max->ptr->email);
        strcpy(skills, max->ptr->skills);
        strcpy(experience, max->ptr->experience);
        strcpy(projects_num, max->ptr->projects_num);
        strcpy(unique, max->ptr->unique);
        strcpy(job_role, max->ptr->job_role);

        *root1 = insert(r1, *root1, key, name, mobile, address, email, skills, experience, projects_num, unique, job_role);
        file = fopen("employees.txt", "a+");
        if (file == NULL)
        {
            perror("Error opening file.");
            return;
        }
         findAndPrint(*root1, key, 'a');
        fprintf(file, "%d,%s,%s,%s,%s,%s,%s,%s,%s,%s\n", key, name, mobile, address, email, skills, experience, projects_num, unique, job_role);
        fclose(file);
        // code for deletion
	
        *root = writeToFileExcludingRecord(*root, "applicants.txt", key);

        file = fopen("applicants.txt", "a+");
        if (file == NULL)
        {
            perror("Error opening file.");
            return;
        }

        char line[1000];

        *root = NULL;
        int i = 0;
        while (i < r->numvertices)
        {
            free(r->vertices[i]);
            i++;
        }
        free(r->max);
        free(r->roleid);

        init_roles(r);
        while (fgets(line, sizeof(line), file) != NULL)
        {
            sscanf(line, "%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
                   &key, name, mobile, address, email, skills, experience, projects_num, unique, job_role);
            *root = insert(r, *root, key, name, mobile, address, email, skills, experience, projects_num, unique, job_role);
        }
        // printf("bp3\n");
        fclose(file);
        // printf("looper=%d\t", looper);
        // printf("roleid=%d\t", r->roleid[i]);
        // printf("vacancy check=%d\n", vacancy(check,r1));
        looper++;
    }
    // printf("%d\n", looper);
    // free(t);
}

void insert_role(roles **ptr, record *recptr)
{
    int i;

    i = get_role_code(recptr);
    if (i == -1)
        return;
    (*ptr)->roleid[i]++;
    rolenode *p = (*ptr)->vertices[i];
    if (!p)
    {
        (*ptr)->vertices[i] = create_role_node(&recptr);
        return;
    }
    while (p->next)
    {
        p = p->next;
    }
    p->next = create_role_node(&recptr);
    return;
}
void writeLeafNodesExcludingRecord(node *node, FILE *file, int keyToExclude)
{
    if (node == NULL)
    {
        return;
    }

    if (node->is_leaf)
    {
        // Write data from leaf node to file, excluding the specified key
        for (int i = 0; i < node->num_keys; i++)
        {
            if (node->keys[i] != keyToExclude)
            {
                fprintf(file, "%d,%s,%s,%s,%s,%s,%s,%s,%s,%s\n", node->keys[i], ((record *)node->pointers[i])->name, ((record *)node->pointers[i])->mobile, ((record *)node->pointers[i])->address, ((record *)node->pointers[i])->email, ((record *)node->pointers[i])->skills, ((record *)node->pointers[i])->experience, ((record *)node->pointers[i])->projects_num, ((record *)node->pointers[i])->unique, ((record *)node->pointers[i])->job_role);
            }
        }
    }
    else
    {
        // Recursively traverse child nodes
        for (int i = 0; i < node->num_keys + 1; i++)
        {
            writeLeafNodesExcludingRecord(node->pointers[i], file, keyToExclude);
        }
    }
    return;
}

node *writeToFileExcludingRecord(node *root, const char *filename, int keyToExclude)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        perror("Error opening file for writing.");
        return NULL;
    }

    // Traverse the B+ tree and write each key-value pair to the file, excluding the specified key
    writeLeafNodesExcludingRecord(root, file, keyToExclude);

    fclose(file);
    return root;
}
void sql(roles *r, roles *r1, node **root, node **root1, int operation)
{
    char *query;
    int c;

    int end = 0;
    int first = 1;
    while (end == 0)
    {
        if (first == 1)
        {
            while ((c = getchar()) != '\n')
                ;
            first = 0;
        }
        printf("Enter query:");
        query = (char *)malloc(sizeof(char) * 1000);
        int k = 0;

        while ((c = getchar()) != ';')
        {
            query[k++] = c;
        }
        query[k++] = ';';
        query[k] = '\0';

        tokens *t = (tokens *)malloc(sizeof(tokens));
        t->operation = 0;
        t->assist = 0;
        t->condition = 0;
        t->field = 0;
        t->star = 0;
        t->table = 0;
        char *token = strtok(query, " ,;=()");

        while (token != NULL)
        {

            if (strcmp(token, "select") == 0)
            {
                t->operation = 1;
            }
            else if (strcmp(token, "from") == 0)
            {
                t->assist = 2;
            }
            else if (strcmp(token, "insert") == 0)
            {
                t->operation = 3;
            }
            else if (strcmp(token, "into") == 0)
            {
                t->assist = 4;
            }
            else if (strcmp(token, "values") == 0)
            {
                t->condition = 5;
            }
            else if (strcmp(token, "UPDATE") == 0)
            {
                t->operation = 6;
            }
            else if (strcmp(token, "SET") == 0)
            {
                t->assist = 7;
            }
            else if (strcmp(token, "delete") == 0)
            {
                t->operation = 8;
            }
            else if (strcmp(token, "where") == 0)
            {
                t->condition = 9;
            }
            else if (strcmp(token, "name") == 0)
            {
                t->field = 10;
            }
            else if (strcmp(token, "mobile") == 0)
            {
                t->field = 11;
            }
            else if (strcmp(token, "address") == 0)
            {
                t->field = 12;
            }
            else if (strcmp(token, "email") == 0)
            {
                t->field = 13;
            }
            else if (strcmp(token, "skills") == 0)
            {
                t->field = 14;
            }
            else if (strcmp(token, "experience") == 0)
            {
                t->field = 15;
            }
            else if (strcmp(token, "projects_num") == 0)
            {
                t->field = 16;
            }
            else if (strcmp(token, "unique") == 0)
            {
                t->field = 17;
            }
            else if (strcmp(token, "job_role") == 0)
            {
                t->field = 18;
            }
            else if (strcmp(token, "*") == 0)
            {
                t->star = 1;
            }
            else if (strcmp(token, "applicants") == 0)
            {
                t->table = 20;
            }
            else if (strcmp(token, "employees") == 0)
            {
                t->table = 21;
            }
            // printf("here:%s\n", token);
            if (t->operation == 3 && t->star == 0 && t->assist == 4 && (t->table == 20 || t->table == 21) && t->condition == 5 && operation == 2)
            { // INSERT INTO tablename VALUES (dhruv,1234,);
                if (operation == 2 && t->table == 21)
                {
                    printf("Invalid querry\n");
                    break;
                }
                char *iname = strtok(NULL, ",");
                char *imobile = strtok(NULL, ",");
                char *iaddress = strtok(NULL, ",");
                char *iemail = strtok(NULL, ",");
                printf("seg dault?\n");
                char *iskills = strtok(NULL, ",");
                printf("seg dault2?\n");
                char *iexperience = strtok(NULL, ",");
                char *iprojects_num = strtok(NULL, ",");
                char *iunique = strtok(NULL, ",");
                char *ijob_role = strtok(NULL, ")");
                FILE *file;
                if (t->table == 20)
                {
                    file = fopen("applicants.txt", "a+");
                    if (file == NULL)
                    {
                        perror("Error opening file.");
                        return;
                    }
                }
                else if (t->table == 21)
                {
                    file = fopen("employees.txt", "a+");
                    if (file == NULL)
                    {
                        perror("Error opening file.");
                        return;
                    }
                }
                   printf("reaching here?\n");
                fprintf(file, "%d,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",
                        atoi(iunique), iname, imobile, iaddress, iemail, iskills, iexperience, iprojects_num, iunique, ijob_role);
                fclose(file);
                if (t->table == 20)
                {
                    *root = insert(r, *root, atoi(iunique), iname, imobile, iaddress, iemail, iskills, iexperience, iprojects_num, iunique, ijob_role);
                    
                    printf("The following applicant has been inserted into our database:\n\n");

                    findAndPrint(*root, atoi(iunique), 'a');
                    // printf("Vacancy:%d\n", vacancy(ijob_role, &r));
                }
                else if (t->table == 21)
                {
                    *root1 = insert(r1, *root1, atoi(iunique), iname, imobile, iaddress, iemail, iskills, iexperience, iprojects_num, iunique, ijob_role);

		    printf("The following applicant has been inserted into our database:\n\n");
                    findAndPrint(*root1, atoi(iunique), 'a');
                }
                break;
            }

            else if (t->operation == 1 && t->star == 1 && t->assist == 2 && (t->table == 20 || t->table == 21) && t->condition == 9 && t->field >= 10 && t->field <= 18 && (operation == 1 || operation == 2))
            { // SELECT * FROM tablename WHERE <field> = <value> ;
                if (t->field == 17)
                {
                    token = strtok(NULL, " ,;=()");

                    if (t->table == 20)
                        findAndPrint(*root, atoi(token), 'a');
                    else if (t->table == 21)
                        findAndPrint(*root1, atoi(token), 'a');
                }
                else if (t->field == 18)
                {
                    token = strtok(NULL, ",;=()");
                    if (t->table == 20)
                        display_role_wise(r, token, *root);
                    else if (t->table == 21)
                        display_role_wise(r1, token, *root1);
                }

                break;
            }

            else if (t->operation == 8 && t->star == 0 && t->assist == 2 && (t->table == 20 || t->table == 21) && t->condition == 9 &&
                     t->field >= 10 && t->field <= 18)
            { // DELETE FROM tablename WHERE <field>= <value>;
                token = strtok(NULL, " ,;=()");
                if (t->table == 20)
                {
                    *root = writeToFileExcludingRecord(*root, "applicants.txt", atoi(token));
                    // destroyTree(*root);
                }
                else if (t->table == 21)
                {
                    *root1 = writeToFileExcludingRecord(*root1, "employees.txt", atoi(token));
                    // printf("bp2\n");
                    // destroyTree(*root1);
                }
                // printf("bp1\n");
                FILE *file;
                if (t->table == 20)
                    file = fopen("applicants.txt", "a+");
                else if (t->table == 21)
                    file = fopen("employees.txt", "a+");
                if (file == NULL)
                {
                    perror("Error opening file.");
                    return;
                }
                int key;
                char name[100], mobile[100], address[100], email[100], skills[1000], experience[100], projects_num[100], unique[100], job_role[100];
                char line[1000];
                if (t->table == 20)
                {
                    *root = NULL;
                    int i;
                    while (i < r->numvertices)
                    {
                        free(r->vertices[i]);
                        i++;
                    }
                    free(r->max);
                    free(r->roleid);

                    init_roles(r);
                    while (fgets(line, sizeof(line), file) != NULL)
                    {
                        sscanf(line, "%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
                               &key, name, mobile, address, email, skills, experience, projects_num, unique, job_role);
                        *root = insert(r, *root, key, name, mobile, address, email, skills, experience, projects_num, unique, job_role);
                    }
                }
                else if (t->table == 21)
                {
                    *root1 = NULL;
                    r1 = NULL;
                    while (fgets(line, sizeof(line), file) != NULL)
                    {
                        sscanf(line, "%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
                               &key, name, mobile, address, email, skills, experience, projects_num, unique, job_role);
                        *root1 = insert(r1, *root1, key, name, mobile, address, email, skills, experience, projects_num, unique, job_role);
                    }
                }

                fclose(file);

                break;
            }
            token = strtok(NULL, " ,;=()");
        }
        free(t);
        free(query);

        printf("Do you wish to exit query mode? Enter 0 for no and enter 1 for yes:\n");
        scanf("%d", &end);
        while ((c = getchar()) != '\n')
            ;
    }
}
