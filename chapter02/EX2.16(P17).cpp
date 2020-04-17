Status DeleteAndInsertSub(LinkList la, LinkList lb, int i, int j, int len)
{
	if (i < 0 || j < 0 || len < 0)return INFEASIBLE;
	LinkList p;//指向la中第i个结点，假设存在
	p = la; int k = 1;
	while (k < i) { p = p->next; k++; }
	LinkList q;//指向la中第i+len-1个结点,假设存在
	q = p;
	while (k < i + len - 1) { q = q->next; k++; }
	LinkList r;//指向la中第i+len个结点，假设存在
	r = q->next;
	p->next = r;
	LinkList s;//指向lb中的j-1个结点，假设存在
	s = lb;
	k = 1;
	while (k < j - 1) { s = s->next; }
	q->next = s->next;
}