# Maze Runner - Génération et Résolution

Ce projet implémente un **générateur et un solveur de labyrinthe** en C++. Le labyrinthe est généré de manière aléatoire et peut être résolu en utilisant **l'algorithme A\***. Ce projet est avant tout un exercice personnel, sans objectif spécifique, visant à renforcer mes compétences en C++, en algorithmie et en gestion des structures de données.

## Fonctionnalités

1. **Génération aléatoire de labyrinthes**  
   - Création d'un labyrinthe de dimensions spécifiées.  
   - Suppression aléatoire des murs pour créer un chemin viable.  
   - Utilisation d'une approche récursive pour la génération.

2. **Résolution du labyrinthe**  
   - Utilisation de **l'algorithme A\*** pour trouver le chemin optimal.  
   - Prise en compte des obstacles et des impasses.  
   - Affichage du chemin trouvé avec des `*`.

3. **Affichage du labyrinthe en console**  
   - `E` représente le point de départ.  
   - `X` représente le point d'arrivée.  
   - `*` marque le chemin trouvé par le solveur.

## Structure du projet

- **main.cpp**  
  Point d’entrée principal du programme.  
  - Initialise un labyrinthe.  
  - Génère les murs et affiche le labyrinthe.  
  - Utilise le solveur pour trouver le chemin optimal.

- **Maze.h / Maze.cpp**  
  Classe `Maze` gérant :  
  - La structure interne du labyrinthe.  
  - L'affichage du labyrinthe dans la console.

- **MazeGenerator.h / MazeGenerator.cpp**  
  - Génération récursive d'un labyrinthe.  
  - Suppression aléatoire des murs pour créer un chemin.

- **MazeSolver.h / MazeSolver.cpp**  
  - Implémentation de **l’algorithme A\*** pour résoudre le labyrinthe.  
  - Stocke le chemin optimal et l'affiche dans la console.

## Compilation & Exécution

### Compilation

Utilisez `g++` pour compiler le projet (dans le dossier "src") :

```sh
g++ main.cpp Maze.cpp MazeGenerator.cpp MazeSolver.cpp -o MazeRunner
```

### Exécution

```sh
./MazeRunner
```

## Exemples de sortie

Après exécution, un affichage type ressemble à ceci :

```
+--+--+--+--+
|E |     |  |
+  +--+  +  +
|  |  X  |  |
+--+--+--+--+
Chemin trouvé ! (indiqué par '*')
```

## Améliorations possibles

- Ajouter d'autres algorithmes de résolution (**DFS, BFS, Dijkstra**).  
- Ajouter une **interface graphique** pour une meilleure visualisation.  
- Exporter le labyrinthe en format **image** ou **JSON**.

## Auteur

Projet développé en **C++** pour la génération et la résolution de labyrinthes. 🚀
