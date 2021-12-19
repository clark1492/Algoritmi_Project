all: 
	javac -d ./classes src/unionfind/*
	javac -d ./classes -cp .:./lib/hamcrest-core-1.3.jar:./lib/junit-4.12.jar:./src src/test/*

run:
	java -cp .:./lib/hamcrest-core-1.3.jar:./lib/junit-4.12.jar:./classes/test/UnionFindTests.class:./src classes/test.UnionFind_TestsRunner

clean:
	rm -rf classes/* build/*