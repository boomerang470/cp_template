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
