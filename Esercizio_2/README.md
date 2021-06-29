***COMPILAZIONE***

1) posizionarsi in .../Esercizio_2
2) make all (nella directory corrente ci deve essere il Makefile opportuno)

***CANCELLAZIONE *.o e *.exe***
1) posizionarsi in .../Esercizio_2
2) make clean (nella directory corrente ci deve essere il Makefile opportuno)


***ESECUZIONE***

--PER ESEGUIRE edit_distance---
1) Compilare
2) posizionarsi in .../Esercizio_2/bin
3) ./edit_distance e come parametri i file correctme.txt e dictionary.txt

---PER ESEGUIRE edit_distance_tests---
1) Compilare
2) posizionarsi in .../Esercizio_2/bin
3) ./edit_distance_tests

***RELAZIONE***

L'applicazione è volta a provare l'efficacia dell'algoritmo edit_distance con programmazione dinamica che limita le chiamate ricorsive.
Nell'implementare l'algoritmo si è pensato nello specifico nel non differenziare due caratteri con case differente (not case_sensitive), in modo da ottenere una più accurata analisi delle stringhe e non incrementare la edit_distance di due stringhe uguali (minuscole e maiuscole a parte).
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
