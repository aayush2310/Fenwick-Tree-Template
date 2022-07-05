//Binary Lifting on Fenwick Tree//
int bin_lift(int k){
    int curr_index=0,curr_sum=0;
    //N=length of the array
    for(int i=log2N;i>=0;i--){
        if(curr_sum+fen[curr_index+1<<i]<k){
            curr_index=curr_index+(1<<i);
            curr_sum+=fen[curr_index];
        }
    }
    return(curr_index+1);
}
