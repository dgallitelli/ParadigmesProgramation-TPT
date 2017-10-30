# INF224 Paradigmes de Programmation - TELECOM ParisTech A.Y. 2017/18

This document has been used to reply to previous years exams for the INF224 course.

#### Donner et definir les 4 grands paradigmes en programmation.

Les 4 grands paradigmes en programmation sont:

- la programmation **imperative** (C, Ada, Pascal, Fortran)
- la programmation **à objets et à acteurs** (C++, Java, SmallTalk)
- la programmation **fonctionnelle** (Lisp)
- la programmation **en logique** (Prolog)

La *programmation imperative* es la programmation basée sur les structures des controle **while** et *if-then**, et sur les instructions d'affectation.

La *programmation à objets* est la programmation basée sur des structures des données particuliers appellées **classes**, où il y a des fonctions pour gerer les données appellées **methodes**.

La *programmation fonctionnelle* est la programmation pour la quelle les programmes sont une **liste de transformation numerique**, où les fonctions ont un argument et un resultat. Ce concept libere le programmeur de la gestion de la memoire.

Avec la *programmation logiciel* on programme des relations entre de données representées par des **atomes**, symbols et nombres, et des **termes fonctionels**. On permet aussi d'utiliser une catégorie restreinte de formule logiques pour programmer, c'est-à-dire le *clause d'Horn*.

#### Citer le théorème de Boehm et Jacopini. A quoi a-t-il servi?

Le théorème de Boehm et Jacopini enonce: tous les programmes contenant des structures de saut conditionnelle peuvent etre réécrit avec des structures de controle **while** et **if-then**. Il  a servi comme base pour la programmation moderne structuré: permit aux programmeurs de raisonner uniquement sur le programme, et c'est le compilateur qui s'occupe de traduire les structures de controle.

#### Comme est structuré le programme en Lisp?

En Lisp le programme est codé comme des données: les programmes sont des listes gerées dynamiquement et récupérées automatiquement par un remasse miettes (*garbage collector*). La structure de liste est une structure de listes chainées qui sont construites à l'aide de doublets de listes appelées *cons*:
- *nil* ou *()* est la liste vide
- *(cons x y)* est le doublet dont le premier element est *x* et le deuxième est *y*
- *(car d)* permet d'extraire la première composante d'un doublet
- *(cdr d)* permet d'extraire la deuxième composante d'un doublet
- *(null x)* permet de distinguer un doublet de la liste vide

#### Qu'est-ce que la reflexivité? Pourquoi Lisp est un language reflexif?

La reflexivité en Lisp est la proprieté pour la quelle tous les fonctions de Lisp sont ecrit en Lisp, donc redefinir sus fonctions base permet de changer la syntaxe et la semantique du language. Un example sont les fonctions *read*, *print* et *eval*. Les applications de Lisp sont: *emacs*, *SmallTalk*, l'*I.A.* .

#### Qu'est-ce que l'encapsulation en programmation objet? Quels sont les buts recherchés? Concrètement, comment est-ce implémenté en C++ et y a t'il des différences avec Java?

L'*encapsulation* est un concept fondamental de la programmation orientée à objet: c'est le principe de definir dans chaque classe des **méthodes** pour interagir avec les données, ou **variables d'instance**. Un objet est le seul qui peur accéder à ses variables, avec sus méthodes. L'encapsulation comprends deux etages:

- *specifier* une interface avec l'exterieur (API), avec la quelle interagir avec les données;
- *implementer* les methodes d'accès, qui protegent l'integrité du objet et la validité des données

L'encapsulation permit aussi beaucoup de modularisation, c'est-à-dire la possibilité de changer l'implementation d'un objet sans modifier les autres.

L'encapsulation en C++ est implementée avec les mots-clés **private** (default, accès uniquement pour la classe), **protected** (accès pour les sous-classes), et **public** (accès pour tout le monde). En plus, en C++ il est possible specifier les droits d'accès pour certaines classes ou fonctions avec le mot clé **friend**: la classe ou les methodes qui ont avant le mot clè *friend* peuvent acceder a les variables et les methodes d'instance de la classe ou le *friend* a été specifié.

En **Java** l'encapsulation est implementée de maniere tres similaire. Il n'y a pas le mot clé *friend*, mais il y a les **package**: tous les classes dans le meme package sont *friend*.

#### Qu'est-ce que la programmation générique et quels sont ses avantages? Y a-t'il	des	différences entre C++ et Java? Citez des exemples typiques de cas où c'est utile.

La *programmation générique* est une programmation basée sur l'utilise de structures permitant de parametriser les types. On parle de **template**: la meme fonction peut etre instancièe à la complation de faison differente en fonction du type utilisé comme parametre. La programmation générique est utile avec des algorithmes avec le meme definition pour types differentes: pour example, la fonction **max** o **min**, qui marche a meme maniere independamment du type.

En **Java**, c'est sufficient importer le package **generics**, et definir la classe générique avec le type parametrisé. Toutefois, c'est pas possible utiliser les types de base, ou faire traitements sur les types (*dynamic_cast* de C++).

#### On souhaite écrire une fonction swap()	qui	échange	la valeur de deux entiers qui lui sont passés en argument. Ecrire cette	fonction en	C++	et en Java. Quelles	sont les différences? Pourquoi?

```cpp
void swap(int &a, int &b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}

// à l'appel:
swap(x,y);
```

```Java
int swap(int a, int b){
	return a;
}
// à l'appel
y = swap(x, x=y)
```

#### Quelles sont les techniques de programmation typiquement utilisées pour ajouter des listeners aux composants graphiques Java Swing? Expliquez en vous aidant événtuellement de schémas.

1. Classe avec implements Listener associé a une classe extends JFrame , le listener doit avoir une reference vers la partie graphique - solution flexible mais lourde
<insert here pic of version1>
2. Objets hybrides: classe extends JFrame & implements Listener - solution plus simple mais limité, une seule methode actionPerformed() doit specifier beaucoup de butons
<insert here pic of version2>
3. Classes imbriquées - combine les avantages des 2 solutions precedentes
<insert here pic of version3>

#### Quels sont les cas d'utilisation du mot-clé *const* en C++? En prenant un exemple, (par exemple le TP) expliquez pourquoi il est important de préciser ce qui est constant. Quelles sont les alternatives, par exemple en Java?

Le mot-clé *const* est utilisé pour returner des valeurs qui ne doivent pas etre modifiés - sont ideal pour le **passage par valeur** (copie). Il specifie ce que la fonction a le droit de faire, pour eviter les erreurs. Dans le TP, on a utilisé le mot-clé *const* avec le getteurs, parce que les valeurs returnés ne doivent pas etre modifiés (pour respecter l'encapsulation). Les objet *const* permit de partager sans risque les données, sans les dupliquer.

En **Java**, il n'y a pas *const*:
- il y a *final*, equivalent de *const*
- on utilise les **types immuables** (String pour example) majoritairement, mais on peut utiliser des types muables (StringBuffer) selon besoins.

#### Qu'est-ce qui caractérise les fonctions lambda? Pourquoi permettent elles de simplifier le code?

Sont des fonctions anonymes qui capturent les variables specifiées, et peuvent etre definits comme arguments des autres fonctions, donc elles permettent de simplifier beaucoup le code. On peut specifier:
- [] - capture rien
- [=] - capture tous les variables par copie
- [&] - capture tous les variables par reference
- [var] - capture la variable var par copie
- [&var] - capture la variable var par reference
- [this] - si la lambda est dans un method, capture l'instance du objet appellant

#### Q10 from Exam Nov17

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
