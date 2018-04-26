#include "stdafx.h"
#include "Tree.h"


Tree* Tree::Tree_create()
{
	Tree* node;
	node = new Tree;
	if (node == NULL)
		return NULL;
	node->ch = '\0';
	node->value = NULL;
	node->sibling = NULL;
	node->child = NULL;

	return node;
}

Tree* Tree::Tree_insert(Tree* root, char* key, char* value)
{
	Tree* node = NULL;
	Tree* parent = NULL;
	Tree* list = NULL;
	parent = NULL;
	list = root;
	for (; *key != '\0'; key++)
	{
		/* Lookup sibling node */
		for (node = list; node != NULL; node = node->sibling)
		{
			if (node->ch == *key)
				break;
		}
		if (node == NULL)
		{
			/* Node not found. Add new node */
			node = Tree_create();
			node->ch = *key;
			node->sibling = list;
			if (parent != NULL)
				parent->child = node;
			else
				root = node;
			list = NULL;
		}
		else
		{
			/* Node found. Move to next level */
			list = node->child;
		}
		parent = node;

	}
	/* Update value in leaf */
	if (node->value != NULL)
		free(node->value);
	node->value = strdup(value);

	return root;

}


void Tree::Tree_print(Tree* root, int level)
{
	Tree* node;
	int i;

	for (node = root; node != NULL; node = node->sibling)
	{
		for (i = 0; i < level; i++)
			std::cout << "  ";
		if (node->value != NULL)
		{
			std::cout << node->ch << " (" << node->value << ")" << std::endl;
		}
		else
		{
			std::cout << node->ch << " " << std::endl;
		}
		if (node->child != NULL)
			Tree_print(node->child, level + 1);
	}
}

bool Tree::compare(std::string x, std::string y)
{
	int count = 0;
	for (int i = 0; y.length() > i; i++)
	{
		if (x[i] == y[i])
			count++;
	}
	if (count == y.length())
		return true;
	else
		return false;
}


/**Search prefixs in the tree and add to the map**/
void Tree::SearchTree_T9( Tree *root, int level, std::string PartWord, std::string GPartTemp, std::map<std::string, int> *TEMP)
{
	Tree* node;
	int i;

	for (node = root; node != NULL; node = node->sibling)
	{

		std::string GPartTemp_temp = GPartTemp;
		GPartTemp = "";
		for (i = 0; i < level; i++)
		{
			GPartTemp = GPartTemp + GPartTemp_temp[i];
		}

		if (node->value != NULL)
		{
			GPartTemp = GPartTemp + node->ch;

			if (compare(GPartTemp, PartWord))
				TEMP->insert(std::pair<std::string, int>(GPartTemp, 0));
		}
		else
			GPartTemp = GPartTemp + node->ch;


		if (node->child != NULL)
			SearchTree_T9(node->child, level + 1, PartWord, GPartTemp, TEMP);

	}
}

Tree::~Tree() 
{
	delete this->sibling;
	delete this->child;;
	delete this->value;
}