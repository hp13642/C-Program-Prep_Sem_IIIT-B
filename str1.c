int main()
{
	char s1[7],s2[6];
	puts("Enter first string\n");
	gets(&s1);
	puts("Enter second string\n");
	gets(&s2);
/*	printf("\n\n");
	puts(s1);
	printf("\n");
	puts(s2);
*/	if(strcmp(s1,s2)==0)
	{
		puts("Strings are Equal");
	}
	else
	puts("Strings are Differenbt");

	return 0;	
}
