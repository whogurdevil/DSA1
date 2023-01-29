#include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int s, int e){
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
		while(arr[i] < pivot){
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

void sortArr(int *arr, int s, int e){
	//base case
	if(s >= e)
		return;

	int p = partition(arr, s, e);
	
	//left part
	sortArr(arr, s, p-1);

	//right part
	sortArr(arr, p+1, e);


}

int main(){

	int size  = 7;
    int arr[size] = {7,6,0,4,3,2,1};

    sortArr(arr, 0, size-1);

    for(int i = 0; i< size; i++){
        cout << arr[i] << " ";
    }

return 0;
}
