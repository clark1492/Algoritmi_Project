import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;

/**
 *
 * @author esposito
 */
public class UnionFind_TestsRunner {

  /**
   * @param args: the command line arguments
   */
  public static void main(String[] args) {
    Result result = JUnitCore.runClasses(UnionFindTests.class);
    for (Failure failure : result.getFailures()) {
      System.out.println(failure.toString());
    } // for

    System.out.println(result.wasSuccessful());
  } // main
} // class
