#include "Nest.h"


using namespace std;

int main()
{
    Nest ob;
    ob.read();
    ob.precursors();
	ob.fillLP();
    //do
    //{
    	ob.fillQueue();
    //}
    //while(ob.order.size()!=ob.n);
    ob.startAndEnd();
    for (int i=1; i<=ob.n; i++)
    	cout << ob.S[i] << " " << ob.C[i] << endl;;
    cout << ob.Cmax << endl;
	
    return 0;
}
