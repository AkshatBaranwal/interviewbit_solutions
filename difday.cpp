#include <bits/stdc++.h>
using namespace std;
int main() {
	int d, m, y, x, n[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	cout << "Date: ";			cin >> d;
	cout << "Month: ";			cin >> m;
	cout << "Year: ";			cin >> y;
	cout << "No. of Days: ";	cin >> x;
	x += d;
	n[1] += y%400 == 0 || y%4 == 0 && y%100 != 0;
	while(--m) x += n[m-1];
	--y;
	while(y%400 && (y%4 || y%100==0)) --y, x += 365;
	x += 366;
	y += 4 * (x/1461) - 1;
	x %= 1461;
	n[1] = 28 + (x < 367);
	if(x > 366) ++y, x -= 366;
	y += x/365;
	x %= 365;
	while(x > n[m]) x -= n[m++];
	if(x == 0) {
		if(m == 0) x = 31, m = 11;
		else x = n[--m], ++y;
	}
	else ++y;
	cout << endl << x << "/" << m+1 << "/" << y << endl;
	return 0;
}