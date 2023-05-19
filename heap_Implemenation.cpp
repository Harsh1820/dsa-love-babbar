#include <iostream>

using namespace std;

class heap
{

public:
    int arr[100];
    int size;

    heap(){

        arr[0]=-1;

        size=0;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {

                swap(arr[parent] < arr[index])
                    index = parent;
            }
            else
            {

                return;
            }
        }
    }

    void print()
    {

        for (int i = 0; i < size; i++)
        {
            cout << arr[i];
        }
        cout << endl;
    }


    void deletion(){
        arr[1] = arr[size];
        size--;

        if(size == 0){
            cout << "Nothing to delete" << endl;
            return;
        }


        // take root node to its correct position
        int i = 1;
        while(i<size){
            int leftIndex = 2*i;
            int rightIndex = 2*i + 1;

            if(leftIndex <= size || rightIndex <= size){
                if(arr[leftIndex] > arr[rightIndex]){
                    swap(arr[i] , arr[leftIndex]);
                    i = leftIndex;
                }
                else{
                    swap(arr[i] , arr[rightIndex]);
                    i = rightIndex;
                }
            }
            else return;
        }
    }


};

int main()
{

    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();
    return 0;
}