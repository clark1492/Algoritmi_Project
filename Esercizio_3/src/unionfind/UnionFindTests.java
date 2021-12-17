package unionfind;

import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;

/**
 * It specifies a test suite for the UnionFind library
 * @author esposito
 */
public class UnionFindTests {

  private UnionFind<Integer> data;

  @Before
  public void createUnionFind() throws UnionFindException {
    data = new UnionFind<>();
  }

  @Test
  public void makeSetTest_true() throws UnionFindException {
    data.makeSet(1);
    assertEquals(Integer.valueOf(1), data.findSet(1));
  }
  
  @Test
  public void makeSetTest_false() throws UnionFindException {
    data.makeSet(1);
    assertNotEquals(Integer.valueOf(2),data.findSet(1));
  }

  @Test
  public void unionTest_true() throws UnionFindException {
    data.makeSet(1);
    data.makeSet(2);
    data.union(1, 2);
    assertEquals(data.findSet(1) ,data.findSet(2));
  }

  @Test
  public void unionTest_false() throws UnionFindException {
    data.makeSet(1);
    data.makeSet(2);
    assertNotEquals(data.findSet(1) ,data.findSet(2));
  }
}