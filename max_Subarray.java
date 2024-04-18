import java.util.Scanner;

class solution {
    public static int maxSubArray(int[] nums) {
        int maxSub = Integer.MIN_VALUE;
        int curr_sum = 0;

        for(int i = 0 ;i < nums.length; i++){
            curr_sum += nums[i];
            if(curr_sum < nums[i]) curr_sum = nums[i];
            if(maxSub < curr_sum){
                maxSub = curr_sum;
            }
            
        }
        return maxSub;
    }
}

public class max_Subarray{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i = 0; i < arr.length; i++){
            arr[i] = sc.nextInt();
        }
        System.out.println(solution.maxSubArray(arr));
    }
}
