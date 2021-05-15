package editdistanceusage;

import java.util.ArrayList;
import editdistance.EditDistance;

public class ListTerms {
    
  private String word;
  private ArrayList <String> term;
  private EditDistance cmp;
  private int edit_d;

/**
 * Create a new ListTerms.
 * @param word: a string to compare to an array of strings
 *  in order to calculate the edit distance between them.
 * @throws editdistanceusage.ListTermsException if the string is null
 */
  public ListTerms (String word) throws ListTermsException {
    if (word == null)
      throw new ListTermsException("the word cannot be null");
    this.word = word;
    term = new ArrayList <String>(); 
    cmp = new EditDistance();
    edit_d = word.length();   
  }
/**
 * Set the new edit distance between the strings.
 * @param i: the value of the edit distance to set.
 * @throws editdistanceusage.ListTermsException if and only the edit 
 * distance is less than zero.
 */
  private void set_edit(int i) throws ListTermsException {
    if(i < 0)
      throw new ListTermsException("edit distance cannot be less than zero");
    edit_d = i;
  }
/**
 * Removes each terms in the list and set
 * the edit distance with the length of the word examined.
 */
  private void clearTerms() throws ListTermsException{
    term.clear();
    set_edit(this.word.length());
  }
/**
 * Print the entire ListTerms
 */ 
  public void print() {
    System.out.println("The word examined:\t\"" + word + "\"\nThe terms list with edit distance " + edit_d + ":\n");
    for(int i = 0; i < term.size(); i++) 
      System.out.println(" - " + term.get(i)); 
  }
/**
 * Returns if the list of terms is empty or not.
 */
  public boolean isEmpty() {
    return this.term.isEmpty();
  }
/**
 * Adds a string to the list.
 * If the new edit distance is different
 * from the old one, it will be setted with new value.
 * @param t: string to add 
 * @throws editdistanceusage.ListTermsException
 */
  public void addTerm(String t) throws ListTermsException{
    if(t == null)
      throw new ListTermsException("add:element cannot be null.");
    if(this.edit_d != getDistance(this.word,t)){
      clearTerms();
      set_edit(getDistance(this.word, t));
      term.add(t);
    }
    else term.add(t);
  }
/**
 * Returns the word examined.
 */
  public String getWord() {
    return this.word;
  }
/**
 * Returns the i-nth term of the list.
 */
  public String getTerm(int i) {
    return term.get(i);
  }
/**
 * @return the edit distance between two strings
 */
  public int getDistance(String s1,String s2) {
    return (this.cmp).edit_distance_dyn(s1, s2);
  }
}