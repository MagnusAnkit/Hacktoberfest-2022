#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
     char data;
     unordered_map<char,Node*> children;
     bool isTerminal;
     Node(char ch='\0')
     {
      data=ch;
      isTerminal=false;
     }
};
class Trie{
    public:
     Node*root;
     int cnt;
     Trie()
     {
      root=new Node();
      cnt=0;
     }
     void insert(string s)
     {
      Node*temp=root;
      for(auto i:s)
      {
       if(temp->children.count(i))
         temp=temp->children[i];
       else
       {
        Node*newNode=new Node(i);
        temp->children[i]=newNode;
        temp=newNode;
       }
      }
      temp->isTerminal=true;
     }
     bool find(string s)
     {
      Node*temp=root;
      for(auto i:s)
      {
       if(temp->children.count(i)==0)
        return false;
       else
        temp=temp->children[i];
      }
      return temp->isTerminal;
     }
};
int main() 
{
    int n,q;
    string s;
    cin>>n;
    Trie t;
    for(int i=0;i<n;i++)
    {
     cin>>s;
     t.insert(s);
    }
    cin>>q;
    for(int i=0;i<q;i++)
    {
     cin>>s;
     if(t.find(s)) cout<<"Present\n";
     else cout<<"Absent\n";
    }
    return 0;
}
