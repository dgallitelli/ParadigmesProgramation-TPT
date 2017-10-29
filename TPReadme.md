GALLITELLI Davide - INF224 A.Y. 2017/18

### ETAPE 4
#### Comme pour la fonction d'affichage, la fonction pour jouer l'objet ne modifie pas l'objet et elle doit être déclarée dans les classes Photo et Video et dans la classe de base afin de permettre un appel polymorphique sur la hiérarchie de classes. Cependant, contrairement à la fonction d'affichage, elle ne peut pas avoir d'implementation au niveau de la classe de base (car a priori chaque type d'objet nécessite un utilitaire différent pour être joué). Comment appelle-t'on ce type de méthode et comment faut-il les déclarer ?

Ce type de methode s'appelle **methode abstrait**, et il faut le declaraire avec le mot-clè *virtual*. Dans l'header de la classe *MultimediaObject*, on va avoir:

```
virtual void reproduce() const = 0;
```

#### Si vous avez fait correctement ce qui précède, il ne sera plus possible d'instancer des objets de la classe de base. Pourquoi ?

Parce que une classe avec des methodes abstraits est un **classe abstrait**: il n'est pas possible d'instancer objets de ce classe, mais seulement des objets qui sont herités de la classe base.

### ETAPE 5
#### On veut maintenant pouvoir traiter génériquement une liste comprenant à la fois des photos et des vidéos. Pour ce faire créer dans main.cpp un tableau dont les éléments sont tantôt une photo tantôt une vidéo. Ecrire ensuite une boucle permettant d'afficher les attributs de tous les élements du tableau (ou de les "jouer"). Cette boucle n'a pas besoin de connaître le type des élements : elle doit pouvoir traiter de la même manière tous les objets dérivant de la classe de base. Quelle est la propriété caractéristique de l'orienté objet qui permet de faire cela ? Qu'est-il spécifiquement nécessaire de faire dans le cas du C++ ? Quel est le type des éléments du tableau : est-ce que ce tableau contient les objets ou des pointeurs vers ces objets ? Pourquoi ? Comparer à Java.

La propriété caractéristique de l'orienté à objet qui permet ce truc c'est le polymorphisme: le polymorphisme permet de choisir le plus de vue le plus approprié selon les besoins, c'est-à-dire qu'il permet de appeler le methode pour chaque classe mais de le traiter de manière uniforme. Pour exploiter ce puissance de C++, il faut avoir dans la superclasse une *methode abstraite*, qui a été redefinit dans tous les classes fils. En plus, il faut definir un tableau de double pointeurs a la superclasse, et appeler la methode pour chaque element du tableau. Le double pointeurs sont necessaires parce que chaque element doit pointer à une instance de une classe fil. Dans notre cas, nous avons:

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

En Java, c'est pareil: de défault, Java implemente une liaison tardive, c'est-à-dire qui la methode appellée c'est toujours la du *pointé*. Donc, l'implementation de la solution serait tres similaire a la de C++, avec un tableau de références aux objets de a superclasse qui appellent le methode abstrait de la superclasse (definit en Java avec le mot-clé **abstract**).

### ETAPE 6
#### Que faut-il faire pour que l'objet Film ait plein contrôle sur ses données et que son tableau de durées des chapitres ne puisse pas être modifié (ou pire, détruit) à son insu ? (c'est l'objet qui doit pouvoir modifier ce qui lui appartient, pas les autres !)

Il faut faire une **copie profonde** de ses données quand on appelle le *constructeur* ou la methode *set* sur le tableau de chapitres. De cette façon, l'objet *Film* aura sa copie des données, qui peut etre modifie uniquement par lui.

#### Attention, le même problème se pose si un accesseur retourne directement ce tableau sans prendre les précautions nécessaires : la encore le contenu du tableau n'est pas récopié et l'appelant peut le modifier à sa guise. Quelle est la solution très simple que propose C/C++ pour éviter ce problème ?



### ETAPE 7
#### Contrairement à Java ou C#, C/C++ ne gère pas la mémoire dynamique automatiquement (\*) : comme il n'y a pas de ramasse miettes, tout ce qui a été créé avec new doit être détruit avec delete sinon on aura des fuites mémoires. Parmi les classes précédemment écrites quelles sont celles qu'il faut modifier afin qu'il n'y ait pas de fuite mémoire quand on détruit leurs instances ?



#### De même, la copie d'objets peut poser problème dans certains cas. Pourquoi et que faudrait-il faire ?



### ETAPE 8
#### Le groupe ne doit pas détruire les objets quand il est détruit car un objet peut appartenir à plusieurs groupes (on verra ce point à la question suivante). On rappelle aussi que la liste d'objets doit en fait être une liste de pointeurs d'objets. Pourquoi ? Comparer à Java.



### ETAPE 10
#### Les méthodes précédentes permettent d'assurer la cohérence de la base de données car quand on crée un objet on l'ajoute à la table adéquate. Par contre, ce ne sera pas le cas si on crée un objet directement avec new (il n'appartiendra à aucune table). Comment peut-on l'interdire, afin que seule la classe servant à manipuler les objets puisse en créer de nouveaux?
