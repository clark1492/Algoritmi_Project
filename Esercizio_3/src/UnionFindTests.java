import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import org.junit.Before;
import org.junit.Test;

/**
 *
 * @author esposito
 */
public class UnionFindTests {

    private UnionFind<Integer> unionFind;

    @Before
    public void createUnionFind() {
        unionFind = new UnionFind<>();
    }

    @Test
    public void makeSetTest_true() throws UnionFindException {
        unionFind.makeSet(1);
        assertEquals(Integer.valueOf(1), unionFind.findSet(1));
    }

    @Test
    public void makeSetTest_false() throws UnionFindException {
        unionFind.makeSet(1);
        unionFind.makeSet(2);
        assertNotEquals(unionFind.findSet(1), unionFind.findSet(2));
    }

    @Test
    public void unionTest_true() throws UnionFindException {
        unionFind.makeSet(1);
        unionFind.makeSet(2);
        unionFind.makeSet(3);
        unionFind.makeSet(4);
        unionFind.union(1, 2);
        unionFind.union(1, 4);
        assertEquals(unionFind.findSet(1), unionFind.findSet(2));
        assertEquals(unionFind.findSet(1), unionFind.findSet(4));
        assertEquals(unionFind.findSet(2), unionFind.findSet(4));
    }

    @Test
    public void unionTest_false() throws UnionFindException {
        unionFind.makeSet(1);
        unionFind.makeSet(2);
        unionFind.makeSet(3);
        unionFind.makeSet(4);
        unionFind.union(1, 4);
        assertNotEquals(unionFind.findSet(1), unionFind.findSet(2));
        assertNotEquals(unionFind.findSet(1), unionFind.findSet(3));
        assertNotEquals(unionFind.findSet(2), unionFind.findSet(3));
    }
}