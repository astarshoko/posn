#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, i, j;
    cin >> n;
    vector<pair<double,int>> v;
    for(i=0;i<n;i++){
        double m;
        cin >> m >> j;
        v.push_back({m/j,j});
    }
    sort(v.begin(),v.end());
    cin >> n;
    for(i=0;i<n;i++){
        double d=0;
        cin >> j;
        while(true){
            if(j>=v[0].second){
                d+=v[0].second*v[0].first;//
                j-=v[0].second;
                v.erase(v.begin());
            }
            else{
                d+=j*v[0].first;
                v[0].second-=j;
                //cout << " " << i << " " << v[0].second << endl;
                break;
            }
        }
        cout << fixed << setprecision(3) << d << "\n";
    }
}
/*
5 10 10 5 10 2000 100 5 5 2 5 5 3 5 5 20 10 
*/