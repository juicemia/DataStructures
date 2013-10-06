package sets;

import java.util.*;

public class Set {
    private static String[] elements = {"Dog", "Fish", "Cat", "Book", "Door", "Pig", "Car", "Window", "Bird"};
    private static final int SET_SIZE = elements.length;
    private boolean[] register = new boolean[SET_SIZE];
    
    // returns empty set
    public Set(){}
    
    // returns a random set with probability n/SET_SIZE
    public Set(int n){
        float x = n/(float)SET_SIZE;
        Random rand = new Random();
        for(int i = 0; i < SET_SIZE;i++) this.register[i] = rand.nextDouble() < x;
    }
    
    // returns a set with one element
    public Set(String w){
        for(int i=0; i < SET_SIZE;i++) {
            if( elements[i].equals(w)){
                this.register[i] = true;
                break;
            }
        }
    }
    
    public void insert(String w){
        /**
         * Inserts a string in the set, if it exists in the elements
         */
        for(int i =0; i<SET_SIZE;i++){
            if(elements[i].equals(w)){
                this.register[i] = true;
                break;
            }
        }
    }
    
    public void remove(String w){
        /**
         * Inserts a string from the set
         */
        for(int i =0; i<SET_SIZE;i++){
            if(elements[i].equals(w)){
                this.register[i] = false;
                break;
            }
        }
    }
    
    public boolean isSubset(Set s){
        /**
         * Checks whether a given set is a substring of parent set
         */
        return this.Union(s).equals(this);
    }
    
    public boolean[] getRegister(){
        /**
         * Returns the register with the values
         */
        return this.register;
    }
    public void setValue(int index){
        /**
         * Sets value of @param index to true
         */
        if (index < SET_SIZE) this.register[index] = true;
    }
    
    public boolean getValue(int index){
        /**
         * Sets value of @param index to false
         */
        if (index < SET_SIZE) return this.register[index];
        return false;
    }
    
    public Set Union(Set s){
        /**
         * Returns a set of an union among the parent set and a parameter @param s
         */
        Set a = new Set();
        for(int i=0; i<SET_SIZE; i++) if(this.getValue(i) || s.getValue(i)) a.setValue(i);
        return a;
    }
    public Set Intersection(Set s){
        /**
         * Returns a set of an intersection among the parent set and a parameter @param s
         */
        Set a = new Set();
        for(int i=0; i<SET_SIZE; i++) if(this.getValue(i) && s.getValue(i)) a.setValue(i);
        return a;
    }
    public Set Complement(){
        /**
         * Returns a set of a complement of a parent set
         */
        Set a = new Set();
        for(int i=0; i<SET_SIZE; i++) if(!this.getValue(i)) a.setValue(i);
        return a;
    }
    public boolean belongs(String w){
        /** 
         * Checks whether the give parameter @param w belongs
         * in the parent set
         */
        for(int i=0; i<SET_SIZE; i++) if(w.equals(elements[i])) return true;
        return false;
    }
    public boolean equals(Set s){
        /**
         * Checks whether a parent set is equal with the @param s set
         */
        for(int i=0; i<SET_SIZE; i++){
            if(this.getValue(i) != s.getValue(i)) return false;
        }
        return true;
    }
    public int getCount(){
        /**
         * Retrieves the count of the current set
         */
        int n = 0;
        for(int i=0; i<SET_SIZE; i++) if (this.register[i]) n++;
        return n;
    }
    public void print(){
        /**
         * Prints the elements of the set
         */
        String accumulator = "";
        int len;
        for(int i=0; i<SET_SIZE; i++) if (this.register[i]) accumulator += elements[i] + ", ";
        len = accumulator.length();
        if (len > 0) accumulator = accumulator.substring(0, len-2);
        System.out.println("{" + accumulator + "}");
    }
}
