package editdistanceusage;

/**
 * 
 * @author esposito
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;

public class EditDistanceApp {
  private static final Charset ENCODING = StandardCharsets.UTF_8;
  
  private static void loadData (String filepath, ArrayList <String> words) throws FileNotFoundException,IOException{
    System.out.println("LOADING DATA FROM FILE..." + filepath);
    Path inputFilePath = Paths.get(filepath);
    try (BufferedReader fileInputReader = Files.newBufferedReader(inputFilePath, ENCODING)){
      String line_c = "";
      String temp = null;
      while ((temp = fileInputReader.readLine()) != null)
        line_c += temp +"\n";
      String[] temp_array = line_c.replaceAll("\\p{Punct}","").split("[^A-Za-z0-9]");
      for(int i = 0; i < temp_array.length; i++ ){
        words.add(temp_array[i]);
      }
      System.out.println("finish");
    }
  }
  /**
   * 
   * @param s1: an array of strings
   * @param s2: an array of strings
   * @return a list for each s1's string with the s2's strings with minimum edit distance.
   */      
  private static void minEditDistance(ListTerms[] lst,ArrayList <String> s1,ArrayList <String> s2) throws ListTermsException{
    
    for(int i = 0; i < s1.size(); i++){
      lst[i] = new ListTerms(s1.get(i));
      boolean first = true;
      int dist = s1.get(i).length();
      for(int j = 0; j < s2.size(); j++){
        if(first){
          dist = lst[i].getDistance(s1.get(i),s2.get(j));
          lst[i].addTerm(s2.get(j));
          first = false;
        }
        else{
          if(lst[i].getDistance(s1.get(i),s2.get(j)) < dist){
            dist = lst[i].getDistance(s1.get(i),s2.get(j));
            lst[i].addTerm(s2.get(j));
          }
          if (lst[i].getDistance(s1.get(i),s2.get(j)) == dist)
            lst[i].addTerm(s2.get(j));
        }
      }
    }
  }
  /**
   * Print a ListTerms
   * @param lst: the ListTerms to print
   */
  private static void printList(ListTerms[] lst){
    for(int i = 0; i < lst.length; i++){
      lst[i].print();
      System.out.println();
    }
  }

  private static void testWithEditDistanceFunction(String filepath_1,String filepath_2)
    throws IOException, ListTermsException{
    ArrayList <String> s1,s2;
    s1 = new ArrayList<String>();
    s2 = new ArrayList<String>();
    loadData(filepath_1,s1);
    loadData(filepath_2,s2);
    ListTerms[] lst = new ListTerms[s1.size()];
    minEditDistance(lst, s1, s2);
    printList(lst);
  }

  /**
   * 
   * @param args: the command line arguments. It should contain only two argument specifying the filepath of the data file
  */
  public static void main (String[] args) throws ListTermsException,Exception {
    if(args.length < 2)
      throw new Exception("Usage: EditDistanceApp <file_name1> <file_name2>");
    
    testWithEditDistanceFunction(args[0],args[1]);
  }       
}