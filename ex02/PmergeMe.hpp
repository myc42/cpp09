/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:34:16 by macoulib          #+#    #+#             */
/*   Updated: 2026/02/09 16:29:02 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <string>
#include <climits>   // INT_MAX
#include <cctype> 
#include <vector>
#include <cstdlib>
#include <deque>
#include <ctime>



class PmergeMe
{
          private :
                     std::vector <int> _stock ;
                     std::vector <int> _vec;
                     std::deque <int> _deq;
          public :
                    PmergeMe(){};
                    ~PmergeMe(){};
                    void checkAndStock(std::string **av, int ac);
                    std::vector <int>   fordJohnsonSortVec (std::vector <int> &bigtemp);
                    std::deque <int>   fordJohnsonSortDeq (std::deque <int>  &bigtemp) ;
                    void fordJohnsonSort();
                    PmergeMe( PmergeMe &other);      
                    PmergeMe &operator=( PmergeMe &other);
                    class IntError : public std::exception
 {
                 public :
                     
                        virtual const char* what()  const throw() ;
} ;
                    
};