#include <iostream>
using namespace std;
int main(void){
    char c ='A';
    char* pc;
    pc=&c;
    cout<<&c<<endl;
    cout<<&pc<<endl;
    cout<<" "<<*pc<<endl;
}