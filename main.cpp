#include <string>
#include <iostream>
#include <vector>

bool flag=false;
int k = 0;

struct Tree
{
	std::string std;
	Tree *T1;
	Tree *T2;
	Tree *T3;
	Tree *T4;
};

void add(Tree **tree, std::string& std_)
{
	*tree = new Tree;
    (*tree)->std = std_;
}

void check(Tree** tree, std::vector <std::string>& vect)
{
	if (flag == false)
	{
		if ((*tree)->std.compare("superzub0") != 0)
		{
			int *i_s= new int;
			for (int i = 0; i < 9; i++)
			{
				if ((*tree)->std[i] == '0')
				{
					*i_s = i;
					break;
				}
			}
			if ((*i_s - 1 >= 0) && (*i_s - 1 != 2) && (*i_s - 1 != 4))
			{
				std::string *new_str = new std::string;
				(*new_str) = (*tree)->std;
				std::swap((*new_str)[*i_s], (*new_str)[*i_s - 1]);
				bool fl1 = false;
				for (std::string std : vect)
				{
					if (std.compare(*new_str) == 0){
						fl1 = true;
						break;
					}
				}
				if (fl1 == false)
				{
					add((&(*tree)->T1), *new_str);
					vect.push_back((*tree)->T1->std);
					(*new_str).clear();
					check(&((*tree)->T1), vect);
				}
			}
			if ((*i_s + 1 <= 8) && (*i_s + 1 != 3) && (*i_s + 1 != 5))
			{
				std::string *new_str = new std::string;
				(*new_str) = (*tree)->std;
				std::swap((*new_str)[*i_s], (*new_str)[*i_s + 1]);
				bool fl1 = false;
				for (std::string std : vect)
				{
					if (std.compare(*new_str) == 0){
						fl1 = true;
						break;
					}
				}
				if (fl1 == false)
				{
					add((&(*tree)->T2), *new_str);
					vect.push_back((*tree)->T2->std);
					(*new_str).clear();
					check(&((*tree)->T2), vect);
				}
			}
			if (*i_s - 3 >= 0)
			{
				std::string *new_str = new std::string;
				(*new_str) = (*tree)->std;
				std::swap((*new_str)[*i_s], (*new_str)[*i_s - 3]);
				bool fl1 = false;
				for (std::string std : vect)
				{
					if (std.compare(*new_str) == 0){
						fl1 = true;
						break;
					}
				}
				if (fl1 == false)
				{
					add((&(*tree)->T3), *new_str);
					vect.push_back((*tree)->T3->std);
					(*new_str).clear();
					check(&((*tree)->T3), vect);
				}
			}
			if (*i_s + 3 <= 8)
			{
				std::string *new_str = new std::string;
				(*new_str) = (*tree)->std;
				std::swap((*new_str)[*i_s], (*new_str)[*i_s + 3]);
				bool fl1 = false;
				for (std::string std : vect)
					{
						if (std.compare(*new_str) == 0){
							fl1 = true;
							break;
						}
					}
				if (fl1 == false)
					{
						add((&(*tree)->T4), *new_str);
						vect.push_back((*tree)->T4->std);
						(*new_str).clear();
						check(&((*tree)->T4), vect);
					}
			}
		}
		else
		{
			flag = true;
			std::cout << "Последовательность найдена!" << std::endl;
			return;
		}
	}
	else return;
}

void main()
{
	setlocale(LC_ALL, "Russian");
	Tree *tree = new Tree;
	std::vector <std::string> *broot = new std::vector <std::string>;
	std::cout << "Введите последовательность букв: ";
	std::string seq;
	std::cin >> seq;
	(*tree).std = seq;
	check(&tree, *broot);
	std::cin.get();
	std::cin.get();
}