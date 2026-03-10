JUNIT = ./lib/junit-4.12.jar
HAMCREST = ./lib/hamcrest-core-1.3.jar
CP = ./classes:$(JUNIT):$(HAMCREST)
FILE ?= ../Data/italian_dist_graph.csv

all:
	mkdir -p classes
	javac -d classes src/unionfind/*.java
	javac -d classes src/graph/*.java
	javac -d classes -cp classes src/kruskalAlgorithm/*.java
	javac -d classes -cp classes src/graphusagejava/*.java
	javac -d classes -cp $(CP) src/test/*.java

run_test:
	java -cp $(CP) test.Graph_TestsRunner

run_app:
	java -cp ./classes graphusagejava.KruskalAlgorithmUsage $(FILE)


clean:
	rm -rf classes

	