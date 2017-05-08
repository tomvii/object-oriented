#include"calcu.h"
using namespace std;
int u = 0, z = 0;
char *p2;
int main(int argc, char *argv[])
{
	char *p = argv[1];
	p2 = argv[2];
	int total;
	total = fileread(p);
	boundary();
	z = test(total);
	print();
	system("pause");
	return 0;
}
