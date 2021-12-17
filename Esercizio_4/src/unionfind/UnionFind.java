package unionfind;

import java.util.Map;
import java.util.HashMap;

/**
 * 
 * @author esposito
 * @param <T>: type of the union find
 */

public class UnionFind<T> {

  private Map<T, T> parenthood = new HashMap<>();
  private Map<T, Integer> rank = new HashMap<>();

  public void makeSet(T element) throws UnionFindException {
    if (element == null)
      throw new UnionFindException("makeSet: element cannot be null");
    parenthood.put(element, element);
    rank.put(element, (Integer) 0);
  }

  public T findSet(T child) throws UnionFindException {
    if (child == null)
      throw new UnionFindException("findSet: element cannot be null");
    T father = parenthood.get(child);
    if (child != father) {
      father = findSet(father);
      parenthood.put(child, father);
    }
    return father;
  }

  public void union(T elementX, T elementY) throws UnionFindException {
    if (elementX == null || elementY == null)
      throw new UnionFindException("union: elements cannot be null");
    if (elementX == elementY)
      throw new UnionFindException("union: elements must be different");
    link(findSet(elementX), findSet(elementY));
  }

  private void link(T elementX, T elementY) throws UnionFindException {

    Integer rankX = rank.get(elementX);
    Integer rankY = rank.get(elementY);

    if (rankX.compareTo(rankY) > 0)
      parenthood.put(elementY, elementX);
    else {
      parenthood.put(elementX, elementY);
      if (rankX.equals(rankY))
        rank.put(elementY, rankY.intValue() + 1);
    }
  }
}