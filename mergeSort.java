import java.io.*;
public class MergeSort{
    public static void main(String [] args){
        int [] arr={20,78,12,55,98,22,34,20,10,45};
        int [] merged =mergeSort(arr,0,arr.length-1);
        for(int val:merged){
            system.out.print(val+"");
        }
    }
    public static int[] mergeSort(int[]arr,int lo,int hi){
        if(lo==hi){
            int []br=new int[1];
            br[0]=arr[0];
            return br;
        }
        int mid =(lo+hi)/2;
        int []fh =mergeSort(arr,lo,mid);
        int []sh= mergeSort(arr,mid+1,hi);

        int[] merged=mergeTwoSortedArrays(fh,sh);

        return merged;
    }
    public static int[] mergeTwoSortedArrays(int []one,int []two){
        int sorted =new int [one.length+two.length];
        int i=0;
        int j=0;
        int k=0;

        while(i<one.length&& j<two.length){
            if(one[i]<two[j]){
                sorted[k]=one[i];
                k++;
                i++;
            }
            else{
                sorted[k]=two[j];
                k++;j++;
            }
        }
        if(i==one.length){
            while(j<two.length){
                sorted[k]=two[j];
                k++;
                j++;
            }
        }
        if(j==two.length){
            while(i<one.length){
                sorted[k]=one[i];
                k++;
                i++;
            }
        }
        return sorted;
    }
}
