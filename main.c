#include<stdio.h>

// define the functions/sections
double f1(double x){
return x;
}

double f2(double x){
return -x;
}
double f3(double x){
return x*x;
}
double f4(double x){
return -x*x*x;
}
double f5(double x){
return (3*cos(x)-2*sin(4*x)-1)/2;
}

// function to compute maximum of an array -->for ymax
double max(double arr[],int size){
double mx = arr[0];
for(int i=1;i<size;i++)
if(arr[i]>mx)
mx = arr[i];
return mx;
}


int main(){
// menu
printf("\n 1. f(x) = x");
printf("\n 2. f(x) = -x");
printf("\n 3. f(x) = x^2");
printf("\n 4. f(x) = -x^3");
printf("\n 5. f(x) = (3*cos(x)-2*sin(4*x)-1)/2");
printf("\n\n 0. Exit\n");

int section;
double xbegin,xend,xstep,ystep;

printf("\n Section: "); scanf("%d",&section);
if(section==0)
exit(0);
printf("\n From: "); scanf("%lf",&xbegin);
printf("\n To: "); scanf("%lf",&xend);
printf("\n Step: "); scanf("%lf",&xstep);
int n = (int)((xend-xbegin)/xstep+1);

// populating the x and y arrays
double x[n],y[n];
switch(section){
case(1):
printf("\nFunction to print x\n");
x[0] = xbegin;
y[0] = f1(x[0]);
for(int i=1;i<n;i++){
x[i] = x[i-1] + xstep;
y[i] = f1(x[i]);
}
break;
case(2):
printf("\nFunction to print -x\n");
x[0] = xbegin;
y[0] = f2(x[0]);
for(int i=1;i<n;i++){
x[i] = x[i-1] + xstep;
y[i] = f2(x[i]);
}
break;
case(3):
printf("\nFunction to print x^2\n");
x[0] = xbegin;
y[0] = f3(x[0]);
for(int i=1;i<n;i++){
x[i] = x[i-1] + xstep;
y[i] = f3(x[i]);
}
break;
case(4):
printf("\nFunction to print -x^3\n");
x[0] = xbegin;
y[0] = f4(x[0]);
for(int i=1;i<n;i++){
x[i] = x[i-1] + xstep;
y[i] = f4(x[i]);
}
break;
case(5):
printf("\nFunction to print (3*cos(x)-2*sin(4*x)-1)/2\n");
x[0] = xbegin;
y[0] = f5(x[0]);
for(int i=1;i<n;i++){
x[i] = x[i-1] + xstep;
y[i] = f5(x[i]);
}
break;
default:
printf("\nUnknown input");
break;
}

// printing the functions
int squares = 10; // grid size
double ymax = max(y,n);
ystep = ymax/squares;
double p;

printf("x\tf(x)\n");
for(int i=0;i<n;i++){
printf("%0.2f\t%0.2f ",x[i],y[i]);

// plot the positive part
if(y[i]>=0){
p = 0;
while(p<=y[i]){
printf(" ");
p = p + ystep;
}
// align the x axis
for(int i=0;i<=squares;i++){
printf(" ");
}
printf("*");

}
// plot the negative part
else{
p = 0;
double q = ymax+y[i]; // start from the -max, move towards x-axis
while(p<=q){
printf(" ");
p = p + ystep;
}
printf("*");

}
printf("\n");
}

return 0;
}
