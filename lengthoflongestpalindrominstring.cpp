#include<bits/stdc++.h>
using namespace std;
int longestP(string s)
{
	int l = s.size();
	bool V[l][l];
	int j=0;
	int lo = 1;
	for(int i=0;i<l&&j<l;i++)
	{
		V[j][i] = false;
		if(i==l-1)
		{
			i=-1;
			j++;
		}
	}
	for(int i=0;i<l;i++)
	{
		V[i][i] = true;
	}
	for(int i=0;i<l-1;i++)
	{
		if(s[i]==s[i+1])
		{
			V[i][i+1] = true;
			l=2;
		}
	}
	for(int k=2;k<l;k++)
	{
		for(int i=0;i<k-1;i++)
		{
			if(s[i]==s[k])
			{
				if(V[i+1][k-1] == true)
				{
					V[i][k]=true;
					lo = max(lo,k-i+1);
				}
			}
		}	
	}
	return lo;		
}

int main()
{
	string str;
	cin>>str;
	cout<<longestP(str);	
}
