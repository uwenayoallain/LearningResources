#include<iostream>

using namespace std;

int countOc(int n , int d){
	int count =0;
	while(n!=0){
		if(n% 10 == d){
			count++;
		}
		n= n/10;
	}
	return count;
}
int maxCount(int n){
	int maxNumber = -1;
	int maxCount = 0;
	for(int d=0;d<=9;d++){
		int count = countOc(n,d);
		if(count > maxCount){
			maxCount = count;
			maxNumber = d;
		}
	}
	return maxNumber;
}

int main(){
	return 0;
	int count = maxCount(550029499);
	cout<<count<<endl;
}
