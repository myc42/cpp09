/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:34:13 by macoulib          #+#    #+#             */
/*   Updated: 2026/02/08 19:46:05 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"

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


bool validInt(std::string av)
{
   if(  av[0] == '+' || av[0] == '-' )
        return (false);
   long result = 0 ;
   for(size_t i = 0 ; i <  av.size() ; ++i)
   {
      if(!std::isdigit(av[i]))
            return  false ;
      result  = result * 10 + (av[i] - '0');
   }
   if(result > INT_MAX)
        return  false ;
   return true ;
}

void PmergeMe::checkAndStock(std::string **av, int ac)
{
    
     for(int i = 1 ; i < ac ;  ++i)
     {      
         if (!validInt(*av[i]))
                   throw IntError();
        _stock.push_back(std::atoi(av[i]->c_str())) ;       
     }
     //la construction par plage vers le début vers la fin  ;Les types doivent être compatibles / convertibles
     _deq = std::deque<int>(_stock.begin(), _stock.end());
     _vec = std::vector<int>(_stock.begin(), _stock.end());
}

// Algo ford 

std::vector <int>   PmergeMe::fordJohnsonSortVec ( std::vector <int> &bigtemp )
{
    
     if(bigtemp.size() <= 1) 
        return bigtemp; // il reste encore du code à exécuter dans l’appel actuel.
     std::vector <int> big ;
     std::vector <int> small;
     std::vector <int> ::iterator it  = bigtemp.begin();
   
     while(it != bigtemp.end())
     {
        int first = *it;
        ++it;
        if(it != bigtemp.end())
        {
            int second = *it;
            if(first > second) {
                big.push_back(first);
                small.push_back(second);
            } else {
                big.push_back(second);
                small.push_back(first);
            }
            ++it; 
        } else {
            big.push_back(first); 
        }
    }
     
    big = fordJohnsonSortVec(big); // Remontée  apres lexe ↑
   

     for (size_t i = 0; i < small.size(); ++i)
     {
        std::vector<int>::iterator pos = std::lower_bound(big.begin(), big.end(), small[i]);
        big.insert(pos, small[i]);
     }
    return big; 
}


 std::deque <int>   PmergeMe::fordJohnsonSortDeq ( std::deque <int>  &bigtemp )
{
     if(bigtemp.size() <= 1) 
        return bigtemp; // il reste encore du code à exécuter dans l’appel actuel.
    std::deque <int>  big ;
     std::deque <int>  small;
      std::deque <int> ::iterator it  = bigtemp.begin();
   
     while(it != bigtemp.end())
     {
        int first = *it;
        ++it;
        if(it != bigtemp.end())
        {
            int second = *it;
            if(first > second) {
                big.push_back(first);
                small.push_back(second);
            } else {
                big.push_back(second);
                small.push_back(first);
            }
            ++it; 
        } else {
            big.push_back(first); 
        }
    }
     
    big = fordJohnsonSortDeq(big); // Remontée  apres lexe ↑
   

     for (size_t i = 0; i < small.size(); ++i)
     {
         std::deque <int> ::iterator pos = std::lower_bound(big.begin(), big.end(), small[i]);
        big.insert(pos, small[i]);
     }
    return big; 
}

   void  PmergeMe::fordJohnsonSort()
   {
        std::cout << "Before: ";
        for (size_t i = 0; i < _vec.size(); ++i)
            std::cout << _vec[i] << " ";
        std::cout << std::endl;
        // time variables 
        std::clock_t	start, end;
        double duration_deq , duration_vec;
        //deq
        start = std::clock();
        std::deque <int>  deq =  fordJohnsonSortDeq(_deq);
        end = std::clock();
        duration_deq = double(end - start) / CLOCKS_PER_SEC;
        //vec
        start = std::clock();
        std::vector <int>  vec =   fordJohnsonSortVec(_vec);
        end = std::clock();
        duration_vec = double(end - start) / CLOCKS_PER_SEC;
        // Affichage
        std::cout << "After: ";
        for (size_t i = 0; i < vec.size(); ++i)
            std::cout << vec[i] << " ";
        std::cout << std::endl;

        std::cout << "Time to process a range of " << deq.size()
          << " elements with std::deque : " << duration_deq << " us" << std::endl;

        std::cout << "Time to process a range of " << vec.size()
          << " elements with std::vector : " << duration_vec << " us" << std::endl;
        
        
   }