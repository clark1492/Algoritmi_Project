package app;
import java.io.*;
import java.util.StringTokenizer;

public class EditDistanceApp {
/**
 * Returnes the edit distance between two strings.
 * The method is recursive without the optimization of the dynamic programming.
 */
    public static int edit_distance(String s1, String s2) {

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
 * Returnes the edit distance between two strings.
 * The method is recursive with the optimization of the dynamic programming.
 */
    public static int edit_distance_dyn(String s1, String s2) {
        int[][] t = new int[s1.length() + 1][s2.length() + 1];  // matrix initialization to save the value
                                                                // of the edit distance.
        for(int i = 0; i <= s1.length(); i++)                  
            t[i][0] = i;
        for(int j = 0; j <= s2.length(); j++)
            t[0][j] = j;
        for(int i = 1; i <= s1.length(); i++)
            for(int j = 1; j <= s2.length(); j++)
                t[i][j] = -1;
        return rec_edit_distance_dyn(s1,s2,s1.length(),s2.length(),t);
    }

    private static int rec_edit_distance_dyn(String s1, String s2, int n, int m, int[][] t) {
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

    public static void main (String[] args) {
        String line_c = "" ;
        String line_d = "";
        String temp = "";
        String [] words;
        String [] terms;
        

        try {
            BufferedReader in = new BufferedReader(new FileReader("correctme.txt"));
            temp = in.readLine();
            while (temp != null) {
                line_c += temp;
                temp = in.readLine();
            }
            in.close();
        }
        catch (FileNotFoundException e) {
            System.err.println("No File found");  
        } 

        catch (IOException e) {
            System.err.println(e);  
        }       
        
        // Memorization of each token from the read string.

        StringTokenizer token = new StringTokenizer(line_c);
        words = new String[token.countTokens()];
        int k = 0;
        while(token.hasMoreTokens()) {
            words[k] = token.nextToken();
            words[k] = words[k].replaceAll("[^A-Za-z0-9]", "").toLowerCase();
            k++;
        }
            
        try {       
            BufferedReader in = new BufferedReader(new FileReader("dictionary.txt"));
            temp = "";
            temp = in.readLine();
            while (temp != null){
                line_d += temp + "\n";
                temp = in.readLine();
            }
            in.close(); 
        }

        catch (FileNotFoundException e) {
            System.err.println("No File found");  
        } 

        catch (IOException e) {
            System.err.println(e);  
        }    
            
        token = new StringTokenizer(line_d);
        terms = new String[token.countTokens()];
        k = 0;
        while(token.hasMoreTokens()) {
            terms[k] = token.nextToken();
            k++;
        }   
        /**
         * Defines an array of ListTerms to save 
         * for each word the dictionary terms
         * with the minimum edit distance between 
         * the word and the terms.
         */      

        ListTerms lst[] = new ListTerms[words.length];
        for(int i = 0; i < words.length; i++) {
            lst[i] = new ListTerms(words[i]);
            boolean first = true;
            int dist = words[i].length();
            for(int j = 0; j < terms.length; j++) {
                if(first) {
                    dist = edit_distance_dyn(words[i],terms[j]);
                    lst[i].addTerm(terms[j],edit_distance_dyn(words[i],terms[j]));
                    first = false;
                }
                else {
                    if(edit_distance_dyn(words[i],terms[j]) < dist) {
                        dist = edit_distance_dyn(words[i],terms[j]);
                        lst[i].clear();
                        lst[i].addTerm(terms[j],edit_distance_dyn(words[i],terms[j]));
                    }
                    else if (edit_distance_dyn(words[i],terms[j]) == dist)
                        lst[i].addTerm(terms[j],edit_distance_dyn(words[i],terms[j]));

                }
            }
        }

        try {
            BufferedWriter buf = new BufferedWriter(new FileWriter("output.txt"));
            PrintWriter out = new PrintWriter(buf);
            for(int i = 0; i < lst.length; i++)
                out.print(lst[i].print());
            out.close();
        }

        catch (IOException e) {
                System.err.println(e);  
        }       
    }
}