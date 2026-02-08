/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:33:57 by macoulib          #+#    #+#             */
/*   Updated: 2026/02/08 17:48:34 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2) 
    {
            std::cerr << "ERROR: only one argument accepted\n";
            return 1;
    }
    try 
    {
        
        std::string params = av[1];
        RNP rnp;
        rnp.functionPr(params);
    }
   catch (const std::exception &e)
   {
        std::cerr << e.what() << std::endl;
   }
}