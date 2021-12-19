***COMPILAZIONE***

1) Posizionarsi in .../Esercizio_1
2) make all (nella directory corrente ci deve essere il Makefile opportuno)

***CANCELLAZIONE *.o e *.exe***
1) Posizionarsi in .../Esercizio_1
2) make clean (nella directory corrente ci deve essere il Makefile opportuno)

***ESECUZIONE***

--PER ESEGUIRE merge_binary_insertion_sort---
1) Compilare
2) Posizionarsi in .../Esercizio_1
3) make run_app (nella directory corrente ci deve essere il Makefile opportuno)
4) Per impostare i parametri dell'applicazione, recarsi nel Makefile e alla voce run_app fornire un file *.csv (ogni riga con struttura "_id: < int >, field1: < char * >, field2: < int >, field3: < float >\n_"), scrivere il path del file come primo argomento, seguito da un intero corrispondente il campo da ordinare, e un altro intero compreso da 0 e il numero dei record del file( il numero della lunghezza della sottolista minima da cui l'algoritmo comincerà ad usare il BinaryInsertion Sort).

---PER ESEGUIRE merge_binary_insertion_sort_tests---
1) Compilare
2) Posizionarsi in .../Esercizio_1
3) make run_test (nella directory corrente ci deve essere il Makefile opportuno)

***RELAZIONE***

L'applicazione ha lo scopo di implementare l'algoritmo di ordinamento Merge BinaryInsertion Sort, ibrido che combina Merge Sort e BinaryInsertion Sort. Nello specifico utilizzerà il BinaryInsertion Sort per ordinare sottoliste di lunghezza k o inferiore, essendo questo più veloce con liste corte rispetto al Merge Sort. In seguito le sottoliste ordinate vengono combinate tramite Merge Sort.
Il Merge Sort ha complessità Θ(n*log(n)), mentre il BinaryInsertion Sort O(n^2).
Testando l'applicazione con diversi valori per il parametro k, si evince che più k è uguale a valori 
vicini lo zero, più i tempi di ordinamento sono ottimali.
Alcuni risultati di ordinamento non decrescente del campo double dei records caricati:

- k = 0         Sorting time: 23.299931
- k = 2         Sorting time: 22.788744
- k = 5         Sorting time: 22.944937
- k = 30        Sorting time: 24.207675
- k = 50        Sorting time: 24.530646
- k = 100       Sorting time: 26.077782
- k = 300       Sorting time: 31.260232
- k = 1000      Sorting time: 54.105893
- k = 10000     Sorting time: 531.985899

Per valori superiore non è stato possibile misurare i tempi di ordinamento, che si sono protratti per più di dieci minuti, facendo lanciare il segnale di alarm dell'applicazione.