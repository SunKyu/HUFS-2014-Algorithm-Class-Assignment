#include <iostream>
#include <algorithm>
using namespace std;

int planet[4000];

int main (void)
{
    int T=0;
    int N;
    cin>>T;
    int temp=T;
    int sub=0;
    while(temp--){
        cin>>N;
        int maxsub;
        for(int i=0 ; i<N; i++){
            cin>>planet[i];
        }
        sort(planet, planet+N);
        
        for(int i =0; i<N; i++)
            cout<<planet[i]<<" ";
    }
}
