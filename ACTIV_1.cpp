//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>

#define endl "\n"
#define inputv(x,n) for(ll i=0;i<n;i++) cin>>x[i];
using namespace std;
typedef long long ll;
const ll M=1e8;

ll binarySearch(vector<vector<ll>> &v,ll val){
	ll start=0,end=v.size()-1;
	ll ans=end+1;
	while(start<=end){
		ll mid=(start+end)/2;
		if(v[mid][0]>=val){
			ans=mid;
			end=mid-1;
		}
		else{
			start=mid+1;
		}
	}
	return ans;
}

ll findSum(vector<ll>&v,ll pos){
	ll sum=0;
	pos++;
	while(pos>0){
		sum=(sum+v[pos])%M;
		pos-=(pos&(-pos));
	}
	return sum;
}
void updateSum(vector<ll>&v,ll val,ll pos){
	//cout<<val<<" "<<pos<<endl;
	pos++;
	while(pos<=v.size()){
		v[pos]=(v[pos]+val)%M;
		pos+=(pos&(-pos));
	}
	//return pos;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	while(cin>>n){
		if(n==-1)	break;
		unordered_map<ll,ll> mps;
		unordered_map<ll,ll> mpe;
		vector<vector<ll>> vs(n);
		vector<vector<ll>> ve(n);
		vector<ll> BIT(n+1);
		vector<ll> dp(n);
		for(ll i=0;i<n;i++){
			ll s,e;
			cin>>s>>e;
			vs[i]={s,i};
			ve[i]={e,i};
		}
		sort(vs.begin(),vs.end());
		sort(ve.begin(),ve.end());
		for(ll i=0;i<vs.size();i++){
			mps[vs[i][1]]=i;
		}
		for(ll i=ve.size()-1;i>=0;i--){
			ll pos=ve[i][1];
			pos=mps[pos];
			//find sum for next indices
			ll index=binarySearch(vs,ve[i][0]);
			ll sum=((1+findSum(BIT,n-1))%M-findSum(BIT,index-1)+M)%M;
			//update sum at pos 
			updateSum(BIT,sum,pos); 
		}
		ll ans=findSum(BIT,n-1);
		//cout<<ans<<endl;
		ans%=M;
		string sol="00000000";
		sol+=to_string(ans);
		cout<<sol.substr(sol.length()-8,8)<<endl;
	}
	return 0;
}

