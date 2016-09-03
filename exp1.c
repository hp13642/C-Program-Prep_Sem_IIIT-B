#include<stdio.h>
#include<string.h>
#include<math.h>
int exp_evaluator(char a[],int b);
main()
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


printf("%s\n",exp1);
int j;
for(j=0;j<no_val;j++){
	int val;
	val=exp_evaluator(&exp1,test_val[j]);
	printf("%d\n",val);
	
}

return 0;
}




int exp_evaluator(char exp[],int tval){
	
	int j,k=0,l=0,operand[50];
	char oprtor[50];

	for(j=0;j<strlen(exp);j++){
			if((int)exp[j]>96&&(int)exp[j]<123){
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
	
