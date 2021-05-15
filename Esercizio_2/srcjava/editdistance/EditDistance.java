package editdistance;

public class EditDistance {
/**
 * @param s1: a string
 * @param s2: a string
 * @return the edit distance between two strings
 */
  public int edit_distance(String s1, String s2) {
    if (s1.length() == 0)
      return s2.length();
    
    if (s2.length() == 0)
      return s1.length();
    
    if (s1.charAt(0) == s2.charAt(0))
      return edit_distance(s1.substring(1,s1.length()),s2.substring(1,s2.length()));
    
    return 1 + Math.min(edit_distance(s1.substring(0,s1.length()),s2.substring(1,s2.length())) , 
      edit_distance(s1.substring(1,s1.length()),s2.substring(0,s2.length())));
  }
/**
 * The method is recursive with the optimization of the dynamic programming.
 * @param s1: a string
 * @param s2: a string
 * @return  the edit distance between two strings 
 */
  public int edit_distance_dyn(String s1, String s2) {
    int[][] t = new int[s1.length() + 1][s2.length() + 1];  // matrix initialization to save the value
                                                            // of the edit distance.
    for(int i = 0; i <= s1.length(); i++)                  
      t[i][0] = i;
    for(int j = 0; j <= s2.length(); j++)
      t[0][j] = j;
    for(int i = 1; i <= s1.length(); i++){
      for(int j = 1; j <= s2.length(); j++)
        t[i][j] = -1;
    }
    return rec_edit_distance_dyn(s1,s2,s1.length(),s2.length(),t);
  }

  private int rec_edit_distance_dyn(String s1, String s2, int n, int m, int[][] t) {
    if ( n == -1)
      return m;
    if ( m == -1 )
      return n;
    if(t[n][m] != -1)
      return t[n][m];
    if(s1.charAt(n-1) == s2.charAt(m-1)) {
      if(t[n-1][m-1]!= -1)
        return t[n-1][m-1];
      else 
        return rec_edit_distance_dyn(s1,s2,n-1,m-1,t);
    }
    else {
      int m1,m2;
      
      if(t[n-1][m] != -1)   
        m1 = t[n-1][m];                
      else
        m1 = rec_edit_distance_dyn(s1, s2, n-1, m, t);      
                 
      if(t[n][m-1] != -1)               
        m2 = t[n][m-1];            
      else  
        m2 = rec_edit_distance_dyn(s1, s2, n, m-1, t);
      return t[n][m] = 1 + Math.min(m1,m2);         
    }
  }
}