#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define ld long double
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;

ll primeCount[100007];
ll primeProd[100007];
void sieve()
{
 ll isPrime[100007]={1};
 REP(i,0,100007)
  primeCount[i]=0,primeProd[i]=1,isPrime[i]=1;
 isPrime[0]=isPrime[1]=0;
 for(ll i=2;i*i<=100007;i++)
 {
  if(isPrime[i])
  {
   primeCount[i]++;
   primeProd[i]*=i;
   for(ll j=2*i;j<100007;j+=i)
   	isPrime[j]=0,primeCount[j]++,primeProd[j]*=i;
  }
 }
}


int main()
{
 sieve();
 REP(i,1,31)
 {
  if(primeProd[i]==i)
  {
   if(primeCount[i]%2)
   	cout<<"-1 ";
   else
   	cout<<"1 ";
  }
  else
   cout<<"0 ";
 }
 return 0;
}