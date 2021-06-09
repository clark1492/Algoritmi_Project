package unionfind;

import java.util.HashSet;
import java.util.Set;
import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;

/**
 * 
 * @author esposito
 * @param <T>: type of the union find
 */

public class UnionFind<T> {

  private class Node<T> {
    private T element;
    private Integer rank;
  }

  private Map<Node<T>, Set<Node<T>>> map = null;

  public UnionFind(List<T> elements) throws UnionFindException {
    if (elements == null)
      throw new UnionFindException("UnionFind: elements cannot be null\n");
    if (elements.isEmpty())
      throw new UnionFindException("UnionFind: list elements cannot be empty\n");
    this.map = new HashMap<Node<T>, Set<Node<T>>>();
    Iterator<T> it = elements.iterator();
    while (it.hasNext()) {
      T el = (T) it.next();
      Node<T> node = new Node<T>();
      node.element = el;
      node.rank = 0;
      Set<Node<T>> set = new HashSet<Node<T>>();
      set.add(node);
      this.map.put(node, set);
    }
  }

  public void addElement(T element) throws UnionFindException {
    if (element == null)
      throw new UnionFindException("addElement: element cannot be null\n");
    Node<T> node = new Node<T>();
    node.element = element;
    node.rank = 0;
    Set<Node<T>> set = new HashSet<Node<T>>();
    set.add(node);
    this.map.put(node, set);
  }

  public T findSet(T element) throws UnionFindException {
    if (element == null)
      throw new UnionFindException("addElement: element cannot be null");

    Set<Node<T>> keySet = this.map.keySet();// prelevo le chiavi
    for (Node<T> key : keySet) {
      Set<Node<T>> valueSet = map.get(key);// per ogni chiavi prendo set di values
      if (valueSet.contains(getNode(element))) { // se il set contiene element restituisco la chiave
        return key.element;
      }
    }
    throw new UnionFindException("addElement: element not present");
  }

  public boolean inSameSet(T element1, T element2) throws UnionFindException {
    if (element1 == null || element2 == null)
      throw new UnionFindException("inSameSet: elements cannot be null");
    return findSet(element1).equals(findSet(element2)) ? true : false;
  }

  public int numberOfSets() {
    return this.map.size();
  }

  public void reset() {
    Set<Node<T>> keySet = this.map.keySet();
    List<Node<T>> valueList = new ArrayList<>();
    for (Node<T> key : keySet) {
      Set<Node<T>> valueSet = this.map.get(key);
      for (Node<T> node : valueSet)
        valueList.add(node);
    }
    this.map.clear();
    Iterator<Node<T>> it = valueList.iterator();
    while (it.hasNext()) {
      Node<T> newNode = (Node<T>) it.next();
      Set<Node<T>> newSet = new HashSet<Node<T>>();
      newSet.add(newNode);
      this.map.put(newNode, newSet);
    }
  }

  public int size() {
    int n_elem = 0;
    Set<Node<T>> keySet = map.keySet();// prelevo le chiavi
    for (Node<T> key : keySet) {
      Set<Node<T>> valueSet = map.get(key);// per ogni chiavi prendo set di values
      n_elem += valueSet.size();
    }
    return n_elem;
  }

  public String toString() {
    String result = new String();
    result = null;

    Set<Node<T>> keySet = map.keySet();// prelevo le chiavi
    result += "ELEMENT : REPRESENTATIVE KEY\n";
    for (Node<T> key : keySet) {
      Set<Node<T>> valueSet = map.get(key);// per ogni chiavi prendo set di values
      for (Node<T> value : valueSet)
        result += value.element + "\t:\t" + key.element + "\n";
    }
    return result;
  }

  public void union(T element1, T element2) throws UnionFindException {
    if (element1 == null || element2 == null || element1 == element2)
      throw new UnionFindException("union: elements cannot be null");
    link(findSet(element1), findSet(element2));
  }

  private void link(T elementx, T elementy) throws UnionFindException {

    Node<T> nodeX = getNode(elementx);
    Node<T> nodeY = getNode(elementy);
    Set<Node<T>> setX = null;
    Set<Node<T>> setY = null;

    if (this.map.containsKey(nodeY) && this.map.containsKey(nodeX)) {
      setY = this.map.get(nodeY);
      setX = this.map.get(nodeX);
      if (setX != null && setY != null) {
        if (nodeX.rank > nodeY.rank) {
          setX.addAll(setY);
          this.map.remove(nodeY);
          this.map.put(nodeX, setX);
        } else {
          if (nodeX.rank == nodeY.rank)
            nodeY.rank++;
          setY.addAll(setX);
          this.map.remove(nodeX);
          this.map.put(nodeY, setY);
        }
      }
    }
  }

  private Node<T> getNode(T element) throws UnionFindException {
    Node<T> found = new Node<>();
    found = null;

    Set<Node<T>> keySet = map.keySet(); // prelevo tutte le chaivi
    for (Node<T> key : keySet) { // percorro ogni singola chiave
      Set<Node<T>> valueSet = map.get(key);
      for (Node<T> node : valueSet)
        if ((node.element).equals(element))
          found = node;
    }
    if (found != null)
      return found;
    else
      throw new UnionFindException("getNode: element not present");
  }
}