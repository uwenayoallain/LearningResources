#include <iostream>
using namespace std;

int reverseNumber(int n){
    int revNumber = 0;
    while(n>0){
        int rem = n % 10;
        revNumber = revNumber * 10 + rem;
        n= n/10;
    }
    return revNumber;
}

int main(){
    int n = 123;
    cout<<reverseNumber(n)<<endl;
    return 0;
}