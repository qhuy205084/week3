#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	char id[11];
	char name[20];
	int grade;
}student;

struct student_t{
	student data;
	struct student_t *next;
};
typedef struct student_t *node;
node createnode(student value){
	node temp;
	temp=(node)malloc(sizeof(struct student_t));
	temp->next=NULL;
	temp->data=value;
	return temp;	
}
node AddTail(node head, student value){
    node temp,p;
    temp = createnode(value);
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
    student value;
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
        printf("\nNhap ma so sinh vien:");
        fflush(stdin);
        gets(value.id);
        printf("\nNhap so diem :");
        scanf("%d",&value.grade);
        head = AddTail(head, value);
    }
    return head;
}
void Traverser(node head){
    printf("\n");
    node p;
    
    for( p = head; p != NULL; p = p->next){
       printf("%s\n",p->data.name);
    }
}
void swap(student *a,student *b){
	student tmp=*a;
	*a=*b;
	*b=tmp;
}
void sortstudents(node head){
	node p,q;
	for (p=head;p!=NULL;p=p->next){
		for (q=p->next;q!=NULL;q=q->next){
		if (p->data.grade<q->data.grade)
		swap(&p->data,&q->data);
	}
}
}
node AddHead(node head, student value){
    node temp = createnode(value);
    if(head == NULL){
        head = temp;
    }else{
        temp->next = head;
        head = temp; 
    }
    return head;
}
 
node AddAt(node head, student value, int position){
    if(position == 0 || head == NULL){
        head = AddHead(head, value);
    }else{
       
        int k = 1;
        node p = head;
        while(p != NULL && k != position){
            p = p->next;
            ++k;
        }
 
        if(k != position){
            
            head = AddTail(head, value);
            
        }else{
            node temp = createnode(value);
            temp->next = p->next;
            p->next = temp;
        }
    }
    return head;
}

void search(node head,char id[11]){
	int i=0;
	node m;
	for( m = head; m != NULL; m = m->next){
       if (strcmp(m->data.id,id)==0&&strstr(m->data.id,id)!=NULL){  
       printf("Sinh vien duoc tim kiem:%s",m->data.name);
       
       i++;
    }
   
}
 if (i==0) printf("Khong tim thay sinh vien thoa max \n\n ");
	
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
node DelAt(node head, int position){
    if(position == 0 || head == NULL || head->next == NULL){
        head = DelHead(head); 
    }else{
       
        int k = 1;
        node p = head;
        while(p->next->next != NULL && k != position){
            p = p->next;
            ++k;
        }
 
        if(k != position){
          
            head = DelTail(head);
         
        }else{
            p->next = p->next->next;
        }
    }
    return head;
}
int xoa(node head,char id[]){
		int i=0;
	node m;
	for( m = head; m != NULL; m = m->next){
      if (strcmp(m->data.id,id)!=0||strstr(m->data.id,id)==NULL)
      i++;
      else break;
    }
    return i;
}

int main(){
	student p;
	int n,m;
	char id[11];
	//tao danh sach lien ket
		printf("\n==Tao 1 danh sach lien ket==");
    node head = Input();
    Traverser(head);
    //Sap xep
      printf("\nSap xep danh sach sinh vien :\n");
      
      sortstudents(head);
      Traverser(head);
    //Chen sinh vien
      printf("\nNhap thong tin sinh vien can chen:\n");
	  
	  printf("\nNhap ten sinh vien:");
	  fflush(stdin);
	  gets(p.name);
	  printf("\nNhap MSSV:");
	  fflush(stdin) ;
	  gets(p.id);
	  printf("\nNhap diem:");
	  scanf("%d",&p.grade);
	  printf("\n");
	  AddTail(head,p);
      sortstudents(head);
	   Traverser(head);
	//Tim kiem sinh vien:   
	  printf("Tim kiem sinh vien:\n");
	  printf("Nhap mssv can tim kiem:");
	  fflush(stdin);
	  gets(id);
	  search(head,id);
	//Xoa sinh vien
	printf("\n");
	  DelAt(head,2);
	  Traverser(head);	
}
