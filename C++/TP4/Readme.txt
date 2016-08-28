Compte rendu Tp4
Héritage & planche à clous

DERORY Quentin
MAURANYAPIN Jean-Baptiste

Les fichiers sources sont à la racine du Tp.
Les fichiers objets sont dans le répertoire bin.
Les fichiers headers sont dans le répertoire include.

Pour compiler,il faut lancer make all dans un terminal à la racine du répertoire.


Remarque:
Si jamais le compteur 0 n'a pas rencontré de palet, la simulation affichera uniquement la valeur des différents compteurs(le nombre de fois qu'il a rencontré un palet).

Trace d'execution de Valgrind:

==9360== Memcheck, a memory error detector
==9360== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==9360== Using Valgrind-3.10.0.SVN and LibVEX; rerun with -h for copyright info
==9360== Command: ./main
==9360== 
1, 3, 3, 1, 8, 
==9360== 
==9360== HEAP SUMMARY:
==9360==     in use at exit: 72 bytes in 4 blocks
==9360==   total heap usage: 17 allocs, 13 frees, 520 bytes allocated
==9360== 
==9360== LEAK SUMMARY:
==9360==    definitely lost: 24 bytes in 1 blocks
==9360==    indirectly lost: 48 bytes in 3 blocks
==9360==      possibly lost: 0 bytes in 0 blocks
==9360==    still reachable: 0 bytes in 0 blocks
==9360==         suppressed: 0 bytes in 0 blocks
==9360== Rerun with --leak-check=full to see details of leaked memory
==9360== 
==9360== For counts of detected and suppressed errors, rerun with: -v
==9360== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

Trace d'execution:
1, 3, 3, 1, 8, 



A améliorer:
La destruction n'est pas entièrement bien géré d'après valgrind.
Une solution serait de désallouer le tableau de clous que j'instancie dans le constructeur de la planche mais je n'ai pas trouvé de moyen de le faire.

Question :
La relation père fils ainsi établie définit lors de la désallocation une recherche en profondeur.
