package graph;

import java.util.Map;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.Set;

public class DirectedGraph<T, U> {

  protected Map<Node<T>, Map<Node<T>, Edge<T, U>>> adjacencyList;
  protected boolean isWeighted;

  /**
   * Method constructs the struct of empty Graph
   *
   */
  public DirectedGraph() {

    this.isWeighted = false;
    this.adjacencyList = new HashMap<>();
  }// construct

  /**
   * Setter for the isWeighted variable
   * 
   * @param isWeighted
   */
  public void setIsWeighted(boolean isWeighted) {
    this.isWeighted = isWeighted;
  }// setIsWeighted

  /**
   * Method returns true if the graph is weighted
   * 
   * @return
   */
  public boolean isWeighted() {
    return this.isWeighted;
  }// isWeighted

  /**
   * Method returns true if the graph is directed
   * 
   * @return
   */
  public boolean isDirected() {
    return true;
  }// isDirected

  /**
   * Method adds node to the graph from it value
   * 
   * @param nodeValue
   * @return
   */
  public boolean addNode(T nodeValue) {
    return this.addNode(new Node<>(nodeValue));
  }// addNode

  /**
   * Method adds node to the graph
   * 
   * @param node
   * @return
   */
  public boolean addNode(Node<T> node) {
    if (node == null || node.getNodeValue() == null)
      return false;
    return adjacencyList.putIfAbsent(node, new HashMap<>()) == null;
  }// addNode

  /**
   * Method adds edge to the graph from its values
   * 
   * @param source
   * @param destination
   * @param edgeLabel
   * @return
   */
  public boolean addEdge(T source, T destination, U edgeLabel) {
    return this.addEdge(new Node<>(source), new Node<>(destination), edgeLabel);
  }// addEdge

  /**
   * Method adds edge to the graph from its nodes values
   * 
   * @param source
   * @param destination
   * @param edgeLabel
   * @return
   */
  public boolean addEdge(Node<T> source, Node<T> destination, U edgeLabel) {
    if (source == null || source.getNodeValue() == null)
      return false;
    if (destination == null || destination.getNodeValue() == null)
      return false;

    if (adjacencyList.containsKey(source) && adjacencyList.containsKey(destination)) {
      return adjacencyList.get(source).putIfAbsent(destination, new Edge<>(source, destination, edgeLabel)) == null;
    }
    return false;
  }// addEdge

  /**
   * Method adds edge to the graph
   * 
   * @param edge
   * @return
   */
  public boolean addEdge(Edge<T, U> edge) {
    if (edge == null)
      return false;
    return this.addEdge(edge.getSource(), edge.getDestination(), edge.getEdgeLabel());
  }// addEdge

  /**
   * Method returns true if a node is conteined in the graph, passing a value
   *
   * @param nodeValue
   * @return
   */
  public boolean containsNode(T nodeValue) {
    return containsNode(new Node<>(nodeValue));
  }// containsNode

  /**
   * Method returns true if a node is conteined in the graph, passing the node
   * itself
   * 
   * @param node
   * @return
   */
  public boolean containsNode(Node<T> node) {
    return adjacencyList.containsKey(node);
  }// containsNode

  /**
   * Method returns true if a edge is conteined in the graph, passing the nodes
   * values of the edge
   * 
   * @param source
   * @param destination
   * @return
   */
  public boolean containsEdge(T source, T destination) {
    return this.containsEdge(new Node<>(source), new Node<>(destination));
  }// containsEdge

  /**
   * Method returns true if a edge is conteined in the graph, passing the nodes of
   * the edge
   * 
   * @param source
   * @param destination
   * @return
   */
  public boolean containsEdge(Node<T> source, Node<T> destination) {
    if (adjacencyList.containsKey(source) && adjacencyList.containsKey(destination)) {
      return adjacencyList.get(source).containsKey(destination);
    }
    return false;
  }// containsEdge

  /**
   * Method returns true if a edge is conteined in the graph, passing the edge
   * itself
   * 
   * @param edge
   * @return
   */
  public boolean containsEdge(Edge<T, U> edge) {
    if (edge == null)
      return false;
    return containsEdge(edge.getSource(), edge.getDestination());
  }// containsEdge

  /**
   * Methods removes node, passing a value
   * 
   * @param nodeValue
   * @return
   */
  public boolean removeNode(T nodeValue) {
    return this.removeNode(new Node<>(nodeValue));
  }// removeNode

  /**
   * Methods removes node, passing the node itself
   * 
   * @param value
   * @return
   */
  public boolean removeNode(Node<T> node) {
    if (node == null || node.getNodeValue() == null)
      return false;

    for (Map.Entry<Node<T>, Map<Node<T>, Edge<T, U>>> entry : adjacencyList.entrySet()) {
      if (entry.getKey().equals(node))
        continue;
      entry.getValue().remove(node);
    }
    return adjacencyList.remove(node) != null;
  }// removeNode

  /**
   * Methods removes edge, passing the edge itself
   * 
   * @param edge
   * @return
   */
  public boolean removeEdge(Edge<T, U> edge) {
    if (edge == null)
      return false;
    return this.removeEdge(edge.getSource(), edge.getDestination());
  }// removeEdge

  /**
   * Methods removes edge, passing the nodes of the edge
   * 
   * @param source
   * @param destination
   * @return
   */
  public boolean removeEdge(Node<T> source, Node<T> destination) {
    if (source == null || source.getNodeValue() == null)
      return false;
    if (destination == null || destination.getNodeValue() == null)
      return false;

    if (adjacencyList.containsKey(source))
      return adjacencyList.get(source).remove(destination) != null;
    return false;
  }// removeEdge

  /**
   * Methods removes edge, passing the nodes values of the edge
   * 
   * @param source
   * @param destination
   * @return
   */
  public boolean removeEdge(T source, T destination) {
    return this.removeEdge(new Node<>(source), new Node<>(destination));
  }// removeEdge

  /**
   * Method returns the number of the nodes of the graph
   * 
   * @return
   */
  public int getNodeSize() {
    return adjacencyList.size();
  }// getNodeSize

  /**
   * Method returns the number of the edges of the graph
   * 
   * @return
   */
  public int getEdgeSize() {
    Set<Node<T>> setNode = adjacencyList.keySet();
    int edgeSize = 0;
    for (Node<T> key : setNode) {
      edgeSize += adjacencyList.get(key).size();
    }
    return edgeSize;
  }// getEdgeSize

  /**
   * Method returns the list of the nodes
   * 
   * @return
   */
  public ArrayList<Node<T>> getNodes() {
    Set<Node<T>> set = adjacencyList.keySet();
    ArrayList<Node<T>> nodeList = new ArrayList<>();
    for (Node<T> key : set)
      nodeList.add(key);
    return nodeList;
  }// getNodes

  /**
   * Method returns the list of the edges
   * 
   * @return
   */
  public ArrayList<Edge<T, U>> getEdges() {
    Set<Node<T>> setNode = adjacencyList.keySet();
    ArrayList<Edge<T, U>> edgeList = new ArrayList<>();
    for (Node<T> key : setNode)
      edgeList.addAll(adjacencyList.get(key).values());
    return edgeList;
  }// getEdges

  /**
   * Method returns the list of the nodes adjacent to the passed node
   * 
   * @param node
   * @return
   * @throws GraphException
   */
  public ArrayList<Node<T>> getAdjacentNodes(Node<T> node) throws GraphException {
    if (node == null || node.getNodeValue() == null)
      throw new GraphException("getAdjacentNodes: node cannot be null");
    if (!adjacencyList.containsKey(node))
      throw new GraphException("getAdjacentNodes: node not present");
    ArrayList<Node<T>> adjacentNodes = new ArrayList<>();
    adjacentNodes.addAll(adjacencyList.get(node).keySet());
    return adjacentNodes;
  }// getAdjacentNodes

  /**
   * Method returns the list of the nodes adjacent to the passed node value
   * 
   * @param nodeValue
   * @return
   * @throws GraphException
   */
  public ArrayList<Node<T>> getAdjacentNodes(T nodeValue) throws GraphException {
    return getAdjacentNodes(new Node<>(nodeValue));
  }// getAdjacentNodes

  /**
   * Method returns the label of the edge of the passed nodes
   * 
   * @param source
   * @param destination
   * @return
   * @throws GraphException
   */
  public U getLabel(Node<T> source, Node<T> destination) throws GraphException {
    if (source == null || destination == null)
      throw new GraphException("getLabel: nodes cannot be null");
    if (source.getNodeValue() == null || destination.getNodeValue() == null)
      throw new GraphException("getLabel: nodes values cannot be null");
    Edge<T, U> edge = adjacencyList.get(source).get(destination);
    return edge.getEdgeLabel();
  }// getLabel

  /**
   * Method returns the label of the edge of the passed nodes values
   * 
   * @param source
   * @param destination
   * @return
   * @throws GraphException
   */
  public U getLabel(T source, T destination) throws GraphException {
    return getLabel(new Node<>(source), new Node<>(destination));
  }// getLabel

  /**
   * Method returns the graph's weight
   * 
   * @return
   */
  public double getGraphWeight() throws GraphException {
    if (!isWeighted)
      throw new GraphException("The graph is not weighted");
    double graphWeight = 0;

    for (Map<Node<T>, Edge<T, U>> nodeValues : adjacencyList.values())
      for (Edge<T, U> edge : nodeValues.values())
        graphWeight = graphWeight + edge.getWeight();

    return graphWeight;
  }// getGraphWeight
}// class