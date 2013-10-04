template <typename T>
class Stack{
	private:
		T* elements;
		int size;

	public:
		Stack();
		Stack(T* init, int sz);

		int getSize();

		void push(T elem);
		T pop();
		T peek();
};

template <typename T>
Stack<T>::Stack(){
	elements = new T;
	size = 0;
}

template <typename T>
Stack<T>::Stack(T* init, int sz){
	elements = new T[sz];
	for(int i = 0; i < size; i++){
		elements[i] = init[i];
	}

	size = sz;
}

template <typename T>
int Stack<T>::getSize(){
	return size;
}

template <typename T>
void Stack<T>::push(T elem){
	size++;
	T* tmp = new T[size];
	for(int i = 0; i < size - 1; i++){
		tmp[i] = elements[i];
	}

	tmp[size - 1] = elem;
	elements = tmp;
}

template <typename T>
T Stack<T>::pop(){
	size--;
	T popped = elements[size];
	T* tmp = new T[size];
	for(int i = 0; i < size; i++){
		tmp[i] = elements[i];
	}

	elements = tmp;
	return popped;
}

template <typename T>
T Stack<T>::peek(){
	return elements[size - 1]; 
}

