#include"calcu.h"
void writefile(char str[20])
{
	FILE *out;
	if ((out = fopen(str1, "a")) == NULL)
	{
		cout << "Can not write it!!!";
		exit(0);
	}
	fputs(str, out);
	fputs("\n", out);
	//fputs("\n", out);
}

void print()
{
	char temp0[20] = { 0 }, temp1[20] = { 0 };
	cout << "Right:" << u << endl;
	cout << "Wrong:" << z << endl;
	temp0[0] = 'R';
	temp0[1] = 'i';
	temp0[2] = 'g';
	temp0[3] = 'h';
	temp0[4] = 't';
	temp0[5] = ':';
	temp0[6] = u + 48;

	writefile(temp0);

	temp1[0] = 'W';
	temp1[1] = 'r';
	temp1[2] = 'o';
	temp1[3] = 'n';
	temp1[4] = 'g';
	temp1[5] = ':';
	temp1[6] = z + 48;
	writefile(temp1);


}

void boundary()
{
	srand(time(NULL));
	int p;
	cout << "0(中文) 1(Enlish):";
	cin >> p;
	cout << "*******************************************************" << endl;
	if (p == 0)
		cout << "已读写成功";
	if (p == 1)
		cout << "Already done(Use # to end this test.)";
	cout << endl << "*******************************************************" << endl;
}

void random(int *a,int*b,int*c,int *d )
{
	*a = 10 * rand() / RAND_MAX;
	*b = 10 * rand() / RAND_MAX;
	*c = 10 * rand() / RAND_MAX;
	*d = 10 * rand() / RAND_MAX;
}
int fileread()
{
	FILE *in;
	char c[50] = { 0 };
	char ch[2]{ 0 };
	cin >> c;
	cout << c << endl;
	if ((in = fopen(c, "r")) == NULL)
	{
		cout << "Can not open it!!!";
		exit(0);
	}
	fgets(ch, 2, in);
	return ch[0] - '0';
}

void generateExpression(int x)
{
	char o;
	int a, b, c, d;
	char str2[20] = { 0 };
	int orgina, orginb;
	int multiple, factor, right, numerator, answer, answert, y1, y2, t, j, k, w;
	random(&a, &b, &c, &d);
	if (x == 0)
	{
		char temp2[20] = { 0 };
		char temp3[20] = { 0 };
		while (a == 0 || b == 0 || d == 0 || c == 0)
			random(&a, &b, &c, &d);
		cout << a << "/" << b << "+" << c << "/" << d << "=?" << endl;
		temp2[0] = a + 48;
		temp2[1] = '/';
		temp2[2] = b + 48;
		temp2[3] = '+';
		temp2[4] = c + 48;
		temp2[5] = '/';
		temp2[6] = d + 48;
		temp2[7] = '=';
		temp2[8] = '?';
		writefile(temp2);
		y1 = b;
		y2 = d;
		for (;;)
		{
			t = y1%y2;
			if (t != 0)
			{
				y1 = y2;
				y2 = t;
			}
			else
			{
				factor = y2;
				multiple = b*d / y2;
				break;
			}
		}
		numerator = a*multiple / b + c*multiple / d;
		orgina = numerator;
		orginb = multiple;
		while (multiple != 0)
		{
			t = numerator%multiple;
			numerator = multiple;
			multiple = t;
		}
		cin >> answer >> o >> answert;
		temp3[0] = answer + 48;
		temp3[1] = o;
		temp3[2] = answert + 48;
		writefile(temp3);
		if (answer == (orgina / numerator) && answert == (orginb / numerator))
			u++;
		else
			z++;
	}
	if (x == 1)
	{
		char temp2[20] = { 0 };
		char temp3[20] = { 0 };
		cout << "(" << a << "+" << b << ")*(" << c << "-" << d << ")=?" << endl;
		temp2[0] = '(';
		temp2[1] = a + 48;
		temp2[2] = '+';
		temp2[3] = b + 48;
		temp2[4] = ')';
		temp2[5] = '*';
		temp2[6] = '(';
		temp2[7] = c + 48;
		temp2[8] = '-';
		temp2[9] = d + 48;
		temp2[10] = ')';
		temp2[11] = '=';
		temp2[12] = '?';
		writefile(temp2);
		right = (a + b)*(c - d);
		cin >> answer;
		temp3[0] = answer + 48;
		writefile(temp3);

		if (answer == right)
			u++;
		else
			z++;
	}
	if (x == 2)
	{
		char temp4[20] = { 0 };
		char temp5[20] = { 0 };
		cout << "(" << a << "+" << b << ")*(" << c << "+" << d << ")=?" << endl;
		temp4[0] = '(';
		temp4[1] = a + 48;
		temp4[2] = '+';
		temp4[3] = b + 48;
		temp4[4] = ')';
		temp4[5] = '*';
		temp4[6] = '(';
		temp4[7] = c + 48;
		temp4[8] = '+';
		temp4[9] = d + 48;
		temp4[10] = ')';
		temp4[11] = '=';
		temp4[12] = '?';
		writefile(temp4);
		right = (a + b)*(c + d);
		cin >> answer;
		temp5[0] = answer + 48;
		writefile(temp5);
		if (answer == right)
			u++;
		else
			z++;
	}
	if (x == 3)
	{
		char temp2[20] = { 0 };
		char temp3[20] = { 0 };
		cout << "(" << a << "-" << b << ")*(" << c << "+" << d << ")=?" << endl;
		temp2[0] = '(';
		temp2[1] = a + 48;
		temp2[2] = '-';
		temp2[3] = b + 48;
		temp2[4] = ')';
		temp2[5] = '*';
		temp2[6] = '(';
		temp2[7] = c + 48;
		temp2[8] = '+';
		temp2[9] = d + 48;
		temp2[10] = ')';
		temp2[11] = '=';
		temp2[12] = '?';
		writefile(temp2);
		right = (a - b)*(c + d);
		cin >> answer;
		temp3[0] = answer + 48;
		writefile(temp3);
		if (answer == right)
			u++;
		else
			z++;
	}
	if (x == 4)
	{
		char temp2[20] = { 0 };
		char temp3[20] = { 0 };
		cout << "(" << a << "-" << b << ")*(" << c << "-" << d << ")=?" << endl;
		temp2[0] = '(';
		temp2[1] = a + 48;
		temp2[2] = '-';
		temp2[3] = b + 48;
		temp2[4] = ')';
		temp2[5] = '*';
		temp2[6] = '(';
		temp2[7] = c + 48;
		temp2[8] = '-';
		temp2[9] = d + 48;
		temp2[10] = ')';
		temp2[11] = '=';
		temp2[12] = '?';
		writefile(temp2);
		right = (a - b)*(c - d);
		cin >> answer;
		temp3[0] = answer + 48;
		writefile(temp3);
		if (answer == right)
			u++;
		else
			z++;
	}
	if (x == 5)
	{
		char temp2[20] = { 0 };
		char temp3[20] = { 0 };
		while (a == 0 || b == 0 || d == 0 || c == 0 || c == d)
			random(&a, &b, &c, &d);
		cout << "(" << a << "-" << b << ")/(" << c << "-" << d << ")=?" << endl;
		temp2[0] = '(';
		temp2[1] = a + 48;
		temp2[2] = '-';
		temp2[3] = b + 48;
		temp2[4] = ')';
		temp2[5] = '/';
		temp2[6] = '(';
		temp2[7] = c + 48;
		temp2[8] = '-';
		temp2[9] = d + 48;
		temp2[10] = ')';
		temp2[11] = '=';
		temp2[12] = '?';
		writefile(temp2);
		orgina = a - b; j = a - b;
		orginb = c - d; k = c - d;
		while (k != 0)
		{
			t = j%k;
			j = k;
			k = t;
		}
		cin >> answer >> o >> answert;
		temp3[0] = answer + 48;
		temp3[1] = o;
		temp3[2] = answert + 48;
		writefile(temp3);
		w = orgina / orginb;
		if (answer == orgina / j&&answert == orginb / j)
			u++;
		else if (answer == w&&orgina%orginb == 0)
			u++;
		else
			z++;
	}
	if (x == 6)
	{
		char temp2[20] = { 0 };
		char temp3[20] = { 0 };
		while (a == 0 || b == 0 || d == 0 || c == 0 || c == d)
			random(&a, &b, &c, &d);
		cout << "(" << a << "+" << b << ")/(" << c << "-" << d << ")=?" << endl;
		temp2[0] = '(';
		temp2[1] = a + 48;
		temp2[2] = '+';
		temp2[3] = b + 48;
		temp2[4] = ')';
		temp2[5] = '/';
		temp2[6] = '(';
		temp2[7] = c + 48;
		temp2[8] = '-';
		temp2[9] = d + 48;
		temp2[10] = ')';
		temp2[11] = '=';
		temp2[12] = '?';
		writefile(temp2);
		orgina = a + b; j = a + b;
		orginb = c - d; k = c - d;
		while (k != 0)
		{
			t = j%k;
			j = k;
			k = t;
		}
		cin >> answer >> o >> answert;
		temp3[0] = answer + 48;
		temp3[1] = o;
		temp3[2] = answert + 48;
		writefile(temp3);
		w = orgina / orginb;
		if (answer == orgina / j&&answert == orginb / j)
			u++;
		else if (answer == w&&orgina%orginb == 0)
			u++;
		else
			z++;
	}
	if (x == 7)
	{
		char temp2[20] = { 0 };
		char temp3[20] = { 0 };
		while (a == 0 || b == 0 || d == 0 || c == 0)
			random(&a, &b, &c, &d);
		cout << "(" << a << "-" << b << ")/(" << c << "+" << d << ")=?" << endl;
		temp2[0] = '(';
		temp2[1] = a + 48;
		temp2[2] = '-';
		temp2[3] = b + 48;
		temp2[4] = ')';
		temp2[5] = '/';
		temp2[6] = '(';
		temp2[7] = c + 48;
		temp2[8] = '+';
		temp2[9] = d + 48;
		temp2[10] = ')';
		temp2[11] = '=';
		temp2[12] = '?';
		writefile(temp2);
		orgina = a - b; j = a - b;
		orginb = c + d; k = c + d;
		while (k != 0)
		{
			t = j%k;
			j = k;
			k = t;
		}
		cin >> answer >> o >> answert;
		temp3[0] = answer + 48;
		temp3[1] = o;
		temp3[2] = answert + 48;
		writefile(temp3);
		w = orgina / orginb;
		if (answer == orgina / j&&answert == orginb / j)
			u++;
		else if (answer == w&&orgina%orginb == 0)
			u++;
		else
			z++;
	}
	if (x >= 8 )
	{
		char temp2[20] = { 0 };
		char temp3[20] = { 0 };
		while (a == 0 || b == 0 || d == 0 || c == 0)
			random(&a, &b, &c, &d);
		cout << "(" << a << "+" << b << ")/(" << c << "+" << d << ")=?" << endl;
		temp2[0] = '(';
		temp2[1] = a + 48;
		temp2[2] = '+';
		temp2[3] = b + 48;
		temp2[4] = ')';
		temp2[5] = '/';
		temp2[6] = '(';
		temp2[7] = c + 48;
		temp2[8] = '+';
		temp2[9] = d + 48;
		temp2[10] = ')';
		temp2[11] = '=';
		temp2[12] = '?';
		writefile(temp2);
		orgina = a + b; j = a + b;
		orginb = c + d; k = c + d;
		while (k != 0)
		{
			t = j%k;
			j = k;
			k = t;
		}
		cin >> answer >> o >> answert;
		temp3[0] = answer + 48;
		temp3[1] = o;
		temp3[2] = answert + 48;
		writefile(temp3);
		w = orgina / orginb;
		if (answer == orgina / j&&answert == orginb / j)
			u++;
		else if (answer == w&&orgina%orginb == 0)
			u++;
		else
			z++;
	}
}
int test(int total)
{
	int i,v;
	for (i = 0; i<total; i++)
	{
		v = 8 * rand() / RAND_MAX;
		generateExpression(v);
		if (getchar() == '#')
		{
			z--;
			break;
		}
	}
	return z;
}

