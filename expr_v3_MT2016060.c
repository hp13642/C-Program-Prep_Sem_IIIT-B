#include<stdio.h>
#include<string.h>
#include<math.h>
void pushOp(int ele);
char popOp();
void pushOp1(int ele);
int popOp1();
int priority(char ele);
void infixToPostfix(char arr[]);
int postfixEvaluator(char arr[],int tval);

int tos=-1,j=0,tos1=-1;
char s1[50],postfix[50];
int s2[50];
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
		}
		else
		continue;
	}
	printf("%s\n",exp1);
	void infixToPostfix(exp1);
	for(j=0;j<no_val;j++){
		int val;
		tos=-1;
		val=postfixEvaluator(postfix,test_val[j]);
		printf("%d\n",val);
	
}
	return 0;
}

pushOp(char ele){                    
 s1[++tos]=ele;
}

char popOp(){                     
 return(s1[tos--]);
}
 pushOp1(int ele){
 	s2[++tos1]=ele;
 }

 int popOp1(){
 	return (s2[tos--]);
 }



int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x=='^')
    return 3;
}
 

void infixToPostfix(char exp[]){
	char ch;
	int i=0;
	while(exp[i]!='\0'){
		ch=exp[i];
		if(((int)exp[i]>47&&(int)exp[i]<58)||((int)exp[j]>96&&(int)exp[j]<123))
			postfix[j++]=ch;
		else if(ch==')'){
			do{
				postfix[j++]=popOp();
			}while(s1[tos--]!='(');
		
		}
		else if(ch=='(')
			pushOp('(');
		else{
			while(priority(s1[tos])>=priority(ch)||ch=='('||(tos==-1)){
				postfix[j++]=popOp();
			}
		}
		i++;
	}
	while(++tos)
			postfix[j++]=popOp();
	for(i=0;i<j;i++)
	printf("%c",postfix[i]);
}


int postfixEvaluator(char postfix[],int tval){
	char ch;
	int i=0,s2[100];
	while(i<j){
		ch=postfix[i];
		if((int)exp[i]>47&&(int)exp[i]<58)
			pushOp(ch);
		else{
			int val1,val2;
			val1=(int)s2[tos1--]-48;
			val2=(int)s2[tos1]-48;
		if(ch=='^'){
			s2[tos1++]=pow(val2,val1);
		}
		else if(ch=='/'){
			s2[tos1++]=val2/val1;
		}

		else if(ch=='*'){
			s2[tos1++]=val2*val1;
		}

		else if(ch=='+'){
			s2[tos1++]=val2+val1;
		}

		else {
			s2[tos1++]=val2-val1;
		}
		}
	}
	return s2[--tos1];
	
}
