#include<stdio.h>
#define M 100

typedef struct node
{
	int el;
	struct node* left;
	struct node* right; 
}node;

void display(node* head)
{
	do{
		if(head!=NULL)
		{
			printf("%d",head->el);
			head=head->right;
		}
		
	}while(head!=NULL);
	printf("\n\n");
}

node* createNumber(char* st,node* h)
{
	int i,j,no;
	int ln,pow;
	char ch;
	node* ptr;
	
	for(ln=0;st[ln]!='\0';ln++);
	for(i=ln-1;i>=0;)
	{
		no=0;
		pow=1;
		for(j=0;j<4&&i>=0;j++,i--)
		{
			ch=st[i];
			no=no+pow*(ch-48);
			pow*=10;
		}
		//printf("\n%d\n",no);
		if(h==NULL)
		{
			ptr=(node*)malloc(sizeof(node));
			ptr->left=NULL;
			ptr->right=NULL;
			ptr->el=no;
			h=ptr;
		}
		else
		{
			ptr=(node*)malloc(sizeof(node));
			ptr->left=NULL;
			ptr->right=h;
			h->left=ptr;
			ptr->el=no;
			h=ptr;
		}
	}
	return h;
	
}

node* add(node* h1,node* h2)
{
	node* h3=NULL;
	node *ptr;
	int a=0,b=0,c,d;
	int carry=0;
	while(h1->right!=NULL)
	{
		h1=h1->right;
	}
	while(h2->right!=NULL)
	{
		h2=h2->right;
	}
	
	while(h1!=NULL||h2!=NULL)
	{
		a=0;
		b=0;
		if(h1!=NULL)
		{
			a=h1->el;
			//printf("\nabove h1");
			h1=h1->left;
			//printf("\nin h1");
		}
		if(h2!=NULL)
		{
			b=h2->el;
			//printf("\nabove h2");
			h2=h2->left;
			//printf("\nin h2");
		}
		c=a+b;
		d=c;
		c=c%10000;
		//printf("\n>%d ",c);
		ptr=(node*)malloc(sizeof(node));
		ptr->el=c+carry;
		carry=d/10000;
			
		ptr->left=NULL;
		ptr->right=h3;
		
		if(h3!=NULL)
		h3->left=ptr;
		
		h3=ptr;
		
	}
	//printf("\ndone");
	if(carry>0)
	{
		ptr=(node*)malloc(sizeof(node));
		ptr->el=c;
		ptr->right=h3;
		h3->left=ptr;
		ptr->left=NULL;
		h3=ptr;
	}
	return h3;
}
node* sub(node* h1,node* h2)
{
	node* h3=NULL;
	node* ptr;
	
	int a=0,b=0,c,d;
	int borrow=0,bflag=0;
	while(h1->right!=NULL)
	{
		h1=h1->right;
	}
	while(h2->right!=NULL)
	{
		h2=h2->right;
	}
	
	while(h1!=NULL||h2!=NULL)
	{
		a=0;
		b=0;
		if(h1!=NULL)
		{
			a=h1->el;
			//printf("\nabove h1");
			h1=h1->left;
			//printf("\nin h1");
		}
		if(h2!=NULL)
		{
			b=h2->el;
			//printf("\nabove h2");
			h2=h2->left;
			//printf("\nin h2");
		}
		c=a-b;
		if(c<0)
		{
			bflag=1;
			c=c*-1;
		}
		else
		bflag=0;
		
		//printf("\n>%d ",c);
		ptr=(node*)malloc(sizeof(node));
		ptr->el=c+borrow;
		borrow=bflag;
			
		ptr->left=NULL;
		ptr->right=h3;
		
		if(h3!=NULL)
		h3->left=ptr;
		
		h3=ptr;
	}
	
	while(h3->el==0&&h3->right!=NULL)
	h3=h3->right;
	
	//printf("\ndone");
	/*
	if(borrow>0)
	{
		ptr=(node*)malloc(sizeof(node));
		ptr->el=c;
		ptr->right=h3;
		h3->left=ptr;
		ptr->left=NULL;
		h3=ptr;
	}*/
	return h3;
}

node* mul(node* h1,node* h2)
{
	node* h3=NULL;
	node* ptr,*unity,*hadd;
	
	unity=(node*)malloc(sizeof(node));
	unity->right=NULL;
	unity->left=NULL;
	unity->el=1;
	
	hadd=(node*)malloc(sizeof(node));
	hadd->right=NULL;
	hadd->left=NULL;
	hadd->el=0;
	
	while(h2->el!=0||h2->right!=NULL)
	{
		hadd=add(h1,hadd);
		h2=sub(h2,unity);
	}
	return hadd;
}
void main()
{
	char str[M];
	node* head1=NULL;
	node* head2=NULL;
	node* headA=NULL;
	node* headS=NULL;
	node* headM=NULL;
	
	printf("\nEnter a number: ");
	scanf("%s",str);
	head1=createNumber(str,head1);
	//display(head1);
	//printf("\n\n%d",head1->el);
	printf("\nEnter another number: ");
	scanf("%s",str);
	head2=createNumber(str,head2);
	//display(head2);
	//printf("\n\n%d",head2->el);
	
	headA=add(head1,head2);
	display(headA);
	getch();
	headS=sub(head1,head2);
	display(headS);
	getch();
	headM=mul(head1,head2);
	display(headM);
	getch();
}
