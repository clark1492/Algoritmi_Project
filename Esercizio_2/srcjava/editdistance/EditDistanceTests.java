package editdistance;

import static org.junit.Assert.assertEquals;
import org.junit.Test;
import org.junit.Before;


public class EditDistanceTests {
   
  String[] s1 = {"abcd","efgh","ab","cdefgh",""};
  
  @Test
  public void testSameWord() {
    EditDistance e = new EditDistance();
    assertEquals(0,e.edit_distance_dyn(s1[0],s1[0])); 
  }
  @Test
  public void testAllDifferentCharSameLength() {
    EditDistance e = new EditDistance();
    assertEquals(s1[0].length()*2,e.edit_distance_dyn(s1[0],s1[1]));
  }
  @Test
  public void testAllDifferentCharDifferentLength() {
    EditDistance e = new EditDistance();
    assertEquals(s1[0].length()+s1[1].length(),e.edit_distance_dyn(s1[0],s1[1])); 
  }
  @Test
  public void testWithEmptyString() {
    EditDistance e = new EditDistance();
    assertEquals(s1[0].length(),e.edit_distance_dyn(s1[0],s1[4])); 
  }
  @Test
  public void testEmptyStrings() {
    EditDistance e = new EditDistance();
    assertEquals(0,e.edit_distance_dyn(s1[4],s1[4])); 
  }
}