int main()
{
	int l1,l2,l;
	static char a[100],b[100];
	static int c[101];
	puts("Enter first number\n");
	scanf("%s",a);
	
	puts("Enter second number\n");
	scanf("%s",b);
	
	
	l1=strlen(a);
	l2=strlen(b);
	l=(l1>=l2)?(l1+1):(l2+1);
	int i;
	for(i=l-1;i>=0;i--)
	{
		if(l1==0&&l2!=0)
		{
			c[i]=c[i]+((int)b[l2-1]-48);
			l2--;
			if(c[i]>9)
			{
			c[i]=c[i]-10;
			c[i-1]=1;
			}
			continue;
		}
		else if(l1!=0&&l2==0)
			{
			c[i]=c[i]+((int)a[l1-1]-48);
			l1--;
			if(c[i]>9)
			{
			c[i]=c[i]-10;
			c[i-1]=1;
			}
			continue;
		}
		else if(l1==0&&l2==0)
			break;		
		else 
		{
			
		c[i]=c[i]+((int)a[l1-1]-48)+((int)b[l2-1]-48);
		l1--;
		l2--;
		if(c[i]>9)
		{
			c[i]=c[i]-10;
			c[i-1]=1;
		}
		}
		
	}
	//printf("%s",c);
	for(i=0;i<l;i++)
	printf("%d",c[i]);
	return 0;
}
