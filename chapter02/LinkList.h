#ifndef LINKLIST_H
#define LINKLIST_H

#include<functional>
#include<stdexcept>
using std::invalid_argument;
using std::function;

template<typename T>class ListNode;
template<typename T>class LinkListItr;
template<typename T>class LinkList;



template<typename T>class ListNode
{
	friend class LinkList<T>;
	friend class LinkListItr<T>;
private:
	ListNode(const T& d=T(),ListNode<T>* n=nullptr)
		:data(d),next(n){}
private:
	T data;
	ListNode<T>* next;

};
template<typename T>class LinkList
{

public:
	LinkList() :head(new ListNode<T>()) {}
	LinkList(const LinkList<T>&);
	LinkList& operator=(const LinkList<T>&);
	~LinkList();

	bool isEmpty()const;
	void makeEmpty();
	LinkListItr<T>zeroth()const;
	LinkListItr<T>first()const;
	virtual void insert(const T& x, const LinkListItr<T>& p);
	virtual void insert(const T& x, unsigned i);
	LinkListItr<T>find(const T& x)const;
	LinkListItr<T>findPrevious(const T& x)const;
	void remove(const T& x);
	void remove(unsigned i);//ɾ����i�����
	void remove(LinkListItr<T>it);//ɾ����������ָ��ֱ�Ӻ�̽��
private:
	ListNode<T>* head;//ͷ���
};

template<class T>
class LinkListItr
{
	friend class LinkList<T>;

public:
	LinkListItr():current(nullptr){}
	bool isPastEnd()const
	{
		return current == nullptr;
	}
	void advance()
	{
		if (!isPastEnd())current = current->next;
	}
	void advance(unsigned i)
	{
		while (!isPastEnd() && i != 0)
		{
			current = current->next;
			i--;
		}
	}
	const T& retrieve()const//��ȡ��ǰֵ
	{
		if (isPastEnd())throw invalid_argument("ivalid iterator");
		return current->data;
	}
	T& retrieve()
	{
		if (isPastEnd())throw invalid_argument("ivalid iterator");
		return current->data;
	}
	ListNode<T>*& getNextNode() { return current->next; }
private:
	LinkListItr(ListNode<T>* theNode)
		:current(theNode) {}

private:
	ListNode<T>* current;
};

template<typename T>
LinkList<T>::LinkList(const LinkList<T>& li)
{
	head = new ListNode<T>;
	*this = li;
}

template<typename T>
LinkList<T>::~LinkList()
{
	makeEmpty();
	delete head;
}

template<typename T>
bool LinkList<T>::isEmpty()const
{
	return head->next == nullptr;
}

template<typename T>
void LinkList<T>::makeEmpty()
{
	while (!isEmpty())
		remove(first().retrieve());
}

template<typename T>
LinkListItr<T> LinkList<T>::zeroth()const
{
	return LinkListItr<T>(head);
}

template<typename T>
LinkListItr<T> LinkList<T>::first()const
{
	return LinkListItr<T>(head->next);
}

template<typename T>
void LinkList<T>::insert(const T& x, const LinkListItr<T>& p)//p֮�������
{
	if (p.current != nullptr)
	{
		auto node = new ListNode<T>(x, p.current->next);//����dataΪx���½�㣬�˽��ָ��p.current->next;
		p.current->next = node;
	}
}
template<typename T>
void LinkList<T>::insert(const T& x, unsigned i)
{
	auto it = this->zeroth();
	it.advance(i);//��ͷ���ͽ�i��Ϊi-1������Ҫ�ж�i�Ƿ����1
	insert(x, it);
}
template<typename T>
LinkListItr<T> LinkList<T>::find(const T& x)const
{
	ListNode<T>* p = head->next;
	while (p != nullptr && p->data != x)
		p = p->next;
	return LinkListItr<T>(p);//���û�ҵ�������β����
}

template<typename T>
LinkListItr<T> LinkList<T>::findPrevious(const T& x)const
{
	ListNode<T>* p = head;
	while (p->next != nullptr && p->next->data != x)
		p = p->next;
	return LinkListItr<T>(p);
}

template<typename T>
void LinkList<T>::remove(const T& x)
{
	ListNode<T>* p = findPrevious(x).current;
	if (p->next != nullptr)
	{
		ListNode<T>* oldnode = p->next;
		p->next = p->next->next;
		delete oldnode;
	}
}

template<typename T>
void LinkList<T>::remove(LinkListItr<T>it)//ɾ����������ָ��ֱ�Ӻ�̽��
{
	auto p = it.current;
	if (p->next != nullptr)
	{
		ListNode<T>* oldnode = p->next;
		p->next = p->next->next;
		delete oldnode;
	}
}

template<typename T>
void LinkList<T>::remove(unsigned i)//�ٶ�i>=1
{
	auto itr = this->zeroth();
	itr.advance(i-1);
	remove(itr);
}

template<typename T>
LinkList<T>& LinkList<T>::operator=(const LinkList<T>& rhs)
{
	if (this != &rhs)
	{
		makeEmpty();
		auto ritr = rhs.first();//��Ԫ���
		auto itr = zeroth();//ͷ���
		for (; !ritr.isPastEnd(); ritr.advance(), itr.advance())
			insert(ritr.retrieve(), itr);
	}
	return *this;
}

#endif // !LINKLIST_H
