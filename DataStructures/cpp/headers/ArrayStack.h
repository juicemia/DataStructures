template <typename T>
class ArrayStack
{
	private:
		T* elements;
		int size;

	public:
		ArrayStack();
		ArrayStack(T* init, int sz);

		int getSize();

		void push(T elem);
		T pop();
		T peek();
};

template <typename T>
ArrayStack<T>::ArrayStack()
{
	elements = new T;
	size = 0;
}

template <typename T>
ArrayStack<T>::ArrayStack(T* init, int sz)
{
	elements = new T[sz];
	for(int i = 0; i < size; i++){
		elements[i] = init[i];
	}

	size = sz;
}

template <typename T>
int ArrayStack<T>::getSize()
{
	return size;
}

template <typename T>
void ArrayStack<T>::push(T elem)
{
	size++;
	T* tmp = new T[size];
	for(int i = 0; i < size - 1; i++){
		tmp[i] = elements[i];
	}

	tmp[size - 1] = elem;
	elements = tmp;
}

template <typename T>
T ArrayStack<T>::pop()
{
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
T ArrayStack<T>::peek()
{
	return elements[size - 1];
}

