#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int ru(int l, int m)
{
	vector<int> cyfry;
	vector<int> reszty;
	int cyfra, reszta, okres = 0, indeks = 0;
	cout << l << " / " << m << " = ";
	cout << l / m << ".";
	reszta = l % m;

	if (reszta == 0)
	{
		cout << "0" << endl;
		return 0;
	}

	while (reszta != 0 && okres == 0)
	{
		reszta = reszta * 10;
		cyfra = reszta / m;
		reszta = reszta % m;
		cyfry.push_back(cyfra);
		vector<int>::iterator okr = find(reszty.begin(), reszty.end(), reszta);

		if (okr != reszty.end())
		{
			okres = 1;
			indeks = okr - reszty.begin();
		}
		else
		{
			okres = 0;
			reszty.push_back(reszta);
		}
	}
	if (okres != 0)
	{
		for (int i = 0; i <= indeks; i++)
			cout << cyfry[i];
		cout << "(";

		for (int i = indeks + 1; i < cyfry.size(); i++)
			cout << cyfry[i];
			cout << ")";
	}
	else
	{
		for (int i = 0; i < cyfry.size(); i++)
			cout << cyfry[i] << endl;
	}
	cout << endl;
	return 0;
}

int main()
{
	int l = 23, m = 14;
	ru(l, m);
	 l = 1, m = 86;
	ru(l, m);
	 l = 1, m = 334;
	ru(l, m);
	return 0;
}
