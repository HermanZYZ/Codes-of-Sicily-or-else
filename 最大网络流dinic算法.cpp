 #include <bits/stdc++.h>

#define MAXX 300
#define INF (1<<30)
using namespace std;

int c[MAXX][MAXX], pre[MAXX], Layer[MAXX], V_num, E_num;
bool visit[MAXX];
int k = 0;
bool LayerDivide() // 分层
{
	int v;
	k++;
	queue<int> q;
	q.push(1);
	memset(Layer, 0xff, sizeof(Layer)); // 初始化
	Layer[1] = 0;
	while (!q.empty())
	{
		v = q.front(); q.pop();
		for (int i = 1; i <= V_num; ++i)
		{
			if (c[v][i]>0 && Layer[i]==-1)// 有剩余流量且未被分层
			{
				Layer[i] = Layer[v] + 1;
				if (i == V_num)	return true;
				else 		    q.push(i);
			}
		}
	}
	return false;
}

int Dinic()//Dinic算法
{
	int v, MaxFlow = 0, addFlow = 0;
	vector<int> s;
	int minNumFlow[MAXX] = { INF };
	int minNumFlowPos = 0;
	while (LayerDivide())
	{
		s.push_back(1);
		memset(visit, 0, sizeof(visit));
		visit[1] = true;
		while (!s.empty())
		{
			v = s.back();
			if (v == V_num)
			{
				MaxFlow += addFlow;
				for (int i = s.size(); i >= 2; --i) // S(0) 1 2 3 4 T
				{
					c[s[i - 2]][s[i-1]] -= addFlow;
					c[s[i - 1]][s[i - 2]] += addFlow;
					if (minNumFlowPos + 1<s.size())  s.pop_back();  // 退栈到
				}
				minNumFlowPos = 0;
			}
			else
			{
				int i = 1;
				for (; i <= V_num; ++i)
				{
					if (c[v][i] > 0 && Layer[i] == Layer[v] + 1 && !visit[i])
					{
						if (minNumFlow[Layer[v]] > c[v][i]) //记录第Layer[v]层最小容量
						{
							minNumFlow[Layer[i]] = c[v][i];
							minNumFlowPos = Layer[v];       // 得到最小容量弧线start点所在的层数
						}
						else minNumFlow[Layer[i]] = minNumFlow[Layer[v]];
						visit[i] = true;
						s.push_back(i);
						addFlow = minNumFlow[Layer[i]]; // 第Layer[v]层最小容量
						break;
					}
				}
				if (i > V_num) 
					s.pop_back();
			}
		}
	}
	return MaxFlow;
}
/*int main()
{
	while (cin >> E_num >> V_num) // edge num    vertex num
	{
		int s, e, capability;

		memset(c, 0, sizeof(c));
		for (int i = 0; i < E_num; ++i)
		{
			cin >> s >> e >> capability;  // 某条变的容量
			c[s][e] += capability;   //可能有重边
		}
		cout << Dinic() << endl;
	}
}*/
int main()
{
	int n,m,s;
	while(cin >> n >> m)
	{
		int nn = m+n;
		memset(c, 0, sizeof(c));
		for (int i = 2; i <= n+1; ++i)
		{
			c[1][i] = 1; /*0号为超级源点*/
			
			for (int j = n+2; j <= nn+1; ++j)  /*0   1-n  n+1 -> n+m   n+m+1*/
			{
				cin >> c[i][j];
				c[j][nn+2] = 1; /*nn+1 为超级汇点*/
			}
		}
		V_num = n+m+2;
		cout << Dinic() << endl;
	}
}