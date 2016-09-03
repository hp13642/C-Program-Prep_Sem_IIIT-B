#include<stdio.h>
#include<string.h>
#include<math.h>
void pushOp(char ele);
char popOp();
void pushOp1(int ele);
int popOp1();
int priority(char ele);
int infixToPostfix(char arr[],int tval);
int postfixEvaluator(char arr[],int tval);

int tos=-1,j=0,tos1=-1;
char s1[50],postfix[50];
int s2[50];
int main()
{
	char exp1[100];
	int test_val[100],i=-1,no_val;
	//input
	scanf("%s",exp1);
	do{
		i++;
		scanf("%d",&test_val[i]);
	}while((test_val[i]!=1000));
	
	no_val=i;

	for(j=0;j<no_val;j++){
		int val;
		tos=-1;
		tos1=-1;
		val=infixToPostfix(exp1,test_val[i]);
		printf("%d\n",val);
	
	}
	return 0;
}

void pushOp(char ele){                    
 	s1[++tos]=ele;
}

char popOp(){                     
 	return(s1[tos--]);
}
void pushOp1(int ele){
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
 

int infixToPostfix(char exp[],int tval){
	char ch;
	int i=0;
	while(exp[i]!='\0'){
		ch=exp[i];
		if((int)exp[i]>47&&(int)exp[i]<58){		
				do{
					postfix[j++]=ch;
					i++;		
				}while((int)exp[i]>47&&(int)exp[i]<58);
				postfix[j++]='@';
				continue;
		}		
		else if((int)exp[i]>96&&(int)exp[i]<123){
			postfix[j++]=ch;
		}
		else if(ch==')'){
			do{
				postfix[j++]=popOp();
			}while(s1[tos--]!='(');
		
		}
		else if(ch=='(')
			pushOp('(');
		else{
			if(priority(s1[tos])>=priority(ch))
				pushOp(ch);
			else
			while(priority(s1[tos])>=priority(ch)||ch=='('||(tos==-1)){
				postfix[j++]=popOp();
			}
		}
		i++;
	}
	while(++tos)
			postfix[j++]=popOp();
//	for(i=0;i<j;i++)
///	printf("%c",postfix[i]);
//	return 0;
	return postfixEvaluator(postfix,tval);
}


int postfixEvaluator(char postfix[],int tval){
	char ch;
	int i=0;
	while(i<j){
		ch=postfix[i];
		if((int)ch>47&&(int)ch<58){
				int temp=0;
				do{
					temp=(temp*10)+(int)postfix[i]-48;
					i++;
				}while((int)postfix[i]>47&&(int)postfix[i]<58);
				pushOp1(temp);
		}
		else if(ch=='@'){
			i++;
			continue;
		}
		else if((int)ch>96&&(int)ch<123){
			pushOp1(tval);
		}
			
		else{
			int val1,val2;
			val1=popOp1();
			val2=popOp1();
			if(ch=='^'){
				pushOp1(pow(val2,val1));
			}
			else if(ch=='/'){
				pushOp1(val2/val1);
			}
			else if(ch=='*'){
					pushOp1(val2*val1);
			}
			else if(ch=='+'){
					pushOp1(val2+val1);
			}
			else {
					pushOp1(val2-val1);
			}
		}
	}
	return s2[--tos1];
	
}
