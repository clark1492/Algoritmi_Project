package unionfind;

import java.util.List;
import java.util.ArrayList;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;
import org.junit.Before;
import org.junit.Test;

/**
 *
 * @author esposito
 */
public class UnionFindTests {

  private List<Integer> list;
  private UnionFind<Integer> data;

  @Before
  public void createUnionFind() throws UnionFindException {
    list = new ArrayList<Integer>();
    for (int i = 0; i < 10; i++)
      list.add(i);
    data = new UnionFind<Integer>(list);
  }

  @Test
  public void testNew() throws UnionFindException {
    assertEquals((Integer) 1, data.findSet(1));
    assertEquals(10, data.numberOfSets());
    assertEquals(10, data.size());
    assertTrue(data.inSameSet(0, 0));
    assertFalse(data.inSameSet(0, 1));
    data.addElement(10);
    assertEquals(11, data.numberOfSets());
  }

  @Test
  public void testMerge() throws UnionFindException {
    data.union(1, 2);
    data.union(3, 4);
    data.union(1, 4);
    data.union(5, 6);
    assertEquals(6, data.numberOfSets());
    assertTrue(data.inSameSet(3, 1));
    assertFalse(data.inSameSet(8, 1));
    data.reset();
    assertEquals(10, data.numberOfSets());
  }

}