package unionfind;

/**
 * Exception throwable by the UnionFind library
 * 
 */
public class UnionFindException extends Exception{
	
	/**
  * @param message: the message displayed when the exception is thrown
  */
  public UnionFindException(String message){
    super(message);
  }
}
