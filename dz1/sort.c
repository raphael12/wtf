#include <stdio.h> 
#include <stdlib.h>

void swap(int32_t* a, int32_t lhs, int32_t rhs) {
	int32_t tmp = a[lhs];
	a[lhs] = a[rhs];
	a[rhs] = tmp;
}


void insertion_sort(int32_t* a, int32_t n) {
	int32_t i;
	for (i = 1; i < n; ++i) {
		int32_t j = i;
		while (j > 0 && a[j - 1] > a[j]) { // push current to the left
			swap(a, j - 1, j);
			j--;
		}
	}
}

int main() {
	int n, i;
	scanf("%d", &n);
	int* mas;
	mas = (int *)malloc(n*sizeof(int));
	for(i = 0; i < n; i++)  {
		scanf("%d, ", &mas[i]);
    }
    
    insertion_sort(mas, n);
    
    for(i = 0; i < 10; i++) {
		printf("%d ", mas[i]);
    }
  
    return 0;
}
    
    
	
