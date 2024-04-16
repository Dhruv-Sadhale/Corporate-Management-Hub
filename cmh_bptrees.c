#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cmh_heap.c"


void enqueue(node *new_node)
{
    node *c;
    if (queue == NULL)
    {
        queue = new_node;
        queue->next = NULL;
    }
    else
    {
        c = queue;
        while (c->next != NULL)
        {
            c = c->next;
        }
        c->next = new_node;
        new_node->next = NULL;
    }
}

// Dequeue
node *dequeue(void)
{
    node *n = queue;
    queue = queue->next;
    n->next = NULL;
    return n;
}
void printLeaves(node *const root)
{
    if (root == NULL)
    {
        printf("Empty tree.\n");
        return;
    }
    int i;
    node *c = root;
    while (!c->is_leaf)
        c = c->pointers[0];
    while (true)
    {
        for (i = 0; i < c->num_keys; i++)
        {
            if (verbose_output)
                printf("%p ", c->pointers[i]);
            printf("%d ", c->keys[i]);
        }
        if (verbose_output)
            printf("%p ", c->pointers[order - 1]);
        if (c->pointers[order - 1] != NULL)
        {
            printf(" | ");
            c = c->pointers[order - 1];
        }
        else
            break;
    }
    printf("\n");
}

// Calculate height
int height(node *const root)
{
    int h = 0;
    node *c = root;
    while (!c->is_leaf)
    {
        c = c->pointers[0];
        h++;
    }
    return h;
}

// Get path to root
int pathToLeaves(node *const root, node *child)
{
    int length = 0;
    node *c = child;
    while (c != root)
    {
        c = c->parent;
        length++;
    }
    return length;
}

// Print the tree
void printTree(node *const root)
{
    node *n = NULL;
    int i = 0;
    int rank = 0;
    int new_rank = 0;

    if (root == NULL)
    {
        printf("Empty tree.\n");
        return;
    }
    queue = NULL;
    enqueue(root);
    while (queue != NULL)
    {
        n = dequeue();
        if (n->parent != NULL && n == n->parent->pointers[0])
        {
            new_rank = pathToLeaves(root, n);
            if (new_rank != rank)
            {
                rank = new_rank;
                printf("\n");
            }
        }
        if (verbose_output)
            printf("(%p)", n);
        for (i = 0; i < n->num_keys; i++)
        {
            if (verbose_output)
                printf("%p ", n->pointers[i]);
            printf("%d ", n->keys[i]);
        }
        if (!n->is_leaf)
            for (i = 0; i <= n->num_keys; i++)
                enqueue(n->pointers[i]);
        if (verbose_output)
        {
            if (n->is_leaf)
                printf("%p ", n->pointers[order - 1]);
            else
                printf("%p ", n->pointers[n->num_keys]);
        }
        printf("| ");
    }
    printf("\n");
}

// Find the node and print it
void findAndPrint(node *const root, int key, bool verbose)
{
    node *leaf = NULL;
    record *r = find(root, key, verbose, NULL);
    if (r == NULL)
        printf("Record not found under key %d.\n", key);
    else{
            printf("---------------------------------------------------------------------------------------------------------\n");
        printf("NAME:\t\t\t%s\nCONTACT NO.:\t\t%s\nADDRESS:\t\t%s\nEMAIL ID:\t\t%s\nSKILLS: \t\t%s\nEXPERIENCE:\t\t%s\nNUMBER OF PROJECTS:\t%s\nUNIQUE ID:\t\t%s\nJOB ROLE:\t\t%s\n\n",r->name, r->mobile, r->address, r->email, r->skills, r->experience, r->projects_num, r->unique, r->job_role);
        printf("---------------------------------------------------------------------------------------------------------\n");
	}
}
// Find and print the range
void findAndPrintRange(node *const root, int key_start, int key_end,
                       bool verbose)
{
    int i;
    int array_size = key_end - key_start + 1;
    int returned_keys[array_size];
    void *returned_pointers[array_size];
    int num_found = findRange(root, key_start, key_end, verbose,
                              returned_keys, returned_pointers);
    printf("Num_found: %d\n", num_found);
    if (!num_found)
        printf("None found.\n");
    else
    {
        for (i = 0; i < num_found; i++)
            printf("Key: %d   Location: %p\n%s,%s,%s,%s,%s,%s,%s,%s,%s\n",
                   returned_keys[i],
                   returned_pointers[i],
                   ((record *)returned_pointers[i])->name, ((record *)returned_pointers[i])->mobile, ((record *)returned_pointers[i])->address, ((record *)returned_pointers[i])->email, ((record *)returned_pointers[i])->skills, ((record *)returned_pointers[i])->experience, ((record *)returned_pointers[i])->projects_num, ((record *)returned_pointers[i])->unique, ((record *)returned_pointers[i])->job_role);
    }
}

// Find the range
int findRange(node *const root, int key_start, int key_end, bool verbose,
              int returned_keys[], void *returned_pointers[])
{
    int i, num_found;
    num_found = 0;
    node *n = findLeaf(root, key_start, verbose);
    if (n == NULL)
        return 0;
    for (i = 0; i < n->num_keys && n->keys[i] < key_start; i++)
        ;
    if (i == n->num_keys)
        return 0;
    while (n != NULL)
    {
        for (; i < n->num_keys && n->keys[i] <= key_end; i++)
        {
            returned_keys[num_found] = n->keys[i];
            returned_pointers[num_found] = n->pointers[i];
            num_found++;
        }

        n = n->next;
        if (!n)
            printf("getting NULL here\n");
        // printf("bp:%d\n",n->keys[0]);
        i = 0;
    }
    return num_found;
}

// Find the leaf
node *findLeaf(node *const root, int key, bool verbose)
{
    if (root == NULL)
    {
        if (verbose)
            printf("Empty tree.\n");
        return root;
    }
    int i = 0;
    node *c = root;
    while (!c->is_leaf)
    {
        if (verbose)
        {
            
            for (i = 0; i < c->num_keys - 1; i++)
                ;
            
        }
        i = 0;
        while (i < c->num_keys)
        {
            if (key >= c->keys[i])
                i++;
            else
                break;
        }
        
        c = (node *)c->pointers[i];
    }
    /*if (verbose)
    {
        //printf("Leaf [");
        for (i = 0; i < c->num_keys - 1; i++)
            printf("%d ", c->keys[i]);
       // printf("%d] ->\n", c->keys[i]);
    }*/
    return c;
}
record *find(node *root, int key, bool verbose, node **leaf_out)
{
    if (root == NULL)
    {
        if (leaf_out != NULL)
        {
            *leaf_out = NULL;
        }
        return NULL;
    }

    int i = 0;
    node *leaf = NULL;

    leaf = findLeaf(root, key, verbose);

    for (i = 0; i < leaf->num_keys; i++)
    {
        if (leaf->keys[i] == key)
        {
            break;
        }
    }

    if (leaf_out != NULL)
    {
        *leaf_out = leaf;
    }

    if (i == leaf->num_keys)
    {
        return NULL;
    }
    else
    {
        return (record *)leaf->pointers[i];
    }
}

int cut(int length)
{
    if (length % 2 == 0)
        return length / 2;
    else
        return length / 2 + 1;
}

record *makeRecord(char *name, char *mobile, char *address, char *email, char *skills, char *experience, char *projects_num, char *unique, char *job_role)
{
    record *record_pointer = (record *)malloc(sizeof(record));
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

    return record_pointer;
}
node *makeNode(void)
{
    node *new_node;
    new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        perror("Node creation.");
        exit(EXIT_FAILURE);
    }
    new_node->keys = malloc((order - 1) * sizeof(int));
    if (new_node->keys == NULL)
    {
        perror("New node keys array.");
        exit(EXIT_FAILURE);
    }
    new_node->pointers = malloc(order * sizeof(void *));
    if (new_node->pointers == NULL)
    {
        perror("New node pointers array.");
        exit(EXIT_FAILURE);
    }
    new_node->is_leaf = false;
    new_node->num_keys = 0;
    new_node->parent = NULL;
    new_node->next = NULL;
    return new_node;
}

node *makeLeaf(void)
{
    node *leaf = makeNode();
    leaf->is_leaf = true;
    return leaf;
}

int getLeftIndex(node *parent, node *left)
{
    int left_index = 0;
    while (left_index <= parent->num_keys &&
           parent->pointers[left_index] != left)
        left_index++;
    return left_index;
}

node *insertIntoLeaf(node *leaf, int key, record *record_pointer)
{
    int i, insertion_point;

    insertion_point = 0;
    while (insertion_point < leaf->num_keys && leaf->keys[insertion_point] < key)
        insertion_point++;

    // Shift keys and pointers to make space for the new record
    for (i = leaf->num_keys; i > insertion_point; i--)
    {
        leaf->keys[i] = leaf->keys[i - 1];
        leaf->pointers[i] = leaf->pointers[i - 1];
    }

    // Allocate memory for the new record
    leaf->pointers[insertion_point] = (record *)malloc(sizeof(record));
    if (leaf->pointers[insertion_point] == NULL)
    {
        perror("Record creation.");
        exit(EXIT_FAILURE);
    }
    //	printf("inside the insert into leaf function for the next 2 lines\n");
    // printf("%s\n", record_pointer->name);
    // Copy the data to the new record
    memcpy((record *)leaf->pointers[insertion_point], record_pointer, sizeof(record));
    // printf("%s\n", ((record*)leaf->pointers[insertion_point])->name);

    leaf->keys[insertion_point] = key;
    leaf->num_keys++;

    return leaf;
}

node *insertIntoLeafAfterSplitting(node *root, node *leaf, int key, record *record_pointer)
{
    node *new_leaf;
    int *temp_keys;
    void **temp_pointers;
    int insertion_index, split, new_key, i, j;

    new_leaf = makeLeaf();

    temp_keys = malloc(order * sizeof(int));
    if (temp_keys == NULL)
    {
        perror("Temporary keys array.");
        exit(EXIT_FAILURE);
    }

    temp_pointers = malloc(order * sizeof(void *));
    if (temp_pointers == NULL)
    {
        perror("Temporary pointers array.");
        exit(EXIT_FAILURE);
    }

    insertion_index = 0;
    while (insertion_index < order - 1 && leaf->keys[insertion_index] < key)
        insertion_index++;

    // Copy keys and pointers to temporary arrays
    for (i = 0, j = 0; i < leaf->num_keys; i++, j++)
    {
        if (j == insertion_index)
            j++;
        temp_keys[j] = leaf->keys[i];
        temp_pointers[j] = leaf->pointers[i];
    }

    // Insert the new key and record pointer
    temp_keys[insertion_index] = key;
    temp_pointers[insertion_index] = (record *)malloc(sizeof(record));
    if (temp_pointers[insertion_index] == NULL)
    {
        perror("Record creation.");
        exit(EXIT_FAILURE);
    }
    // printf("inside the insert into leaf function for the next 2 lines\n");
    // printf("%s\n", record_pointer->name);
    // Copy the data to the new record

    memcpy((record *)temp_pointers[insertion_index], record_pointer, sizeof(record));
    // printf("%s\n", ((record*)leaf->pointers[insertion_index])->name);

    leaf->num_keys = 0;

    split = cut(order - 1);

    // Copy keys and pointers to the original and new leaf nodes
    for (i = 0; i < split; i++)
    {
        leaf->pointers[i] = temp_pointers[i];
        leaf->keys[i] = temp_keys[i];
        leaf->num_keys++;
    }

    for (i = split, j = 0; i < order; i++, j++)
    {
        new_leaf->pointers[j] = temp_pointers[i];
        new_leaf->keys[j] = temp_keys[i];
        new_leaf->num_keys++;
    }

    // Update parent pointers
    new_leaf->parent = leaf->parent;
    new_key = new_leaf->keys[0];
    leaf->next = new_leaf;

    free(temp_pointers);
    free(temp_keys);

    return insertIntoParent(root, leaf, new_key, new_leaf);
}

node *insertIntoNode(node *root, node *n,
                     int left_index, int key, node *right)
{
    int i;

    for (i = n->num_keys; i > left_index; i--)
    {
        n->pointers[i + 1] = n->pointers[i];
        n->keys[i] = n->keys[i - 1];
    }
    n->pointers[left_index + 1] = right;
    n->keys[left_index] = key;
    n->num_keys++;
    return root;
}

node *insertIntoNodeAfterSplitting(node *root, node *old_node, int left_index,
                                   int key, node *right)
{
    int i, j, split, k_prime;
    node *new_node, *child;
    int *temp_keys;
    node **temp_pointers;

    temp_pointers = malloc((order + 1) * sizeof(node *));
    if (temp_pointers == NULL)
    {
        exit(EXIT_FAILURE);
    }
    temp_keys = malloc(order * sizeof(int));
    if (temp_keys == NULL)
    {
        exit(EXIT_FAILURE);
    }

    for (i = 0, j = 0; i < old_node->num_keys + 1; i++, j++)
    {
        if (j == left_index + 1)
            j++;
        temp_pointers[j] = old_node->pointers[i];
    }

    for (i = 0, j = 0; i < old_node->num_keys; i++, j++)
    {
        if (j == left_index)
            j++;
        temp_keys[j] = old_node->keys[i];
    }

    temp_pointers[left_index + 1] = right;
    temp_keys[left_index] = key;

    split = cut(order);
    new_node = makeNode();
    old_node->num_keys = 0;
    for (i = 0; i < split - 1; i++)
    {
        old_node->pointers[i] = temp_pointers[i];
        old_node->keys[i] = temp_keys[i];
        old_node->num_keys++;
    }
    old_node->pointers[i] = temp_pointers[i];
    k_prime = temp_keys[split - 1];
    for (++i, j = 0; i < order; i++, j++)
    {
        new_node->pointers[j] = temp_pointers[i];
        new_node->keys[j] = temp_keys[i];
        new_node->num_keys++;
    }
    new_node->pointers[j] = temp_pointers[i];
    free(temp_pointers);
    free(temp_keys);
    new_node->parent = old_node->parent;
    for (i = 0; i <= new_node->num_keys; i++)
    {
        child = new_node->pointers[i];
        child->parent = new_node;
    }

    return insertIntoParent(root, old_node, k_prime, new_node);
}

node *insertIntoParent(node *root, node *left, int key, node *right)
{
    int left_index;
    node *parent;

    parent = left->parent;

    if (parent == NULL)
        return insertIntoNewRoot(left, key, right);

    left_index = getLeftIndex(parent, left);

    if (parent->num_keys < order - 1)
        return insertIntoNode(root, parent, left_index, key, right);

    return insertIntoNodeAfterSplitting(root, parent, left_index, key, right);
}

node *insertIntoNewRoot(node *left, int key, node *right)
{
    node *root = makeNode();
    root->keys[0] = key;
    root->pointers[0] = left;
    root->pointers[1] = right;
    root->num_keys++;
    root->parent = NULL;
    left->parent = root;
    right->parent = root;
    return root;
}

node *startNewTree(int key, record *pointer)
{
    node *root = makeLeaf();
    root->keys[0] = key;
    root->pointers[0] = pointer;
    root->pointers[order - 1] = NULL;
    root->parent = NULL;
    root->next = NULL;
    root->num_keys++;
    return root;
}

void destroyTree(node *root)
{
    printf("reacing in destroying tree method?\n");
    if (root == NULL)
    {
        return;
    }

    if (!root->is_leaf)
    {
        for (int i = 0; i <= root->num_keys; i++)
        {
            destroyTree(root->pointers[i]);
        }
    }

    for (int i = 0; i < root->num_keys; i++)
    {
        free(root->pointers[i]); // Free memory allocated for records in leaf nodes
    }

    free(root->keys);
    free(root->pointers);
    free(root);
}
