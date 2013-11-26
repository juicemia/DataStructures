
package linkedlists;


public class <T> LinkedList implements List{
	// Current and head pointers
    private Node head, curr;
    private int size;
    
    public LinkedList(){
    	// Initially just an empty list
        this.head = this.curr = new Node();
        this.size = 0;
    }
    private Node getTail(){
    	/**
    	 * Retrieves the tail after iterating through the whole list
    	 */
        Node cur = this.head;
        while (cur.getNext() != null){
            cur = cur.getNext();
        }
        return cur;
    }
    @Override
    public void clear(){
    	/**
    	 * Empties the list. Garbage collector should take care
    	 * of the rest 
    	 */
        this.head.setNext(null);
        this.head = this.curr = new Node();
        this.size = 0;
    }
    @Override
    public void insert(T elem){
    	/**
    	 * Inserts @param elem to the list
    	 */
        if (this.size == 0){
        	/*
        	 * If the list is empty, insert a new node into head, and
        	 * make head.next point to the current.next 
        	 */
            this.head = new Node(elem, this.curr.getNext());
        } else {
        	/*
        	 * If the list is not empty, make the current.next
        	 * point to a new node with a value of @param elem
        	 * and its next pointing to current.next
        	 */
            this.curr.setNext(new Node(elem, this.curr.getNext()));
        }
        this.size++;
    }
    @Override
    public void append(T elem){
    	/**
    	 * Appends the @param elem to the end of the list
    	 */
        Node tail = getTail();
        Node prov = new Node(elem, null);
        tail.setNext(prov);
        this.size++;
    }
    @Override    
    public void remove(){
    	/**
    	 * Removes the current element from the list.
    	 * Heavy reliance on garbage collector
    	 */
        this.curr.setNext(this.curr.getNext().getNext());
        this.size--;
    }
    @Override
    public void moveToStart(){
    	/**
    	 * Moves the current pointer to the head.
    	 */
        this.curr = this.head;
    }
    @Override
    public void moveToEnd(){
    	/**
    	 * Moves the current pointer to the tao;.
    	 */
        this.curr = this.getTail();
    }
    @Override
    public void prev(){
    	/**
    	 * Updates the current pointer to point 
    	 * to the previous element in the list
    	 * 
    	 * IMPORTANT!
    	 * Haven't tested this method, although logically it should
    	 * work fine
    	 */
    	
    	// Let's find the previous pointer
        Node temp = this.head;
        Node prev = this.head;
        // if head is equal to current, there is no prev
        while (temp != this.curr){
        		prev = temp;
        		temp = temp.getNext();
        }
        this.curr = prev;
    }
    @Override   
    public void next(){
    	/**
    	 * Updates the current pointer to point 
    	 * to the next element in the list
    	 */
        if (this.curr.getNext() != null)    this.curr = this.curr.getNext();
    }
    @Override
    public int length(){
    	/**
    	 * Returns the size of the linked list
    	 */
        return this.size;
    }
    @Override
    public int getPosition(){
        /**
         * Gets the position of the current pointer
         * IMPORTANT!
    	 * Haven't tested this method, although logically it should
    	 * work fine
    	 * 
    	 * @return position
    	 * 
         */
        Node temp = this.head;
        int position = 1;
        // if head is equal to current, there is no prev
        for(int position = 1; temp != this.curr; position++){
        		temp = temp.getNext();
        }
        return position;
    }
    @Override
    public void moveToPosition(int pos){
        /**
         * Moves the current pointer to the @param position,
         * if such position exists (size > position)
         * IMPORTANT!
    	 * Haven't tested this method, although logically it should
    	 * work fine
         */
    	Node temp = this.head;
    	if (this.size > position){
    		for (int i = 1 ; i < position; i++){
    			temp = temp.getNext();
    		}
    		this.curr = temp;
    	}
    }
    @Override
    public T getValue(){
    	/**
    	 * Returns the value of the current element of the list.
    	 * The reason why it's curr.getNext(), because the current always
    	 * points to an empty node, where an insertion will happen. (I assume)
    	 */
        return this.curr.getNext().getValue();
    }
    public void print(){
    	/** 
    	 * Prints the linked list
    	 */
        Node h=this.head;
        System.out.print(" < ");
        while(h!= null && h.getNext() != null){
            System.out.print(""+h.getValue());
            System.out.print(" , ");
            h=h.getNext();
        }
        if (h != null)
        	System.out.print("" + h.getValue());
        System.out.println(" > ");
    }
}
