#include <iostream>
using namespace std;

Person addDate(Person a){

        a.Date=newDate();
        return a;
}


int plus5(int a){

    return a+5;
}

int main(int argc, char const *argv[])
{
    Person SunKyu;
    SunKyu=Newperson();
    SunKyu=addDate(SunKyu);
    return 0;
}