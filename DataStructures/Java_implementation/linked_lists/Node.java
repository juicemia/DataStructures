
package linkedlists;

public class Node {
    private int value;
    private Node next;
    // constructors
    public Node(int v, Node nxt){
        this.value = v;
        this.next = nxt;
    }
    
    public Node(){
        this.next = null;
    }
    
    public Node getNext(){
        return this.next;
    }
    
    void setNext(Node n){
        this.next = n;
    }
    
    int getValue(){
        return this.value;
    }
    
    void setValue(int v){
        this.value = v;
    }
}
