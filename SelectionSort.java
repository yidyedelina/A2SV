import java.util.ArrayList;
import java.util.List;

public class SelectionSort {
    int  select(int arr[], int i)
    {
        // code here such that selectionSort() sorts arr[]
        int min = arr[i];
        int minIndex = i;
        for(int j = i; j < arr.length; j++){
            if(arr[j] < min){
                min = arr[j];
                minIndex = j;
            }
        }
        return minIndex;
    }

    void selectionSort(int arr[], int n)
    {
        //code here
        for(int i = 0; i < n; i++){
            int index = select(arr, i);
            int temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
        }

    }
    public static void main(String[] args){
        int[] arr = {4, 3, 1,5, 2};
        SelectionSort s = new SelectionSort();
        s.selectionSort(arr,5);
        for(Integer it: arr){
            System.out.println(it);
        }
    }
}
