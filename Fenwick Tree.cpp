//FENWICK TREE TEMPLATE//
class fenTree{
private:
    vector<int>fen;
    vector<int>arr;
public:
    fenTree(vector<int>v){
        int n=v.size();
        arr.resize(n+1);
        arr[0]=0;
        for(int i=0;i<n;i++){
            arr[i+1]=v[i];
        }
        fen.resize(n+1);
        memset(fen,0,sizeof(fen));
    }
    void build(){
        for(int i=1;i<arr.size();i++){
            update(i,arr[i]);
        }
    }
    void update(int idx,int val){
        int n=arr.size();
        while(idx<n){
            fen[idx]+=val;
            idx=idx+(idx&(-idx));
        }
    }
    int rangesum(int l,int r){
        return(sum(r)-sum(l-1));
    }
    int sum(int idx){
        int s=0;
        while(idx>0){
            s=s+fen[idx];
            idx=idx-(idx&(-idx));
        }
        return(s);
    }
};

int main(){
    //TEST CASES
    int t;
    cin>>t;
    while(t){
        solve();
        t--;
    }
    return(0);
}
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int u=0;u<n;u++){
        cin>>arr[u];
    }
    fenTree fen1(arr);
    fen1.build();
    int idx,val;
    cin>>idx>>val;
    fen1.update(idx,val);
    int l,r;
    cin>>l>>r;
    cout<<rangesum(l,r)<<endl;
    return;
}
