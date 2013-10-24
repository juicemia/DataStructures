
package linkedlists;

public class <T> Node {
    private T value;
    private Node next;
    // constructors
    public Node(T v, Node nxt){
        this.value = v;
        this.next = nxt;
    }
    
    public Node(){
        this.next = null;
    }
    
    public Node getNext(){
        return this.next;
    }
    
    public void setNext(Node n){
        this.next = n;
    }
    
    public T getValue(){
        return this.value;
    }
    
    public void setValue(int v){
        this.value = v;
    }
}
