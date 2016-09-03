
#define MAX 10
#define T 2   // t is test case
int main()
{
	int i=0;
	char s[T][MAX];
	//for input
	printf("Enetr the strings to check lapindrome\n");
	while(i<T)
	{
		gets(s[i]);
		i++;
	}
	int l,l1,l2,k,m;
	for(i=0;i<T;i++)
	{
		
		l=strlen(s[i]);
		if(l%2==0){
			l1=l/2;
			l2=++l1;
		}
		else{
			l1=l/2;
			l2=l1+2;
		}
		for(k=0;k<l1;k++)
		{
			for(m=l2-1;m<l;m++)
			{
				if(s[i][k]==s[i][m])
				s[i][m]='\0';
				else
				continue;
			}
		}
		for(m=l2-1;m<l;m++)
		{	
		    if(s[i][m]!='\0')
		    break;
		    else
		    continue;
			
		}
		if(m==l)
		printf("YES\n");
		else
		printf("NO\n");
	}
	
	return 0;	
		
}
