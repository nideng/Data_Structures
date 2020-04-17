/*
(a)S->next=P->next;P->next=S;

(b)Q=P;P=L;while(P->next!=Q) P=P->next;S->next=P->next;P->next=S;

(c)S->next=L;L=S;

(d)P=L;while(P->next!=NULL)P=P->next;P->next=S;S->next=NULL:
*/