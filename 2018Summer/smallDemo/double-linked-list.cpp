template<typename T>
struct Node
{
	explicit Node(T *v):value_(v), next_(NULL), pre_(NULL){}
	explicit Node(T v):value_(new T(v)), next_(NULL), pre_(NULL){}
	Node():next_(NULL), pre_(NULL){}
	~Node(){delete value_;}
	T* value_;
	Node<T> *next_;
	Node<T> *pre_;
};
template<typename T>
class List
{
public:
	List<T>():head_(new Node<T>()), tail_(new Node<T>())
	{
		head_->next_ = tail_;
		tail_->pre_ = head_;
	};
	~List<T>(){delete head_; delete tail_;} 
	void push_back(const T &value);
	void push_front(const T &value);
	void push_back(T *pv);
	void push_front(T *pv);
	void print();
	T pop_back();
	T pop_front();
private:
	Node<T> *head_;
	Node<T> *tail_;
};
template<typename T>
void List<T>::print()
{
	Node<T> *p = head_->next_;
	while(p != tail_){
		cout << *p->value_ << endl;
		p = p->next_;
	}
}
template<typename T>
void List<T>::push_front(const T &value)
{
	T *v = new T(value);
	Node<T> *p = new Node<T>(v);
	head_->next_->pre_ = p;
	p->next_ = head_->next_;
	p->pre_ = head_;
	head_->next_ = p;
}

template<typename T>
void List<T>::push_back(const T &value)
{
	T *v = new T(value);
	Node<T> *p = new Node<T>(v);
	tail_->pre_->next_ = p;
	p->pre_ = tail_->pre_;
	p->next_ = tail_;
	tail_->pre_ = p;
}
template<typename T>
void List<T>::push_back(T *pv)
{
	Node<T> *p = new Node<T>(pv);
	tail_->pre_->next_ = p;
	p->pre_ = tail_->pre_;
	p->next_ = tail_;
	tail_->pre_ = p;
}
template<typename T>
void List<T>::push_front(T *pv)
{
	Node<T> *p = new Node<T>(pv);
	head_->next_->pre_ = p;
	p->next_ = head_->next_;
	p->pre_ = head_;
	head_->next_ = p;
}
template<typename T>
T List<T>::pop_front()
{
	T result = *head_->next_->value_;
	Node<T> *temp = head_->next_;
	head_->next_ = temp->next_;
	temp->next_->pre_ = head_;
	delete temp;
	return result;
}
template<typename T>
T List<T>::pop_back()
{
	T result = *tail_->pre_->value_;
	Node<T> *temp = tail_->pre_;
	tail_->pre_ = temp->pre_;
	temp->pre_->next_ = tail_;
	delete temp;
	return result;
}