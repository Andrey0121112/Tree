#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>


class Tree
{

private:
	char* value;
	char ch;
	Tree* sibling;   /* Sibling node */
	Tree* child;     /* First child node */
public:
	

	Tree *Tree_create();

	Tree *Tree_insert(Tree* root, char* key, char* value);

	void Tree_print(struct Tree*root, int level);

	bool compare(std::string x, std::string y);

	void SearchTree_T9(struct Tree *root, int level, std::string PartWord, std::string GPartTemp, std::map<std::string, int> *TEMP);
	
	void TreeDelete(Tree * root);

	~Tree();

};