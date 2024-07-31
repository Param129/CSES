#include<bits/stdc++.h>
using namespace std;

#define int long long
signed main(){
    int n,tar;
    cin>>n>>tar;
    vector<pair<int,int>>a(n);

    for(int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second=i+1;
    }

    sort(a.begin(),a.end());

    for(int i=0;i<n-3;i++){
        for(int j=i+1;j<n-2;j++){
            int k=j+1;
            int l=n-1;
            while(k<l){
                int sum=a[i].first+a[j].first+a[k].first+a[l].first;
                if(sum==tar){
                    cout<<a[i].second<<" "<<a[j].second<<" "<<a[k].second<<" "<<a[l].second;   
                    return 0;             
                }
                else if(sum>tar){
                    l--;
                }
                else{
                    k++;
                }
            }
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}