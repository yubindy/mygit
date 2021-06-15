1.
#include <stdio.h>
#include <stdlib.h>
typedef struct Date{
	int date;
	struct Date *next;
}D;
D *Createlink(){
	D *h,*p,*t;
	int date;
	h=NULL;
	while(1){
		p=(D *)malloc(sizeof(D));
		p->next=NULL;
		scanf("%d",&date);
		if(date==-1) return h;
		p->date=date;
		if(!h){
			h=t=p;
		}
		else{
			t->next=p;
			t=p;
		}
	}
}
void PutLine(D *h1,D *h2){
	D *p1,*p2;
	if(!(h1||h2)){
		printf("NULL");
		exit(0);
	}
	for(p1=h1,p2=h2;p1&&p2;!(p1&&p2)?:printf(" ")){
		if(p1->date<p2->date){
			printf("%d",p1->date);
			p1=p1->next;
		}
		else{
			printf("%d",p2->date);
			p2=p2->next;
		}
	}
	while(p1){
		printf(" %d",p1->date);
		p1=p1->next;
	}
	while(p2){
		printf(" %d",p2->date);
		p2=p2->next;
	}
}
int main(void){
	D *h1,*h2;
	h1=Createlink();
	h2=Createlink();
	PutLine(h1,h2);
    return 0;
}
2.
#include<stdio.h>
struct node
{
    int data;
    int next;
}p[100001];
 
int main()
{
    int i,j,n,be,x,This_address,Next_address;
    int add1[100001];
    int add2[100001];
    int length,k=0;
    
    scanf("%d %d",&be,&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d",&This_address,&x,&Next_address);
        p[This_address].data=x;
        p[This_address].next=Next_address;
    }
    
    while(be!=-1)
    {
        add1[k++]=be;
        be=p[be].next;
    }
    
    length=k;
    k=0;
    
    for(i=0,j=length-1;i<=j;)
    {
        if(i==j)
        {
            add2[k]=add1[i];
            break;
        }
        else
        {
            add2[k++]=add1[j--];
            add2[k++]=add1[i++];
        }
    }
    
    for(i=0;i<length-1;i++)
    {
        printf("%05d %d %05d\n",add2[i],p[add2[i]].data,add2[i+1]);
    }
    printf("%05d %d -1\n",add2[length-1],p[add2[length-1]].data);
    
    return 0;
}
3.
#include <stdio.h>
#include <stdlib.h>
typedef struct Date{
	int date;
	struct Date *next;
}D;
D *Createlink(int n){
	D *h,*p,*t;
	int i;
	for(i=0,h=NULL;i<n;i++){
		p=(D *)malloc(sizeof(D));
		p->next=NULL;
		scanf("%d",&p->date);
		if(!h){
			h=t=p;
		}
		else{
			t->next=p;
			t=p;
		}
	}
	return h;
}
int Addline(D *h,int n){
	D *p,*r;
	int i,x,y;
	scanf("%d%d",&x,&y);
	if(x>n) return n;
		if(!x){
		r=(D *)malloc(sizeof(D));
		r->next=h->next;
		h->next=r;
		r->date=h->date;
		h->date=y;
		return n+1;
	}
	for(i=1,p=h;i<x;++i,p=p->next);
	r=(D *)malloc(sizeof(D));
	r->date=y;
	r->next=p->next;
	p->next=r;
	return n+1;
}
int Delline(D *h,int n){
	D *p;
	int i,x;
	scanf("%d",&x);
	if(x>n||!x) return n;
	for(i=2,p=h;i<x;++i,p=p->next);
	p->next=p->next->next;
	return n+1;
}
void PutLine(D *h){
	D *p;
	for(p=h;p;p=p->next)
		printf("%d ",p->date);
}
int main(void){
	D *head;
	int i,x,N,T;
	scanf("%d",&N);
	head=Createlink(N);
	scanf("%d",&T);
	for(i=0;i<T;i++){
		scanf("%d",&x);
		switch(x){
			case 0:N=Addline(head,N);break;
			case 1:N=Delline(head,N);break;
		}
	}
	PutLine(head);
	return 0;
}
4.
#include <stdio.h>
#include <stdlib.h>
typedef struct Doubleline{
	int date;
	struct Doubleline *prev;
	struct Doubleline *next;
}Line;
void Createline(Line *h1,Line *h2){
	Line *p,*t1,*t2;
	int date,i;
	for(i=1,h1=t1=h2=t2=NULL;1;i++){
		p=(Line *)malloc(sizeof(Line));
		p->next=NULL;
		scanf("%d",&date);
		if(date==-1){
			break;
		}
		p->date=date;
		if(i%2){
			if(!h1){
				h1=t1=p;
				h1->prev=NULL;
			}
			else{
				t1->next=p;
				p->prev=t1;
				t1=p;
			}
		}
		else{
			if(!h2){
				h2=t2=p;
				h2->prev=NULL;
			}
			else{
				t2->next=p;
				p->prev=t2;
				t2=p;
			}
		}
	}
	if(!h1||!h2){
		if(h1) printf("%d\n%d",h1->date,h1->date);
		if(h2) printf("%d\n%d",h2->date,h2->date);
		
	}
    else{
    for(p=t1;p;p=p->prev)
		printf("%d ",p->date);
	for(p=h2;p->next||!printf("%d\n",p->date);p=p->next)
		printf("%d ",p->date);
	for(p=t2;p;p=p->prev)
		printf("%d ",p->date);
	for(p=h1;p->next||!printf("%d\n",p->date);p=p->next)
		printf("%d ",p->date);
    }

}
int main(void){
	Line *h1,*h2;
	Createline(h1,h2);
	return 0;
}
