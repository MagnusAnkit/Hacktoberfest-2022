#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define ld long double
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;

ll modular_multiplication(ll a,ll b,ll n)
{
 ll res=0;
 while(b)
 { 
  if(b&1ll)
  	res+=a;
  a*=2;
  b/=2;
  res%=n;
  a%=n;
 }
 return res;
}


ll modular_exponentiation(ll a,ll b,ll n)
{
 ll res=1;
 while(b)
 {
  if(b&1ll)
  	res=modular_multiplication(res,a,n);
  a=modular_multiplication(a,a,n);
  b/=2;
 }
 return res;
}

bool miller_rabin(ll n)
{
 if(n==1) return false;
 if(n==2) return true;
 if(n%2==0) return false;
 //case which remains is n is odd => n-1 is even
 ll d=n-1,s=0;
 while(d%2==0)
 {
  s++;
  d/=2;
 }
 //a represents the array of random prime numbers arrays
 vector<ll> a({2,3,5,7,11,13,17,19,23});
 REP(i,0,a.size())
 {
  if(a[i]>n-2)
  	continue;
  //(a[i]^d)%n
  ll ad=modular_exponentiation(a[i],d,n);
  if(ad%n==1)
  	continue;
  bool prime=false;
  REP(r,0,s)
  {
   //(2^r)%n
   ll rr=modular_exponentiation(2,r,n);
   //(a[i]^d)^(2^r)%n
   ll ard=modular_exponentiation(ad,rr,n);
   if(ard%n==n-1)
   {
    prime=true;
    break;
   }
  }
  if(prime==false)
  	return false;
 }
 return true;
}


int main()
{
 ll t;
 cin>>t;
 while(t--)
 {
  ll n;
  cin>>n;
  if(miller_rabin(n))
  	cout<<"prime\n";
  else 
  	cout<<"not prime\n";
 }
 return 0;
}