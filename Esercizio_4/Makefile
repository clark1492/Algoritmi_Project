all: build/unionfind build/graph build/graphusage

build/unionfind:
	javac -d ./classes -cp ".:./src" src/unionfind/*.java

build/graph:
	javac -d ./classes -cp ".:./src:./lib/junit-4.12.jar:./lib/hamcrest-core-1.3.jar" src/graph/*.java

build/graphusage:
	javac -d ./classes -cp ".:./src:" src/graphusagejava/*.java

run_test:
	java -cp ".:./classes:./lib/junit-4.12.jar:./lib/hamcrest-core-1.3.jar" graph/Graph_TestsRunner

run_app:
	java -cp ".:./classes:./lib/junit-4.12.jar:./lib/hamcrest-core-1.3.jar" graphusagejava/KruskalAlgorithmUsage italian_dist_graph.csv

clean:
	rm -rf ./classes/*
