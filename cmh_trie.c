#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cmh_headers.h"


trieNode *createNode()
{
    trieNode *nn;
    nn = (trieNode *)malloc(sizeof(trieNode));
    if (nn)
    {
        nn->isEndOfWord = false;
        for (int i = 0; i < SIZE; i++)
        {
            nn->arr[i] = NULL;
        }
    }
    return nn;
}

void insert_trie(trieNode *t, char *c)
{
    trieNode *p = t;
    int len = strlen(c);
    for (int i = 0; i < len; i++)
    {
        int index;
        if (c[i] >= 'a' && c[i] <= 'z')
            index = c[i] - 'a';
        else if (c[i] >= 'A' && c[i] <= 'Z')
            index = c[i] - 'A' + 26;
        else if (c[i] == ' ')
            index = 52;
        if (p->arr[index] == NULL)
        {
            p->arr[index] = createNode();
        }
        p = p->arr[index];
    }
    p->isEndOfWord = true;
    return;
}

bool search(trieNode *t, char *c)
{
    trieNode *p = t;
    int len = strlen(c);
    for (int i = 0; i < len; i++)
    {
        int index;
        if (c[i] >= 'a' && c[i] <= 'z')
            index = c[i] - 'a';
        else if (c[i] >= 'A' && c[i] <= 'Z')
            index = c[i] - 'A' + 26;
        else if (c[i] == ' ')
            index = 52;
        if (p->arr[index] == NULL)
            return false;
        p = p->arr[index];
    }
    if (p != NULL && p->isEndOfWord)
        return true;
    else
        return false;
}

trieNode *fill_trie(int i)
{
    trieNode *t = createNode();
    switch (i)
    {
    case 0: // CEO
        insert_trie(t, "Strategic Planning");
        insert_trie(t, "Leadership Development");
        insert_trie(t, "Financial Management");
        insert_trie(t, "Decision Making");
        insert_trie(t, "Public Speaking");
        break;
    case 1: // CTO
        insert_trie(t, "Software Development");
        insert_trie(t, "Project Management");
        insert_trie(t, "Technology Innovation");
        insert_trie(t, "Team Leadership");
        insert_trie(t, "Cloud Computing");
        break;
    case 2: // VP of Engineering
        insert_trie(t, "Software Architecture");
        insert_trie(t, "Agile Methodologies");
        insert_trie(t, "Technical Leadership");
        insert_trie(t, "System Design");
        insert_trie(t, "Continuous Integration or Continuous Deployment");
        break;
    case 3: // Chief Architect
        insert_trie(t, "Enterprise Architecture");
        insert_trie(t, "Solution Design");
        insert_trie(t, "Scalability Planning");
        insert_trie(t, "System Integration");
        insert_trie(t, "API Design");
        break;
    case 4: // Technical Lead
        insert_trie(t, "Software Design Patterns");
        insert_trie(t, "Code Review");
        insert_trie(t, "Mentoring and Coaching");
        insert_trie(t, "Technical Documentation");
        insert_trie(t, "Problem Solving");
        break;
    case 5://Principal Software Engineer
        insert_trie(t, "Software Architecture");
        insert_trie(t, "System Design");
        insert_trie(t, "Object Oriented Programming");
        insert_trie(t, "Test Driven Development");
        insert_trie(t, "Debugging");
        break;
    case 6: // Senior Software Engineer
        insert_trie(t, "Object Oriented Programming");
        insert_trie(t, "Test Driven Development");
        insert_trie(t, "Version Control");
        insert_trie(t, "Debugging");
        insert_trie(t, "Software Optimization");
        break;
    case 7: // VP of Marketing
        insert_trie(t, "Digital Marketing Strategy");
        insert_trie(t, "Brand Management");
        insert_trie(t, "Market Research");
        insert_trie(t, "Campaign Management");
        insert_trie(t, "Content Marketing");
        break;
    case 8: // Product Manager
        insert_trie(t, "Product Lifecycle Management");
        insert_trie(t, "User Experience Design");
        insert_trie(t, "Market Analysis");
        insert_trie(t, "Product Roadmapping");
        insert_trie(t, "Agile Product Development");
        break;
    case 9: // HR Director
        insert_trie(t, "Talent Acquisition");
        insert_trie(t, "Employee Relations");
        insert_trie(t, "Performance Management");
        insert_trie(t, "Diversity and Inclusion");
        insert_trie(t, "HR Compliance");
        break;
    case 10: // Recruiting Director
        insert_trie(t, "Candidate Sourcing");
        insert_trie(t, "Interviewing Techniques");
        insert_trie(t, "Recruitment Metrics Analysis");
        insert_trie(t, "Employer Branding");
        insert_trie(t, "Applicant Tracking Systems");
        break;
    }

    return t;
}
