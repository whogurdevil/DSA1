#include <bits/stdc++.h> 
using namespace std;

int partition(vector<int>& arr, int s, int e){
	int smallcount = 0;
	int pivot = arr[s];

	for(int i = s+1; i <= e; i++){
		if(arr[i] <= pivot){
			smallcount++;
		}
			
	}
	int pivotindex = s+smallcount;
	swap(arr[s], arr[pivotindex]);

	int i = s, j = e;
	while (i < pivotindex &&  j > pivotindex)
	{
		while(arr[i] <= pivot){
			i++;
		}
		while(arr[j] > pivot){
			j--;
		}
		if(i < pivotindex &&  j > pivotindex){
			swap(arr[i++], arr[j--]);
		}
	}

	return pivotindex;
	
}

void sortArr(vector<int>& arr, int s, int e){
	//base case
	if(s >= e)
		return;

	int p = partition(arr, s, e);
	
	//left part
	sortArr(arr, s, p-1);

	//right part
	sortArr(arr, p+1, e);


}
vector<int> quickSort(vector<int> arr)
{
    sortArr(arr, 0, arr.size()-1);
    return arr;
}
