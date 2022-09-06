#include<iostream>
#include<windows.h>
#include<vector>

using namespace std;
void copying(vector<vector<vector<int>>> a, vector<vector<vector<int>>> b)
{
	vector <vector<vector<int>>> c(a.begin(), a.end());
	b = c;
}
void see(vector<vector<vector<int>>> a)
{
	for (size_t i = 0; i < a.size(); i++)
	{
		for (size_t j = 0; j < a[i].size(); j++)
		{
			for (size_t g = 0; g < a[i][j].size(); g++)
			{
				cout << a[i][j][g] << " ";
			}
			cout << endl;
		}
		cout << "\n\n";
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));

	int command = 0;
	int x = 0, y=0;
	bool t = true;
	vector<vector<int>> a;
	vector<int> b;
	vector<vector<vector<int>>> MVector;

	while (true)
	{
		t = true;
		b = {};
		a = { {} };
		x = 0; 
		y = 0;
		cout << "\nМеню:\n"
			<< "1 - додати матрицю\n"
			<< "2 - знайти суму всіх матриць\n" // просто знаходиться сумe всіх чисел матриць
			<< "3 - додати одну матрицю до іншої\n"
			<< "4 - побачити усі матриці\n"
			<< "5 - заповнити матриці\n";
		cin >> command;

		if (command == 1)
		{
			cout << "Введіть кількість стовбців матриці:	";
			cin >> x;
			try
			{
				if ( x <= 0 )
				{
					throw"ERROR";
				}
			}
			catch (...)
			{
				cout << "\nНеправильно заданий номер матриці. Прошу ввести знову номер.\n";
			}

			b.resize(x, 0);

			cout << "Введіть кількість рядків матриці:	";
			cin >> x;
			try
			{
				if (x <= 0)
				{
					throw"ERROR";
				}
			}
			catch (...)
			{
				cout << "\nНеправильно заданий номер матриці. Прошу ввести знову номер.\n";
			}
			a.resize(x + 1,b);
			MVector.push_back(a);
		}
		else if (command == 2)
		{
			y = 0;
			for (size_t i = 0; i < MVector.size(); i++)
			{
				for (size_t j = 0; j < MVector[i].size(); j++)
				{
					for (size_t g = 0; g < MVector[i][j].size(); g++)
					{
						y += MVector[i][j][g];
					}
				}
			}
			cout << "\nсума = " << y;
		}
		else if (command == 3)
		{
				cout << "Введіть номер матриці, яку хочете додати:	";
				cin >> x;
				cout << "Введіть номер матриці, до якої хочете додати:	";
				cin >> y;
				try {


					for (size_t i = 0; i < MVector[x].size(); i++)
					{
						for (size_t j = 0; j < MVector[x][i].size(); j++)
						{
							MVector[y][i][j] = MVector[x][i][j];
						}
					}
				}
				catch (...) {
					cout << "Ви ввели номер неіснуючої матриці.";
				}
		}
		else if (command == 4)
		{
			see(MVector);
		}
		else if (command == 5)
		{
			cout << "\nВведіть номер матрицю, яку бажаєте заповнити:	";
			cin >> x;
			try {
				for (size_t i = 0; i < MVector[x].size(); i++)
				{
					for (size_t j = 0; j < MVector[x][i].size(); j++)
					{
						MVector[x][i][j] = rand() % 11;
					}
				}
			}
			catch (...) {
				cout << "Ви ввели номер неіснуючої матриці.";
			}
		}
		else
		{
			cout << "\n\nНевідома команда\n\n";
		}
	}
}
		