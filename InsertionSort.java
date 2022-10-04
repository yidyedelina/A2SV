import java.util.List;

public class InsertionSort {
    public static void insertionSort1(int n, List<Integer> arr) {
        // Write your code here
        int j = arr.size() - 1;
        int temp = arr.get(j);
        for(; j >= 0; j--){
            if(j == 0){
                arr.set(j  , temp);
                for(int k = 0; k <= arr.size() - 1; k++){
                    if (k != arr.size() - 1) {
                        System.out.print(arr.get(k) + " ");
                    } else {
                        System.out.println(arr.get(k));
                    }
                }
                break;
            }
            else if(temp < arr.get(j - 1)){
                arr.set(j, arr.get(j - 1));
                for(int k = 0; k < arr.size(); k++){
                    if (k != arr.size() - 1) {
                        System.out.print(arr.get(k) + " ");
                    } else {
                        System.out.println(arr.get(k));
                    }
                }
            }else {
                arr.set(j  , temp);
                for(int k = 0; k <= arr.size() - 1; k++){
                    if (k != arr.size() - 1) {
                        System.out.print(arr.get(k) + " ");
                    } else {
                        System.out.println(arr.get(k));
                    }
                }
                break;
            }
        }

    }
}
