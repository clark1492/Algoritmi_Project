all:
	javac -d ./classes -cp ".:./src:./lib/junit-4.12.jar:./lib/hamcrest-core-1.3.jar" src/unionfind/*.java

run:
	java -cp ".:./classes:./lib/junit-4.12.jar:./lib/hamcrest-core-1.3.jar" unionfind/UnionFindTests_Runner

clean:
	rm -rf ./classes/*

