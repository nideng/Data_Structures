/*
(a)Q=P->next;P->next=p->next->next;free(Q);

(b)Q=P;P=L;while(P->next!=Q) P=P->next;P->next=P->next->next;free(Q);

(c)Q=P;P=L;while(P->next=!=Q)P=P->next;P->next=P->next->next;free(Q);

(d)P=L;Q=P->next;P->next=P->next->next;free(Q);

(e)while(P->next->next!=NULL) P=P->next;Q=P->next;P->next=P->next->next;free(Q);

*/