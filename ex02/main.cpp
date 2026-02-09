/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:34:07 by macoulib          #+#    #+#             */
/*   Updated: 2026/02/09 17:36:45 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


int main(int ac, char **av)
{
 
        if (ac < 2) {
             std::cerr << "Error \n";
            return 1;}
         std::string* str_argv[ac];
       
       try{
        
        for (int i = 0; i < ac; ++i){
            str_argv[i] = new std::string(av[i]);
       }
             PmergeMe pm;
            pm.checkAndStock(str_argv,ac);
            pm.fordJohnsonSort();
            for (int i = 0; i < ac; ++i){
              delete str_argv[i];
            }
       }catch (const std::exception &e) {
        for (int i = 0; i < ac; ++i){
              delete str_argv[i];
            }
        std::cerr  << e.what() << std::endl;
        return 1;
    }
       
     
}