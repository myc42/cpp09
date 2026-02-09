/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:33:48 by macoulib          #+#    #+#             */
/*   Updated: 2026/02/08 21:39:16 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
#include <exception>
#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>


class Btc
{
     private :
                std::map<std::string, double> btcBD ; 
                std::string line;
                double value ;
                std::ifstream _fd;
                std::ifstream _inputfd;
     public :
              Btc();
             ~Btc();
             void OpenDb(const  std::string& val);
             void CompareDb(const std::string& val);
             void reorgDB(const  std::string& line);
             class CantNotOpenFile : public std::exception
             {
                public :
                     
                        virtual const char* what()  const throw() ;
             } ;
              Btc( Btc &other) ;
              Btc &operator=( Btc &other) ;
               
};