#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

// Trie node structure
typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
} TrieNode;

// Function to create a new trie node
TrieNode* createNode() {
    TrieNode* newNode = (TrieNode*)malloc(sizeof(TrieNode));
    if (newNode) {
        newNode->isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            newNode->children[i] = NULL;
        }
    }
    return newNode;
}

// Function to insert a word into the trie
void insertWord(TrieNode* root, const char* word) {
    TrieNode* currentNode = root;
    int length = strlen(word);
    for (int i = 0; i < length; i++) {
        int index = word[i] - 'a';
        if (!currentNode->children[index]) {
            currentNode->children[index] = createNode();
        }
        currentNode = currentNode->children[index];
    }
    currentNode->isEndOfWord = true;
}

// Function to search for a word in the trie
bool searchWord(TrieNode* root, const char* word) {
    TrieNode* currentNode = root;
    int length = strlen(word);
    for (int i = 0; i < length; i++) {
        int index = word[i] - 'a';
        if (!currentNode->children[index]) {
            return false;
        }
        currentNode = currentNode->children[index];
    }
    return (currentNode != NULL && currentNode->isEndOfWord);
}

// Function to tokenize the resume text into sections based on subtitles
// and insert skills into trie
void parseResumeAndInsertSkills(TrieNode* root, const char* resumeText) {
    char* token;
    char* rest = (char*)malloc(strlen(resumeText) + 1);
    strcpy(rest, resumeText);

    // Tokenize based on newline character assuming each subtitle is in a new line
    token = strtok(rest, "\n");
    while (token != NULL) {
        // Assuming subtitles are followed by a colon (e.g., "Skills:")
        char* subtitle = strtok(token, ":");
        if (subtitle != NULL && strcmp(subtitle, "Skills") == 0) {
            // Extract skills and insert into trie
            char* skillsText = strtok(NULL, ":");
            char* skill = strtok(skillsText, ",");
            while (skill != NULL) {
                // Trim leading and trailing spaces from skill
                while (*skill == ' ') {
                    skill++;
                }
                int len = strlen(skill);
                while (len > 0 && skill[len - 1] == ' ') {
                    skill[len - 1] = '\0';
                    len--;
                }
                // Insert skill into trie
                insertWord(root, skill);
                skill = strtok(NULL, ",");
            }
        }
        token = strtok(NULL, "\n");
    }
    free(rest);
}

int main() {
    // Example usage
    TrieNode* root = createNode();

    // Parse resume text and insert skills into trie
    char resumeText[] = "Name: John Doe\nSkills: C, C++, Python, Java\nExperience: XYZ Corp, ABC Inc";
    parseResumeAndInsertSkills(root, resumeText);

    // Search for skills in the trie
    printf("Searching for 'C' skill: %s\n", searchWord(root, "C") ? "Found" : "Not Found");
    printf("Searching for 'Java' skill: %s\n", searchWord(root, "Java") ? "Found" : "Not Found");

    // Free memory
    // Add function to free trie nodes if needed

    return 0;
}

