Compte rendu Tp5
Modèles de classes et de fonctions :
Ensemble de presque nimporte quoi

DERORY Quentin
MAURANYAPIN Jean-Baptiste

Les fichiers sources et headers sont à la racine du Tp.

Pour compiler,il faut lancer make all dans un terminal à la racine du répertoire.
Cela donnera l'executable pour le main.cpp nommé main et pour essai_ensemble.cc nommé essai.


Remarque:
Comme fonction exemple, nous avons pris une fonction affine.


Trace d'execution de essai:
true
true
false
e = {10;9;8;7;6;5;4;3;2;1}
f = {20;19;18;17;16;15;14;13;12;11;10;9;8;7;6;5}
g = {19;18;17;16;15;14}
 e U f = {11;12;13;14;15;16;17;18;19;20;1;2;3;4;5;6;7;8;9;10}
 e inter f = {10;9;8;7;6;5}
 e - f = {1;2;3;4}
 e inter g = {}

 e diffSym f = {20;19;18;17;16;15;14;13;12;11;4;3;2;1}
 e diffSym g = {19;18;17;16;15;14;10;9;8;7;6;5;4;3;2;1}
 e - e = {}

 e - {40.0} = {1;2;3;4;5;6;7;8;9;10}
 e U {40} U {50} = {50;10;9;8;7;6;5;4;3;2;1;40}

 e = {10;9;8;7;6;5;4;3;2;1}
 f = {20;19;18;17;16;15;14;13;12;11;10;9;8;7;6;5}
 (e U f) - f {4;3;2;1}
 (e U f) - f == e ?   false
 En effet, car e inter f = {10;9;8;7;6;5}

 e == e U {} ? true
 e - {5} < e ? true

 a = {true}
 b = {false}
 a + b = {false;true}
 a + b - {true} = {false}


Trace d'execution de main:
{7;6;5}
7
6
5
Affichage du résultat
26
23
20
