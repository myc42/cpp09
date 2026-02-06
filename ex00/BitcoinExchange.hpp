/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:33:48 by macoulib          #+#    #+#             */
/*   Updated: 2026/02/06 12:58:53 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
#include <exception>
#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>

class CantNotOpenFile : public std::exception
 {
                public :
                     
                        virtual const char* what()  const throw() {
                             return "Cant not open file !";
                        };       
} ;