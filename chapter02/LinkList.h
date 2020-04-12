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
	void remove(unsigned i);//删除第i个结点
	void remove(LinkListItr<T>it);//删除迭代器所指的直接后继结点
private:
	ListNode<T>* head;//头结点
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
	const T& retrieve()const//获取当前值
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
void LinkList<T>::insert(const T& x, const LinkListItr<T>& p)//p之后插入结点
{
	if (p.current != nullptr)
	{
		auto node = new ListNode<T>(x, p.current->next);//创建data为x的新结点，此结点指向p.current->next;
		p.current->next = node;
	}
}
template<typename T>
void LinkList<T>::insert(const T& x, unsigned i)
{
	auto it = this->zeroth();
	it.advance(i);//无头结点就将i改为i-1；不过要判断i是否大于1
	insert(x, it);
}
template<typename T>
LinkListItr<T> LinkList<T>::find(const T& x)const
{
	ListNode<T>* p = head->next;
	while (p != nullptr && p->data != x)
		p = p->next;
	return LinkListItr<T>(p);//如果没找到，返回尾后结点
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
void LinkList<T>::remove(LinkListItr<T>it)//删除迭代器所指的直接后继结点
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
void LinkList<T>::remove(unsigned i)//假定i>=1
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
		auto ritr = rhs.first();//首元结点
		auto itr = zeroth();//头结点
		for (; !ritr.isPastEnd(); ritr.advance(), itr.advance())
			insert(ritr.retrieve(), itr);
	}
	return *this;
}

#endif // !LINKLIST_H
