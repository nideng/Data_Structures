Status DeleteAndInsertSub(LinkList la, LinkList lb, int i, int j, int len)
{
	if (i < 0 || j < 0 || len < 0)return INFEASIBLE;
	LinkList p;//ָ��la�е�i����㣬�������
	p = la; int k = 1;
	while (k < i) { p = p->next; k++; }
	LinkList q;//ָ��la�е�i+len-1�����,�������
	q = p;
	while (k < i + len - 1) { q = q->next; k++; }
	LinkList r;//ָ��la�е�i+len����㣬�������
	r = q->next;
	p->next = r;
	LinkList s;//ָ��lb�е�j-1����㣬�������
	s = lb;
	k = 1;
	while (k < j - 1) { s = s->next; }
	q->next = s->next;
}