/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:34:07 by macoulib          #+#    #+#             */
/*   Updated: 2026/02/08 17:35:11 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


int main(int ac, char **av)
{
 
        if (ac < 2) {
             std::cerr << "ERROR \n";
            return 1;}
        std::string* str_argv[ac];
        for (int i = 0; i < ac; ++i){
            str_argv[i] = new std::string(av[i]);
       } 
       PmergeMe pm;
       pm.checkAndStock(str_argv,ac);
       pm.fordJohnsonSort();
       for (int i = 0; i < ac; ++i){
         delete str_argv[i];
       }
       
     
}