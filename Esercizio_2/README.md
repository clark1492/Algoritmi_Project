***COMPILAZIONE***

1) posizionarsi in .../Esercizio_2
2) make all (nella directory corrente ci deve essere il Makefile opportuno)

***CANCELLAZIONE *.o e *.exe***
1) posizionarsi in .../Esercizio_2
2) make clean (nella directory corrente ci deve essere il Makefile opportuno)


***ESECUZIONE***

--PER ESEGUIRE edit_distance---
1) Compilare
2) posizionarsi in .../Esercizio_2
3) make run_app (nella directory corrente ci deve essere il Makefile opportuno)
4) Fornire nella cartella Data un file *.txt da correggere come primo parametro e come secondo un file *.txt usato come dizionario per le relativecorrezioni. Scrivere i due path nel Makefile dopo la voce run_app.

---PER ESEGUIRE edit_distance_tests---
1) Compilare
2) posizionarsi in .../Esercizio_2
3) make run_test (nella directory corrente ci deve essere il Makefile opportuno)

***RELAZIONE***

L'applicazione è volta a provare l'efficacia dell'algoritmo edit_distance con programmazione dinamica che limita le chiamate ricorsive.
Nell'implementare l'algoritmo si è pensato nello specifico nel non differenziare due caratteri con case differente (not case_sensitive) e ignorare la punteggiatura del testo, in modo da ottenere una più accurata analisi delle stringhe e non incrementare la edit_distance di due stringhe uguali (minuscole e maiuscole a parte).
L'algoritmo si è dimostrato abbastanza efficace, malgrado tra le correzioni suggerite in tre parole del testo non sono presenti i termini giusti:
- <made>    ---> <made>   invece di madre
- <squola>  ---> <suola>  invece di scuola
- <selice>  ---> <selice> invece di felice
Questo perchè le correzioni trovate hanno un edit_distance minore del termine corretto.
- edit_distance(made,madre) = 1 > edit_distance(made,made) = 0
- edit_distance(squola,scuola) = 2 > edit_distance(squola,suola) = 1
- edit_distance(selice,felice) = 2 > edit_distance(selice,selice) = 0

Due miglioramenti da poter apportare all'applicazione sarebbero: 
- Aggiungere l'operazione di sostituzione di un carattere, in maniera tale che ciò comporterebbe una sola operazione al posto di due (una di cancellazione e una di inserimento).
- Comprendere tra i termini quelli con valore edit distance compreso in un determinato range, in modo da includere le correzioni appropriate.
Si è scelto di implementare una struttura dati TermList che memorizza la parola da correggere e le relative correzioni in un array di stringhe, con l'edit distance tra la stringa di riferimento e le sue correzioni.