package graphusagejava;

import graph.*;
import unionfind.*;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class KruskalAlgorithmUsage {

  private static final Charset ENCODING = StandardCharsets.UTF_8;

  private static void loadGraph(String filepath, UndirectedGraph<String, Double> graph)
      throws IOException, FileNotFoundException {

    System.out.println("\nLoading data from file...\n");

    int rowsCount = 0;
    Path inputFilePath = Paths.get(filepath);
    try (BufferedReader fileInputReader = Files.newBufferedReader(inputFilePath, ENCODING)) {
      String line = null;
      while ((line = fileInputReader.readLine()) != null) {
        String[] lineElements = line.split(","); // In CSV values are separated by commas

        graph.addNode(lineElements[0]);
        graph.addNode(lineElements[1]);
        graph.addEdge(lineElements[0], lineElements[1], Double.parseDouble(lineElements[2]));
        rowsCount++;
      }
    }
    System.out.println(rowsCount + " file rows has been successfully loaded into the memory.");
  }

  public static void main(String[] args) throws IOException, FileNotFoundException, GraphException, UnionFindException {

    if (args.length < 1) {
      System.err.println("Invalid argument");
      System.err.println("Usage: java kruskalAlgorithmUsage.KruskalAlgorithmUsage <csv_file_path>");
      System.exit(0);
    }

    UndirectedGraph<String, Double> graph = new UndirectedGraph<>();

    graph.setIsWeighted(true);

    loadGraph(args[0], graph);

    // Execute the algorithm
    KruskalAlgorithm<String, Double> kruskalAlgorithm = new KruskalAlgorithm<>();
    System.out.println("Executing Kruskal's algorithm...\n");
    long startTime = System.currentTimeMillis();
    UndirectedGraph<String, Double> minimumSpanningTree = kruskalAlgorithm.execute(graph);
    long endTime = System.currentTimeMillis();

    System.out.println("Original Graph: \n\tNodes: " + graph.getNodeSize() + "\n\tEdges: " + graph.getEdgeSize()
        + "\n\tWeight: " + String.format("%.0f", graph.getGraphWeight() / 1000) + " km");

    System.out.println("Minimum Spanning Tree Graph: \n\tNodes: " + minimumSpanningTree.getNodeSize() + "\n\tEdges: "
        + minimumSpanningTree.getEdgeSize() + "\n\tWeight: "
        + String.format("%.0f", minimumSpanningTree.getGraphWeight() / 1000) + " km");

    System.out.println("\n\nExecution ended in " + (endTime - startTime) + " milliseconds");
  }

}
