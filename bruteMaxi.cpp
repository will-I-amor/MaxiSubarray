#include <iostream>
#include <vector>
using namespace std;
void vecPush(vector<int>&vec){
	vec.push_back(2);
	vec.push_back(6);
	vec.push_back(-20);
	vec.push_back(-100);
	vec.push_back(-50);
}
int brute_maxi(vector<int>vec){
	int max = vec[0];
	int sum;
	for(int i = 0;i<vec.size();i++){
		for(int j = i;j<vec.size();j++){
			sum =0;
			for(int k = i;k<=j;k++){
				sum = vec[k] + sum;//我之前写的是sum = sum + v[i]+v[k];和sum = v[i]+ v[k]
			}
			if(sum > max){
				max = sum;
			}
		}
	}
	return max;
}
int main(){
	vector<int>myVec;
	vecPush(myVec);
	int n = 0;
	n = brute_maxi(myVec);
	cout<<"n is: "<<n<<endl;
	return 0;
}



