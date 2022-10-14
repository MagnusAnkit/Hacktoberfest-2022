#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define ld long double
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;
ll maxXOR=LLONG_MIN,l=0,r=0;
class Node{
public:
	Node*left; //for storing 0
	Node*right; //for storing 1
	bool isTerminal;
	ll index;
	Node()
	{
	 left=right=NULL;
	 isTerminal=false;
	 index=-1;
	}
};
class Trie{
public:
	Node*root;
	Trie()
	{
	 root=new Node();
	}
	void insert(ll n,ll ind)
	{
	 Node*temp=root,*newNode;
	 REPI(i,0,64)
	 {
	  ll bit=(n>>i)&1ll;
	  if(bit==0)
	  {
	   if(temp->left==NULL)
	   {
	    newNode=new Node();
	    temp->left=newNode;
	   }
	   temp=temp->left;
	  }
	  else
	  {
	   if(temp->right==NULL)
	   {
	    newNode=new Node();
	    temp->right=newNode;
	   }
	   temp=temp->right;
	  }
	 }
	 temp->isTerminal=true;
	 temp->index=ind;
	}
	void calculate_max_xor_subarray(ll val,ll ind)
	{
	 Node*temp=root;
	 ll ans=0;
	 REPI(i,0,64)
	 {
	  ll bit=(val>>i)&1ll;
	  if(bit==0)
	  {
	   if(temp->right)
	   {
	   	ans+=(1<<i);
	   	temp=temp->right;
	   }
	   else if(temp->left)
	   	temp=temp->left;
	  }
	  else
	  {
	   if(temp->left)
	   {
	    ans+=(1<<i);
	    temp=temp->left;
	   }
	   else if(temp->right)
	   	temp=temp->right;
	  }
	 }
	 if(ans>maxXOR)
	  maxXOR=ans,l=temp->index+1,r=ind;
	}
};
int main()
{
 Trie t;
 ll n;
 cin>>n;
 ll a[n],xorPrefix[n];
 REP(i,0,n)
 {
  cin>>a[i];
  if(i==0)
  	xorPrefix[i]=a[i];
  else
  	xorPrefix[i]=a[i]^xorPrefix[i-1];
  t.insert(xorPrefix[i],i);
  t.calculate_max_xor_subarray(xorPrefix[i],i);
 }
 cout<<"Maximum XOR value of a subarray is "<<maxXOR<<" and the subarray is "<<"["<<l<<","<<r<<"]\n";
 return 0;
}