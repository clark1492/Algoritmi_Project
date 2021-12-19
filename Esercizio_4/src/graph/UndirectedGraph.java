package graph;

/**
 * The data structure of a undirected graph that it could be weighted or not
 * 
 * @param <T>: nodes label type
 * @param <U>: edges label type
 */
public class UndirectedGraph<T, U> extends DirectedGraph<T, U> {

  /**
   * Method construct of an empty undirected graph
   * 
   */
  public UndirectedGraph() {
    super();
  }

  /**
   * Method returns if the graph is directed
   * 
   * @return
   */
  @Override
  public boolean isDirected() {
    return false;
  }

  /**
   * Method returns the number of the edges of the graph
   * 
   * @return
   */
  @Override
  public int getEdgeSize() {
    return super.getEdgeSize() / 2;
  }

  /**
   * Method adds an edge, passing the values of the edge's node
   * 
   * @param source
   * @param destination
   * @param edgeLabel
   * @return
   */
  @Override
  public boolean addEdge(T source, T destination, U edgeLabel) {
    return super.addEdge(source, destination, edgeLabel) && super.addEdge(destination, source, edgeLabel);
  }

  /**
   * Method adds an edge, passing the nodes of the edge
   * 
   * @param source
   * @param destination
   * @param edgeLabel
   * @return
   */
  @Override
  public boolean addEdge(Node<T> source, Node<T> destination, U edgeLabel) {
    return super.addEdge(source, destination, edgeLabel) && super.addEdge(destination, source, edgeLabel);
  }

  /**
   * Method adds an edge, passing the edge to add
   * 
   * @param edge
   * @return
   */
  @Override
  public boolean addEdge(Edge<T, U> edge) {
    if (edge == null)
      return false;
    return super.addEdge(edge.getSource(), edge.getDestination(), edge.getEdgeLabel())
        && super.addEdge(edge.getDestination(), edge.getSource(), edge.getEdgeLabel());
  }

  /**
   * Method removes an edge, passing the nodes of the edge
   * 
   * @param source
   * @param destination
   * @return
   */
  @Override
  public boolean removeEdge(Node<T> source, Node<T> destination) {
    return super.removeEdge(source, destination) && super.removeEdge(destination, source);
  }

  /**
   * Method adds an edge, passing the edge to remove
   * 
   * @param edgeToRemove
   * @return
   */
  @Override
  public boolean removeEdge(Edge<T, U> edgeToRemove) {
    if (edgeToRemove == null)
      return false;
    return super.removeEdge(edgeToRemove.getSource(), edgeToRemove.getDestination())
        && super.removeEdge(edgeToRemove.getDestination(), edgeToRemove.getSource());
  }

  /**
   * Method returns the graph's weight
   * 
   * @throws GraphException
   * @return
   */
  @Override
  public double getGraphWeight() throws GraphException {
    return super.getGraphWeight() / 2;
  }
}