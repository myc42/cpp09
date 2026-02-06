/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:33:57 by macoulib          #+#    #+#             */
/*   Updated: 2026/02/06 17:14:39 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <string>
#include <cctype>
#include <stack>
 bool errorHandling(std::string av)
{
     /*Expression vide → erreur.  Moins de deux nombres quand on rencontre un opérateur → erreur. 
      Reste plus d’un nombre à la fin → erreur.  Division par zéro → erreur.*/ 

    if (av.length() == 1 && std::isdigit(av[0]))
        return true;
    if (av == "+" || av == "-" || av == "*" || av == "/")
        return true;
    return false ;
}
int main(int ac, char **av)
{
    (void)av;
     std::stack<double> st ;
    try 
    {
        if (ac != 2) 
        {
            std::cerr << "ERROR: only one argument accepted\n";
            return 1;
        }
    
        std::string params = av[1];
        std::istringstream iss(params);
        std::string token;

       while (iss >> token) { // lit chaque token séparé par espace
            if(!errorHandling(token)){
              std::cerr << "Error " << "\n";
              return (1);
            }
            if(token != "+" &&   token != "-"  &&  token != "/" && token != "*" )
                  st.push(atof(token.c_str())) ;
           else{
            
            if(st.size() < 2)
            {
                
                std::cerr<< "Error \n";
                return (1);
            }
               
            if(token == "+" ){
                 double firstx = st.top();    
                 st.pop();
                 double secondx = st.top();
                 st.pop();
                 st.push( secondx + firstx );
            }
             if(token == "-" ){
                 double firstx = st.top();    
                 st.pop();
                 double secondx = st.top();
                 st.pop();
                 st.push( secondx - firstx );
            }
             if(token == "*" ){
                 double firstx = st.top();    
                 st.pop();
                 double secondx = st.top();
                 st.pop();
                 st.push( secondx * firstx );
                 
            }
             if(token == "/" ){
                 double firstx = st.top();    
                 st.pop();
                 double secondx = st.top();
                 st.pop();
                 st.push( secondx / firstx );
                 
            }  
              }
        
            
       }
     
       if (!st.empty()) {
        std::cout << "Résultat : " << st.top() << std::endl;
       }
        
    }
   catch (const std::exception &e)
   {
        
   }
}