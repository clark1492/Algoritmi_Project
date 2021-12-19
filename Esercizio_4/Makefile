all: 
	javac -d ./classes src/unionfind/*.java
	javac -d ./classes src/graph/*.java
	javac -d ./classes -cp .:./src/ src/kruskalAlgorithm/*.java
	javac -d ./classes -cp .:./src/ src/graphusagejava/*.java
	javac -d ./classes -cp .:./lib/hamcrest-core-1.3.jar:./lib/junit-4.12.jar:./src src/test/*

run_test:
	java -cp .:./classes/graph/*.class:./classes/graphusagejava/:./classes/kruskalAlgorithm/*.class:./classes/test/*.class classes/test.Graph_TestsRunner

run_app:
	java -cp .:./lib/hamcrest-core-1.3.jar:./lib/junit-4.12.jar:./classes/test/UnionFindTests.class:./src classes/test.UnionFind_TestsRunner


clean:
	rm -rf classes/* build/*