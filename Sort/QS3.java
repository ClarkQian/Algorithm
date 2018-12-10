package myTest;

public class Sort_Demo {
	public static void __Sort(int[] arr, int l, int r) {
		if(r-l <= 0)
			return;
		
		swap(arr, l, (int)(Math.random()*(r-l+1))+l);		
		int e = arr[l];
		int lt = l;
		int gt = r+1;
		int i = l + 1;
		while(i < gt) {
			if(arr[i] < e) {
				swap(arr, lt+1, i);
				lt++;
				i++;
			}
			else if(arr[i]> e) {
				swap(arr, i, gt-1);
				gt--;
			} else {
				i++;
			}
		}
		swap(arr, l, lt);
		__Sort(arr, l, lt-1);
		__Sort(arr, gt, r);
	}
	
	public static void Sort(int []arr) {
		__Sort(arr, 0, arr.length - 1);
	}
	public static void swap(int []a, int n1, int n2) {
		int t = a[n1];
		a[n1]= a[n2];
		a[n2] = t; 
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] a = new int[100];
		for(int i = 0; i < 100; i++)
			a[i] = 100 - i; 
		Sort(a);
		for(int i = 0; i < 100; i++)
			System.out.printf("%d ", a[i]);
		System.out.println();
	}

}
