// 2014.10.01
//SunKyu Lee

#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;


/*
*   first divide whole use O(n) algorithm 
*   divide the whole input untill the length is 1
*   base cases are lentgh is 1 and the forhead part last sum is nagative or 0  
*/
void check(int first, int last, int a[], int sum[]){
    if(first==last){
        return;
    }
    int mid1= (first+last)/2;
    check(first, mid1, a, sum);
    check(mid1+1, last, a, sum);
    
    int mid = (first+last)/2;
    int com = sum[mid];

    //the case of forhead part's last sum is nagative
    if(com<=0)
        return;
    /*
    * use O(n) algorithm
    */
    for (int i = mid+1; i < last+1; ++i)
    {
        if(sum[i-1]+a[i]>0)
            sum[i]=a[i]+sum[i-1];
        else{
            sum[i]=a[i];
            break;
        }
    }
}


/*
* Start of Recursive function
*/
void build(int a[], int sum[], int size){
    int first=0;
    int last=size-1;
    int mid= (first+last)/2;
    for(int i=0 ;i<size ; i++ ){
        sum[i]=a[i];
    }
    check(first, last, a, sum);
}

int main (int argc, char* argv[]){
    fstream IN;
    IN.open(argv[1]);
    clock_t start;//start time
    clock_t end;//endtime
    auto n=0;//input num
    IN >> n;
    int count=0;
    int finalcount=0;
    int value[n];//input value
    int * qsum= new int[n];
    int maxSum=qsum[0];
    for (auto i = 0; i < n; i++){
        IN >> value[i];
    }
    start = clock();
    build(value, qsum, n);//for the Recursive

    /*
    *  find maxSum 
    *  count the continueous the number of positive sum
    *  when maxSum is same at sum, if the finalcount is smaller than count, then keep store the number 
    */
    for (int i=0; i<n; i++) {
        if (qsum[i]>0)
        {
            count++;
        }
        else
            count=0;
        if (maxSum<qsum[i]) {
            maxSum=qsum[i];
            finalcount=count;
        }
        else if (maxSum==qsum[i])
        {
            if (finalcount>count)
            {
                finalcount=count;
            }
        }
    }
    cout<<finalcount<<" "<<maxSum<<endl;
    end = clock();
    printf("%lf \n",((double)(end - start))/CLOCKS_PER_SEC);
    delete [] qsum;
    cout<<endl;
}
