***COMPILAZIONE***

1) Posizionarsi in .../Esercizio_1
2) make all (nella directory corrente ci deve essere il Makefile opportuno)

***CANCELLAZIONE *.o e *.exe***
1) Posizionarsi in .../Esercizio_1
2) make clean (nella directory corrente ci deve essere il Makefile opportuno)


***ESECUZIONE***

--PER ESEGUIRE merge_binary_insertion_sort---
1) Posizionarsi in .../Esercizio_1
2) Digitare nel terminale make run_app
3) Nel Makefile specificare parametri nel campo run_app dopo ./bin/merge_binary_insertion_sort: come primo parametro un file csv (con struttura: "_id: < int >, field1: <char *> field2: < int > field3: <float>\n_"), seguito da un intero compreso tra 1 e 3 (il campo da ordinare) e uno compreso fra 0 e il numero totale dei record presenti nel file csv.

./bin/merge_binary_insertion_sort <path_file_record> < 1 | 2 | 3 > < k >, dove k è un intero compreso tra 0 e il numero totale dei record del file.

---PER ESEGUIRE merge_binary_insertion_sort_tests---
1) Posizionarsi in .../Esercizio_1
2) Digitare nel terminale make run_test

***RELAZIONE***

L'applicazione ha lo scopo di implementare l'algoritmo di ordinamento Merge BinaryInsertion Sort, ibrido che combina Merge Sort e BinaryInsertion Sort. Nello specifico utilizzerà il BinaryInsertion Sort per ordinare sottoliste di lunghezza k o inferiore, essendo questo più veloce con liste corte rispetto al Merge Sort. In seguito le sottoliste ordinate vengono combinate tramite Merge Sort.
La complessità del Merge Sort è di O(n*log(n)) mentre quella del BinaryInsertion Sort è di O(n^2).
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