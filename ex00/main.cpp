/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:33:51 by macoulib          #+#    #+#             */
/*   Updated: 2026/02/09 17:20:35 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int ac, char **av)
{
     try {
        if(ac == 1){
             std::cerr << "Error: could not open file.\n";
            return 1;
        }
            if (ac != 2) {
             std::cerr << "ERROR: only one argument accepted\n";
            return 1;
        }
        const std::string data = "data.csv";
        const std::string av1 = av[1];
        Btc btc;
        btc.OpenDb(data);
        btc.CompareDb(av1);
        
     }catch (const std::exception &e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return 1;
    }
}