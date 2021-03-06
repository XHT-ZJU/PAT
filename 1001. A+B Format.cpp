1001. A+B Format (20)

时间限制
400 ms
内存限制
32000 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue

Calculate a + b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

Input

Each input file contains one test case. Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. The numbers are separated by a space.

Output

For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

Sample Input
-1000000 9
Sample Output
-999,991

//按格式输出  基本数学题
----------------------------------------------------------------------------------------------------------
#include<stdio.h>
using namespace std;

int main(void){
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		int c = a+b;
		if(c<0){
			c=-c;
			printf("-");
		}
		if(c>=1000000)
			printf("%d,%03d,%03d\n",c/1000000,(c/1000)%1000,c%1000);
		else if(c>=1000)
			printf("%d,%03d\n",c/1000,c%1000);
		else
			printf("%d\n",c);
	}
	return 0;
}

----------------------------------------------------------------------------------------------------------
#pragma warning (disable:4786)
#include<iostream>
#include<iomanip>
#include<string>
#include<cstdio>
#include<algorithm>
#include<map>
#include<sstream>
using namespace std;

bool flag;

void Output(int num)
{
     if(flag==true)
     {
         cout<<",";
        cout<<num/100<<num/10%10<<num%10;
     }
    else
    {
        cout<<num;
         flag=true;
    }
}

void Process(int num)
{
    while(num>=1000)
    {
        int cur=num/1000;
        Process(cur);
        num-=cur*1000;
    }
    Output(num);
}

int main()
{
    int num1,num2;
    while(cin>>num1>>num2)
    {
        int sum=num1+num2;
        if(sum<0)
        {
            printf("-");
            sum=-sum;
        }
        flag=false;
        Process(sum);
        cout<<endl;
    }
    return 0;
}
