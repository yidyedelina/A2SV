public class kclosest {
    public int[][] kClosest(int[][] points, int k) {
        quicksort(points, 0, points.length - 1);
        int[][] closest = new int[k][2];
        for(int i = 0; i < k; i++){
            closest[i][0] = points[i][0];
            closest[i][1] = points[i][1];
        }
        return closest;
    }
    public int compare(int[] arr, int[] arr1){
        if((Math.sqrt(arr[0] * arr[0] + arr[1] * arr[1])) <= (Math.sqrt(arr1[0] * arr1[0] + arr1[1] * arr1[1]))){
            return -1;
        }
        return 1;
    }
    public double distance(int a, int b){
        return Math.sqrt(a*a + b*b);
    }
    public void swap(int[][] arr, int low, int pivot){
        int[] tmp = arr[low];
        arr[low] = arr[pivot];
        arr[pivot] = tmp;
    }
    public int partition(int[][] arr, int low, int high){
        int p = low, j;
        for(j=low+1; j <= high; j++)
            if(distance(arr[j][0], arr[j][1]) <distance(arr[low][0], arr[low][1]))
                swap(arr, ++p, j);

        swap(arr, low, p);
        return p;
    }
    public void quicksort(int[][] arr, int low, int high){
        if(low < high){
            int p = partition(arr, low, high);
            quicksort(arr, low, p-1);
            quicksort(arr, p+1, high);
        }
    }

    public static void main(String[] args){
        int[][] arr = {{1,3},{-2,-2}};
        kclosest k = new kclosest();
        int[][] closest = k.kClosest(arr, 1);
        for(int i = 0; i < 1;i++){
            System.out.println(closest[i][0] + " " + closest[i][1]);
        }
    }

}
