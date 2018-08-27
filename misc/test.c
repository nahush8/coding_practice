#include<stdio.h>

void myFunc(int *ptr){
	*ptr = 20;

}

int main(){
int a = 10;
int *p = &a;
printf("\nValue of a before the function call: %d\n",*p);
myFunc(p);
printf("\nValue of a after the function call: %d\n",*p);

return 0;
}
