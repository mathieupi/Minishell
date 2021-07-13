# Minishell
[![Team 42Project Score](https://badge42.herokuapp.com/api/project/bledda/minishell)](https://github.com/JaeSeoKim/bad)

## Le points de minishell

> L'objectif de ce projet est pour vous de créer un shell simple.
> Oui ton petit bash ou zsh. Vous en apprendrez beaucoup sur les processus et les descripteurs de fichiers
>
> ## 📝 PDF
>
> - [**`FICHIER ORIGINAL`**](https://github.com/louchebem06/Docs-42/blob/master/en.minishell.pdf)

## 🚀 Contenu

### 🚩 Partie obligatoire

| Program name     | minishell                                                                                                                                                                                        |
| :--------------- | :------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Turn in files    |                                                                                                                                                                                        |
| Makefile         | Yes                                                                                                                                                                                          |
| Arguments        |                                                                                 |
| External functs. | readline, rl_on_new_line, rl_replace_line, rl_redisplay, add_history, printf, malloc, free, write, open, read, close, fork, wait, waitpid, wait3, wait4, signal, kill, exit, getcwd, chdir, stat, lstat, fstat, unlink, execve, dup, dup2, pipe, opendir, readdir, closedir, strerror, errno, isatty, ttyname, ttyslot, ioctl, getenv |
| Libft authorized | Yes                                                                                                                                                                                           |
| Description      | Écrire un shell                                                                                                                                                           |

Votre shell doit :
- Ne pas interpréter les guillemets non fermés ou les caractères spéciaux non spécifiés comme \ ou ;.
- N'utilisez pas plus d'une variable globale, réfléchissez-y et soyez prêt à expliquer pourquoi ? tu le fais.
- Afficher une invite lors de l'attente d'une nouvelle commande.
- Avoir une histoire de travail.
- Rechercher et lancer le bon exécutable (basé sur la variable PATH ou en utilisant chemin relatif ou absolu)
- Il doit implémenter les commandes intégrées :
	- echo avec l'option -n
	- cd avec seulement un chemin relatif ou absolu
	- pwd sans options
	- export sans options
	- unset sans options
	- env sans options ni arguments
	- exit sans options
- ' inhibe toute interprétation d'une séquence de caractères.
- " inhibe toute interprétation d'une séquence de caractères à l'exception de $.
- Redirections :
	- < doit rediriger l'entrée.
	- \> devrait rediriger la sortie.
	- « << » lit l'entrée de la source actuelle jusqu'à une ligne contenant uniquement le de-limiteur est vu. il n'a pas besoin de mettre à jour l'historique !
	- ">>" devrait rediriger la sortie avec le mode ajout.
- Tuyaux | La sortie de chaque commande dans le pipeline est connectée via un tuyau ausaisie de la commande suivante.
- Les variables d'environnement ($ suivis de caractères) doivent se développer jusqu'à leurs valeurs.
- $ ? devrait se développer jusqu'à l'état de sortie du premier plan exécuté le plus récemmentpipeline.
- ctrl-C ctrl-D ctrl-\ devrait fonctionner comme dans bash.
- En mode interactif :
	- ctrl-C imprime une nouvelle invite sur une nouvelle ligne.
	- ctrl-D quitte le shell.
	- ctrl-\ ne fait rien.
- Tout ce qui n'est pas demandé n'est pas obligatoire.
- Pour chaque point, si vous avez le moindre doute, prenez [bash](https://www.gnu.org/savannah-checkouts/gnu/bash/manual/) comme référence.

### 🚩 Bonus part

- Si la partie obligatoire n'est pas parfaite, ne pensez même pas aux bonus
- &&, || avec des parenthèses pour les priorités.
- le joker * devrait fonctionner pour le répertoire de travail courant.
