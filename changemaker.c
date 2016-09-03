#include<stdio.h>
#include<string.h>
#include<math.h>
int Dval[100],k;
void changeRs(int );

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
	
	int l=i;

	for(i=0;i<l;i++){
		k=0;
		changeRs(val[i]);
		
	}	
	return 0;

}

void changeRs(int val){
	int j;
	if(!val){
		printf("\n");
		return;	
	}
		
	else if(val>=Dval[k]){
		printf("%d:%d",Dval[k],val/Dval[k]);
		j=val%Dval[k];
		if(j)
			printf(",");
		k++;
		changeRs(j);	
	}
	else{
		k++;
		changeRs(val);
	}
}
