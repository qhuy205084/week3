#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct  phoneaddress
{
    char phonenumber[12];
    struct phoneaddress *next;
};
typedef struct phoneaddress node;
node *createnewnode(char a[]){
    node *temp;
    temp=(node *)malloc(sizeof(struct  phoneaddress));
    strcpy(temp->phonenumber,a);
    temp->next=NULL; 
}
node *addhead(node *head,char a[]){
    node *temp;
    temp=createnewnode(a);
    if (head==NULL){
        head=temp;
    }
    else{
        temp->next=head;
    }
    return temp;
}
node *addtail(node *head,char a[]){
    node *temp,*p;
    temp=createnewnode(a);
    if (head==NULL){
        head=temp;
    }
    else{
         p=head;
         while(p->next!=NULL){
             p=p->next;
         }
         p->next=temp;
    }
    return head;
}
node *deletehead(node *head){
    node *p;
    p=head;
    if (head==NULL){
        printf("ko co j de xoa !!!!\n");
    }else
    p=p->next;
    free(head);
    return p;
}
node *deltail(node *head){
	node *p;
	p=head;
	while(p->next->next!=NULL){
		p=p->next;
	}
	p->next=NULL;
	return head;
	
}
void *duyetds(node *head){
    node *p;
    p=head;
    while(p!=NULL){
        printf("So dien thoai:");
        puts(p->phonenumber);
        p=p->next;
    }
}
int main(){
    node *head=NULL;
    char a[12];
    int i;
    for (i=0;i<3;i++){
        printf("Nhap so dien thoai thu nhat:");
        fflush(stdin);
        gets(a);
        head=addhead(head,a);
    }
    head=deltail(head);
    duyetds(head);
    return 0;
}