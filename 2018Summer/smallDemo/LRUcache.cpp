/*
 * @filename:    LRUcache.cpp
 * @author:      Jack Kang
 * @date:        2016年07月27日 04:29:31
 * @description:
 */

#include <iostream>
#include <unordered_map>
#include <list>
#include <cassert>
using namespace std;

template<typename T>
class Cache
{
public:
	template<typename V>
	struct Node
	{
		explicit Node(V *v):value(v), next(NULL), pre(NULL){}
		explicit Node(V v):value(new V(v)), next(NULL), pre(NULL){}
		Node():next(NULL), pre(NULL){}
		~Node(){delete value;}
		Node<V> *next;
		Node<V> *pre;
		V *value;
	};
	Cache():head_(new Node<T>()), tail_(new Node<T>()){head_->next = tail_; tail_->pre =head_;}; 
	Cache(const Cache&) = delete;
	Cache operator=(Cache &) = delete;
	// static Cache* getInstance()
	// {
	// 	static Cache* cache = new 
	// }
	T get(const string &key);
	int set(const string &key, const T& value);
private:
	int push_front(Node<T> *v);
	int cutNode(Node<T> *v);
	unordered_map<string, Node<T>*> map_;
	Node<T> *head_;
	Node<T> *tail_;
};
template<typename T>
int Cache<T>::push_front(Node<T> *v)
{
	head_->next->pre = v;
	v->next = head_->next;
	v->pre = head_;
	head_->next = v;
	return 0;
}
template<typename T>
int Cache<T>::cutNode(Node<T> *v)
{
	v->next->pre = v->pre;
	v->pre->next = v->next;
	return 0;
}template<typename T>
T Cache<T>::get(const string &key)
{
	if(map_.find(key) == map_.end())
		return string();
	else{
		Node<string> *n = map_[key];
		cutNode(n);
		push_front(n);
		return *n->value;
	}
}
template<typename T>
int Cache<T>::set(const string &key, const T &value)
{
	T *p = new T(value);
	Node<T> *node = new Node<T>(p);
	map_.insert(make_pair(key, node));
	push_front(node);
}


int main(int argc, char const *argv[])
{
	Cache<string> cache(); // complie error
	string key = "hello";
	string value = "world";

	cache.set(key, value);
	string t = cache.get(key);
	cout << t << endl;
	return 0;
}
// todo:node type;