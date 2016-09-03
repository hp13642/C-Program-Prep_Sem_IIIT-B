#include<stdio.h>
#include<string.h>
#include<math.h>
int Dval[100],k;
void changeRs(int );

int main()
{
	int i=0,p=0,M,N;
	int val[100];
	char Dlist[100];
	scanf("%d",&M);
	scanf("%d",&N);

for(i=0;i<M;i++)
	scanf("%d",&Dval[i]);
for(i=0;i<N;i++)
	scanf("%d",&val[i]);
int j,temp;
  for(i=0;i<M;i++)
     {
           for(j=0;j<M-i;j++)
           {
                 if(Dval[j]<Dval[j+1])
                 {
                       temp=Dval[j+1];
                       Dval[j+1]=Dval[j];
                	   Dval[j]=temp;
                 }
           }
     }

for(i=0;i<M;i++){
	printf("%d",Dval[i]);
	if(i!=M-1)
		printf(",");
}
	printf("\n");
	for(i=0;i<N;i++){
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
