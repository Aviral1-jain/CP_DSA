//https://practice.geeksforgeeks.org/problems/heap-sort/1
O(NlogN)
class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
      // Your Code Here
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
    
        if(left<n && arr[largest]<arr[left]){
            largest=left;
        }
        if(right<n && arr[largest]<arr[right]){
            
            largest=right;
        }
    
        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
    
        return;
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    // Your Code Here
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    
    
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
        buildHeap(arr,n);
        int size=n;
        while(size>0){
            swap(arr[0],arr[size-1]);
            size--;
            heapify(arr,size,0);
        }
        return;
        
    }
};