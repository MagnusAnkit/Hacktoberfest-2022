/* Peter found a digital dictionary which is far better than normal dictionaries. 
The digital dictionary has an input field in which one can search any string 
and the dictionary displays all the words whose prefix is that input string in lexicographical order.
Now you are given a task to make your own digital dictionary. 
You will be given words that you can store in your database 
and then you need to design the search functionality. 
And if no such words are available for a given search word, add this word to your dictionary. */

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
	char data;
	map<char,Node*> children;
	bool isTerminal;
	Node(char d='\0')
	{
	 data=d;
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
	void insert(string s)
	{
	 Node*temp=root,*newNode;
	 REP(i,0,s.size())
	 {
      if(temp->children.count(s[i]))
      	temp=temp->children[s[i]];
      else
      {
       newNode=new Node(s[i]);
       temp->children[s[i]]=newNode;
       temp=temp->children[s[i]];
      }
	 }
	 temp->isTerminal=true;
	}
	void insertFromQuery(Node**node,string s)
	{
	 Node*temp=*node,*newNode;
	 REP(i,0,s.size())
	 {
	  if(temp->children.count(s[i]))
      	temp=temp->children[s[i]];
      else
      {
       newNode=new Node(s[i]);
       temp->children[s[i]]=newNode;
       temp=temp->children[s[i]];
      }
	 }
	 temp->isTerminal=true;
	}
	void printAllStringsHavingGivenPrefix(Node*temp,string s)
	{
	 if(temp->isTerminal)
	  cout<<s<<endl;
	 for(auto it=temp->children.begin();it!=temp->children.end();it++)
	 	printAllStringsHavingGivenPrefix(temp->children[it->first],s+(it->first));
	}
	void query(string s)
	{
	 Node*temp=root;
	 REP(i,0,s.size())
	 {
	  if(temp->children.count(s[i]))
	  	temp=temp->children[s[i]];
	  else
	  {
	   insertFromQuery(&temp,s.substr(i,s.size()-i));
	   cout<<"No suggestions"<<endl;
	   return;
	  }
	 }
	 printAllStringsHavingGivenPrefix(temp,s);
	}

};
int main()
{
 Trie t;
 string s;
 ll n;
 cin>>n;
 REP(i,0,n)
 {
  cin>>s;
  t.insert(s);
 }
 ll q;
 cin>>q;
 REP(i,0,q)
 {
  cin>>s;
  t.query(s);
 }
 return 0;
}


