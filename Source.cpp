#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>

int k = 0;

int hash_func(const std::string& str)
{
	long a = 0;
	for (int i = 0; i<str.length(); i++)
	{
		a += (int)str[i]*i;
	}
	a = a % 50;
	return(a % 50);
}

std::string addHash(std::string &str,std::vector<std::string> **hash)
{
	if (!(*hash)[hash_func(str)].empty()){ k++; }
	(*hash)[hash_func(str)].push_back(str);
	std::cout << (*hash)[hash_func(str)].size();
	return(str);
}

std::string findWord(const std::string &str, std::vector<std::string> **hash)
{
	int i = 0;
	std::string vect;
	for (std::string element : (*hash)[hash_func(str)])
	{
		i++;
		if (element == str)
		{
			
			vect = std::to_string(i);
			vect += " Yes ";
			
		}
	}
	return(vect);
}

void main()
{
	std::vector<std::string> *hash = new std::vector<std::string>[50];
	std::string str="asd";
	while (str != "0")
	{
		std::cout << "Print the word: " << std::endl;
		std::getline(std::cin, str);
		str=addHash(str,&hash);
		std::cout << " element has been added" << std::endl;
	}
	std::cout << "Number of cozziliy="<<k<<std::endl;
	std::cout << findWord("123", &hash);
	std::cin.get();
	delete[] hash;
}