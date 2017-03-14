#include<iostream>
#include<vector>
using namespace std;


//in O(nlogn) - similar to mergesort

int max_subarray_sum(int arr[], int n)
{

	if(n==1){
		return arr[0];
	}

	int m=n/2;
	int left_MSS = max_subarray_sum(arr, m);
	int right_MSS = max_subarray_sum(arr+m, n-m);
	int leftsum = 0;
	int rightsum = 0;
	int sum = 0;

	for (int i = m; i < n; ++i)
	{
		sum += arr[i];
		rightsum = max(rightsum, sum);
	}

	sum = 0;

	for (int i = m-1; i >= 0; --i)
	{
		sum += arr[i];
		leftsum = max(leftsum, sum);	
	}

	int ans = max(left_MSS, right_MSS);
	return max(ans, leftsum + rightsum);

}

int main()
{
	int n1;
	cin >> n1;
	int a[n1];
	for (int i = 0; i < n1; ++i)
	{
		cin >> a[i];
	}

	int res = max_subarray_sum(a, n1);
	cout << res;
	return 0;
}


// O(n^2) solution

// int Solution::maxSubArray(const vector<int> &A) {
//     // Do not write main() function.
//     // Do not read input, instead use the arguments to the function.
//     // Do not print the output, instead return values as specified
//     // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
//     int sum = 0;
//     int tsum = 0;
//     int ans = 0;
    
//     for(int i=0; i<A.size(); i++){
//         if(A[i]<ans){
//             ans = A[i];
//         }
//     }
        
//         for(int i=0; i<A.size(); i++){
//             //int sum = 0;
//             for(int j=1; j<=A.size(); j++){
                
//                 if(i+j>A.size())
//                     break;
                 
//                 sum += A[i+j-1];
//                  //cout << tsum << " ";
//                 ans = max(ans,sum);
//             }
            
//             sum = 0;
            
//         }

    
//     return ans;
// }