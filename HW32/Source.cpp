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
		cout << "\n����:\n"
			<< "1 - ������ �������\n"
			<< "2 - ������ ���� ��� �������\n" // ������ ����������� ���e ��� ����� �������
			<< "3 - ������ ���� ������� �� ����\n"
			<< "4 - �������� �� �������\n"
			<< "5 - ��������� �������\n";
		cin >> command;

		if (command == 1)
		{
			cout << "������ ������� �������� �������:	";
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
				cout << "\n����������� ������� ����� �������. ����� ������ ����� �����.\n";
			}

			b.resize(x, 0);

			cout << "������ ������� ����� �������:	";
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
				cout << "\n����������� ������� ����� �������. ����� ������ ����� �����.\n";
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
			cout << "\n���� = " << y;
		}
		else if (command == 3)
		{
				cout << "������ ����� �������, ��� ������ ������:	";
				cin >> x;
				cout << "������ ����� �������, �� ��� ������ ������:	";
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
					cout << "�� ����� ����� �������� �������.";
				}
		}
		else if (command == 4)
		{
			see(MVector);
		}
		else if (command == 5)
		{
			cout << "\n������ ����� �������, ��� ������ ���������:	";
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
				cout << "�� ����� ����� �������� �������.";
			}
		}
		else
		{
			cout << "\n\n������� �������\n\n";
		}
	}
}
		