#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main() {
	string function;
	cin >> function;
	string s1 = "#" + function + "#";//方程字符串
	int constnum[2] = { 0 };
	int constx[2] = { 0 };
	char a=' ';
	int count = 0;//辅助计数
	int ans = 0;//单项求和
	int sumnum = 0;//常数项
	int sumx = 0;//系数
	int bracn = 0;//括号常数
	int bracx = 0;//括号系数
	for (int i = s1.size(); i > 0; i--) {
		if (s1[i] == ')') {
			i = i - 1;
			while (s1[i] != '(') {

				if ((s1[i] <= 'Z' && s1[i] >= 'A') || (s1[i] <= 'z' && s1[i] >= 'a')) {
					a = s1[i];
					if (s1[i - 1] > '9' || s1[i - 1] < '0') {
						if(s1[i-1]=='-')
							bracx = bracx -1;
						else
							bracx = bracx + 1;

					}
				}
				//
				double test1 = 0;
				int g = 0;
				int h = 0;
				if (s1[i] <= '9' && s1[i] >= '0') {
					if (s1[i + 1] > '9' || s1[i + 1] < '0') {
						count = i;
						test1 = count - i;
						ans = ans + (s1[i] - '0') * pow(10, test1);
						g++;
					}
					//
					if (s1[i - 1] > '9' || s1[i - 1] < '0') {
						g++;
						test1 = count - i;
						ans = ans + (s1[i] - '0') * pow(10, test1);
						if (s1[i + 1] > '9' || s1[i + 1] < '0') {
							ans = ans / 2;

						}
						if (s1[i - 1] == '-') {
							ans = ans * (-1);

						}
						if (s1[count + 1] == a) {
							bracx = bracx + ans;
							ans = 0;
							h++;
						}

						if (h != 0) {
							goto flag2;
						}
						else {
							bracn = bracn + ans;
							ans = 0;
						}
					}
					//
					if (g != 0) {
						goto flag2;
					}
					else {
						test1 = count - i;
						ans = ans + (s1[i] - '0') * pow(10, test1);
					}
				}
			flag2:
				i--;
			}
		}
		
		if ((s1[i] <= 'Z' && s1[i] >= 'A') || (s1[i] <= 'z' && s1[i] >= 'a')) {
			a = s1[i];
			if (s1[i - 1] > '9' || s1[i - 1] < '0') {
				if (s1[i - 1] == '-')
					sumx = sumx - 1;
				else
					sumx = sumx + 1;

			}
		}
	
		if (s1[i] == '(' && s1[i - 1] == '-') {
			sumx = sumx - bracx;
			bracx = 0;
			sumnum = sumnum - bracn;
			bracn = 0;
		}
		double test = 0;
		int v = 0;
		int p = 0;
		
		if (s1[i] <= '9' && s1[i] >= '0') {
			if (s1[i + 1] > '9' || s1[i + 1] < '0') {
				count = i;
				test = count - i;
				ans = ans + (s1[i] - '0') * pow(10, test);
				v++;
			}
			if (s1[i - 1] > '9' || s1[i - 1] < '0') {
				v++;
				test = count - i;
				ans = ans + (s1[i] - '0') * pow(10, test);
				if (s1[i + 1] > '9' || s1[i + 1] < '0') {
					ans = ans / 2;
					
				}
				if (s1[i - 1] == '-') {
					ans = ans * (-1);
					
				}
				if (s1[count + 1] == '(') {
					sumx = sumx + (bracx * ans);
					p++;
					sumnum = sumnum + (bracn * ans);
					bracn =0 ;
					bracx = 0;
					ans = 0;
				}
				if (s1[count+1] == a) {
					sumx = sumx + ans;
					ans = 0;
					p++;
					}
				
				if (p != 0) {
					goto flag1;
				}
				else {
					sumnum = sumnum + ans;
					ans = 0;
				}
			}
			if (v != 0) {
				goto flag1;
			}
			else {
				test = count - i;
				ans = ans + (s1[i] - '0') * pow(10, test);
			}
		}
		flag1:
		if (s1[i] == '=') {
			constnum[1] = sumnum;
			constx[1] = sumx;
			ans = 0;
			sumnum = 0;
			sumx = 0; 
			
		}
	}
	constnum[0] = sumnum;
	constx[0] = sumx;
	
	double q = constnum[0] - constnum[1];
	
	double w = constx[1] - constx[0];
	double e = q / w;
	::cout << a << "=" << e << endl;


	

	return 0;
}
