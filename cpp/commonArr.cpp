#include<iostream>

using namespace std;

Pair<int*,int> getCommon(int arr1[],int arr2[], int n1, int n2){
	if(!arr1||!arr2){
		return {NULL,0};
	}
	int s1,s2;
	int* outerarr;
	int* innerarr;
	if(n1<n2){
		s1=n1;
		s2=n2;
		outerarr=arr1;
		innerarr = arr2;
		
	}else{
		outerarr =arr2;
		innerarr =arr1;
		s1=n2;
		s2=n1;
	}
	int* carr;
	int k=0;
	for(int i =0;i<s1;i++){
		for(int j=0;j<s2;j++){
			if(outerarr[i]==innerarr[j]){
				*(carr+k)=outerarr[i];
				k++;
				break;
			}
		}
	}
	return {carr,k};
}

int main(){
	int arr[]={2,4,5,6,10,3,5};
	pair<int*,int> result= Return Common
}
