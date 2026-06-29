#include<stdio.h>
int main()
{
int num=0;
for(int i=0;i<8;i++)
{
num=num|(1<<i);
printf("i[%d]=%d\n",i,num);

}
return 0;
}
