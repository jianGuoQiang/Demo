/*
������еĺϲ�������ͬ����֮����Ҫ����һ������ʱ
�������������ո���ַ������ǵ�cin.ignore()ȥ���������Ļ��з�
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
	cin.ignore();   //�ǳ��Ĺؼ������Ҫ������������д��пո���ַ���ʱ
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
; //�ҳ�����ںϵ���һ������
   while (que[index].size())
   {
	   cout << que[index].front()<<" ";
	   que[index].pop();
   }
  // system("pause");
   return 0;
}