#include <iostream>
#include <string>
using namespace std;
int va1, va2;
int first[300];
bool checkf[300];
int last[300];
bool checkl[300];

int Maxfirst(int num, int a[], int& val){
    int max=0;
    int temp;
    int value = 0;
    int maxval=0;
    for(int i=0; i<num ; i++){
        temp=0;
        value=0;
        if(checkf[i]==true)
            continue;
        for(int j=i; j<num; j++){
            if(a[i]==a[j]){
                temp++;
                value=a[i];
            }
            if(temp>=max){
                max=temp;
                maxval=a[i];
            }
        }
    }
    val=value;
    va1=maxval;
    return max;
}


int Maxlast(int num, int a[], int& val){
    int max=0;
    int temp;
    int value = 0;
    int maxval=0;
    for(int i=0; i<num ; i++){
        temp=0;
        value=0;
        
        if(checkl[i]==true)
            continue;
        for(int j=i; j<num; j++){
            if(a[i]==a[j]){
                temp++;
                value=a[i];
            }
            if(temp>=max){
                max=temp;
                maxval=a[i];
            }
        }
    }
    val=value;
    va2=maxval;
    return max;
}



int main (void){
    int n;
    cin>>n;
    string a; string b;
    while(true){
        if(n==0)
            break;
        for(int i = 0 ; i<n ; i++){
            cin>>a;
            cin>>b;
            first[i]=(int)a[0];
            last[i]=(int)b[0];
            if (last[i]==83||84||85||86||87||88||89) {
                checkl[i]=true;
            }
        }
        int val, val2;
        int anum , bnum;
        int count=0;
        while (true) {
            anum=Maxfirst(n, first, val);
            bnum=Maxlast(n, last, val2);
            //cout<<anum<<" ";
            //cout<<bnum<<endl;
            //cout<<val;
            if (anum>=bnum) {
                for(int i=0; i<n ; i++){
                    if(first[i]==va1){
                        checkl[i]=true;
                        checkf[i]=true;
                    }
                }
                count++;
            }
            else{
                for(int i=0; i<n ; i++){
                    if(last[i]==va2){
                        checkl[i]=true;
                        checkf[i]=true;
                    }
                    
                }
                count++;
            }
            bool end=false;
            for (int i=0; i<n; i++) {
                if (checkf[i]==false) {
                    end=true;
                }
            }
            if (end==false) {
                break;
            }
            
        }
        
        cout<<count<<endl;
        for(int i=0; i<n ; i++)
            if(checkl[i]==false)
                cout<<first[i]<<" ";
        cin>>n;
    }
    
    
    
}
