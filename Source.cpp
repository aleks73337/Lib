#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
int k = 0;

int hash_func(std::string& str, int tryi)
{
	k++;
	std::hash<std::string> hash_fn;
	size_t hash = hash_fn(str);
	int a = (hash*tryi+k) % 2000;
	return(a);
}

void addHash(std::string& str, std::string **hash,int tryi)
{
	int numHash = hash_func(str, tryi);
	if ((*hash)[numHash].empty())
	{
		(*hash)[numHash]=str;
		return;
	}
	else
	{
		addHash(str, hash, tryi+=1);
	}
}

std::string findWord(std::string str, std::string **hash,int tryi)
{
	if (tryi == 3000) return("Нет слова");
	if ((*hash)[hash_func(str,tryi)]==str)
	{
			std::string vect;
			vect += "Yes ";
			return(vect);
	}
	else
	{
		return findWord(str, hash, tryi +=1);
	}
}

void main()
{
	setlocale(LC_ALL, "rus");
	std::string *hash = new std::string[2000];
	char mass[1000];
	std::string stringMass;
	std::ifstream fcin("words_alpha.txt");
	for (int k = 1; k < 1000;k++)
	{
		//std::cout << "Print the word: " << std::endl;
		fcin >> mass;
		//std::cout << std::string(mass) << std::endl;
		//stringMass = std::string(mass);
		addHash(std::string(mass), &hash, 1);
		//std::cout << "Element has been added" << std::endl;
	}
	std::cout << "Кол-во коллизий: "<<k<<std::endl<<"Введите нужное слово: ";
	std::cin >> stringMass;
	std::cout << findWord(stringMass, &hash, 1);
	std::cin.get();
	delete[] hash;
}