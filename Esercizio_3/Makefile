JUNIT = lib/junit-4.12.jar
HAMCREST = lib/hamcrest-core-1.3.jar
CP = classes:$(JUNIT):$(HAMCREST)

all:
	mkdir -p classes
	javac -d classes src/unionfind/*.java
	javac -d classes -cp $(CP) src/test/*.java

run:
	java -cp $(CP) test.UnionFind_TestsRunner

clean:
	rm -rf classes