#ifndef SEQLIST_H
#define SEQLIST_H
#include<memory>
#include<functional>
#include<stdexcept>
#include<initializer_list>
#include<iostream>
using std::allocator;
using std::function;
using std::invalid_argument;
using std::initializer_list;

template<typename T>class SeqList;
template<typename T>
int LocateElem(const SeqList<T>& seq, const T& e, function<bool(T, T)>f);

template<typename T>class SeqList
{
	friend int LocateElem<T>(const SeqList<T>& seq, const T& e, function<bool(T, T)>f);
public:
	SeqList() :length(0), listsize(0), elem(nullptr) {}
	SeqList(const initializer_list<T>& l):length(l.size()),listsize(l.size())
	{
		auto data = alloc.allocate(length);
		std::uninitialized_copy_n(l.begin(), length, data);
		elem = data;
	}
	SeqList(const SeqList<T>&);
	SeqList& operator=(const SeqList<T>&);
	T& operator[](int i) {
		if (i >= 0 && i < length)return *(elem + i);
		else throw invalid_argument("invalid_argument");
	}
	const T& operator[](int i) const {
		if (i >= 0 && i < length)return *(elem + i);
		else throw invalid_argument("invalid_argument");
	}
	~SeqList();

	void ClearList();
	int ListLength()const;
	bool ListEmpty()const { return length == 0 ? true : false; }
	void GetElem(int i, T* e);//获取顺序表中第i个元素，将其存储到e中。
	void PriorElem(const T& cur_e, T* pre_e);
	void NextElem(const T& cur_e, T* next_e);
	void ListInsert(int i, T e);
	void ListInsert(T e);//默认插在最后面
	void ListDelete(int i, T* e);
	void ListDelete();
private:
	void chk_n_alloc()
	{
		if (length == listsize) reallocate();
	}
	void free();
	void reallocate();

private:
	T* elem;//基址
	int length;//当前长度
	int listsize;//当前存储量
	allocator<T>alloc;//分配元素
};


template<typename T>
SeqList<T>::SeqList(const SeqList<T>&seq)
	:length(seq.length),listsize(seq.length)
{
	auto data = alloc.allocate(length);
	std::uninitialized_copy_n(seq.elem, length, data);
	elem = data;
}

template<typename T>
SeqList<T>& SeqList<T>::operator=(const SeqList<T>& seq)
{
	auto data = alloc.allocate(seq.length);
	free();
	length =listsize= seq.length;
	std::uninitialized_copy_n(seq.elem, length, data);
	elem = data;
	return *this;
}

template<typename T>
void SeqList<T>::free()
{
	if (elem)
	{
		for (int i = length; i !=0; i--)
			alloc.destroy((elem+i-1));
	}
	alloc.deallocate(elem, listsize);
}

template<typename T>
SeqList<T>::~SeqList()
{
	free();
}

template<typename T>
void SeqList<T>::ClearList()
{
	if (elem)
	{
		for (int i = length; i != 0; i--)
			alloc.destroy((elem + i - 1));
	}
}
template<typename T>
int SeqList<T>::ListLength()const
{
	return length;
}

template<typename T>
void SeqList<T>::reallocate()
{
	auto newListsize = ListLength() ? 2 * ListLength() : 1;
	auto newdata = alloc.allocate(newListsize);
	auto dest = newdata;
	auto e = elem;
	for (int i = 0; i != ListLength(); i++)
		alloc.construct(dest++, std::move(*e++));
	free();
	elem = newdata;
	length = dest - elem;
	listsize = newListsize;
}
template<typename T>
void SeqList<T>::GetElem(int i, T* e)
{
	e = &(this->operator[](i));
}

template<typename T>
int LocateElem<T>(const SeqList<T>& seq, const T& e, function<bool(T, T)>f)
{
	auto p =seq.elem;
	int i = 0;
	while (i !=seq.length && !f(*p, e))
	{
		i++;
		p++;
	}
	return i;//如果没找到，返回顺序表最后元素序号
}
template<typename T>
void SeqList<T>::ListInsert(int i, T el)
{
	if (i<1 || i>length+1)
		throw invalid_argument("invalid argument");
	else if (i == length+1)
		ListInsert(el);
	else
	{
		if (listsize == length)
		{
			auto newListsize = ListLength() ? 2 * ListLength() : 1;
			auto newdata = alloc.allocate(newListsize);
			auto dest = newdata;
			auto e = elem;
			for (int j = 0; j != i-1; j++)
				alloc.construct(dest++, std::move(*e++));
			alloc.construct(dest++, el);
			for (int j = i-1; j != length; j++)
				alloc.construct(dest++, std::move(*e++));
			free();
			elem = newdata;
			length = dest - elem;
			listsize = newListsize;
		}

	}

}

template<typename T>
void SeqList<T>::ListInsert(T e)
{
	chk_n_alloc();
	alloc.construct(elem + length, e);
	length++;
}

template<typename T>
void SeqList<T>::ListDelete(int i, T* e)
{
	if(i<1||i>length)
		throw invalid_argument("invalid argument");

	else if (i == length)
	{
		*e = *(elem + (i - 1));
		ListDelete();
	}
	else
	{
		*e = *(elem + (i - 1));
		for (int j = i; i != length; i++)
		{
			auto p = elem + (i - 1);
			auto q= elem + i;
			*p = *q;
		}

		alloc.destroy(elem + (length - 1));
		length--;
	}
}
template<typename T>
void SeqList<T>::ListDelete()
{
	if (elem)
		alloc.destroy(elem +(length-1));
}
#endif // !SEQLIST_H
