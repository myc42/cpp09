/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:34:04 by macoulib          #+#    #+#             */
/*   Updated: 2026/02/08 17:51:28 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <exception>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <cctype>
#include <stack>



class RNP
{
    private :
                 std::stack<double> st ;

    public :
            RNP(){};
            ~RNP(){};
             bool errorHandling(std::string av);
             void functionPr(std::string av);
             class ErrorExcp : public std::exception
             {
                public :
                     
                        virtual const char* what()  const throw() {
                             return "Error ";
                        };       
             } ;
    

    
};