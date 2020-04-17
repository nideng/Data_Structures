/*
(a) S->next=P->next;P->next->previous=S;P->next=S;S->previous=P;

(b)P->previous->next=S;S->previous=P->previous;P->previous=S;S->next=P;

(c)Q=P->next;P->next=P->next->next;P->next->previous=P;free(Q);

(d)Q=P->previous;P->previous=P->previous->previous;P->previous->next=P;free(Q);

(e)P->next->previous=P->previous;P->previous->next=P->next;free(P);
*/