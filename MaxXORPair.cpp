#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define ld long double
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;
ll maxXOR=LLONG_MIN,x=0,y=0;
class Node{
public:
	Node*left; //for storing 0
	Node*right; //for storing 1
};
class Trie{
public:
	Node*root;
	Trie()
	{
	 root=new Node();
	}
	void insert(ll n)
	{
    //  cout<<"Inserting "<<n<<endl;
	 Node*temp=root,*newNode;
	 REPI(i,0,32)
	 {
	  ll bit=(n>>i)&1ll;
	  if(bit==0)
	  {
	   if(temp->left==NULL){
         newNode=new Node();
	     temp->left=newNode;
       }
	   temp=temp->left;
	  }
	  else
	  {
	   if(temp->right==NULL){
          newNode=new Node();
	      temp->right=newNode;
       }
	   	temp=temp->right;
	  }
	 }
    // cout<<"Insertion of "<<n<<" done\n";
	}
	void calculate_max_xor(ll val)
	{
	 ll ans=0ll,a=0ll,b=val;
	 Node*temp=root;
	 REPI(i,0,32)
	 {
	  ll bit=(val>>i)&1ll;
	  if(bit==0)
	  {
	   if(temp->right)
	   {
        ans+=(1<<i);
        a+=(1<<i);
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
	   	a+=(1<<i),temp=temp->right;
	  }
	 }
    //  cout<<ans<<endl;
	 if(ans>maxXOR)
	  maxXOR=ans,x=a,y=b;
	}
};
int main()
{
 Trie t;
 ll n;
 cin>>n;
 ll a;
 REP(i,0,n)
 {
  cin>>a;
  t.insert(a);
  t.calculate_max_xor(a);
 }
 cout<<"Max XOR obtained is "<<maxXOR<<" for ("<<x<<","<<y<<")\n";
 return 0;
}