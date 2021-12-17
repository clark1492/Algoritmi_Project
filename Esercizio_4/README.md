***COMPILAZIONE***

1) posizionarsi in .../Esercizio_4
2) make all (nella directory corrente ci deve essere il Makefile opportuno)

***CANCELLAZIONE***
1) posizionarsi in .../Esercizio_4
2) make clean (nella directory corrente ci deve essere il Makefile opportuno)


***ESECUZIONE***

--PER ESEGUIRE graphusagejava/KruskalAlgorithmUsage---
1) Posizionarsi in .../Esercizio_4
2) Digitare nel terminale make run_app 
3) Nel Makefile specificare parametro nel campo run_app dopo graphusagejava/KruskalAlgorithmUsage: il parametro deve essere un file .csv con il formato <string>,<string>,<float> con record separati dal carattere di fine riga.

graphusagejava/KruskalAlgorithmUsage <path_file> 

---PER ESEGUIRE graph/Graph_TestsRunner---
1) Posizionarsi in .../Esercizio_4
2) Digitare nel terminale make run_test 

***COMMENTO***

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
    * Complessità:O(1)
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
    * Complessità : O(1)
 * **getEdgeSize** - Restituisce il numero degli archi presenti nel grafo
    * Complessità:O(n)
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

* **MakeSet** - crea un albero con l'elemento passato come parametro come unico nodo. Imposta il rango a 0, e come nodo radice se stesso.
* **FindSet** - Restituisce il nodo padre (o rappresentante) del nodo passato come parametro. Applica l'euristica della compressione del cammino, per fare in modo che ciascun nodo nel cammino di ricerca punti direttamente al nodo radice.
* **Union**  - Unisce i due alberi passati a parametro. Si applica l'unione pe rango che collega l'albero con rango minimo alla radice dell'albero con rango massimo.