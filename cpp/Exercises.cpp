#include<iostream>

using namespace std;
//Question 8
int countOnes(int n){
	int k=0;
	while(n>0){
		int rem = n%2;
		if(rem ==1){
			k++;
		}
		n=n/2;
	}
	return k;
}
//Question 10
int isOddValent(int arr[], int n){
	int count=0;
	bool containsOdd=false;
	for(int i=0;i<n;i++){	
		if((arr[i]%2 )!=0){
			containsOdd=true;
		}
		for(int j=i+1;j<n;j++){
			if(arr[j] == arr[i]){
				count++;
				break;
			}
		}
	}
	if(count>0 and containsOdd==true){
		return 1;
	}
	return 0;
}
// Question 15

bool isPrime(int n){
	if(n<1){
	return false;
	}
	for(int i=2;i<n/2;i++){
		if(n%i == 0){
			return false;
		}
	}
	return true;
}

int isFineArr(int arr[],int n){
	for(int i=0;i<n;i++){
		bool prime = isPrime(arr[i]);
		if(prime){
			for(int j=0;j<n;j++){
				if(arr[j] = arr[i]+2 || arr[j] == arr[i]-2){
					if(isPrime(arr[j])){
					return 1;	
					}
				}
			}
		}
	}
	return 0;
}


int main(){
//	int ones = countOnes(9);
	int arr[] = {4, 7, 9, 6,5,5};
	int size = sizeof(arr)/sizeof(arr[0]);
//	cout<<isPrime(4);
//	cout<<isOddValent(arr,size)<<endl;
	cout<<isFineArr(arr,size)<<endl;
//	cout<<ones<<endl;
}
