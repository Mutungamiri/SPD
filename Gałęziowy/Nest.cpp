#include "Nest.h"

void Nest::read()
{
	ifstream file;
	file.open("Dane8.txt", ios::in);
	file >> n;

	tab_order=new int[n+1];
	for (int i=0; i<=n; i++)
		tab_order[i]=0;

	for(int i=1; i<=n; i++)
	{
        T[i]=0;
        file >> T[i];
	}

	for(int i=1; i<=n; i++)
	{
        M[i]=0;
        file >> M[i];
	}

	for(int i=1; i<=n; i++)
	{
        P[i]=0;
        file >> P[i];
	}

/*	for(int i=1; i<=n; i++)
	{
          tmp[i];
          file >> tmp[i];
	}*/
}

void Nest::precursors()
{
	for (int i=1; i<=n; i++)
	{
		T_P[T[i]]=i;
		M_P[M[i]]=i;
	}
}


void Nest::fillLP()
{
	for (int i=1; i<=n; i++)
	{
		LP[i]=0;
		if (T_P[i]!=0)
			LP[i]++;
		if (M_P[i]!=0)
			LP[i]++;
	}
}

void Nest::fillQueue()
{
	//vector<int> tmp;
	for (int i=1; i<=n; i++)	
	{
		if (LP[i]==0)
		{
			//if (!isThere(i))
			//{
				order.push(i);
				//tab_order[k]=i;
				//k++;
				//tmp.push_back(i);
			//}

		}
	}

	/*while(!tmp.empty())
	{
		for (int j=1; j<=n; j++)
		{
			if (T_P[j]==tmp.back() && LP[j]!=0) 
				LP[j]--;
			if (M_P[j]==tmp.back() && LP[j]!=0)
				LP[j]--;
		}
		tmp.pop_back();
	}*/
}

bool Nest::isThere(int a)
{
	for (int i=1; i<=n; i++)
		if (tab_order[i]==a)
			return true;

	return false;
}

void Nest::startAndEnd()
{
	int e;
	while(!order.empty())
	{
		e=order.front();
		C[e]=max(C[T_P[e]], C[M_P[e]])+P[e];
		order.pop();
		if (T[e]!=0 && --LP[T[e]]==0)
			order.push(T[e]);
		if (M[e]!=0 && --LP[M[e]]==0)
			order.push(M[e]);
	}
	Cmax=C[n];
	for (int i=1; i<=n; i++)
	{
		S[i]=max(C[T_P[i]], C[M_P[i]]);
		if (C[i]>Cmax)
			Cmax=C[i];
	}
}