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
  }// makeSet

  /**
   * Method returns the representative of the passed element using path
   * compression
   * 
   * @param child
   * @return
   * @throws UnionFindException
   */
  public T findSet(T child) throws UnionFindException {
    if (child == null)
      throw new UnionFindException("findSet: element cannot be null");
    T father = parenthood.get(child);
    if (child != father) {
      father = findSet(father);
      parenthood.put(child, father);
    }
    return father;
  }// findSet

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
    link(findSet(elementX), findSet(elementY));
  }//union

  /**
 * Method that unites two set.
 * 
 * @param elementX
 * @param elementY
 * @throws UnionFindException
 */
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
  }//link
}//class