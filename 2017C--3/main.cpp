#include"calcu.h"
using namespace std;
int u = 0, z = 0;
char str1[20] = { 0 };
int main()
{
	int total;
	total = fileread();
	cin >> str1;
	boundary();
	z = test(total);
	print();
	system("pause");
	return 0;
}
