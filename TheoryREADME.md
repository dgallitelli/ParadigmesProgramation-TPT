# INF224 Paradigmes de Programmation - TELECOM ParisTech A.Y. 2017/18

This document has been used to reply to previous years exams for the INF224 course.

## Donner et definir les 4 grands paradigmes en programmation.

Les 4 grands paradigmes en programmation sont:

- la programmation **imperative** (C, Ada, Pascal, Fortran)
- la programmation **à objets et à acteurs** (C++, Java, SmallTalk)
- la programmation **fonctionnelle** (Lisp)
- la programmation **en logique** (Prolog)

La _programmation imperative_ es la programmation basée sur les structures des controle **while** et _if-then*_, et sur les instructions d'affectation.

La _programmation à objets_ est la programmation basée sur des structures des données particuliers appellées **classes**, où il y a des fonctions pour gerer les données appellées **methodes**.

La _programmation fonctionnelle_ est la programmation pour la quelle les programmes sont une **liste de transformation numerique**, où les fonctions ont un argument et un resultat. Ce concept libere le programmeur de la gestion de la memoire.

Avec la _programmation logiciel_ on programme des relations entre de données representées par des **atomes**, symbols et nombres, et des **termes fonctionels**. On permet aussi d'utiliser une catégorie restreinte de formule logiques pour programmer, c'est-à-dire le _clause d'Horn_.

## Citer le théorème de Boehm et Jacopini. A quoi a-t-il servi?

Le théorème de Boehm et Jacopini enonce: tous les programmes contenant des structures de saut conditionnelle peuvent etre réécrit avec des structures de controle **while** et **if-then**. Il a servi comme base pour la programmation moderne structuré: permit aux programmeurs de raisonner uniquement sur le programme, et c'est le compilateur qui s'occupe de traduire les structures de controle.

## Comme est structuré le programme en Lisp?

En Lisp le programme est codé comme des données: les programmes sont des listes gerées dynamiquement et récupérées automatiquement par un remasse miettes (_garbage collector_). La structure de liste est une structure de listes chainées qui sont construites à l'aide de doublets de listes appelées _cons_:

- _nil_ ou _()_ est la liste vide
- _(cons x y)_ est le doublet dont le premier element est _x_ et le deuxième est _y_
- _(car d)_ permet d'extraire la première composante d'un doublet
- _(cdr d)_ permet d'extraire la deuxième composante d'un doublet
- _(null x)_ permet de distinguer un doublet de la liste vide

## Qu'est-ce que la reflexivité? Pourquoi Lisp est un language reflexif?

La reflexivité en Lisp est la proprieté pour la quelle tous les fonctions de Lisp sont ecrit en Lisp, donc redefinir sus fonctions base permet de changer la syntaxe et la semantique du language. Un example sont les fonctions _read_, _print_ et _eval_. Les applications de Lisp sont: _emacs_, _SmallTalk_, l'_I.A._ .

## Definir le probleme de coloriage de carte et sus phases de resolution

Le probleme de coloriage de carte consiste en colorier une carte avec des couleurs de telle manière que due zones contigues aient des couleurs differentes. Il y a deux phases de resolution:

- **Phase Generate** : le programme génère toutes les solutions envisageables, c'est-à-dire tous les coloriages possibles pour le prédicat _color(X)_ qui génère N branches de demonstration pour chacune des valeurs possibles de X (zone de la carte).
- **Phase Test** : le programme controle si la solution generée est conforme. Pour cela, il suffit de tester si les couleurs de duex zones contigues sont differentes. Le programme peut etre amélioré en mélangeant les deux phases pour couper les branches de la démonstration, mais la programmation devient moins logique. Ce probleme peut etre résolu en definissant des contraintes dans la phase Generate.

## Qu'est-ce qu'une variable d'instance, une variable de classe, une méthode d'instance, une méthode de classe ? Y a-t'il des différences entre Java et C++ ?

- **Variable d'instance**: chaque objet de la classe possede sa propre copie de cette type de variable, et elle doit etre _private_ ou _protected_. Les variables d'instance doivent etre initalisées si sont des types de base ou des pointers, sinon ont valeur aleatoire.
- **Variable de classe**: sont des variables partagées entre les instances de la meme classe. Doivent etre initialisées. Il faut specifier le mot-clé _static_ avant le type de variable.
- **Methode d'instance**: methode qui permet l'access aux variables d'instance, c'est-à-dire les données de l'instance particulier d'une classe. Si la methode ne modifie pas les variables d'instance, il faut mettre le mot-clé _const_.
- **Methode de classe**: methode qui permet l'access aux variables de classe. Il faut specifier le mot-clé _static_ avant le type de retour.

En Java la sémantique est la meme, mais il n'y a pas _const_.

## A quoi servent les destructeurs en C++ et dans quels cas sont-ils nécessaires ? Y a t'il des destructeurs en Java ?

Le **destructeur** est la methode appelée avant la destruction de l'objet, c'est-à-dire avant de libèrer la memoire (pour le _delete_). Il sert a "faire le ménage", par exemple afin de fermer un fichier ou un socket, ou pour detruire d'autres objets auxiliaire créé dans le constructeur.

En Java, il n'y a pas des destructeurs parce que la liberation de memoire est gerée automatiquement pour le remasse miettes (_garbage collector_). Il y a aussi une methode _finalize()_, qui a plus ou moins la meme fonction de les destructeurs, mais ne sont pas chainés et sont rarement utilisés.

## Qu'est-ce que l'encapsulation en programmation objet? Quels sont les buts recherchés? Concrètement, comment est-ce implémenté en C++ et y a t'il des différences avec Java?

L'_encapsulation_ est un concept fondamental de la programmation orientée à objet: c'est le principe de definir dans chaque classe des **méthodes** pour interagir avec les données, ou **variables d'instance**. Un objet est le seul qui peur accéder à ses variables, avec sus méthodes. L'encapsulation comprends deux etages:

- _specifier_ une interface avec l'exterieur (API), avec la quelle interagir avec les données;
- _implementer_ les methodes d'accès, qui protegent l'integrité du objet et la validité des données

L'encapsulation permit aussi beaucoup de modularisation, c'est-à-dire la possibilité de changer l'implementation d'un objet sans modifier les autres.

L'encapsulation en C++ est implementée avec les mots-clés **private** (default, accès uniquement pour la classe), **protected** (accès pour les sous-classes), et **public** (accès pour tout le monde). En plus, en C++ il est possible specifier les droits d'accès pour certaines classes ou fonctions avec le mot clé **friend**: la classe ou les methodes qui ont avant le mot clè _friend_ peuvent acceder a les variables et les methodes d'instance de la classe ou le _friend_ a été specifié.

En **Java** l'encapsulation est implementée de maniere tres similaire. Il n'y a pas le mot clé _friend_, mais il y a les **package**: tous les classes dans le meme package sont _friend_.

## Qu'est-ce que la programmation générique et quels sont ses avantages? Y a-t'il des différences entre C++ et Java? Citez des exemples typiques de cas où c'est utile.

La _programmation générique_ est une programmation basée sur l'utilise de structures permitant de parametriser les types. On parle de **template**: la meme fonction peut etre instancièe à la complation de faison differente en fonction du type utilisé comme parametre. La programmation générique est utile avec des algorithmes avec le meme definition pour types differentes: pour example, la fonction **max** o **min**, qui marche a meme maniere independamment du type.

En **Java**, c'est sufficient importer le package **generics**, et definir la classe générique avec le type parametrisé. Toutefois, c'est pas possible utiliser les types de base, ou faire traitements sur les types (_dynamic_cast_ de C++).

## On souhaite écrire une fonction swap() qui échange la valeur de deux entiers qui lui sont passés en argument. Ecrire cette fonction en C++ et en Java. Quelles sont les différences? Pourquoi?

```c++
void swap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

// à l'appel:
swap(x,y);
```

```java
int swap(int a, int b){
    return a;
}
// à l'appel
y = swap(x, x=y)
```

## Quelles sont les techniques de programmation typiquement utilisées pour ajouter des listeners aux composants graphiques Java Swing? Expliquez en vous aidant événtuellement de schémas.

1. Classe avec implements Listener associé a une classe extends JFrame , le listener doit avoir une reference vers la partie graphique - solution flexible mais lourde

  <insert here="" pic="" of="" version1="">
  </insert>

2. Objets hybrides: classe extends JFrame & implements Listener - solution plus simple mais limité, une seule methode actionPerformed() doit specifier beaucoup de butons

  <insert here="" pic="" of="" version2="">
  </insert>

3. Classes imbriquées - combine les avantages des 2 solutions precedentes

  <insert here="" pic="" of="" version3="">
  </insert>

## Quels sont les cas d'utilisation du mot-clé _const_ en C++? En prenant un exemple, (par exemple le TP) expliquez pourquoi il est important de préciser ce qui est constant. Quelles sont les alternatives, par exemple en Java?

Le mot-clé _const_ est utilisé pour returner des valeurs qui ne doivent pas etre modifiés - sont ideal pour le **passage par valeur** (copie). Il specifie ce que la fonction a le droit de faire, pour eviter les erreurs. Dans le TP, on a utilisé le mot-clé _const_ avec le getteurs, parce que les valeurs returnés ne doivent pas etre modifiés (pour respecter l'encapsulation). Les objet _const_ permit de partager sans risque les données, sans les dupliquer.

En **Java**, il n'y a pas _const_:

- il y a _final_, equivalent de _const_
- on utilise les **types immuables** (String pour example) majoritairement, mais on peut utiliser des types muables (StringBuffer) selon besoins.

## Qu'est-ce qui caractérise les fonctions lambda? Pourquoi permettent elles de simplifier le code?

Sont des fonctions anonymes qui capturent les variables specifiées, et peuvent etre definits comme arguments des autres fonctions, donc elles permettent de simplifier beaucoup le code. On peut specifier:

- [] - capture rien
- [=] - capture tous les variables par copie
- [&] - capture tous les variables par reference
- [var] - capture la variable var par copie
- [&var] - capture la variable var par reference
- [this] - si la lambda est dans un method, capture l'instance du objet appellant

## Q10 from Exam Nov17

```
class Adresse{
private:
    string nom;
    string prenom;
    string numero;
    string adresse;
public:
    Adresse();
    Adresse(string nom, string prenom, string numero, string addresse) :
            nom(nom), prenom(prenom), numero(numero), addresse(addresse) {}
    string getNom() const {return nom;}
    string getPrenom() const {return prenom;}
    string getNumero() const {return numero;}
    string getAdresse() const {return adresse;}
    void setNom(const string& _nom){nom=_nom;}
    void setNom(const string& _prenom){prenom=_prenom;}
    void setNom(const string& _numero){numero=_numero;}
    void setNom(const string& _addresse){addresse=_addresse;}
}
```

```
class Carnet{
private:
    list<Adresse> carnet;
public:
    Carnet(){}
    Carnet(list<Adresse> _carnet){
        if !_carnet.empty()
            for (auto it:_carnet)
                carnet.push_back(*it);
    }
    void ajoutAdresse(Adresse *newAddr){
        carnet.push_back(*newAddr);
    }
    Adresse rechAdresse(string nom){
        for (auto it:carnet){
            if (it->getNom()==nom)
                return it;
        }
        return nullptr;
    }
    void supAdresse(string nom){
        for (auto it:carnet){
            if (it->getNom()==nom)
                it->erase();
        }
    }
}
```
