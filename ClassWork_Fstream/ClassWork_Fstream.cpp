
#include <iostream>
#include <fstream>

int countCurrSymb(char obj)
{
	int count = 0;
	std::fstream ifile("ClassWork_Fstream.txt");
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
int* countTotal()
{
	int* count = new int[3]; count[0] = 0; count[1] = 0; count[2] = 0;
	std::fstream ifile("ClassWork_Fstream.txt");
	if (ifile.is_open())
	{
		char* a = new char[2]; a[1] = '\0';
		while (!ifile.eof())
		{
			ifile.get(a, 2);
			if (a[0] < 58 && a[0] > 47)
			{
				count[0] += 1;
			}
			else if (a[0] < 91 && a[0] > 64 || a[0] > 96 && a[0] < 123 || a[0] > 127 && a[0] < 176 || a[0] > 223 && a[0] < 248)
			{
				count[1] += 1;
			}
			else if (a[0] != '\0' && a[0] != '\n')
			{
				count[2] += 1;
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

int main()
{
	std::cout << "Enter symbol: ";
	char obj = '0';
	std::cin >> obj;
	std::cout << "Current symbols in file: " << countCurrSymb(obj) << '\n';
	int* arr = countTotal();
	std::cout << "Total Int in file: " << arr[0] << '\n' << "Total Alpha in file: " << arr[1] << '\n' << "Else symbols: " << arr[2] << '\n';
	delete[] arr;
}
