#include <iostream>
#include<cstring>
#include<string>
using namespace std;

int lcs_bruteForce(char* x, char* y, int m, int n) 
{
	if (m == 0 || n == 0) {
		return 0;
	}
	if (x[m - 1] == y[n - 1]) {
		return 1 + lcs_bruteForce(x, y, m - 1, n - 1);
	}
	else {
		return max(lcs_bruteForce(x, y, m - 1, n), lcs_bruteForce(x, y, m, n - 1));
	}
}

void lcs_dynamicProgramming(char* x, char* y, int m, int n)
{
	int l[m + 1][n + 1];

	for (int i = 0; i <= m; i++) 
	{
		for (int j = 0; j <= n; j++) 
		{
			if (i == 0 || j == 0)
			{
				l[i][j] = 0;
			}
			else if (x[i - 1] == y[j - 1]) 
			{
				l[i][j] = l[i - 1][j - 1] + 1;
			}
			else 
			{
				l[i][j] = max(l[i - 1][j], l[i][j - 1]);
			}
		}
	}

	int longest = l[m][n];
	//mesh fahm awy 
	char seq[longest + 1];
	seq[longest] = '\0';
	int i = m, j = n;

	while (i > 0 && j > 0) {

		if (x[i - 1] == y[j - 1]) {
			seq[longest - 1] = x[i - 1];
			i--;
			j--;
			longest--;
		}
		else if (l[i - 1][j] > l[i][j - 1]) {
			i--;
		}
		else {
			j--;
		}
	}
	cout << "The longest commen subsequance of '" << x << "' and '" << y << "' is '" << seq
		<< "'  and is equal to " << l[m][n] << endl;
}
int main()
{
	char* x = new char[0];
	char* y = new char[0];

	//getting first word
	cout << "enter the first word :";
	cin >> x;
	cout << endl;

	//getting second word
	cout << "enter the second word :";
	cin >> y;
	cout << endl;

	//size of each word
	int m = strlen(x);
	int n = strlen(y);

	// longest commen subsequance by brute force
	cout << "The longest commen subsequance of '" << x << "' and '" << y << "' is " << lcs_bruteForce(x, y, m, n) << endl;

	// longest commen subsequance by dynamic programming
	lcs_dynamicProgramming(x, y, m, n);

}