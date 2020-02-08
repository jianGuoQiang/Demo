/*
多个队列的合并——不同集合之间需要保持一定次序时
连续输入多个带空格的字符串，记得cin.ignore()去掉缓冲区的换行符
*/
#include<iostream>
#include<queue>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,p,q,i,index;
	string tmp;
	queue<string> que[101];

	cin >> n;
	cin.ignore();   //非常的关键，如果要想连续输入多行带有空格的字符串时
	for ( i = 1; i <= n; ++i)
	{
		getline(cin, tmp);
		que[i].push(tmp);
	}
	
	for ( i = 1; i < n; i++)
	{
		cin >> p >> q;
        
		while (que[p].size())
		{
			que[q].push(que[p].front());
			que[p].pop();
		}
	}
	for (index = 1; index <= n ; index++) if(que[index].size()) break
; //找出最后融合的那一个队列
   while (que[index].size())
   {
	   cout << que[index].front()<<" ";
	   que[index].pop();
   }
  // system("pause");
   return 0;
}