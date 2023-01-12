#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int> m = {{"Bessie",0},{"Elsie",0},{"Daisy",0},{"Gertie",0},{"Annabelle",0},{"Maggie",0},{"Henrietta",0}};

int main(){
    //freopen("notlast.in", "r", stdin);
	//freopen("notlast.out", "w", stdout);
    int n, i;
    //map<string,int> m;
    cin >> n;
    for(i=0;i<n;i++){
        string s;
        int b;
        cin >> s >> b;
        m[s]+=b;
    }
    set<int> a;
    i=0;
    vector<pair<int,string>> v;
    for(auto x : m){
        v.push_back({x.second,x.first});
        a.insert(x.second);
    }
    sort(v.begin(),v.end());
    for(auto x : a){
        //cout << x << " ";
    }
    int count=v[0].first;
    if((a.size()==1 || a.size()==2)&&n!=1){
        cout << "Tie" << "\n";
    }
    else{
        for(i=0;i<7;i++){
            if(count!=v[i].first){
                cout << v[i].second << "\n";
                return 0;
            }
        }
    }
}
/*
set<int> a;
    vector<pair<int,string>> v;
    for(auto x : m){
        string s;
        int b;
        s=x.first;
        b=x.second;
        v.push_back({b,s});
    }
    sort(v.begin(),v.end());
    int check=-1;
    for(i=0;i<n;i++){
        if(i==0)check=v[0].first;
        else{
            if(v[i].first!=check){
                cout << v[i].second;
                return 0;
            }
        }
    }

}
*/