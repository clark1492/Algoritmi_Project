***COMPILAZIONE***

----PER COMPILARE LE CLASSI PER LA STRUTTURA DATI DirectedGraph NEL PACKAGE graph---
1) posizionarsi in .../Esercizio_4/src
2) javac -d ../classes graph/DirectedGraph.java

----PER COMPILARE LE CLASSI PER LA STRUTTURA DATI UnirectedGraph NEL PACKAGE graph---
1) posizionarsi in .../Esercizio_4/src
2) javac -d ../classes graph/UndirectedGraph.java

----PER COMPILARE LE CLASSI PER LA STRUTTURA DATI UnionFind NEL PACKAGE unionfind---
1) posizionarsi in .../Esercizio_4/src
2) javac -d ../classes graph/UnionFind.java

---PER COMPILARE IL PACKAGE graphusagejava---
1) posizionarsi in .../Esercizio_4/src
2) javac -d ../classes graphusagejava/KruskalAlgorithmUsage.java

---PER COMPILARE LE CLASSI PER GLI UNIT TEST NEL PACKAGE graph---
1) posizionarsi in .../Esercizio_4/src
2) javac -d ../classes -cp '.;../junit-4.12.jar;../hamcrest-core-1.3.jar' graph/*.java 

***ESECUZIONE***

---PER ESEGUIRE graphusagejava/KruskalAlgorithmUsage---
1) posizionarsi in .../Esercizio_4/classes
2) java graphusagejava/KruskalAlgorithmUsage e come parametro il file italian_dist_graph.csv

---PER ESEGUIRE graph/Graph_TestsRunner---
1) posizionarsi in .../Esercizio_4/classes
2) java -cp '.;../junit-4.12.jar;../hamcrest-core-1.3.jar' graph/Graph_TestsRunner

***RELAZIONE***

La classe DirectedGraph e UndirectedGraph rappresentano, in ordine, un grafo diretto e non diretto ottimizzato per dati sparsi. I grafi possono essere pesati o non, ed i loro archi sono etichettati. Per la loro rappresentazione si è scelto di adottare le liste di adiacenza, sfruttando l'implementazione di Maps. Si implementa anche l'algoritmo di Kruskal per calcolare l'albero di supporto minimo di un grafo non orientato e pesato.

 * **DirectedGraph/UndirectedGraph** - Creazione di un grafo vuoto, dotato di una variabile per la lista di adiacenze e una variabile booleana per tenere traccia se il grafo è pesato
    * Complessità: O(1)
 * **isWeighted** - Verifica se il grafo è pesato 
    * Complessità: O(1)
 * **setIsWeighted** - Setta la variabile isWeighted 
    * Complessità: O(1)
 * **isDirected** - Verifica se il grafo è diretto
    * Complessità: O(1)
 * **addNode** - Aggiunge un nodo al grafo nella lista di adiacenza
    * Complessità: O(1)
 * **addEdge** - Aggiunge un arco al grafo
    * Complessità: O(1)
 * **containsNode** - Verifica se il grafo contiene un dato nodo
    * Complessità: O(1)
 * **containsEdge** -Verifica se il grafo contiene un dato arco
    * Complessità: O(1)
 * **removeNode** - Elimina un nodo dal grafo
    * Complessità: O(n)
 * **removeEdge** - Elimina un arco dal grafo
    * Complessità: O(1)
 * **getNodeSize** - Restituisce il numero di nodi presenti nel grafo
    * Complessità: O(1)
 * **getEdgeSize** - Restituisce il numero degli archi presenti nel grafo
    * Complessità: O(n)
 * **getNodes** - Restituisce un ArrayList contenente tutti i nodi del grafo
    * Complessità: O(n)
 * **getEdges** - Restituisce un ArrayList contenente tutti gli archi del grafo
    * Complessità: O(n)
 * **getAdjacentNodes** - Restituisce un ArrayList contenente tutti i nodi adiacenti ad un dato nodo
    * Complessità: O(1)
 * **getLabel** - Restituisce l'etichetta di un arco
    * Complessità: O(1)
 * **getLabel** - Restituisce l'etichetta di un arco
    * Complessità: O(1)

La classe UnionFind crea foreste di insiemi disgiunti e ogni elemento punta soltanto a suo padre. Si è scelto di implementare la struttura dati attraverso Maps per memorizzare la relazione padre-figlio di ogni elemento e tenere traccia del rango degli stessi.
Le tre operazioni degli insiemi disgiunti:

* **MakeSet** - crea semplicemente un albero con un solo nodo, il cui puntatore al padre punta a se stesso.
* **FindSet** - segue i puntatori ai padri finchè non trova la radice dell'albero, sfrutta l'euristica della compressione del cammino per fare in modo che ciascun nodo nel cammino di ricerca punti direttamente alla radice. 
* **Union**   - cambia il puntatore alla radice di un albero, in modo che punti alla radice del secondo passato come argomento e sfrutta l'euristica dell'unione per rango, di modo che la radice dell'albero con meno nodi diventi la radice dell'albero che ne ha di più.

L'applicazione ha come scopo calcolare la foresta minima ricoprente di un grafo.
L'applicazione ottiene i risultati sperati, avendo come output una foresta minima ricoprente con 18.640 nodi, 18.637 archi e il peso di circa 89940 km, il tutto con tempo medio di esecuzione di 350 millisecondi.