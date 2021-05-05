#pragma once
#include <string>
#include <iostream>
#include <time.h>

struct Tree_Item {
public:
	int inf;
	Tree_Item* left;
	Tree_Item* right;
};


void AddNodes(Tree_Item*& pCurrent, int N) {
	if (N <= 0) { pCurrent = NULL;}
	else {
		Tree_Item* pTemp;
		int N_left, N_right;
		N_left = N / 2;
		N_right = N - N_left - 1;
		pTemp = new Tree_Item();
		pTemp->inf = rand() % 100;
		AddNodes(pTemp->left, N_left);
		AddNodes(pTemp->right, N_right);
		pCurrent = pTemp;
	}
}

void Preorder_traversal(int t, std::string& str, Tree_Item* pCurrent) {
	if (pCurrent != NULL) {
		std::string line = "";
		for (int i = 0; i < t; i++) line += "\t";
		line = line + std::to_string(pCurrent->inf);
		str = str + line + "\n";
		Preorder_traversal(t + 1, str, pCurrent->left);
		Preorder_traversal(t + 1, str, pCurrent->right);
	}
}

void Inorder_traversal(int t, std::string& str, Tree_Item* pCurrent) {
	if (pCurrent != NULL) {
		Inorder_traversal(t + 1, str, pCurrent->left);
		std::string line = "";
		for (int i = 0; i < t; i++) line += "\t";
		line = line + std::to_string(pCurrent->inf);
		str = str + line + "\n";
		Inorder_traversal(t + 1, str, pCurrent->right);
	}
}

void Preorder_Inorder_traversal(int t, std::string& str, Tree_Item* pCurrent) {
	if (pCurrent != NULL) {
		Preorder_Inorder_traversal(t + 1, str, pCurrent->right);
		std::string line = "";
		for (int i = 0; i < t; i++) line += "\t";
		line = line + std::to_string(pCurrent->inf);
		str = str + line + "\n";
		Preorder_Inorder_traversal(t + 1, str, pCurrent->left);
	}
}