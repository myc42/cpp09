/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:34:07 by macoulib          #+#    #+#             */
/*   Updated: 2026/02/07 18:13:17 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


std::vector <int>   fordJohnsonSortVec ( std::vector <int> &bigtemp )
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


 std::deque <int>   fordJohnsonSortDeq ( std::deque <int>  &bigtemp )
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

int main(int ac, char **av)
{
    std::vector <int> stock ;
    
    try 
    {  
            if(ac < 2) 
            { 
                 std::cerr << "error minimuim 2\n";
                 return 1;
            } 
            for(int i = 1 ; i < ac ;  ++i)
            {
                if (!validInt(av[i]))
                   throw IntError();
                stock.push_back(std::atoi(av[i])) ;
            }
            //la construction par plage vers le début vers la fin  ;Les types doivent être compatibles / convertibles
           std::vector <int> vec(stock.begin(), stock.end()) ;
           std::deque <int> deq (stock.begin(), stock.end());
           vec = fordJohnsonSortVec(vec);
         for (std::vector <int>::iterator  it = vec.begin(); it != vec.end(); ++it)
{
    std::cout << *it << " ";
}
std::cout << std::endl;

        
    }
   catch (const std::exception &e)
   {
         std::cerr << "ERROR: " << e.what() << std::endl;
   }
}