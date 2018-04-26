#include "stdafx.h"
#include "Tree.h"


Tree* Tree::Tree_create()
{
	Tree* node;
	node = new Tree;
	if (node == nullptr)
		return nullptr;
	node->ch = '\0';
	node->value = nullptr;
	node->sibling = nullptr;
	node->child = nullptr;

	return node;
}

Tree* Tree::Tree_insert(Tree* root, char* key, char* value)
{
	Tree* node = nullptr;
	Tree* parent = nullptr;
	Tree* list = nullptr;
	//parent = NULL;
	list = root;
	for (; *key != '\0'; key++)
	{
		/* Lookup sibling node */
		for (node = list; node != nullptr; node = node->sibling)
		{
			if (node->ch == *key)
				break;
		}
		if (node == nullptr)
		{
			/* Node not found. Add new node */
			node = Tree_create();
			node->ch = *key;
			node->sibling = list;
			if (parent != nullptr)
				parent->child = node;
			else
				root = node;
			list = nullptr;
		}
		else
		{
			/* Node found. Move to next level */
			list = node->child;
		}
		parent = node;

	}
	/* Update value in leaf */
	if (node->value != nullptr)
		free(node->value);
	node->value = strdup(value);

	return root;

}


void Tree::Tree_print(Tree* root, int level)
{
	Tree* node;
	int i;

	for (node = root; node != nullptr; node = node->sibling)
	{
		for (i = 0; i < level; i++)
			std::cout << "  ";
		if (node->value != nullptr)
		{
			std::cout << node->ch << " (" << node->value << ")" << std::endl;
		}
		else
		{
			std::cout << node->ch << " " << std::endl;
		}
		if (node->child != nullptr)
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

	for (node = root; node != nullptr; node = node->sibling)
	{

		std::string GPartTemp_temp = GPartTemp;
		GPartTemp = "";
		for (i = 0; i < level; i++)
		{
			GPartTemp = GPartTemp + GPartTemp_temp[i];
		}

		if (node->value != nullptr)
		{
			GPartTemp = GPartTemp + node->ch;

			if (compare(GPartTemp, PartWord))
				TEMP->insert(std::pair<std::string, int>(GPartTemp, 0));
		}
		else
			GPartTemp = GPartTemp + node->ch;


		if (node->child != nullptr)
			SearchTree_T9(node->child, level + 1, PartWord, GPartTemp, TEMP);

	}
}

void Tree::TreeDelete(Tree * root)
{
	delete root;
}

Tree::~Tree()
{
	delete this->child;
	delete this->sibling;
	delete this->value;
}