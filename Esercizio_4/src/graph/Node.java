package graph;

import java.util.Objects;

/**
 * @param <T>: node type
 */
public class Node<T> {

  private T nodeValue;

  /**
   * Constructor of the Node class.
   *
   * @param NodeValue
   */
  public Node(T nodeValue) {
    this.nodeValue = nodeValue;
  }

  /**
   * Getter of the node.
   */
  public T getNodeValue() {
    return this.nodeValue;
  }

  /**
   * Setter for the node.
   *
   * @param nodeValue
   */
  public void setNodeValue(T nodeValue) {
    this.nodeValue = nodeValue;
  }

  /**
   * if the object exists but isn't the actual one, the two nodes are compared
   *
   * @param obj: the object to compare (presumably of type Node<T>)
   */
  @Override
  public boolean equals(Object obj) {
    if (obj == null)
      return false;
    if (this == obj)
      return true;

    if (obj instanceof Node<?>) {
      // This SuppressWarnings is justified since we are considerably sure that the
      // object will be of type Node<T>,
      // but a warning is still notified due to Java generic typing specification.
      @SuppressWarnings("unchecked")
      Node<T> node = (Node<T>) obj;
      return nodeValue.equals(node.nodeValue);
    } else
      return false;
  }

  /**
   * Method returns String of the value of the node
   * 
   * @return
   */
  @Override
  public String toString() {
    return nodeValue.toString();
  }

  /**
   * Method returns the hashcode of this node
   * 
   * @return
   */
  @Override
  public int hashCode() {
    return Objects.hashCode(this.nodeValue);
  }
}
