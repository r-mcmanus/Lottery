// Lotto++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	ifstream file;
	int numberCombo[2067][6];
	int num1, num2, num3, num4, num5, megaBall;
	bool found = false;
	srand(time(0));
	file.open("mega_millions_numbers.txt");
	if (file.is_open()) {
		
		while (!file.eof())
		{
			for (int i = 0; i < 2067; i++)
				for (int j = 0; j < 6; j++)
				{
					file >> numberCombo[i][j];
				}
		}
		do {
			found = false;
			num1 = rand() % 75 + 1;
			do
				num2 = rand() % 75 + 1;
			while (num1 == num2);
			do
				num3 = rand() % 75 + 1;
			while (num3 == num1 || num3 == num2);
			do
				num4 = rand() % 75 + 1;
			while (num4 == num1 || num4 == num2 || num4 == num3);
			do
				num5 = rand() % 75 + 1;
			while (num5 == num1 || num5 == num2 || num5 == num3 || num5 == num4);
			megaBall = rand() % 15 + 1;
			/*num1 = 5; 
			num2 = 11;
			num3 = 29;     // this is for testing purposes
			num4 = 47;
			num5 = 50;
			megaBall = 17;*/
			for (int i = 0; i < 2067; i++)
			{
				if ((num1 == numberCombo[i][0] || num1 == numberCombo[i][1] ||
					num1 == numberCombo[i][2] || num1 == numberCombo[i][3] ||
					num1 == numberCombo[i][4]) && (num2 == numberCombo[i][0] || 
					num2 == numberCombo[i][1] || num2 == numberCombo[i][2] || 
					num2 == numberCombo[i][3] || num2 == numberCombo[i][4]) && 
					(num3 == numberCombo[i][0] || num3 == numberCombo[i][1] ||
					num3 == numberCombo[i][2] || num3 == numberCombo[i][3] ||
					num3 == numberCombo[i][4]) && (num4 == numberCombo[i][0] || 
					num4 == numberCombo[i][1] || num4 == numberCombo[i][2] || 
					num4 == numberCombo[i][3] || num4 == numberCombo[i][4]) && 
					(num5 == numberCombo[i][0] || num5 == numberCombo[i][1] ||
					num5 == numberCombo[i][2] || num5 == numberCombo[i][3] ||
					num5 == numberCombo[i][4]) && megaBall == numberCombo[i][5])
				{
					found = true;
				}
			}
			//cout << "infinite loop" << endl; // for testing
		} while (found);
		cout << num1 << " " << num2 << " " << num3 << " " << num4 << " " << num5 << " " << megaBall << endl;
	}
	file.close();
    return 0;
}

