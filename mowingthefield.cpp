#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("mowing.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("mowing.out", "w", stdout);
    int n, i, j;
    cin >> n;
    char inputc[n];
    int inputv[n];
    int z=0;
    for(i=0;i<n;i++){
        cin >> inputc[i] >> inputv[i];
        z+=inputv[i];
    }
    int xyt[z][3]; for(i=0;i<3;i++)xyt[0][i]=0;//X Y and TIME
    int state=1;
    z=0;
    int t=1;
    for(i=0;i<n;i++){
        if(inputc[i]=='N' || inputc[i]=='S'){
            if(inputc[i]=='N')state=1;
            else state=-1;
            for(j=0;j<inputv[i];j++){
                if(z==0){
                xyt[z][1]+=state; xyt[z][0]=0; xyt[z][2]=1;
                z++;
                }
                else{
                xyt[z][1]=xyt[z-1][1]; xyt[z][0]=xyt[z-1][0]; xyt[z][2]=xyt[z-1][2];
                xyt[z][2]++;
                xyt[z][1]+=state;
                z++;
                t++;
                }
            }
        }
        else{
            if(inputc[i]=='E')state=1;
            else state=-1;
            for(j=0;j<inputv[i];j++){
                if(z==0){
                xyt[z][1]+=state; xyt[z][0]=0; xyt[z][2]=1;
                z++;
                }
                else{
                xyt[z][1]=xyt[z-1][1]; xyt[z][0]=xyt[z-1][0]; xyt[z][2]=xyt[z-1][2];
                xyt[z][2]++;
                xyt[z][0]+=state;
                z++;
                t++;
                }
            }
        }
    }
    int ans=-1;
    bool firstvisit=true;
    for(i=0;i<z;i++){
        for(j=i+1;j<z;j++){
            if((xyt[i][0]==xyt[j][0])&&(xyt[i][1]==xyt[j][1])&&firstvisit){
                ans=xyt[j][2]-xyt[i][2];
                firstvisit=false;
            }
            else if((xyt[i][0]==xyt[j][0])&&(xyt[i][1]==xyt[j][1])){
                if(xyt[j][2]-xyt[i][2]<ans){
                    ans=xyt[j][2]-xyt[i][2];
                }
            }
        }
    }
    cout << ans;
    /*
    for(i=0;i<z;i++){
        for(j=0;j<3;j++){
            cout << xyt[i][j] << " ";
        }
        cout << endl;
    }
    */
}