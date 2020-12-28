import org.junit.Test;

public class TestEditDistance {
    
    @Test
    public void testSameWord() {
        EditDistanceApp e = new EditDistanceApp();
        String s1 = "word";
        String s2 = s2;
        assertEquals(0,e.edit_distance_dyn(s1,s2)); 
    }

    @Test
    public void testAllDifferentCharSameLength() {
        EditDistanceApp e = new EditDistanceApp();
        String s1 = "abcd";
        String s2 = "efgh";
        assertEquals(s1.legth*2,e.edit_distance_dyn(s1,s2));
    }

    @Test
    public void testAllDifferentCharDifferentLength() {
        EditDistanceApp e = new EditDistanceApp();
        String s1 = "ab";
        String s2 = "cdefgh";
        assertEquals(s1.length()+s2.length(),e.edit_distance_dyn(s1,s2)); 
    }


    @Test
    public void testWithEmptyString() {
        EditDistanceApp e = new EditDistanceApp();
        String s1 = "abcd";
        String s2 = "";
        assertEquals(s1.length(),e.edit_distance_dyn(s1,s2)); 
    }

    @Test
    public void testEmptyStrings() {
        EditDistanceApp e = new EditDistanceApp();
        String s1 = "";
        String s2 = "";
        assertEquals(0,e.edit_distance_dyn(s1,s2)); 
    }

    public static void main(String[] args){
        testSameWord();
        testAllDifferentCharDifferentLength();
        testAllDifferentCharSameLength();
        testAllDifferentDifferentLength();
        testEmptyStrings();
    }
}