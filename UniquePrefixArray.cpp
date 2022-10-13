#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
     char data;
     unordered_map<char,Node*> children;
     unordered_map<char,int> freq;
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
      // cout<<"Inserting for string: "<<s<<endl;
      Node*temp=root;
      for(auto i:s)
      {
       
       if(temp->children.count(i)){
         // cout<<i<<" is already present in Trie\n";
         temp=temp->children[i],temp->freq[i]++;
       }
         
       else
       {
        // cout<<i<<" is not present in Trie\n";
        Node*newNode=new Node(i);
        temp->children[i]=newNode;
        newNode->freq[i]++;
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
     string uniquePrefix(string s)
     {
      Node* temp=root;
      string ans="";
      for(auto i:s)
      {
       ans+=i;
       if((temp->children[i])->freq[i]==1)
        return ans;
       temp=temp->children[i]; 
      }
      return ans;
     }
};
int main() 
{
    int n;
    cin>>n;
    vector<string> vs(n);
    Trie t;
    for(int i=0;i<n;i++)
    {
     cin>>vs[i];
     t.insert(vs[i]);
    }
    for(int i=0;i<n;i++)
    {
     cout<<t.uniquePrefix(vs[i])<<endl;
    }
    return 0;
}
