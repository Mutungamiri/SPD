#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <queue>
#include <vector>
#include "Carlier.h"

using namespace std;



int main()
{
	int n;
	Carlier ob;
	ob.Read();
	ob.Sort();
	//ob.Display();
	//ob.Schrage_without();
	//ob.Schrage_with();
	

     cout << "U: " << ob.carlier() << endl;
	return 0;
}

