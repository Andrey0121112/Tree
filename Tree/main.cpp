#include "stdafx.h"
#include <conio.h>

#include <iostream>
#include <string>
#include <fstream>
#include <map>

#include "Tree.h"


void seeMap(std::map<std::string,int> *TEMP)
{
	for (auto it = TEMP->begin(); it != TEMP->end(); ++it)
	{
		std::cout << it->first << std::endl;     // " : " << it->second << endl;
	}
}

int main()
{
	
	Tree* root;
	std::string PathToFile("d:\\TextTemp.txt");
	std::ifstream File(PathToFile);				

	if (!File)
	{
		std::cout << "File don't open...!\n";
		return NULL;
	}
	else
	{
		char  FileData[20];
		bool keyFirst = false;
		
		for (File >> FileData; !File.eof(); File >> FileData)
		{
			
			if (keyFirst == false)
			{
				keyFirst = true;
					root = root->Tree_insert(NULL, FileData, "50" );
			}
			else
				root = root->Tree_insert(root, FileData, "50" );
		
			
		}

		File.close();
	}


	std::map <std::string, int> *MapRes = new std::map<std::string, int>;
	std::string GPartTemp;

	std::string PartWord;

	while (1)
		{	
			root->Tree_print(root, 0);    
			
			std::cout << " .............. :";
			std::cin >> PartWord;
			
			root->SearchTree_T9(root, 0, PartWord, GPartTemp, MapRes);
			seeMap(MapRes);
			
			system("pause");
			system("cls");
			MapRes->clear();
		}

	root->~Tree();
	return NULL;
}	