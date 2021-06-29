package graph;

public class UndirectedGraph<T, U> extends DirectedGraph<T, U> {

  /**
   * Method construct of an empty undirected graph
   * 
   */
  public UndirectedGraph() {
    super();
  }// constructor

  /**
   * Method returns if the graph is directed
   * 
   * @return
   */
  @Override
  public boolean isDirected() {
    return false;
  }// isDirected

  /**
   * Method returns the number if the edges of the graph
   * 
   * @return
   */
  @Override
  public int getEdgeSize() {
    return super.getEdgeSize() / 2;
  }// getEdgeSize

  /**
   * Method adds an edge, passing the values of the nodes of the edge
   * 
   * @param source
   * @param destination
   * @param edgeLabel
   * @return
   */
  @Override
  public boolean addEdge(T source, T destination, U edgeLabel) {
    return super.addEdge(source, destination, edgeLabel) && super.addEdge(destination, source, edgeLabel);
  }// addEdge

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
  }// addEdge

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
  }// addEdge

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
  }// removeEdge

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
  }// removeEdge

  /**
   * Method returns the graph's weight
   * 
   * @return
   */
  @Override
  public double getGraphWeight() throws GraphException {
    return super.getGraphWeight() / 2;
  }// getGraphWeight
}// class