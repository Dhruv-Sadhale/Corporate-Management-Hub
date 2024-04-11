#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 52
#define NumSkills 

typedef struct trieNode{
	struct trieNode * arr[SIZE];
	bool isEndOfWord;
}trieNode;

trieNode * createNode(){
	trieNode * nn;
	nn = (trieNode *)malloc(sizeof(trieNode));
	if(nn){
		nn -> isEndOfWord = false;
		for(int i = 0; i < SIZE; i++){
			nn -> arr[i] = NULL;
		}
	}
	return nn;
}

void insert_trie(trieNode * t, char * c){
	trieNode * p = t;
	int len = strlen(c);
	for(int i = 0; i < len; i++){
		int index = c[i] - 'a';
		if(p -> arr[index] == NULL){
			p -> arr[index] = createNode();
		}
		p = p -> arr[index];
	}
	p -> isEndOfWord = true;
	return;
}

bool search(trieNode * t, char * c){
	trieNode * p = t;
	int len = strlen(c);
	for(int i = 0; i < len; i++){
		int index = c[i] - 'a';
		if(p -> arr[index] == NULL) return false;
		p = p -> arr[index];
	}
	if(p != NULL && p -> isEndOfWord) return true;
	else return false;
}
/*
trieNode * createTrie(char * skills[NumSkills]){
	
}
*/
int main(){
	trieNode * ceo = createNode();
	insert_trie(ceo, "C");
	insert_trie(ceo, "Java");
	/*insert(trie, "this");
	insert(trie, "is");
	insert(trie, "project");
	printf("Is the word 'hello' present?");*/
	if (search(ceo, "Java")) printf("Yes\n");
	else printf("No\n");
	
	return 0;
} 

