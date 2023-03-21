
#include <iostream>
#include <fstream>

int countCurrSymb(char obj)
{
	int count = 0;
	std::fstream ifile("C:/Users/Admin/source/repos/ClassWork_Fstream/ClassWork_Fstream/ClassWork_Fstream.txt");
	if (ifile.is_open())
	{
		char* a = new char[2]; a[1] = '\0';
		while (!ifile.eof())
		{
			ifile.get(a, 2);
			if (a[0] == obj)
			{
				count++;
			}
		}
		delete[] a;
		ifile.close();
	}
	else
	{
		std::cout << "something wrong with file";
	}
	return count;
}
int countTotal()
{
	int count = 0;
	std::fstream ifile("C:/Users/Admin/source/repos/ClassWork_Fstream/ClassWork_Fstream/ClassWork_Fstream.txt");
	if (ifile.is_open())
	{
		char* a = new char[2]; a[1] = '\0';
		while (!ifile.eof())
		{
			ifile.get(a, 2);
			count++;
		}
		delete[] a;
		ifile.close();
	}
	else
	{
		std::cout << "something wrong with file";
	}
	return count;
}

int main()
{
	std::cout << "Enter symbol: ";
	char obj = '0';
	std::cin >> obj;
	std::cout << "Current symbols in file: " << countCurrSymb(obj) << '\n';
	std::cout << "Total symbols in file: " << countTotal() << '\n';
}
