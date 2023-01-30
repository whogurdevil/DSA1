//{ Driver Code Starts
#include <stdio.h>
 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int select(int arr[], int i);
void selectionSort(int arr[], int n);
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[1000],n,T,i;
  
    scanf("%d",&T);
    
    while(T--){
        
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      
    selectionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends


void solve(int *arr, int size, int ind){
    if(size == 0 || size ==1){
        return;
    }
    
    if(ind == size - 1){
        return;
    }
    
    for(int i = ind+1; i<size; i++){
        if(arr[i] < arr[ind]){
            int temp = arr[i];
            arr[i] = arr[ind];
            arr[ind] = temp;
        }
    }
    
    solve(arr, size, ++ind);
}

int select(int arr[], int i)
{
    // code here such that selecionSort() sorts arr[]
}


void selectionSort(int arr[], int n)
{
  solve(arr, n, 0);
}