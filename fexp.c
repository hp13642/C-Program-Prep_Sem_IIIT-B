#include<stdio.h>
#include<string.h>
#include<math.h>
char stack[100];
int top=-1;
void push (char n)
{
stack[++top]=n;

}
char pop ()
{

return (stack[top--]);
}
int stack1[100];
int top1=-1;
void push1 (int n)
{
stack1[++top1]=n;

}
int pop1 ()
{

return (stack1[top1--]);
}

int main()
{
int b[100];

int exp[100];
char a[100],y;
int i=0,q=-1,ans=0;
int l,n,h,g,z,c,r,p,right;
scanf("%s",a);
l=strlen(a);
    for(i=0;i<l;i++)
        {
        if(a[i]>=97 && a[i]<=122)
            a[i]='x';
        
    }
a[l]=')';
//scanf("%d",&v);


while(1){
scanf("%d",&n);
if(n!=1000){
for(i=0;i<100;i++)
{
b[i]=0;
}
for(i=0;i<=l;i++)
{
    if(a[i]=='(')
    push(a[i]);
    if(a[i]>=48 && a[i]<=57)
    {
    p=1;z=i;r=i;c=0;
                while(a[r+1]>47 &&a[r+1]<58)
                {p=p*10;    c++;
                r++;};right=0;i=i+c;
                while(c>=0)
                {
                right=right+    ((int)a[z]-48)*p;
                c--;z++;p=p/10;    }exp[++q]=right;

    }
    if(a[i]==')')
    {
        while(stack[top]!='(' && top!=-1)        
        {
        y=pop();
        exp[++q]=(int)y;
        b[q]=1;
        }
    y=pop(top);
    }
    if(a[i]=='x')
    exp[++q]=n;    
    if(a[i]=='+' || a[i]=='-')
    {
        while(top!=-1 && stack[top]!='('  )
        {
        exp[++q]=pop();
        b[q]=1;
        }
    push(a[i]);
    }
    if(a[i]=='*' || a[i]=='/')
    {
        while((stack[top]!='(' && top!=-1) && (stack[top]=='*'||stack[top]=='/'||stack[top]=='^'))
        {
        exp[++q]=pop();
        b[q]=1;
        }    
    push(a[i]);

    }
    if(a[i]=='^')
    {
    push(a[i]);

    }
}

for(i=0;i<=q;i++)
{
    if(b[i]==0)
    push1(exp[i]);

    
    else
    {
    h=pop1();
    g=pop1();
    if(exp[i]=='+')
    push1(h+g);
    if(exp[i]=='-')
    push1(g-h);
    if(exp[i]=='*')
    push1(h*g);
    if(exp[i]=='/')
    push1(g/h);
    if(exp[i]=='^')
    {ans=(pow(g,h));
    push1(ans);

    }
            }
}
printf("%d\n",pop1());
top=-1;
top1=-1;
q=-1;ans=0;
for(i=0;i<100;i++)
exp[i]=0;

}
else break;
}
return 0;
}
