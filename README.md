GALLITELLI Davide - INF224 A.Y. 2017/18

# INF224 TP 2017/18

Il faut utiliser dans chaque répertoire pour produire les exécutables:

```
make run
```

Pour le sous-répertoire *cpp*, le fichier principal est *server.cpp*, qui contient le *main* du serveur. Les objets définit dans le main sont:

- "test" pour le fichier "test.png"
- "video1" pour le fichier "video1.avi"
- "film1" pour le fichier "movie1.avi"
- "gdbName" pour le groupe de fichiers

Comme les fichiers utilisée pour les vidéos sont lourds, ils n'ont pas été inclus dans le répertoire.

Pour le sous-répertoire *swing*, le fichier principal est *ClientMain*, qui contient le *main* du client. Dans le client, c'est suffisant spécifier le nom du fichier comme a été specifiée dans le main.

Ci-après, on va trouver les réponses aux questions trouvé dans les différentes étapes du projet.

### ÉTAPE 4
#### Comme pour la fonction d'affichage, la fonction pour jouer l'objet ne modifie pas l'objet et elle doit être déclarée dans les classes Photo et Video et dans la classe de base afin de permettre un appel polymorphique sur la hiérarchie de classes. Cependant, contrairement à la fonction d'affichage, elle ne peut pas avoir d'implementation au niveau de la classe de base (car a priori chaque type d'objet nécessite un utilitaire différent pour être joué). Comment appelle-t'on ce type de méthode et comment faut-il les déclarer ?

Ce type de méthode s'appelle **méthode abstrait**, et il faut le déclarer avec le mot-clè *virtual*. Dans l'header de la classe *MultimediaObject*, on va avoir:

```
virtual void reproduce() const = 0;
```

#### Si vous avez fait correctement ce qui précède, il ne sera plus possible d'instancer des objets de la classe de base. Pourquoi ?

Parce que une classe avec des méthodes abstraits est un **classe abstrait**: il n'est pas possible d’instancier objets de ce classe, mais seulement des objets qui sont herités de la classe base.

### ÉTAPE 5
#### On veut maintenant pouvoir traiter génériquement une liste comprenant à la fois des photos et des vidéos. Pour ce faire créer dans main.cpp un tableau dont les éléments sont tantôt une photo tantôt une vidéo. Ecrire ensuite une boucle permettant d'afficher les attributs de tous les élements du tableau (ou de les "jouer"). Cette boucle n'a pas besoin de connaître le type des élements : elle doit pouvoir traiter de la même manière tous les objets dérivant de la classe de base. Quelle est la propriété caractéristique de l'orienté objet qui permet de faire cela ? Qu'est-il spécifiquement nécessaire de faire dans le cas du C++ ? Quel est le type des éléments du tableau : est-ce que ce tableau contient les objets ou des pointeurs vers ces objets ? Pourquoi ? Comparer à Java.

La propriété caractéristique de l'orienté à objet qui permet ce truc c'est le polymorphisme: le polymorphisme permet de choisir le plus de vue le plus approprié selon les besoins, c'est-à-dire qu'il permet de appeler le méthode pour chaque classe mais de le traiter de manière uniforme. Pour exploiter ce puissance de C++, il faut avoir dans la superclasse une *methode abstraite*, qui a été redéfinit dans tous les classes fils. En plus, il faut définir un tableau de double pointeurs a la superclasse, et appeler la méthode pour chaque élément du tableau. Le double pointeurs sont nécessaires parce que chaque élément doit pointer à une instance de une classe fil. Dans notre cas, nous avons:

```
MultimediaObject* moArray[] = {
	new PhotoObject("obj1", "path1", 0, 0),
	new PhotoObject("obj2", "path2", 0, 0),
	new VideoObject("video1", "pathV1", 10),
	new VideoObject("video2", "pathV2", 25)
};

for (int i = 0; i < valueNum; i++)
	moArray[i]->reproduce();
```

En Java, c'est pareil: de défault, Java implémente une liaison tardive, c'est-à-dire qui la méthode appellée c'est toujours la du *pointé*. Donc, l’implémentation de la solution serait très similaire a la de C++, avec un tableau de références aux objets de a superclasse qui appellent le méthode abstrait de la superclasse (définit en Java avec le mot-clé **abstract**).

### ÉTAPE 6
#### Que faut-il faire pour que l'objet Film ait plein contrôle sur ses données et que son tableau de durées des chapitres ne puisse pas être modifié (ou pire, détruit) à son insu ? (c'est l'objet qui doit pouvoir modifier ce qui lui appartient, pas les autres !)

Il faut faire une **copie profonde** de ses données quand on appelle le *constructeur* ou la méthode *set* sur le tableau de chapitres. De cette façon, l'objet *Film* aura sa copie des données, qui peut être modifie uniquement par lui.

#### Attention, le même problème se pose si un accesseur retourne directement ce tableau sans prendre les précautions nécessaires : la encore le contenu du tableau n'est pas récopié et l'appelant peut le modifier à sa guise. Quelle est la solution très simple que propose C/C++ pour éviter ce problème ?

Le même problème implique la même solution: on va retourner une copie du tableau, pour protéger les données de l'objet. Le méthode *get* retournera une copie profonde du tableau de chapitres, en acceptant comme argument un pointeur a une variable pour le numéro de chapitres.

### ÉTAPE 7
#### Contrairement à Java ou C#, C/C++ ne gère pas la mémoire dynamique automatiquement (\*) : comme il n'y a pas de ramasse miettes, tout ce qui a été créé avec *new* doit être détruit avec *delete* sinon on aura des fuites mémoires. Parmi les classes précédemment écrites quelles sont celles qu'il faut modifier afin qu'il n'y ait pas de fuite mémoire quand on détruit leurs instances ?

Seulement dans la classe *Film* il faut modifier le destructeur pour éviter les fuites mémoires. Les autres classes n'ont pas des variables avec mémoire dynamique, donc on modifiera rien.

#### De même, la copie d'objets peut poser problème dans certains cas. Pourquoi et que faudrait-il faire ?

Si l'objet contient des pointeurs ou, en général, variables avec mémoire dynamique, il faudrait redefinir le constructeur pour copie afin de implementer la **copie profonde** de ces variables.

### ÉTAPE 8
#### Le groupe ne doit pas détruire les objets quand il est détruit car un objet peut appartenir à plusieurs groupes (on verra ce point à la question suivante). On rappelle aussi que la liste d'objets doit en fait être une liste de pointeurs d'objets. Pourquoi ? Comparer à Java.

Utiliser une liste de pointeurs permet de détruire les variables qui pointe à une objet, mais pas l'objet lui-même.

En Java, il n'y a pas problème de destructeur grâce a le *garbage collector*: on peut faire pointer sur rien l'objet du groupe (on le met a *null*), et donc les pointeurs sont invalides mais les objets sont sauvegardés.

### ÉTAPE 10
#### Les méthodes précédentes permettent d'assurer la cohérence de la base de données car quand on crée un objet on l'ajoute à la table adéquate. Par contre, ce ne sera pas le cas si on crée un objet directement avec new (il n'appartiendra à aucune table). Comment peut-on l'interdire, afin que seule la classe servant à manipuler les objets puisse en créer de nouveaux?

Pour interdire ce possibilité, il faut rendre **private** le constructeur de les objets *Photo*, *Video*, *Film* et *Group*, et rendre **friend** de ces classes la classe de la base de données. Dans cette maniere, on peut créer un nouveau objet seulement via les méthodes de la base de données.

### ÉTAPE 11
#### Votre méthode *processRequest()* devra pouvoir accéder aux données de la classe créée à la question précédente. Sachant que cette méthode peut appartenir à n'importe quelle classe, quelle est la solution la plus simple ?

La solution la plus simple est de avoir une référence dans la classe *MyBase* a la base de données pour permettre de le envoyer et renvoyer les informations nécessaires. Le constructeur de *MyBase* initialise ce référence avec le constructeur pour copie de l'objet de la base de données.
