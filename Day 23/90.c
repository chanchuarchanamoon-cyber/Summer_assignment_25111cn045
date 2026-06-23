#include<stdio.h>
#include <stdlib.h>

int main()
{
    char a[100];
    fgets(a,100,stdin);
    int b=strlen(a);
    int c=0;
    for(int i=b-1; i>=0; i--)
    {
        for(int j=i-1; j>=0; j--)
        {
            if(a[i]==a[j] && c==0)
            {
                printf("%c",a[i]);
                c=1;
            }
        }
    }
}
return 0;
}