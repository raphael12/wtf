#include <stdio.h>

int main() {
	int i, j;
	scanf("%d %d", &i, &j);
	int mat[i][j];
	int k, m;
	int copy;
	for(k=0;k<i;k++) {
		for(m=0; m<j; m++){
			scanf("%d", &mat[k][m]);
		}
	}
	printf("\n________________________________________\n");
	
	for(k=0;k<i;k++) {
		for(m=0; m<j; m++){
			printf("%d ", mat[k][m]);	
		}
		printf("\n\n");
	}
	printf("\n________________________________________\n");
	

	for(m=0;m<j;m++) {
		for(k=0; k<i; k++){
			printf("%d ", mat[k][m]);	
		}
		printf("\n\n");
	}
}
