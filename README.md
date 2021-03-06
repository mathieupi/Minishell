# Minishell
[![Team 42Project Score](https://badge42.herokuapp.com/api/project/bledda/minishell)](https://github.com/mathieupi/Minishell)
[![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/mathieupi/Minishell?label=Code%20size&maxAge=3600)](https://github.com/mathieupi/Minishell)
[![norminette](https://github.com/mathieupi/Minishell/workflows/norminette/badge.svg)](https://github.com/mathieupi/Minishell/actions/workflows/norm.yml)

## Le points de minishell

> L'objectif de ce projet est pour vous de crรฉer un shell simple.
> Oui ton petit bash ou zsh. Vous en apprendrez beaucoup sur les processus et les descripteurs de fichiers
>
> ## ๐ PDF
>
> - [**`FICHIER ORIGINAL`**](https://github.com/louchebem06/Docs-42/blob/master/en.minishell.pdf)

## ๐ Contenu

### ๐ฉ Partie obligatoire

| Program name     | minishell                                                                                                                                                                                        |
| :--------------- | :------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Turn in files    |                                                                                                                                                                                        |
| Makefile         | Yes                                                                                                                                                                                          |
| Arguments        |                                                                                 |
| External functs. | readline, rl_on_new_line, rl_replace_line, rl_redisplay, add_history, printf, malloc, free, write, open, read, close, fork, wait, waitpid, wait3, wait4, signal, kill, exit, getcwd, chdir, stat, lstat, fstat, unlink, execve, dup, dup2, pipe, opendir, readdir, closedir, strerror, errno, isatty, ttyname, ttyslot, ioctl, getenv |
| Libft authorized | Yes                                                                                                                                                                                           |
| Description      | รcrire un shell                                                                                                                                                           |

Votre shell doit :
- Ne pas interprรฉter les guillemets non fermรฉs ou les caractรจres spรฉciaux non spรฉcifiรฉs comme \ ou ;.
- N'utilisez pas plus d'une variable globale, rรฉflรฉchissez-y et soyez prรชt ร? expliquer pourquoi ? tu le fais.
- Afficher une invite lors de l'attente d'une nouvelle commande.
- Avoir une histoire de travail.
- Rechercher et lancer le bon exรฉcutable (basรฉ sur la variable PATH ou en utilisant chemin relatif ou absolu)
- Il doit implรฉmenter les commandes intรฉgrรฉes :
	- echo avec l'option -n
	- cd avec seulement un chemin relatif ou absolu
	- pwd sans options
	- export sans options
	- unset sans options
	- env sans options ni arguments
	- exit sans options
- ' inhibe toute interprรฉtation d'une sรฉquence de caractรจres.
- " inhibe toute interprรฉtation d'une sรฉquence de caractรจres ร? l'exception de $.
- Redirections :
	- < doit rediriger l'entrรฉe.
	- \> devrait rediriger la sortie.
	- ยซ << ยป lit l'entrรฉe de la source actuelle jusqu'ร? une ligne contenant uniquement le de-limiteur est vu. il n'a pas besoin de mettre ร? jour l'historique !
	- ">>" devrait rediriger la sortie avec le mode ajout.
- Tuyaux | La sortie de chaque commande dans le pipeline est connectรฉe via un tuyau ausaisie de la commande suivante.
- Les variables d'environnement ($ suivis de caractรจres) doivent se dรฉvelopper jusqu'ร? leurs valeurs.
- $ ? devrait se dรฉvelopper jusqu'ร? l'รฉtat de sortie du premier plan exรฉcutรฉ le plus rรฉcemmentpipeline.
- ctrl-C ctrl-D ctrl-\ devrait fonctionner comme dans bash.
- En mode interactif :
	- ctrl-C imprime une nouvelle invite sur une nouvelle ligne.
	- ctrl-D quitte le shell.
	- ctrl-\ ne fait rien.
- Tout ce qui n'est pas demandรฉ n'est pas obligatoire.
- Pour chaque point, si vous avez le moindre doute, prenez [bash](https://www.gnu.org/savannah-checkouts/gnu/bash/manual/) comme rรฉfรฉrence.

### ๐ฉ Bonus part

- Si la partie obligatoire n'est pas parfaite, ne pensez mรชme pas aux bonus
- &&, || avec des parenthรจses pour les prioritรฉs.
- le joker * devrait fonctionner pour le rรฉpertoire de travail courant.
