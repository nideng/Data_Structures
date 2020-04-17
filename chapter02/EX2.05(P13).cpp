/*
L=(LinkList)malloc(sizeof(LNode));P=L;//P指向头结点
for(i=1;i<=4;i++){
P->next=(LinkList)malloc(sizeof(LNode));
P=P->next;P->data=i*2-1;         
}//循环结束后，除去头结点，链表有四个节点，结点从前到后的值依次为1 ，3 ，5，7。P指向最后一个结点。最后一个结点的指针域为空
P-> next=NULL;
for(i=4;i>=1;i--) Ins_LinkList(L,i+1;i*2);//循环结束后，除去头结点，链表有8个节点，结点从前到后的值依次为1，2，3 ，4，5，6，7，8。P仍然指向7所对应的结点
for(i=1;i<=3;i++) Del_LinkList(L,i);//循环结束，删掉1，3，5对应的结点
*/