#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void pushOp(char ele);
char popOp();
void pushOp1(int ele);
int popOp1();
int priority(char ele);
void infixToPostfix(char arr[]);
int postfixEval(char postfix[],int val);
int tos=-1,tos1=-1;
char s1[100];
static char postfix[100];
static int j;
static int s2[100];
int main()
{
	char exp1[100];
	int test_val[100],i=-1,no_val;
	//input
/*	exp1[0]='(';
	scanf("%s",&exp1[1]);
	exp1[strlen(exp1)]=')';
	do{
		i++;
		scanf("%d",&test_val[i]);
	}while((test_val[i]!=1000));
	
	no_val=i;
//	tos=-1;
	infixToPostfix(exp1);
	for(i=0;i<no_val;i++){
		int val;
//		tos1=-1;
		val=postfixEval(postfix,test_val[i]);
		printf("%d\n",val);
	
	}			
*/
	int val;
	char exp[]="x2^4+1-";
	val=postfixEval(exp,3);
	printf("%d",val);	
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
   return (s2[tos1--]);
}

int priority(char x)
{
    if(x == '(')
        return 0;
    else if(x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '/')
        return 2;
    else
    return 3;
}



void infixToPostfix(char exp[]){
	char ch;
	int i=0;
	j=0;
	while(i<strlen(exp)){
		ch=exp[i];
		if((int)ch>47&&(int)ch<58){		
				do{
					postfix[j]=ch;
					j++;
					i++;		
				}while((int)exp[i]>47&&(int)exp[i]<58);
				postfix[j]='@';
				j++;
				continue;
		}		
		else if((int)ch>96&&(int)ch<123){
			postfix[j]=ch;
			j++;
			
		}
		else if(ch==')'){
			do{
				postfix[j]=popOp();
				j++;
			}while(s1[tos--]!='(');
		
		}
		else if(ch=='(')
			pushOp('(');
		else{
			int p1,p2;
			p1=priority(s1[tos]);
			p2=priority(ch);
			if(p1<p2)
				pushOp(ch);
			else
			while(p1>=p2){
				postfix[j]=popOp();
				j++;
				p1=priority(s1[tos]);
				p2=priority(ch);
				if(s1[tos]==')'){
					tos--;
					break;
				}
					
				else if (tos==-1)
					break;
				else continue;
			}
		}
		i++;
	}
	while(++tos){
		
			postfix[j]=popOp();
			j++;
	}
/*	
for(i=0;i<j;i++){
	printf("%c  ",postfix[i]);
	}
	printf("\n");
*/
}



int postfixEval(char postfix1[],int tval){
	char ch;
	int i=0;
	while(i<strlen(postfix1)){
		ch=postfix1[i];
		if((int)ch>47&&(int)ch<58){
				int temp=0;
				do{
					temp=(temp*10)+(int)postfix1[i]-48;
					i++;
				}while((int)postfix1[i]>47&&(int)postfix1[i]<58);
				pushOp1(temp);
				continue;
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
		i++;
	}
	return popOp1();
}
