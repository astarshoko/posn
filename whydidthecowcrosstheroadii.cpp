#include<bits/stdc++.h>
using namespace std;
int ans(int a[], bool check[]){
    int b=0;
    for(int i=0;i<26;i++){
        if(a[i]==1 && check[i])b++;
    }
    return b;
}

void setzero(int a[]){
    int i;
    for(i=0;i<26;i++){
        a[i]=0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("circlecross.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("circlecross.out", "w", stdout);
    string s;
    cin >> s;
    int n=s.length(), i, j;//n = 52
    int a[26], lastans=0;
    setzero(a);
    bool check[26];
    int checks=0;
    for(i=0;i<26;i++)check[i]=true;
    for(i=0;i<n;i++){
        if(check[s[i]-'A']){
            checks++;
            j=i+1;
            while(s[j]!=s[i]){
                a[s[j]-'A']++;
                //cout << s[j] << " ";
                j++;
            }
            //cout << endl;
            lastans+=ans(a,check);
            setzero(a);
            check[s[i]-'A']=false;
        }
    }
    cout << lastans;
}