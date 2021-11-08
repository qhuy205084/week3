#include <stdio.h>
#include <stdlib.h>
typedef struct{
	char name[20];
	char tel[11];
	char email[20];
}phone;
struct LinkedList{
     phone data;
    struct LinkedList *next;
 };
 typedef struct LinkedList *node;
 node CreateNode(phone value){
    node temp; 
    temp = (node)malloc(sizeof(struct LinkedList)); 
    temp->next = NULL;
    temp->data = value; 
    return temp;
}
node AddTail(node head, phone value){
    node temp,p;
    temp = CreateNode(value);
    if(head == NULL){
        head = temp;     
    }
    else{
        p  = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
    return head;
}
node InitHead(){
    node head;
    head = NULL;
    return head;
}
node Input(){
    node head = InitHead();
    int n;
    phone value;
    int i;
    do{
        printf("\nNhap so luong phan tu n = ");
        scanf("%d", &n);
    }while(n <= 0);
 
    for( i = 0; i < n; ++i){
        printf("\nNhap gia tri can them: ");
        printf("\nNhap ten:");
        fflush(stdin);
        gets(value.name);
        printf("\nNhap so dien thoai:");
        fflush(stdin);
        gets(value.tel);
        printf("\nNhap so email:");
        fflush(stdin);
        gets(value.email);
        head = AddTail(head, value);
    }
    return head;
}


void Traverser(node head){
    printf("\n");
    node p;
    for( p = head; p != NULL; p = p->next){
        printf("\nten:%s", p->data.name);
    }
}
node DelHead(node head){
    if(head == NULL){
        printf("\nCha co gi de xoa het!");
    }else{
        head = head->next;
    }
    return head;
}
node DelTail(node head){
    if (head == NULL || head->next == NULL){
         return DelHead(head);
    }
    node p = head;
    while(p->next->next != NULL){
        p = p->next;
    }
    p->next = p->next->next; // Cho next b?ng NULL
    // Ho?c vi?t p->next = NULL cung du?c
    return head;
}

 int main(){
 	phone add;
 	printf("\n==Tao 1 danh sach lien ket==");
    node head = Input();
    Traverser(head);
    printf("Nhap du lieu can them:\n");
     printf("\nNhap ten:");
        fflush(stdin);
        gets(add.name);
        printf("\nNhap so dien thoai:");
        fflush(stdin);
        gets(add.tel);
        printf("\nNhap so email:");
        fflush(stdin);
        gets(add.email);
     printf("\n==Thu them 1 phan tu vao linked list==");
    head = AddTail(head, add);
    Traverser(head);
      printf("\n==Thu xoa 1 phan tu khoi linked list==");
    head = DelTail(head);
    Traverser(head);
    
 }
