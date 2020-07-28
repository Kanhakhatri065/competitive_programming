#include <iostream>

using namespace std;

void fastscan(int &x){
    bool neg=false;
    register int c;
    x =0;
    c=getchar();
    if(c=='-')
    {
        neg = true;
        c=getchar();
    }
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1) + (x<<3) +c -48;
    if(neg)
        x *=-1;
}

int main(){
    int size, num_queries;
    fastscan(size);
    fastscan(num_queries);
    
    int arr[size];
    for(int i = 0;i < size;i++){
        fastscan(arr[i])
    }

    int sum,counter;
    for(int i = 0;i < num_queries;i++){
        sum = 0;
        counter = 0;
        int lower,upper;
        fastscan(lower);
        fastscan(upper);

        for(int j = lower - 1;j <= (upper - 1);j++){
            counter++;
            sum = sum + arr[j];
        }

        int mean = sum / counter;
        printf("%d\n",mean);
    }    
    return 0;
}