#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    int test;
    cin >> test;
    while (test--) {
        long long a, b;
        cin >> a >> b;
        long long index = 1;
        while(1){
            if(a * index < b){
                index++;
            }
            else{
                long long A=a*index-b;
                a=A;
                b = b*index;
                if(a==0){
                    cout<<index<<endl;
                    break;
                }
                index++;
            }
        }
    }
}








