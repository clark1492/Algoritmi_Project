package unionfind;

import java.util.Map;
import java.util.HashMap;

/**
 * Implementation of a union-find set, implemented using HashMap.
 * The find operation is implemented using the path compression method, and the
 * union by rank operation.
 * 
 * @param <T>: type of the union find
 */

public class UnionFind<T> {
  private Map<T, T> parenthood = new HashMap<>();
  private Map<T, Integer> rank = new HashMap<>();

  /**
   * Method creates a set with the passed element, set its representative with
   * itself and set rank to zero
   * 
   * @param element
   * @throws UnionFindException
   */
  public void makeSet(T element) throws UnionFindException {
    if (element == null)
      throw new UnionFindException("makeSet: element cannot be null");
    parenthood.put(element, element);
    rank.put(element, (Integer) 0);
  }

  /**
   * Method returns the representative of the passed element using path
   * compression
   * 
   * @param child
   * @return
   * @throws UnionFindException
   */
  public T findSet(T element) throws UnionFindException {
    if (element == null)
      throw new UnionFindException("findSet: element cannot be null");
    if (parenthood.isEmpty())
      throw new UnionFindException("findSet: parenthood cannot be empty");
    T father = parenthood.get(element);
    if (element != father) {
      father = findSet(father);
      parenthood.put(element, father);
    }
    return father;
  }

  /**
   * Method unites two sets.The element with the greater ranked rapresentative
   * become the representative of the second one's representative.
   * 
   * @param elementX
   * @param elementY
   * @throws UnionFindException
   */
  public void union(T elementX, T elementY) throws UnionFindException {
    if (elementX == null || elementY == null)
      throw new UnionFindException("union: elements cannot be null");
    if (elementX == elementY)
      throw new UnionFindException("union: elements must be different");
    if (!parenthood.containsKey(elementX) || !parenthood.containsKey(elementY))
      throw new UnionFindException("union: elements must be in the sets");
    link(elementX, elementY);
  }

  /**
   * Method that combines two sets.
   * 
   * @param elementX
   * @param elementY
   * @throws UnionFindException
   */
  private void link(T elementX, T elementY) throws UnionFindException {

    T rootX = findSet(elementX);
    T rootY = findSet(elementY);
    Integer rankX = rank.get(rootX);
    Integer rankY = rank.get(rootY);

    if (rootX == null || rootY == null)
      throw new UnionFindException("link: root element cannot be null");
    if (rootX == rootY) // the elements belongs to the same set
      return;
    if (rankX.compareTo(rankY) > 0) // rootX's rank is higher than rootY's one
      parenthood.put(rootY, rootX); // the root of element Y points to the root of the element X
    else { // the two ranks are equal or rankY is higher than rankX
      parenthood.put(rootX, rootY); // the root of element X points to the root of the element Y
      if (rankX.equals(rankY)) // the two ranks are equal so the rankY is increased by one
        rank.put(rootY, rankY.intValue() + 1);
    }
  }
}