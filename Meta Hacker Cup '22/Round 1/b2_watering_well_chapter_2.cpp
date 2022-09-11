#pragma optimize "-O3"
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif

#define ll long long

const ll MOD = 1e9+7;

void solve(int tc)
{
    int n;
    cin >> n;
    vector<pair<ll,ll>> trees(n);
    for(auto& e:trees) cin >> e.first >> e.second;
    int q;
    cin >> q;
    vector<pair<ll,ll>> wells(q);
    for(auto& e:wells) cin >> e.first >> e.second;
    ll ans = 0;

    // put all x together and y together
    vector<pair<ll,bool>> xdist,ydist; // 0 for well, 1 for tree
    for(auto e:trees)
    {
        xdist.push_back({e.first,true});
        ydist.push_back({e.second,true});
    }
    for(auto e:wells)
    {
        xdist.push_back({e.first,false});
        ydist.push_back({e.second,false});
    }
    sort(xdist.begin(),xdist.end());
    sort(ydist.begin(),ydist.end());

    // ll treesum = 0, wellsum = 0;
    // ll lasttreex = 0, lastwellx = 0, lasttreey = 0, lastwelly = 0;
    // ll numtrees = 0, numwells = 0;


    // dbg(xdist,ydist);
    // for(auto e:xdist)
    // {
    //     if(e.second)
    //     {
    //         // this is a tree, compute for wells

    //         ll d = (e.first-lastwellx+MOD)%MOD;
    //         ll t1 = ((d*d)%MOD * numwells)%MOD;
    //         ll t2 = (((2*d)%MOD * numwells)%MOD * wellsum)%MOD;
    //         dbg(d,t1,t2);
    //         ans += t1;
    //         ans %= MOD;
    //         ans += t2;
    //         ans %= MOD;

    //         treesum += e.first;
    //         treesum %= MOD;
    //         lasttreex = e.first;
    //         numtrees++;
    //     }
    //     else
    //     {
    //         // this is a well, compute for trees

    //         ll d = (e.first-lasttreex+MOD)%MOD;
    //         ll t1 = ((d*d)%MOD * numtrees)%MOD;
    //         ll t2 = (((2*d)%MOD * numtrees)%MOD * treesum)%MOD;
    //         dbg(d,t1,t2);
    //         ans += t1;
    //         ans %= MOD;
    //         ans += t2;
    //         ans %= MOD;

    //         wellsum += e.first;
    //         wellsum %= MOD;
    //         lastwellx = e.first;
    //         numwells++;
    //     }
    //     dbg(ans);
    // }
    // numwells = 0;
    // numtrees = 0;
    // treesum = 0;
    // wellsum = 0;

    // for(auto e:ydist)
    // {
    //     if(e.second)
    //     {
    //         // this is a tree, compute for wells

    //         ll d = (e.first-lastwelly+MOD)%MOD;
    //         ll t1 = ((d*d)%MOD * numwells)%MOD;
    //         ll t2 = (((2*d)%MOD * numwells)%MOD * wellsum)%MOD;
    //         ans += t1;
    //         ans %= MOD;
    //         ans += t2;
    //         ans %= MOD;

    //         treesum += e.first;
    //         treesum %= MOD;
    //         lasttreey = e.first;
    //         numtrees++;
    //     }
    //     else
    //     {
    //         // this is a well, compute for trees

    //         ll d = (e.first-lasttreey+MOD)%MOD;
    //         ll t1 = ((d*d)%MOD * numtrees)%MOD;
    //         ll t2 = (((2*d)%MOD * numtrees)%MOD * treesum)%MOD;
    //         ans += t1;
    //         ans %= MOD;
    //         ans += t2;
    //         ans %= MOD;

    //         wellsum += e.first;
    //         wellsum %= MOD;
    //         lastwelly = e.first;
    //         numwells++;
    //     }
    // }




    ll numtrees = 0, sqtrees = 0, sumtrees = 0;
    ll numwells = 0, sqwells = 0, sumwells = 0;

    for(auto e: xdist)
    {
        if(e.second)
        {
            // this is a tree, compute for wells and update trees

            ll t1 = 0;
            t1 = (e.first*e.first)%MOD;
            t1  *= numwells;
            t1 %= MOD;

            ll t2 = 0;
            t2 = sqwells%MOD;

            ll t3 = 0;
            t3 = (2*e.first)%MOD;
            t3 *= sumwells;
            t3 %= MOD;

            ans += t1;
            ans %= MOD;
            ans += t2;
            ans %= MOD;
            ans -= t3;
            ans += MOD;
            ans %= MOD;


            numtrees++;
            sqtrees += (e.first*e.first)%MOD;
            sqtrees %= MOD;
            sumtrees += e.first;
            sumtrees %= MOD;
        }
        else
        {
            // this is a well, compute for trees and update wells
            
            ll t1 = 0;
            t1 = (e.first*e.first)%MOD;
            t1  *= numtrees;
            t1 %= MOD;

            ll t2 = 0;
            t2 = sqtrees%MOD;

            ll t3 = 0;
            t3 = (2*e.first)%MOD;
            t3 *= sumtrees;
            t3 %= MOD;

            ans += t1;
            ans %= MOD;
            ans += t2;
            ans %= MOD;
            ans -= t3;
            ans += MOD;
            ans %= MOD;


            numwells++;
            sqwells += (e.first*e.first)%MOD;
            sqwells %= MOD;
            sumwells += e.first;
            sumwells %= MOD;

        }
    }
    numtrees = 0; sqtrees = 0; sumtrees = 0;
    numwells = 0; sqwells = 0; sumwells = 0;


    for(auto e: ydist)
    {
        if(e.second)
        {
            // this is a tree, compute for wells and update trees
            
            ll t1 = 0;
            t1 = (e.first*e.first)%MOD;
            t1  *= numwells;
            t1 %= MOD;

            ll t2 = 0;
            t2 = sqwells%MOD;

            ll t3 = 0;
            t3 = (2*e.first)%MOD;
            t3 *= sumwells;
            t3 %= MOD;

            ans += t1;
            ans %= MOD;
            ans += t2;
            ans %= MOD;
            ans -= t3;
            ans += MOD;
            ans %= MOD;


            numtrees++;
            sqtrees += (e.first*e.first)%MOD;
            sqtrees %= MOD;
            sumtrees += e.first;
            sumtrees %= MOD;

        }
        else
        {
            // this is a well, compute for trees and update wells
                        
            ll t1 = 0;
            t1 = (e.first*e.first)%MOD;
            t1  *= numtrees;
            t1 %= MOD;

            ll t2 = 0;
            t2 = sqtrees%MOD;

            ll t3 = 0;
            t3 = (2*e.first)%MOD;
            t3 *= sumtrees;
            t3 %= MOD;

            ans += t1;
            ans %= MOD;
            ans += t2;
            ans %= MOD;
            ans -= t3;
            ans += MOD;
            ans %= MOD;


            numwells++;
            sqwells += (e.first*e.first)%MOD;
            sqwells %= MOD;
            sumwells += e.first;
            sumwells %= MOD;


        }
    }




    cout << "Case #" << tc << ": " << ans << "\n";
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("watering_well_chapter_1_input.txt", "r", stdin);
    // freopen("watering_well_chapter_2_validation_input.txt","r",stdin);
    freopen("watering_well_chapter_2_input.txt","r",stdin);

    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test;
    cin >> test;
    for (int i = 1; i <= test; i++) solve(i);
    return 0;
}
