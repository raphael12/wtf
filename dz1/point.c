#include <stdio.h>

struct point {
	int x,y;
};

int main() {
    struct point a, b, c, in;
	int point1, point2, point3;
	scanf("%d %d", &a.x, &a.y);
	scanf("%d %d", &b.x, &b.y);
	scanf("%d %d", &c.x, &c.y);
	scanf("%d %d", &in.x, &in.y);
	point1=(a.x-in.x)*(b.y-a.y)-(b.x-a.x)*(a.y-in.y);
	point2=(b.x-in.x)*(c.y-b.y)-(c.x-b.x)*(b.y-in.y);
	point3=(c.x-in.x)*(a.y-c.y)-(a.x-c.x)*(c.y-in.y);
	
	if((point1 >= 0 && point2 >= 0 && point3 >= 0) || (point1 =< 0 && point2 =< 0 && point3 =< 0)) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	
}	

	
