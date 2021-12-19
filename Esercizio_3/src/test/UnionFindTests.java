package test;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import org.junit.Before;
import org.junit.Test;

import unionfind.*;

/**
 * Test suite for UnionFind data structure
 */
public class UnionFindTests {

    private UnionFind<Integer> unionFind;

    @Before
    public void createUnionFind() throws UnionFindException {
        unionFind = new UnionFind<>();
        unionFind.makeSet(1);
        unionFind.makeSet(2);
        unionFind.makeSet(3);
        unionFind.makeSet(4);
    }

    @Test
    public void makeSetTest_true() throws UnionFindException {
        assertEquals(Integer.valueOf(1), unionFind.findSet(1));
    }

    @Test
    public void makeSetTest_false() throws UnionFindException {
        assertNotEquals(unionFind.findSet(3), unionFind.findSet(4));
    }

    @Test
    public void unionTest_true() throws UnionFindException {
        unionFind.union(1, 2);
        unionFind.union(3, 4);
        assertEquals(unionFind.findSet(1), unionFind.findSet(2));
        assertEquals(unionFind.findSet(3), unionFind.findSet(4));
        unionFind.union(1, 4);
        assertEquals(unionFind.findSet(2), unionFind.findSet(3));
    }

    @Test
    public void unionTest_false() throws UnionFindException {
        unionFind.union(1, 2);
        unionFind.union(3, 4);
        assertNotEquals(unionFind.findSet(2), unionFind.findSet(3));
        assertNotEquals(unionFind.findSet(1), unionFind.findSet(4));
    }
}