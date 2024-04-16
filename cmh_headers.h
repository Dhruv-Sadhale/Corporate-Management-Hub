

#define SIZE 53
#define NumSkills

// Default order
#define ORDER 5
#define ROLE_SIZE 11
typedef struct record
{
    char *name;
    char *mobile;
    char *address;
    char *email;
    char *skills;
    char *experience;
    char *projects_num;
    char *unique;
    char *job_role;
} record;
typedef struct trieNode
{
    struct trieNode *arr[SIZE];
    bool isEndOfWord;
} trieNode;
typedef struct tokens
{
    int operation;
    int assist;
    int condition;
    int field;
    int table;
    int star;
} tokens;

typedef struct rolenode
{
    record *recptr;
    struct rolenode *next;
} rolenode;
typedef struct roles
{
    rolenode **vertices;
    int *roleid;
    int *max;
    int numvertices;
} roles;
// Node
typedef struct node
{
    void **pointers;
    int *keys;
    struct node *parent;
    bool is_leaf;
    int num_keys;
    struct node *next;
} node;

typedef struct priority
{
    int unique_no;
    int counter;
    record *ptr;
} priority;

typedef struct Heap
{
    priority *arr;
    int size;
    int rear;
} Heap;
int order = ORDER;
node *queue = NULL;
bool verbose_output = false;

void initHeap(Heap *h, int size);

void swap(priority *a, priority *b);

int isEmpty(Heap *h);

int isFull(Heap *h);

void HeapSort(priority arr[], int size);

void insert_heap(Heap *h, int uqn, int coun, record *ptr);

priority *Remove(Heap *h);

void heapify(Heap *h, int index);

// Enqueue
void enqueue(node *new_node);

// Dequeue
node *dequeue(void);
int height(node *const root);
int pathToLeaves(node *const root, node *child);
void printLeaves(node *const root);
void printTree(node *const root);
void findAndPrint(node *const root, int key, bool verbose);
void findAndPrintRange(node *const root, int range1, int range2, bool verbose);
int findRange(node *const root, int key_start, int key_end, bool verbose,
              int returned_keys[], void *returned_pointers[]);
node *findLeaf(node *const root, int key, bool verbose);
record *find(node *root, int key, bool verbose, node **leaf_out);
int cut(int length);

record *makeRecord(char *name, char *mobile, char *address, char *email, char *skills, char *experience, char *projects_num, char *unique, char *job_role); // updated
node *makeNode(void);
node *makeLeaf(void);
int getLeftIndex(node *parent, node *left);
node *insertIntoLeaf(node *leaf, int key, record *pointer);
node *insertIntoLeafAfterSplitting(node *root, node *leaf, int key,
                                   record *pointer);
node *insertIntoNode(node *root, node *parent,
                     int left_index, int key, node *right);
node *insertIntoNodeAfterSplitting(node *root, node *parent,
                                   int left_index,
                                   int key, node *right);
node *insertIntoParent(node *root, node *left, int key, node *right);
node *insertIntoNewRoot(node *left, int key, node *right);
node *startNewTree(int key, record *pointer);
node *insert(roles *ptr, node *root, int key, char *name, char *mobile, char *address, char *email, char *skills, char *experience, char *projects_num, char *unique, char *job_role);
void init_roles(roles *ptr);
node *writeToFileExcludingRecord(node *root, const char *filename, int keyToExclude);
void writeLeafNodesExcludingRecord(node *node, FILE *file, int keyToExclude);
void sql(roles *r, roles *r1, node **root, node **root1, int operation);
void insert_role(roles **ptr, record *recptr);
void selection_process(node **root, node **root1, roles *r, roles *r1, char *check);
int get_role_code2(char *job_role);
int vacancy(char *job_role, roles *r);
int get_role_code(record *recptr);
rolenode *create_role_node(record **recptr);
void init_roles(roles *ptr);
