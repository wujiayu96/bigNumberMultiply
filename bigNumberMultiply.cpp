#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10001
int bigNumberMultiply(int *sum,int *a,int *b,int len_a,int len_b)
{
    int i,j,len_sum = 0 ;
    memset(sum,0,sizeof(sum));
    for(i=1 ; i<= len_a ; i++) /*用数组模拟运算*/
        for(j=1,len_sum=i-1; j<= len_b ; j++)
            sum[++len_sum] += b[j] * a[i] ;
    for(i=1 ; i<= len_sum ; i++)/*进位处理*/
        if (sum[i] >= 10)
        {
            if ( sum[len_sum] >= 10)
                len_sum++ ;
            sum[i+1] += sum[i] / 10 ;
            sum[i] %= 10 ;
        }
    return len_sum ;

}

int main(void)
{
    FILE *fp=NULL;
    int a[MAX]= {0},b[MAX]= {0},sum[MAX*2]= {0} ;
    int len_a=0,len_b=0,len_sum=0;
    int i,j ;
    char sa[MAX],sb[MAX] ;
    fp=fopen("data.txt","r");
    fscanf(fp,"%s,",&sa);
    fscanf(fp,"%s,",&sb);
    len_a = strlen(sa);
    len_b = strlen(sb);
    for(i=1,j=len_a-1; i<= len_a ; i++,j--)/*字符串转数组*/
        a[i] = sa[j] - '0' ;
    for(i=1,j=len_b-1; i<= len_b ; i++,j--)
        b[i] = sb[j] - '0' ;
    len_sum = bigNumberMultiply(sum,a,b,len_a,len_b) ;
    printf("%s * %s = ",sa,sb);
    for(i=len_sum ; i> 0 ; i--)
        printf("%d",sum[i]);
    printf("\n");
    return 0 ;
}
