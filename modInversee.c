int main()
{
	int val;
	val=modInverse(105,4);
	printf("%d",val);
	return 0;
}
int modInverse(int a,int m)
{
	int x=1;
	a=a%m;
	for(x=1;x<m;x++)
	{
		if((a*x)%m==1)
		return x;
	}
}
