#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student_t{
	char id[20];
	char name[20];
	int grade;
	struct student_t *next;
	
}node;

node *createnewnode(char id[],char name[],int grade){
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	if (newnode==NULL){
		printf("Erroos!!!!!\n");
		exit(0);
	}
	
		strcpy(newnode->id,id);
		strcpy(newnode->name,name);
		newnode->grade=grade;
		newnode->next=NULL;
	return newnode;
}
node *addhead(node *head,char id[],char name[],int grade){
	node *temp;
	temp=createnewnode(id, name, grade);
	if (head==NULL)
	head=temp;
	else{
		temp->next=head;
	}
	return temp;
}
node *addtail(node *head,char id[],char name[],int grade){
	node *newnode,*p;
	newnode=createnewnode(id, name, grade);
	if (head==NULL)
	head=newnode;
	else{
		p=head;
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=newnode;
		
	}
	return head;
}
void *addat(node *pre,char id[],char name[],int grade){
	node *newnode;
	newnode=createnewnode(id, name, grade);
	if (pre==NULL) return ;
	newnode->next=pre->next;
	pre->next=newnode;
	
}
node *dehead(node *head){
	if (head==NULL){
		printf("Cha co j de xoa het !!!!");
	}
	else{
		head=head->next;
	}
	return head;
}
node *detail(node *head){
	node *p;
	p=head;
	while(p->next->next!=NULL){
		p=p->next;
	}
	p->next=NULL;
	return head;
	
}
void *delat(node *pre){
	node *p;
	if (pre==NULL) return;
	p=pre->next;
	pre->next=p->next;
	
	
}
void  duyetds(node *head){
	node *p;
	p=head;
	while(p!=NULL){
		printf("MSSV:%s\n",p->id);
		printf("Ho va ten:%s\n",p->name);
		printf("Diem so :%d\n",p->grade);
		p=p->next;
	}
}

int main(){
	node *head=NULL;
	int i,grade;
	char id[20];
	char name[20];
	
for (i=0;i<2;i++){
	fflush(stdin);
	gets(id);
	gets(name);
	scanf("%d",&grade);
	head=addtail(head,id,name,grade);
}
duyetds(head);
printf("\n\n");
	addat(head,"3","Dung",7);
	duyetds(head);
printf("\n\n");
head=delat(head);
	duyetds(head);

	
}