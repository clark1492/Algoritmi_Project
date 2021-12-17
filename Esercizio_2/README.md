***COMPILAZIONE***

1) posizionarsi in .../Esercizio_2
2) make all (nella directory corrente ci deve essere il Makefile opportuno)

***CANCELLAZIONE *.o e *.exe***
1) posizionarsi in .../Esercizio_2
2) make clean (nella directory corrente ci deve essere il Makefile opportuno)


***ESECUZIONE***

--PER ESEGUIRE edit_distance---
1) Posizionarsi in .../Esercizio_2
2) Digitare nel terminale make run_app 
3) Nel Makefile specificare parametri nel campo run_app dopo ./bin/edit_distance: come primo parametro un file .txt da correggere e come secondo un file .txt utilizzato come dizionario per trovare l'edit distance minore per i termini da correggere.

./bin/edit_distance <path_file_da_correggere> <path_dizionario>

---PER ESEGUIRE edit_distance_tests---
1) Posizionarsi in .../Esercizio_2
2) Digitare nel terminale make run_test 

***RELAZIONE***

L'applicazione è volta a provare l'efficacia dell'algoritmo edit_distance con programmazione dinamica che limita le chiamate ricorsive.
Nell'implementare l'algoritmo si è pensato nello specifico nel non differenziare due caratteri con case differente (not case_sensitive), in modo da ottenere una più accurata analisi delle stringhe e non incrementare la edit_distance di due stringhe uguali (minuscole e maiuscole a parte), inoltre ignora la punteggiatura.
L'algoritmo si è dimostrato abbastanza efficace, malgrado tra le correzioni suggerite in tre parole del testo non sono presenti i termini giusti:
- <made>    ---> <made>   invece di madre
- <squola>  ---> <suola>  invece di scuola
- <selice>  ---> <selice> invece di felice
Questo perchè le correzioni trovate hanno un edit_distance minore del termine corretto.
- edit_distance(made,madre) = 1 > edit_distance(made,made) = 0
- edit_distance(squola,scuola) = 2 > edit_distance(squola,suola) = 1
- edit_distance(selice,felice) = 2 > edit_distance(selice,selice) = 0
Un miglioramento dell'applicazione potrebbe essere quello di comprendere termini con edit_distance compreso tra un determinato range di valori.
Un altro miglioramento sostanziale potrebbe essere aggiungere alle operazioni di cancellazione e inserimento dell'algoritmo quella di sostituzione di un carattere.
In questo modo al posto di un'operazione di cancellazione seguita da una di inserimento, si potrebbe effettuare solo un'operazione di sostituzione con un relativo decremento dell'edit_distance.
La complessità dell'algoritmo è di Θ(m*n) dove m è la lunghezza della prima stringa e n della seconda.
