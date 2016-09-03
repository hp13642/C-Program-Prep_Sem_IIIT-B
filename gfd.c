#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char s[25],r[25];
    int i,j=0,tcase;
    scanf("%d",&tcase);
   while(tcase--){
        scanf("%s",s);
    for(i=strlen(s);i<=0;i--)
        r[i]=s[j++];
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    for(i=1;i<strlen(s);i++){
        if(abs(s[i]-s[i-1])==abs(r[i]-r[i-1]))
            continue;
        else
            break;
    }
    if(i==strlen(s))
        printf("FUNNY\n");
    else 
        printf("NOT FUNNY\n");
   }
    return 0;
}
