#include<stdexcept>
using std::invalid_argument;
using std::out_of_range;

template<typename T>
class ListItr;

template<typename T>
class ConstListItr;

template<typename T>
class List;

template<typename T>
class ListNode;

template<typename T>
class ListNode
{
	friend class ConstListItr<T>;
	friend class ListItr<T>;
	friend class List<T>;
private:
	ListNode(const T& t = T(), ListNode* p = nullptr, ListNode* n = nullptr)
		:data(t),prev(p),next(n){}
private:
	T data;
	ListNode* prev;
	ListNode* next;
};

template<typename T>
class List
{
	friend class ListItr<T>;
	friend class ConstListItr<T>;
public:
	using iterator = ListItr<T>;
	using const_iterator = ConstListItr<T>;

	List();
	~List();
	List(const List<T>&);
	List<T>& operator=(const List<T>&);

	iterator begin();
	const_iterator begin()const;

	iterator end();
	const_iterator end()const;
	
	int size()const;
	bool empty()const;

	T& front();
	const T& front()const;
	T& back();
	const T& back()const;

	void push_front(const T&);
	void push_back(const T&);
	void pop_front();
	void pop_back();

	iterator insert(iterator itr, const T&);
	iterator erase(iterator itr);
	iterator erase(iterator start, iterator end);

private:
	void init();
	void makeEmpty();
private:
	int thesize;//长度
	ListNode<T>* head;//头结点
	ListNode<T>* tail;//尾结点
};

template<typename T>
class ConstListItr
{
	friend class List<T>;
public:
	ConstListItr();
	virtual ~ConstListItr(){}

	virtual const T& operator*()const;

	ConstListItr& operator++();
	ConstListItr operator++(int);

	ConstListItr& operator--();
	ConstListItr operator--(int);

	bool operator==(const ConstListItr<T>&)const;
	bool operator!=(const ConstListItr<T>&)const;

	ConstListItr(const List<T>& source, ListNode<T>* p);



protected:
	ListNode<T>* head;
	ListNode<T>* current;
	void isInitialized()const;
	void isvalid()const;
	void isAdvance()const;//前进
	void retreat()const;//后退
	T& retrieve()const;
};

template<typename T>
class ListItr :public ConstListItr<T>
{
	friend class List<T>;
public:
	ListItr();

	T& operator*();
	const T& operator*()const;

	ListItr& operator++();
	ListItr operator++(int);

	ListItr& operator--();
	ListItr operator--(int);


protected:
	ListItr(const List<T>&, ListNode<T>*);
};

template<typename T>
List<T>::List()
{
	init();
}

template<typename T>
void List<T>::init()
{
	thesize = 0;
	head = new ListNode<T>;
	tail = new ListNode<T>;
	head->next = tail;
	tail->prev = head;
}

template<typename T>
List<T>::~List()
{
	makeEmpty();
	delete head;
	delete tail;
}

template<typename T>
void List<T>::makeEmpty()
{
	while (!empty())
		pop_front();
}
template<typename T>
List<T>::List(const List<T>& rhs)
{
	init();
	*this = rhs;
}

template<typename T>
List<T>& List<T>::operator=(const List& rhs)
{
	if (this == &rhs)
		return *this;
	makeEmpty();
	for (const_iterator itr = rhs.begin(); itr != rhs.end(); ++itr)
		push_back(*itr);
	return *this;
}

template<typename T>
typename List<T>::iterator List<T>::begin()
{
	iterator itr(*this, head);
	return ++itr;
}

template<typename T>
typename List<T>::const_iterator List<T>::begin()const
{
	const_iterator itr(*this, head);
	return ++itr;
}

template<typename T>
typename List<T>::iterator List<T>::end()
{
	return iterator(*this, tail);
}

template<typename T>
typename List<T>::const_iterator List<T>::end()const
{
	return const_iterator(*this, tail);
}

template<typename T>
int List<T>::size()const
{
	return thesize;
}

template<typename T>
bool List<T>::empty()const
{
	return size() == 0;
}

template<typename T>
T& List<T>::front()
{
	return *begin();
}

template<typename T>
const T& List<T>::front()const
{
	return *begin();
}

template<typename T>
T& List<T>::back()
{
	return *--end();
}

template<typename T>
const T& List<T>::back()const
{
	return *--end();
}

template<typename T>
void List<T>::push_front(const T& x)
{
	insert(begin(), x);
}

template<typename T>
void List<T>::push_back(const T& x)
{
	insert(end(), x);
}

template<class T>
void List<T>::pop_front()
{
	erase(begin());
}

template<typename T>
void List<T>::pop_back()
{
	erase(--end());
}

template<typename T>
typename List<T>::iterator List<T>::insert(iterator itr, const T& x)
{
	itr.isvalid();
	if (itr.head != head)
		throw invalid_argument("invalid iterator");
	ListNode<T>* p = itr.current;
	p->prev->next = new ListNode<T>(x, p->prev, p);
	p->prev = p->prev->next;
	thesize++;
	return iterator(*this, p->prev);
}

template<typename T>
typename List<T>::iterator List<T>::erase(iterator itr)
{
	itr.isvalid();
	if (itr == end())
		throw out_of_range("cannot erase at end()");
	if (itr.head != head)
		throw out_of_range("erase iterator not in this list");
	ListNode<T>* p = itr.current;
	iterator retVal(*this, p->next);
	p->prev->next = p->next;
	p->next->prev = p->prev;
	delete p;
	thesize--;

	return retVal;
}

template<typename T>
typename List<T>::iterator List<T>::erase(iterator from, iterator to)
{
	for (iterator itr = from;itr != to;)
		itr = erase(itr);
	return to;
}

template<typename T>
ConstListItr<T>::ConstListItr()
	:head(nullptr),current(nullptr)
{}

template<typename T>
void ConstListItr<T>::isInitialized()const
{
	if (head == nullptr || current == nullptr)
		throw invalid_argument("list iterator");
}

template<typename T>
void ConstListItr<T>::isvalid()const
{
	isInitialized();
	if (current == head)
		throw out_of_range("at position prior to begin() in list");
}

template<typename T>
T& ConstListItr<T>::retrieve()const
{
	isvalid();
	if (current->next == nullptr)
		throw out_of_range("can not perform *end() in list");
	return current->data;
}

template<typename T>
const T& ConstListItr<T>::operator*()const
{
	return this->retrieve();
}

template<typename T>
void ConstListItr<T>::isAdvance()const
{
	isInitialized();
	if (current->next == nullptr)
		throw out_of_range("cannot perform ++end() in list");
}

template<typename T>
void ConstListItr<T>::retreat()const
{
	isvalid();
	if (current->prev == head)
		throw out_of_range("cannot perform --begin() in list");

}

template<typename T>
ConstListItr<T>& ConstListItr<T>::operator++()
{
	isAdvance();
	current = current->next;
	return *this;
}

template<typename T>
ConstListItr<T> ConstListItr<T>::operator++(int)
{
	ConstListItr<T> old = *this;
	++(*this);
	return old;
}

template<typename T>
ConstListItr<T>& ConstListItr<T>::operator--()
{
	retreat();
	current = current->prev;
	return *this;
}

template<typename T>
ConstListItr<T> ConstListItr<T>::operator--(int)
{
	ConstListItr<T> old = *this;
	--(*this);
	return old;
}

template<typename T>
bool ConstListItr<T>::operator==(const ConstListItr<T>& rhs)const
{
	return current == rhs.current;
}

template<typename T>
bool ConstListItr<T>::operator!=(const ConstListItr<T>& rhs)const
{
	return !(*this == rhs);
}

template<typename T>
ConstListItr<T>::ConstListItr(const List<T>& source, ListNode<T>* p)
	:head(source.head),current(p)
{
}

template<typename T>
ListItr<T>::ListItr()
{
}

template<typename T>
const T& ListItr<T>::operator*()const
{
	return ConstListItr<T>::operator*();
}

template<typename T>
T& ListItr<T>::operator*()
{
	return this->retrieve();
}

template<typename T>
ListItr<T>& ListItr<T>::operator++()
{
	this->isAdvance();
	this->current = this->current->next;
	return *this;
}

template<typename T>
ListItr<T> ListItr<T>::operator++(int)
{
	ListItr<T> old = *this;
	++(*this);
	return old;
}

template<class T>
ListItr<T>& ListItr<T>::operator--()
{
	this->retreat();
	this->current = this->current->prev;
	return *this;
}

template<typename T>
ListItr<T> ListItr<T>::operator--(int) 
{
	ListItr<T>old = *this;
	--(*this);
	return old;
}

template<typename T>
ListItr<T>::ListItr(const List<T>& source,ListNode<T>* p)
	:ConstListItr<T>(source,p){}