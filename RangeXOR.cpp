/*You are given an array and Q queries of two types.
Type 0: Given a number x , insert the number at the last of the array.
Type 1: Given a number X and two integers L, R, Find a number Y in the range L, R to maximize X ^ Y

Input Format
First line of the test case will be the number of queries Q . 
Then on next Q subsequent lines you will be given a query either of type 0 or type 1. 
Query of type 0 is of the form : 0 X, where X is the integer to be inserted . 
Query of type 1 is of the form : 1 L R X   */

#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define ld long double
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;
class Node{
public:
	Node*left; //for storing 0
	Node*right; //for storing 1
	// map<ll,Node*> children;
	map<ll,set<ll>> indexMap;
	bool isTerminal;
	Node()
	{
	 left=right=NULL;
	 isTerminal=false;
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
   REPI(i,0,60)
   {
    ll bit=(n>>i)&1ll;
    if(bit==0)
    {
     if(temp->left==NULL)
     {
      newNode=new Node();
      indexMap[bit].insert(ind);
      temp->left=newNode;
     }
     temp=temp->left;
    }
    else
    {
     if(temp->right==NULL)
     {
      newNode=new Node();
      indexMap[bit].insert(ind);
      temp->right=newNode;
     }
     temp=temp->right;
    }
   }
   temp->isTerminal=true;
  }
  ll query(ll l,ll r,ll n)
  {
   Node*temp=root;
   ll ans=0;
   REPI(i,0,60)
   {
    ll bit=(n>>i)&1ll;
    if(bit==0)
    {
     if(temp->right)
     {
      auto it=temp->indexMap[bit].lower_bound(l);
      if(it==temp->indexMap[bit].end())
      {
       //XOR = 0 and currBitY=0
        temp=temp->left;
      }
      else if(*it>r)
      {
       //XOR = 0 and currBitY=0
      	temp=temp->left;
      }
      else
      {
       //XOR = 1 and currBitY=1
       ans+=(1ll<<i);
       temp=temp->right;
      }
     }
     else
      temp=temp->left;
    }
    else
    {
     if(temp->left)
     {
      auto it=temp->indexMap[bit].lower_bound(l);
      if(it==temp->indexMap[bit].end())
      {
       //XOR = 0 and currBitY=1
        temp=temp->right;
        ans+=(1ll<<i);
      }
      else if(*it>r)
      {
       //XOR = 0 and currBitY=1
      	temp=temp->right;
      	ans+=(1ll<<i);
      }
      else
      {
       //XOR = 1 and currBitY=0
       temp=temp->left;
      }
     }
     else
      ans+=(1ll<<i),temp=temp->right;
    }
   }
   return ans;
  }
};
int main()
{
 Trie t;
 ll n,ch,l,r,ind=1,val;
 cin>>n;
 REP(i,0,n)
 {
  cin>>ch;
  if(ch==0)
  {
   cin>>val;
   t.insert(val,ind);
   ind++;
  }
  else
  {
   cin>>l>>r>>val;
   cout<<t.query(l,r,val)<<endl;
  }
 }
 return 0;
}