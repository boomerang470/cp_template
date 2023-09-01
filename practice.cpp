//Primes in range
vector<ll> Sieve(ll L,ll R){
    ll lim = sqrt(R);
    vector<bool> mark(lim+1,true);
    mark[0]=false;mark[1]=false;
    for(ll i=2;i<=lim;i++){
        for(ll j=i*i;j<=lim;j+=i){
            mark[j]=false;
        }
    }
    vector<ll> primes;
    for(ll i=0;i<=lim;i++)
        if(mark[i]) primes.push_back(i);

    vector<ll> primeLR(R-L+1,true);
    for(auto x : primes){
        for(ll j=max(x*x,(L+x-1)/(x*x));j<=R-L+1;j+=x){
            primeLR[j-L]=false;
        }
        
    }
    if(L==1) primeLR[0]=false;

    vector<ll> ans;
    for(ll i=0;i<=R-L+1;i++){
        if(primeLR[i]) ans.push_back(L+i);
    }
    return ans;

}


// Binary Expo
ll power(ll a,ll b,ll mod=MOD){
    ll res=1;
    while(b>0){
        if(b&1){
            res = res*a;
            res %= mod;
        }
        a = a*a;
        a %= mod;
        b = b>>1;
    }
    return res;
}



//nCr using Fermat Little Theorem
ll modInverse(ll a,ll p){
    return power(a,p-2,p);
}

ll nCr(ll n,ll r,ll mod=MOD){
    vector<ll> fact(n+1);
    fact[0]=1;
    for(ll i=1;i<=n;i++){
        fact[i] = (i*fact[i-1])%mod;
    }

    ll ans = (fact[n]*(modInverse(fact[n-r],mod))%mod)*(modInverse(fact[r],mod)%mod)%mod;
    return ans;
}

