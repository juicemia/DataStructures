template <typename T>
class ArrayList
{

	private:
		T* elements;
		int currentSize;
		int currentIndex;

	public:
		/***CONSTRUCTORS***/
		ArrayList(); //initialize an empty ArrayList
		ArrayList(int size); //we only know its size (and obviously it's type)
		ArrayList(T* elem, int size); //we know its size and starting elements

        /***DESTRUCTORS***/
		~ArrayList();

		int getCurrentIndex();
		int getCurrentSize();
		T* getCurrentElement();

		//all these guys return the updated size
		int insert(T elem); //insert at the current index
		int append(T elem); //append to the end of the ArrayList
		int remove(); //remove the element at the current index

		//iterators; they all return the new index
		int nextIndex();
		int prevIndex();

		//returns -1 if new index is out of bounds of the array
		int jmpIndex(int index);

};

template <typename T>
ArrayList<T>::ArrayList()
{
	elements = new T;
	currentSize = 0;
	currentIndex = -1;
}

template <typename T>
ArrayList<T>::ArrayList(int size)
{
	elements = new T[size];
	currentSize = size;
	currentIndex = 0;
}

template <typename T>
ArrayList<T>::ArrayList(T *elem, int size)
{
	elements = new T[size];
	for(int i = 0; i < size; i++){
		elements[i] = elem[i];
	}

	currentSize = size;
	currentIndex = 0;
}

template <typename T>
ArrayList<T>::~ArrayList()
{
	delete[] elements;
}

template <typename T>
int ArrayList<T>::getCurrentIndex()
{
	return currentIndex;
}

template <typename T>
int ArrayList<T>::getCurrentSize()
{
	return currentSize;
}

template <typename T>
T* ArrayList<T>::getCurrentElement()
{
	if(currentIndex == -1)
		return 0;

	return &elements[currentIndex];
}

template <typename T>
int ArrayList<T>::insert(T elem)
{
	currentSize++;
	T* tmp = new T[currentSize];

	for(int i = 0; i < currentIndex; i++){
		tmp[i] = elements[i];
	}
	tmp[currentIndex] = elem;
	for(int i = currentIndex + 1; i < currentSize; i++){
		tmp[i] = elements[i - 1];
	}

	elements = tmp;
	return currentSize;
}

template <typename T>
int ArrayList<T>::append(T elem)
{
	T* tmp = new T[currentSize + 1];

	for(int i = 0; i < currentSize; i++){
		tmp[i] = elements[i];
	}

	tmp[currentSize] = elem;
	elements = tmp;
	currentSize++;
	return currentSize;
}

template <typename T>
int ArrayList<T>::remove()
{
	currentSize--;
	T* tmp = new T[currentSize];

	for(int i = currentSize; i > currentIndex; i--){
		tmp[i - 1] = elements[i];
	}
	for(int i = 0; i < currentIndex; i++){
		tmp[i] = elements[i];
	}

	if(currentIndex == currentSize)
		currentIndex--;

	elements = tmp;
	return currentSize;
}

template <typename T>
int ArrayList<T>::nextIndex()
{
	if(currentSize == 0)
		return -1;

	if(currentIndex == currentSize - 1)
		return currentIndex;

	currentIndex++;
	return currentIndex;
}

template <typename T>
int ArrayList<T>::prevIndex()
{
	if(currentSize == 0)
		return -1;

    if(currentSize == 1)
        return 0;

	currentIndex--;
	return currentIndex;
}

template <typename T>
int ArrayList<T>::jmpIndex(int index)
{
	if(index >= currentSize)
		return -1;

	currentIndex = index;
	return currentIndex;
}
