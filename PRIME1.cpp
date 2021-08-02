#include<iostream>
using namespace std;
typedef long long ll;

bool prime(ll l){
	if(l==1) return 0;
	for(ll i=2;i*i<=l;i++){
		if(l%i==0)
			return 0;
	}
	return 1;
}

int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		for(ll i=n;i<=m;i++){
			if(prime(i)){
				cout<<i<<endl;
			}
		}
		cout<<endl;
	}
	return 0;
}


