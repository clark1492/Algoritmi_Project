package graph;

import java.util.ArrayList;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;
import org.junit.Before;
import org.junit.Test;

import unionfind.UnionFindException;

/**
 * It specifies a test suite for the Graph library
 */
public class GraphTest {
  DirectedGraph<Character, Double> directedGraph;
  UndirectedGraph<Character, Double> undirectedGraph;

  @Before
  public void initialize() {
    directedGraph = new DirectedGraph<>();
    undirectedGraph = new UndirectedGraph<>();

    directedGraph.addNode('A');
    undirectedGraph.addNode('A');
    directedGraph.addNode('B');
    undirectedGraph.addNode('B');
    directedGraph.addNode('C');
    undirectedGraph.addNode('C');
    directedGraph.addNode('D');
    undirectedGraph.addNode('D');
    directedGraph.addNode('E');
    undirectedGraph.addNode('E');

    undirectedGraph.addEdge('A', 'C', 5.0);
    undirectedGraph.addEdge('A', 'E', 6.0);
    undirectedGraph.addEdge('B', 'C', 1.0);
    directedGraph.addEdge('A', 'E', 5.0);
    directedGraph.addEdge('A', 'B', 6.0);
    directedGraph.addEdge('B', 'C', 1.0);
    directedGraph.addEdge('D', 'B', 5.0);
    directedGraph.addEdge('E', 'A', -3.5);
    directedGraph.addEdge('E', 'D', -1.0);
  }

  @Test
  public void isDirected() {
    assertTrue(directedGraph.isDirected());
    assertFalse(undirectedGraph.isDirected());
  }

  @Test
  public void isWeighted() {
    assertFalse(directedGraph.isWeighted());
    assertFalse(undirectedGraph.isWeighted());
    directedGraph.setIsWeighted(true);
    undirectedGraph.setIsWeighted(true);
    assertTrue(directedGraph.isWeighted());
    assertTrue(undirectedGraph.isWeighted());
  }

  @Test
  public void duplicateNode() {
    assertFalse(directedGraph.addNode('A'));
    assertFalse(undirectedGraph.addNode('A'));
  }

  @Test
  public void addNullNode() {
    assertFalse(directedGraph.addNode((Character) null));
    assertFalse(undirectedGraph.addNode((Character) null));
  }

  @Test
  public void duplicateEdge() {
    assertFalse(directedGraph.addEdge('A', 'B', 4.0));
    assertFalse(undirectedGraph.addEdge('A', 'E', 4.0));
  }

  @Test
  public void addNullEdge() {
    assertFalse(directedGraph.addEdge(null));
    assertFalse(undirectedGraph.addEdge(null));
  }

  @Test
  public void removeNode() {
    assertTrue(directedGraph.removeNode('C'));
    assertTrue(undirectedGraph.removeNode('C'));
  }

  @Test
  public void removeNullNode() {
    assertFalse(directedGraph.removeNode((Character) null));
    assertFalse(undirectedGraph.removeNode((Character) null));
  }

  @Test
  public void removeNotInListNode() {
    assertFalse(directedGraph.removeNode('X'));
    assertFalse(undirectedGraph.removeNode('Z'));
  }

  @Test
  public void removeEdge() {
    assertTrue(directedGraph.removeEdge('E', 'D'));
    assertTrue(undirectedGraph.removeEdge('E', 'A'));
  }

  @Test
  public void removeNullEdge() {
    assertFalse(directedGraph.removeEdge((Character) null, (Character) null));
    assertFalse(undirectedGraph.removeEdge((Character) null, (Character) null));
  }

  @Test
  public void removeNotInListEdge() {
    assertFalse(directedGraph.removeEdge('E', 'B'));
    assertFalse(undirectedGraph.removeEdge('E', 'D'));

  }

  @Test
  public void nodeSize() {
    assertEquals(5, directedGraph.getNodeSize());
    assertEquals(5, undirectedGraph.getNodeSize());
  }

  @Test
  public void edgeSize() {
    assertEquals(6, directedGraph.getEdgeSize());
    assertEquals(3, undirectedGraph.getEdgeSize());
  }

  @Test
  public void getNodes() {
    ArrayList<Node<Character>> nodes = new ArrayList<>();
    nodes.add(new Node<>('A'));
    nodes.add(new Node<>('B'));
    nodes.add(new Node<>('C'));
    nodes.add(new Node<>('D'));
    nodes.add(new Node<>('E'));
    assertEquals(nodes, directedGraph.getNodes());
    assertEquals(nodes, undirectedGraph.getNodes());
  }

  @Test
  public void getEdges() {
    ArrayList<Edge<Character, Double>> directedEdges = new ArrayList<>();
    ArrayList<Edge<Character, Double>> undirectedEdges = new ArrayList<>();

    undirectedEdges.add(new Edge<>('A', 'C', 5.0));
    undirectedEdges.add(new Edge<>('A', 'E', 6.0));
    undirectedEdges.add(new Edge<>('B', 'C', 1.0));
    undirectedEdges.add(new Edge<>('C', 'A', 5.0));
    undirectedEdges.add(new Edge<>('C', 'B', 1.0));
    undirectedEdges.add(new Edge<>('E', 'A', 6.0));
    directedEdges.add(new Edge<>('A', 'B', 6.0));
    directedEdges.add(new Edge<>('A', 'E', 5.0));
    directedEdges.add(new Edge<>('B', 'C', 1.0));
    directedEdges.add(new Edge<>('D', 'B', 5.0));
    directedEdges.add(new Edge<>('E', 'A', -3.5));
    directedEdges.add(new Edge<>('E', 'D', -1.0));
    assertEquals(directedEdges, directedGraph.getEdges());
    assertEquals(undirectedEdges, undirectedGraph.getEdges());
  }

  @Test
  public void getAdjacentNodes() throws GraphException {
    ArrayList<Node<Character>> adjacenties = new ArrayList<>();
    adjacenties.add(new Node<>('A'));
    adjacenties.add(new Node<>('D'));
    assertEquals(adjacenties, directedGraph.getAdjacentNodes('E'));
    adjacenties.clear();
    adjacenties.add(new Node<>('C'));
    adjacenties.add(new Node<>('E'));
    assertEquals(adjacenties, undirectedGraph.getAdjacentNodes('A'));
    assertEquals(new ArrayList<>(), undirectedGraph.getAdjacentNodes('D'));
  }

  @Test
  public void getLabel() throws GraphException {
    assertEquals(6.0, directedGraph.getLabel('A', 'B'), 0.0);
    assertEquals(6.0, undirectedGraph.getLabel('A', 'E'), 0.0);
  }

  @Test
  public void graphWeight_kruskalAlgorithm() throws GraphException, UnionFindException {
    directedGraph.setIsWeighted(true);
    undirectedGraph.setIsWeighted(true);
    undirectedGraph.addNode('F');
    undirectedGraph.addEdge('F', 'D', 8.0);
    undirectedGraph.addEdge('A', 'B', -5.0);
    assertEquals(12.5, directedGraph.getGraphWeight(), 0.0);
    assertEquals(15.0, undirectedGraph.getGraphWeight(), 0.0);
    KruskalAlgorithm<Character, Double> algorithm = new KruskalAlgorithm<>();
    UndirectedGraph<Character, Double> minimumSpanninTree = algorithm.execute(undirectedGraph);
    assertEquals(10.0, minimumSpanninTree.getGraphWeight(), 0.0);
  }
}
