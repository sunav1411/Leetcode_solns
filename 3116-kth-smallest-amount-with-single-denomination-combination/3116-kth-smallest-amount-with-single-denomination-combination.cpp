#define ll long long
class Solution {
public:
    ll findKthSmallest(vector<int>& c, int k) {
        vector<pair<ll,ll>> p;
        for (int i=1; i<(1<<c.size()); ++i) {
            ll l=1, x=-1;
            for (int j=0; j<c.size(); ++j) {
                if (i&(1<<j)) {
                    l=lcm(l,c[j]);
                    x*=-1;
                }
            }
            p.push_back({l,x});
        }

        auto check=[&k,&p](ll b) -> bool {
            ll cnt = 0;
            for (auto &[l,a]:p) {
                cnt+=(b/l)*a;
            }
            return cnt<k;
        };

        ll ans = 0;
        for (ll b=1e18; b>0; b>>=1) {
            while (check(ans+b)) ans+=b;
        }
        return ans+1;
    }
};