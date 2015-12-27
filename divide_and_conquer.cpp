#include <iostream>
using namespace std;
const int infinite = -10000;
int findCrossingSum(int a[],int low, int mid,int high){
	int sum = 0;
	int left_sum = infinite;
	for(int i = mid;i>=0;i--){//之前的bug，是因为写了i>0,少写了等号。结果大bug
		sum = sum + a[i];
		if(sum>left_sum){
			left_sum = sum;
			//int max_left = i;
		}
	}
	sum = 0;
	int right_sum = infinite;
	for(int i = mid + 1;i<high;i++){
		sum = sum + a[i];
		if(sum>right_sum){
			right_sum = sum;
			//int max_right = i;
		}
	}
	return (left_sum+right_sum);
}
int findMaxiSubArray(int a[],int low, int high){
	int right_total, left_total, cross_total;
	if(high == low){return a[low];}
	else{
		int mid = (low + high)/2;//以前只写了high/2
		left_total = findMaxiSubArray(a,low,mid);
		right_total = findMaxiSubArray(a,mid+1,high);
		cross_total = findCrossingSum(a,low,mid,high);
		if(left_total>=right_total && left_total>=cross_total){return left_total;}
		else if(right_total>=left_total && right_total>=cross_total){return right_total;}
		else{return cross_total;}
	}
}
int main(){
	int a[]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	int high = sizeof(a)/sizeof(int);
	int total;
	total = findMaxiSubArray(a,0,high);
	cout<<total<<endl;
	return 0;
}





