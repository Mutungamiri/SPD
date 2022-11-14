#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <queue>

using namespace std;

struct Quest
{
public:
	int r,p,q;
	int task_number;
	int l;
};

struct Nset
{
	bool operator()(Quest& a, Quest& b)
	{
		return a.r > b.r;
	}
};

struct Gset
{
	bool operator()(Quest& a, Quest& b)
	{
		return a.q < b.q;
	}
};

istream& operator >> (istream& enter, Quest& request)
{
	enter >> request.r >> request.p >> request.q;
	return enter;
}

ostream& operator << (ostream& exit, Quest& request)
{
	cout << request.r << " " << request.p << " " << request.q << endl;
	return exit;
}

Quest* Read(int n, int number_of_tasks, Quest* tab);
Quest* Sort(int number_of_tasks, Quest *tab);
void Display(int number_of_tasks, Quest *tab);


int main()
{
	Quest *tab;
	int n;
	int number_of_tasks;
	int Cmax=0;
	int t=0;
	tab=Read(n, number_of_tasks, tab);
	number_of_tasks=tab[0].r;
	tab[0].r=0;
	Quest l,e; //aktualnie wykonywane zadanie

	//Display(number_of_tasks, tab);
	priority_queue<Quest,vector<Quest>,Nset> N;
	priority_queue<Quest,vector<Quest>,Gset> G;

  l.q=1000;
 // l.p=0;
	for (int i=1; i<number_of_tasks; i++)
	{
		N.push(tab[i]);
	}

	while(!G.empty() || !N.empty())
   {

		while (!N.empty() && N.top().r<=t)
		{
		     e=N.top();
		     G.push(e); // zadanie zaczyna siê wykonywaæ
		     N.pop();
               if(e.q > l.q)
               {
                    l.p=t-e.r;
                    t=e.r;
                    if(l.p > 0)
                    {
                         G.push(l);
                    }
               }
		}

		if(G.empty())
			t=N.top().r;
		else
		{
		     e=G.top();
		     G.pop();
		     l=e;
			t=t+e.p;
			Cmax=max(Cmax, t+e.q);

		}
   }

	cout << "cmax " << Cmax << endl;
	return 0;
}


Quest* Read(int n, int number_of_tasks, Quest* tab)
{
	ifstream file;
	file.open( "SCHRAGE8.DAT", ios::in);
	file >> n;
	tab=new Quest[n+1];
	number_of_tasks=n+1;
	for(int i=1;i<=n;i++)
	    file >> tab[i];
	file.close();
	tab[0].r=number_of_tasks;
	return tab;
}

Quest* Sort(int number_of_tasks, Quest *tab)
{
	for( int i = 0; i < number_of_tasks; i++ )
		for(int j=0; j<number_of_tasks-1; j++)
			if( tab[j].r > tab[j+1].r )
				swap(tab[j], tab[j+1]);
	return tab;
}

void Display(int number_of_tasks, Quest *tab)
{
	for(int i=1;i<number_of_tasks;i++)
		cout << tab[i];
}
