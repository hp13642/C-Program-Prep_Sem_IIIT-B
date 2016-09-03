#include<stdio.h>
#include<string.h>
#include<math.h>
int Dval[100],Dno[100],k;
void changeRs(int );

int main()
{
	int i=0,p=0,q=0,M,N;
	int val[100];
	scanf("%d",&M);
	scanf("%d",&N);

for(i=0;i<M;i++){
	char s[25],ch;
	int j=0;
	scanf("%s",s);
	
		while(s[j]){
			ch=s[j];		 	
			 if(ch!=':'){
				int temp=0;
				do{
					temp=(temp*10)+(int)s[j]-48;
					j++;
				}while((int)s[j]>47&&(int)s[j]<58);
				Dval[p]=temp;
				p++;
		
			}			 			 
			 else{
				j++;
				int temp=0;
				do{
					temp=(temp*10)+(int)s[j]-48;
					j++;					
				}while(((int)s[j]>47&&(int)s[j]<58));
				Dno[q]=temp;
				q++;
			}
			
		
		}
}

for(i=0;i<N;i++)
	scanf("%d",&val[i]);
int j,temp,temp1;
  for(i=0;i<M;i++)
     {
           for(j=0;j<M-i;j++)
           {
                 if(Dval[j]<Dval[j+1])
                 {
                       temp=Dval[j+1];
                       temp1=Dno[j+1];
                       Dval[j+1]=Dval[j];
                       Dno[j+1]=Dno[j];
                	   Dval[j]=temp;
                	   Dno[j]=temp1;
                 }
           }
     }

	for(i=0;i<M;i++){
		printf("%d:0",Dval[i]);
		if(i!=(p-1))
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
	else if(Dval[k]){
		k++;
		changeRs(val);
	}
		
	else if(val>=Dval[k]){
		int l;
		l=val/Dval[k];
		if(Dno[k]>=l){
			printf("%d:%d",Dval[k],l);
			j=val%Dval[k];
			Dno[k]=Dno[k]-l;
			if(j)
				printf(",");
			k++;
			changeRs(j);
		}
		else{
			printf("%d:%d",Dval[k],Dno[k]);
			j=val-(Dval[k]*Dno[k]);
			Dno[k]=0;
			if(j)
				printf(",");
			k++;
			changeRs(j);
		}
		
				
	}
	else{
		k++;
		changeRs(val);
	}
}

