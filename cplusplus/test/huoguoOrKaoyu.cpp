#include <iostream>
#include <stdio.h>
#include <time.h>
#include <algorithm>
using namespace std;

int main() {
	srand((unsigned)time(NULL));
	int a = rand();
	if (a & 1) cout << "Kaoyu" << endl;
	else cout << "huoguo" << endl;
	return 0; 
}