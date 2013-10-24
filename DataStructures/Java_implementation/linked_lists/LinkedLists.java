package linkedlists;

public class LinkedLists {

    public static void main(String[] args) {
        LinkedList<int> a=new LinkedList<int>();
        a.insert((int)31.2);
        a.insert((int)32);
        a.insert((int)33.8);
        a.insert((int)39.20);
        a.print();
        a.append(1234);
        a.print();
    }
}
