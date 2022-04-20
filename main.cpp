#include <iostream>
#include <algorithm>
using namespace std;
int n;
int sequence[20000];
int dp[10000];
int pos[20000];
int ans[20000];


int main() {
    cin>>n;
    if(n==0){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;++i){
        cin>>sequence[i];
    }
    dp[1]=sequence[1];
    int len=1;
    pos[1]=1;
    for(int i=2;i<=n;++i){
        if(sequence[i]>dp[len]) {
            dp[++len]=sequence[i];
            pos[i]=len;
        }
        else{
            int j=lower_bound(dp+1,dp+len+1,sequence[i])-dp;
            dp[j]=sequence[i];
            pos[i]=j;
        }
    }
    cout<<len<<endl;
    int temp=len;
    for(int i=n;i>0;i--){
        if(!len) break;
        if(pos[i]==len){
            ans[len--]=sequence[i];
        }
    }
    for(int i=1;i<=temp;i++){
        cout<<ans[i]<<' ';
    }

}