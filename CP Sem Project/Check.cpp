#include<iostream>
using namespace std;
int main()
{
	int attack;
	srand(time(0));
	attack = rand() %10;
	cout << "Attack: " << attack << endl;
	return attack;
}
