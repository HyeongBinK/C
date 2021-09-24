#include<iostream>
#include<string.h>
using namespace std;

void While(int n)
{
	int Dummy;
	if (n == 1)
	{
		cout << n;
		return;
	}
	else
	{

		Dummy = n % 2;
		n /= 2;
		While(n);
		cout << Dummy;
	}
}

void main()
{
	int Data;
	cin >> Data;
	While(Data);
	return;
}

//void While(int n, int sum)
//{
//	
//	//cout << n << endl;
//	//cout << sum << endl;
//	sum += n;
//
//	if (n == 1)
//	{
//		cout << sum;
//		return;
//	}
//	else
//		While(n - 1, sum);
//	
//}
//
//void main()
//{
//	int Data;
//	cin >> Data;
//	While(Data, 0);
//	return;
//}
//
//

//void While(int n)
//{
//	cout << n << endl;
//	if (n <= 0)
//		return;
//	else
//		While(n - 1);
//	cout << n << endl;
//
//}
//
//void main()
//{
//	While(10);
//	return;
//}
//
//
