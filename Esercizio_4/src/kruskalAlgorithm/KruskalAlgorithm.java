
package kruskalAlgorithm;

import java.util.ArrayList;
import java.util.Comparator;

import unionfind.*;
import graph.*;

public class KruskalAlgorithm<T, U> {

  /**
   * Class to compare edges weights
   */
  public class EdgeComparator implements Comparator<Edge<T, U>> {
    @Override
    public int compare(Edge<T, U> edgeA, Edge<T, U> edgeB) {
      return edgeA.getWeight().compareTo(edgeB.getWeight());
    }
  }

  /**
   * Method returns the minimum spanning tree of the passed undirected and
   * weighted graph passed as parameter
   * 
   * @param graph
   * @return
   * @throws UnionFindException
   */
  public UndirectedGraph<T, U> execute(UndirectedGraph<T, U> graph) throws UnionFindException {

    if (!graph.isWeighted())
      throw new IllegalStateException("The Kruskal Algorithm is meant to be used on weighted data structures");

    UnionFind<Node<T>> unionFind = new UnionFind<>();

    EdgeComparator comparator = new EdgeComparator();

    UndirectedGraph<T, U> minimumSpanningTree = new UndirectedGraph<>();
    minimumSpanningTree.setIsWeighted(true);

    for (Node<T> node : graph.getNodes()) // create a forest in such a way that each graph is a separated tree
      unionFind.makeSet(node);

    ArrayList<Edge<T, U>> edgesList = graph.getEdges();
    edgesList.sort(comparator); // it sorts all the edges in non-decreasing order of weight

    for (Edge<T, U> edge : edgesList) {

      if (unionFind.findSet(edge.getSource()) != unionFind.findSet(edge.getDestination())) { // if the edge does not
                                                                                             // create loops in the tree

        minimumSpanningTree.addNode(edge.getSource());
        minimumSpanningTree.addNode(edge.getDestination());
        minimumSpanningTree.addEdge(edge.getSource(), edge.getDestination(), edge.getEdgeLabel());

        unionFind.union(edge.getSource(), edge.getDestination());
      }
    }
    return minimumSpanningTree;
  }
}