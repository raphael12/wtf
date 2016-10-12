#include <stdio.h>

struct point {
	int x,y;
};

int main() {
    struct point a, b, c, d;
	int point1, point2, point3;
	scanf("%d %d", &a.x, &a.y);
	scanf("%d %d", &b.x, &b.y);
	scanf("%d %d", &c.x, &c.y);
	scanf("%d %d", &d.x, &d.y);
	point1=(a.x-d.x)*(b.y-a.y)-(b.x-a.x)*(a.y-d.y);
	point2=(b.x-d.x)*(c.y-b.y)-(c.x-b.x)*(b.y-d.y);
	point3=(c.x-d.x)*(a.y-c.y)-(a.x-c.x)*(c.y-d.y);
	
	if((point1 > 0 && point2 > 0 && point3 > 0) || (point1 < 0 && point2 < 0 && point3 < 0)) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	
}	

	
