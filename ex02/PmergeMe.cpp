/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:34:13 by macoulib          #+#    #+#             */
/*   Updated: 2026/02/07 13:57:15 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Exemple simple (8 éléments)

Supposons la séquence :
[8, 3, 7, 1, 6, 2, 5, 4]

Étape 1 : Création des paires

Paires : (8,3), (7,1), (6,2), (5,4)

Après tri dans la paire : (3,8), (1,7), (2,6), (4,5)

Étape 2 : Récupérer les grands

Grands : [8,7,6,5] → trier → [5,6,7,8]

Étape 3 : Insérer les petits

Petits : [3,1,2,4] → insérer un par un dans [5,6,7,8] à la bonne position

Résultat : [1,2,3,4,5,6,7,8]

Tout est trié, comparaisons minimisées.

Étape 1 : Pairing

Parcours du container 2 par 2

Stocke les grands et petits séparément (par exemple 2 vectors temporaires)

Étape 2 : Trier les grands

Récursif ou insertion (souvent insertion suffit pour un petit nombre d’éléments)

Étape 3 : Insertion des petits

Parcours des petits dans l’ordre inverse (pour minimiser les déplacements)

Insère dans le container déjà trié à la position correcte

Étape 4 : Retourner la séquence triée

Les deux containers (vector et deque) suivent la même logique, mais avec des itérateurs adaptés

*/

