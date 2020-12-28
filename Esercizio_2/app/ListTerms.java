package app;
import java.util.ArrayList;

public class ListTerms {
    
    private String word;
    private ArrayList <String> term;
    private int edit_d;

/**
 * Create a new ListTerms.
 * Parameter: string to compare to an array of strings
 *  in order to calculate the edit distance between them.
 */
    public ListTerms (String new_word) {
        word = new_word;
        term = new ArrayList <String>();
        edit_d = word.length();

        
    }
/**
 * Set the new edit distance between the strings.
 */
    private void set_edit(int i) {
        edit_d = i;
    }
/**
 * Removes each terms in the list and set
 * the edit distance with the length of the word examined.
 */
    public void clear() {
        term.clear();
        set_edit(word.length());
    }
    
    public String print() {
        String s = "The word examined:\t" + word + "\nThe terms list with edit distance " + edit_d + ":\n";
        for(int i = 0; i < term.size(); i++) 
            s += " - " + term.get(i) + "\n";
        s += "\n\n\n";
        return s;
        
    }
/**
 * Returns if the list of terms is empty or not.
 */
    public boolean isEmpty() {
       return term.isEmpty();
    }
/**
 * Adds a string to the list.
 * Parameters: string to add and the edit distance 
 *  between the word and term. If the new edit distance is different
 *  from the old one, it will be setted with new value.
 */
    public void addTerm(String t, int d) {
        term.add(t);
        if(d != edit_d )
            set_edit(d);
    }
/**
 * Returns the word examined.
 */
    public String getWord() {
        return word;
    }
/**
 * Returns the i-nth term of the list.
 */
    public String getTerm(int i) {
       return term.get(i);
    }
}