#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<malloc.h>

#define SIZE 11
#define NIL 0

struct Trie{
	int isEnd;
	int Count;
	Trie* child[SIZE];
};

Trie* createTrie(){
	Trie* node;
	node = (Trie*)malloc(sizeof(Trie));
	node->Count = 0;
	node->isEnd = 0;
	for (int i = 0; i < SIZE; i++){
		node->child[i] = NIL;
	}
	return node;
}

void insertTrie(Trie* root, char *text){
	int index;
	for (int i = 0; text[i]; i++){
		index = text[i] - '0';
		if (root->child[index] == NIL){
			root->child[index] = createTrie();
		}
		root = root->child[index];
	}
	root->isEnd = 1;
	root->Count++;
}

int searchTrie(Trie* root, char *text){
	int index;
	for (int i = 0; text[i]; i++){
		index = text[i] - '0';
		if (root->child[index] == NIL){
			return 0;
		}
		
		root = root->child[index];
		if (root->isEnd == 1 && root->Count == 1){
			return 1;
		}
	}
	return 0;
}


int main(){
	int TC, N;
	int Flag;
	char number[SIZE];
	freopen("input.txt", "r", stdin);
	scanf("%d", &TC);
	for (int testcase = 0; testcase < TC; testcase++){
		Trie *root;
		root = createTrie();
		Flag = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++){
			scanf("%s", number);
			int ret = searchTrie(root, number);
			if (ret){
				Flag = 1;
			}
			else{
				insertTrie(root, number);
			}
		}
		if (Flag)
			printf("NO\n");
		else
			printf("YES\n");
	}
}
