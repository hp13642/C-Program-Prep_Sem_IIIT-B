#include<stdio.h>
#include<string.h>
#include<math.h>
int exp_evaluator(char a[],int b);
int status=0;
int main()
{	
	char exp1[100];
	int test_val[100],i=-1,no_val,exp_index;
	//input
	scanf("%s",exp1);
	do{
	i++;
	scanf("%d",&test_val[i]);
	}while((test_val[i]!=1000));
	no_val=i;
	for(i=0;i<strlen(exp1);i++)
	{
	if(exp1[i]=='=')
		{
		i++;
		exp_index=i;
		break;
		}
		else
		continue;
	}
int j,l;
printf("%s\n",exp1);

	
	for(j=0;j<no_val;j++){
	int val;
	val=exp_evaluator(&exp1[exp_index],test_val[j]);
	char s[5];
	for(l=0;l<5;l++){
		if(exp1[l]=='('){
				s[l]='(';
				s[++l]=test_val[j];
		}
		else if(exp1[l]=='=')
		{
			s[l]=exp1[l];
			break;
		}
		else
		s[l]=exp1[l];
	}
	
	printf("p(%d)=%d\n",test_val[j],val);
	status=1;
	
	}
	return 0;
}

int exp_evaluator(char exp[],int tval){
	
	static int j;
	int k=0,l=0,operand[50];
	char oprtor[50];
	if(status==1)
	{
		j=0;
		status=0;
	}
	for(;j<strlen(exp);j++){
			
			if(exp[j]==')')
			break;
			
			else if(exp[j]=='('){
				j++;
				operand[k]=exp_evaluator(exp,tval);
				k++;
			
				continue;
			}
			
			else if(((int)exp[j]>96&&(int)exp[j]<123)||
			((int)exp[j]>64&&(int)exp[j]<91)){
				operand[k]=tval;
				k++;
				continue;
			}
			else if((int)exp[j]>47&&(int)exp[j]<58){
				int temp=0;
				do{
					temp=(temp*10)+(int)exp[j]-48;
					j++;
				}while((int)exp[j]>47&&(int)exp[j]<58);
				operand[k]=temp;
				j--;
				k++;
				continue;
			}
			else{
				oprtor[l]=exp[j];
				l++;
			}
	}
	
	
	int i=0,left=operand[0],in=1;;

	for(i=0;i<l;i++){
		if(oprtor[i]=='^'){
			left=pow(left,operand[in]);
			in++;
			continue;
		}
		else if(oprtor[i]=='/'){
			left=left/(operand[in]);
			in++;
			continue;
		}

		else if(oprtor[i]=='*'){
			left=left*(operand[in]);
			in++;
			continue;
		}

		else if(oprtor[i]=='+'){
			left=left+(operand[in]);
			in++;
			continue;
		}

		else {
			left=left-(operand[in]);
			in++;
			continue;
		}
	}
	return left;
}
	