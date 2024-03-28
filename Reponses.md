# Réponse aux questions du TD 5

## Exercice 1 - Copie du processus courant
1. Ce programme affiche les éléments liés au processus parent, et affiche tout de suite après les éléments liés au processus fils.
2. Les 'printf' du fils s'exécute quand même lors de la mort du parent. Le parent n'attend pas que le fils ait terminé, ce qui affiche les 'printf' du fils à la suite du shell.
3. Le parent du processus fils change de parent car le parent n'existe plus. Lors de sa mort, le processus fils prend le PPID du parent (généralement le shell).
4. Ce programme créé 3 processus fils (via fork), affiche leur PID (via parent et fils) et attend la fin des processus fils.
5. La variable `s` récupère le code de retour du fils. Il faut utiliser la méthode `WEXITSTATUS` pour récupérer le bon code de sortie (division par 8 bits).
6. On remarque que le fork s'applique/s'exécute avant l'insertion de sa valeur dans `tabpid`. Le fork commence son exécution à partir de la ligne suivante, sans prendre en compte l'affectation précédente.
7. Rajouter un `fork` donne comme résultat une image avec des lignes de couleurs alternés. Cela est dû au curseur de lecture qui sont communs aux deux: une mise à jour de l'un met à jour l'autre.
8. Même chose mais les couleurs sont tronqués.

## Exercice 2 - Éxécution
1. ✅
2. ✅

## Exercice 3 - Tubes et redirections
1. L'appel système `pipe` utilise un tableau de deux descripteurs de fichiers en paramètre lors de son exécution. Le 1er élément du tableau contient le fd pour `read`, le 2nd élément du tableau contient le fd pour `write`. Sa particularité est qu'il permet de transiter des informations entre le parent et le(s) fils de façon très simpliste. Chaque déclaration de `read` (avec fd[0]) dans le fils attend une nouvelle valeur provoqué par le parent (via fd[1]).
2. Le programme `ex3pipe` créé un pipe avant de fork. Une fois le fork fait, le parent écrit "Bonjour" dans le pipe (via fd[1]), le fils récupère/lit la valeur du parent depuis le pipe (via fd[0]).
3. `0` est le fd de l'entrée standard, `1` est le fd de la sortie standard.
4. ✅
