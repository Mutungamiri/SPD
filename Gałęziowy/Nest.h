#pragma once
#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
#include <vector>

#define INT_MAX 100000

using namespace std;

class Nest
{
public:

	int n,m;
	queue<int> order;
	int *tab_order;
    int T[INT_MAX];
    int M[INT_MAX];
    int T_P[INT_MAX];
    int M_P[INT_MAX];
    int P[INT_MAX];
    //int tmp[INT_MAX]; //moim zdaniem niepotrzebne
    int C[INT_MAX];
    int S[INT_MAX];
    int LP[INT_MAX];
    int k=1;

    int Cmax;

    void read();
    void precursors();
    void fillLP();
    void fillQueue();
    bool isThere(int a);
    void startAndEnd();

};