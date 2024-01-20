#include <iostream>
#include<queue>
using namespace std;

class heap
{
public:
    int arr[100];
    int size = 0;

    void insert(int val) //TC:O(logn)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void delete_ele() //TC:O(logn)
    {
        if(size == 0)
        {
            cout<<"heap is empty"<<endl;
            return;
        }
        
        arr[1]=arr[size];
        size--;

        //take root node to its correct position
        int i =1;
        while (i<size)
        {
            int left=2*i;
            int right =2*i+1;


            if(left<size && arr[i] < arr[left])
            {
                swap(arr[i],arr[left]);
                i=left;
            }
            else if(right <size && arr[i] <arr[right])
            {
            swap(arr[i],arr[right]);
            i=right;
            }else
            {
                return;
            }
        }
        
    }


    void print()
    {
        for (int  i = 1; i <= size; i++)
        {
           cout<<arr[i]<<" ";
        }
        cout<<endl;
        
    }
};

void heapify(int a[],int n,int i) //O(n)
{
    int largest = i;
    int left =2*i;
    int right=2*i+1;

    if(left<=n && a[largest] < a[left])
    {
        largest=left;
    }
    if (right<=n && a[largest] < a[right])
    {
       largest = right;
    }
    
    if (largest != i)
    {
        swap(a[largest],a[i]);
        heapify(a,n,largest);
    }
    
}

void heap_sort(int arr[],int n) //O(nlogn)
{
    int size=n;
    while (size>1)
    {
        swap(arr[1],arr[size]);
        size--;

        heapify(arr,size,1);
    }
    
}
int main()
{
    heap h;
    h.insert(50);
    h.insert(60);
    h.insert(20);
    h.insert(90);

    h.print();

    h.delete_ele();
    // h.delete_ele();
    h.print();

    int arr[6] = {-1,54,53,55,52,50};
    int n=5;
    for (int  i = n/2; i > 0; i--)
    {
        heapify(arr,n,i);
    }

    cout<<"Printing the array "<<endl;
    for (int  i = 1; i <= n; i++)
        {
           cout<<arr[i]<<" ";
        }
        cout<<endl;
    

    heap_sort(arr,n);

    cout<<"Printing sorted array "<<endl;
    for (int  i = 1; i <= n; i++)
        {
           cout<<arr[i]<<" ";
        }
        cout<<endl;

//can use priority queue to establish heaps

priority_queue<int>pq;  //max heap
pq.push(23);
pq.push(50);
pq.push(45);

cout<<"ON top "<<pq.top()<<endl;
pq.pop();
cout<<"ON top "<<pq.top()<<endl;
pq.pop();

}