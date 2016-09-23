#include <stdio.h> 
#include <conio.h> 



void insertion_sort(int* a, int n) {
	int i;
	for (i = 1; i < n; ++i) {
		int j = i;
		while (j > 0 && a[j - 1] > a[j]) { // push current to the left
			swap(a, j - 1, j);
			j--;
		}
	}
}

int main() {
	int n, i;
	scanf("%d", &n);
	int mas[n];
	for(i=0; i<n; i++)  {
		scanf("%d, ", &mas[i]);
    }
    
    insertion_sort(mas, n);
    
    for(i=0; i<10; i++) {
		printf("%d ", mas[i]);
    }
  
  return 0;
}
    
    
	
