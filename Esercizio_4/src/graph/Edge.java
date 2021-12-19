package graph;

import java.util.Objects;

/**
 * The data structure of graph's edge
 * 
 * @param <T>: nodes label type
 * @param <U>: edges label type
 */
public class Edge<T, U> implements Comparable<Edge<T, U>> {

  private Node<T> source;
  private Node<T> destination;

  private U edgeLabel;
  private boolean isWeighted;
  private Double edgeWeight;

  /**
   * Method construct labeled edge between two passed nodes
   *
   * @param source
   * @param destination
   * @param edgeLabel
   */
  public Edge(Node<T> source, Node<T> destination, U edgeLabel) {
    this.source = source;
    this.destination = destination;
    this.edgeLabel = edgeLabel;

    if (edgeLabel instanceof Double) {
      edgeWeight = (Double) edgeLabel;
      isWeighted = true;
    } else
      isWeighted = false;
  }

  /**
   * Method construct labeled edge between two nodes, passing their values
   *
   * @param source
   * @param destination
   * @param edgeLabel
   */
  public Edge(T source, T destination, U edgeLabel) {
    this(new Node<>(source), new Node<>(destination), edgeLabel);
  }

  /**
   * Method returns node source
   *
   * @return
   */
  public Node<T> getSource() {
    return this.source;
  }

  /**
   * Method returns node destination
   *
   * @return
   */
  public Node<T> getDestination() {
    return this.destination;
  }

  /**
   * Method returns label of an edge
   *
   * @return
   */
  public U getEdgeLabel() {
    return this.edgeLabel;
  }

  /**
   * Method returns weight of an edge, if the graph is weighted
   *
   * @return
   */
  public Double getWeight() {
    if (isWeighted)
      return edgeWeight;
    else
      throw new UnsupportedOperationException("The edge isn't weighted.");
  }

  /**
   * Method returns true if the object passed as parameter is equal to this edge
   *
   * @param toCheck
   * @return
   */
  @Override
  public boolean equals(Object toCheck) {
    if (toCheck == null)
      return false;
    if (toCheck == this)
      return true;
    if (!(toCheck instanceof Edge<?, ?>))
      return false;

    @SuppressWarnings("unchecked")
    Edge<T, U> edgeToCheck = (Edge<T, U>) toCheck;
    return Objects.equals(this.source, edgeToCheck.source) && Objects.equals(this.destination, edgeToCheck.destination);
  }

  /**
   * Returns a string with the description of this edge
   *
   * @return
   */
  @Override
  public String toString() {
    return "Edge{Source: " + this.source.toString() + ", Destination: " + this.destination.toString() + ", EdgeLabel: "
        + this.edgeLabel.toString() + "}";
  }

  /**
   * Method compares the weights of the edge passed as parameter with this edge
   *
   * @return
   */
  @Override
  public int compareTo(Edge<T, U> edge) {
    if (this.isWeighted && edge.isWeighted)
      return this.edgeWeight.compareTo(edge.getWeight());
    else
      throw new UnsupportedOperationException("The edge isn't weighted.");
  }
}