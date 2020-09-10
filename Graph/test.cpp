#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a, pair<int,int> b)
{
   double a1=(double)((double)a.first/(double)a.second);
   double a2=(double)((double)b.first/(double)b.second);	
   return a1>a2;
}
double fractionalknapsack(int w,int n,vector<pair<int,int> >v)
{
	sort(v.begin(),v.end(),cmp);
	
	int cw=0;
	double val=0;
	for(int i=0;i<n;i++)
	{
		if(cw+v[i].second<=w)
		{
		cw+=v[i].second;
		val+=v[i].first;
		}else
		{
			int remain=w-cw;
			val+=(double)v[i].first*((double)remain/(double)v[i].second);
		}
	}
	return val;
	
}
int main()
{
	int n,w,val,W;
	// cout<<"enter the size of array";
	cin>>n;
	// cout<<"enter capacity of knapsack";
	cin>>W;
	vector<pair<int,int> >v(n);
	for(int i=0;i<n;i++)
	{
		// cout<<"enter profit and weight respectively";
		cin>>val>>w;
		v.push_back(make_pair(val,w));
	}
	double res=fractionalknapsack(W,n,v);
	cout<<"the maximum profit is "<<res;
	return 0;
}