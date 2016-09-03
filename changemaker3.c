#include<stdio.h>
#include<string.h>
#include<math.h>
int Dval[100],k;
void changeRsDP(int,int);
int main()
{
	int i=0,p=0;
	int val[100];
	char Dlist[100];
	scanf("%s",Dlist);
	char ch;
	while(Dlist[i]){
		ch=Dlist[i];
		if(ch==','){
			i++;
			continue;
		}
		else{
				int temp=0;
				do{
					temp=(temp*10)+(int)Dlist[i]-48;
					i++;
				}while((int)Dlist[i]>47&&(int)Dlist[i]<58);
				Dval[p]=temp;
				p++;
		
		}
	}
	i=-1;
	do{
	i++;
	scanf("%d",&val[i]);
	}while((val[i]!=1000));
	
	printf("%s\n",Dlist);
	
	for(i=0;i<l;i++){
		k=0;
		changeRsDP(val[i],k);		
	}
	return 0;
}

void changeRsDP(int v,int w){
	int 
		if(!val){
			printf("\n");
			return;	
		}
		
	
}
