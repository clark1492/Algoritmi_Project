package unionfind;

import java.util.Map;
import java.util.HashMap;

/**
 * Method constructs the struct of UnionFindSet
 *
 */
public class UnionFind<T> {

  private Map<T, T> parenthood = new HashMap<>();
  private Map<T, Integer> rank = new HashMap<>();


/**
 * Makes a set with the element passed as parameter with itself as representative of the set
 *
 * @param element 
 */
  public void makeSet(T element) throws UnionFindException {
    if (element == null)
      throw new UnionFindException("makeSet: element cannot be null");
    parenthood.put(element, element);
    rank.put(element, (Integer) 0);
  }
  
  /**
   * Method with path compression that returns the representative of a set
   *
   * @param elementToFind
   * @return
   */
  public T findSet(T elementToFind) throws UnionFindException {
    if(parenthood.isEmpty())
      throw new UnionFindException("findSet: the struct is empty");
    if (elementToFind == null)
      throw new UnionFindException("findSet: element cannot be null");
    T father = parenthood.get(elementToFind);
    if (elementToFind != father) {
      father = findSet(father);
      parenthood.put(elementToFind, father); //path compression
    }
    return father;
  }
  
  /**
   * Method that combines by rank two different elements into a single set and sets 
   * as representative that of higher rank between the two sets 
   *
   * @param elementX
   * @param elementY
   */
  public void union(T elementX, T elementY) throws UnionFindException {
    if(parenthood.isEmpty())
      throw new UnionFindException("union: the struct is empty");
    if (elementX == null || elementY == null)
      throw new UnionFindException("union: elements cannot be null");
    if (elementX == elementY)
      throw new UnionFindException("union: elements must be different");
    link(findSet(elementX), findSet(elementY));
  }

  private void link(T elementX, T elementY) throws UnionFindException {

    Integer rankX = rank.get(elementX);
    Integer rankY = rank.get(elementY);

    //union by rank
    if (rankX.compareTo(rankY) > 0)
      parenthood.put(elementY, elementX);
    else {
      parenthood.put(elementX, elementY);
      if (rankX.equals(rankY))
        rank.put(elementY, rankY.intValue() + 1);
    }
  }
}