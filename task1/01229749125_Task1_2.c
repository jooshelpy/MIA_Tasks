#include <stdio.h>
#include <unistd.h>
int main ()
{
    int i,n;
    scanf("%d",&n);
    for (i = n; i > 0; i--){
        printf("%d\n",i);
        sleep(1); // Add a one-second delay
    }
    printf("Blast off the moon!\n");
}