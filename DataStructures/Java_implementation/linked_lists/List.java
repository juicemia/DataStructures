
package linkedlists;

public interface List<Node> {
    /*
     * Remove all the elements from the list
     */
    public void clear();
    
    /*
     * Inserts an element into a list into a current position
     */
    public void insert(int elem);
    
    /*
     * Append the element to the end of the list
     */
    public void append(int elem);
    
    /*
     *  Removes the current element and return its value
     */
    public void remove();
    
    /*
     * Set the current position to the start of the list
     */
    public void moveToStart();
    
    /*
     * Set the current position to the end of the list
     */
    public void moveToEnd();
    
    /*
     * Move the current position to the previous node
     */
    public void prev();
    
    /*
     * Move the current position to the next node
     */
    public void next();
    
    /*
     * Return the number of elements in the list
     */
    public int length();
    
    /*
     * Return the current position pointer
     */
    public int getPosition();
    
    /*
     * Set the current position pointer
     */
    public void moveToPosition(int pos);
    
    /*
     * Return the node in the current position
     */
    public int getValue();
}
