#! /usr/bin/python -*- coding: utf-8 -*-
#
# ENSICAEN
# École Nationale Supérieure d'Ingénieurs de Caen
# 6 Boulevard Maréchal Juin
# F-14050 Caen Cedex France
#
# Artificial Intelligence 2I1AE1
#

#
# @file engine.py
#
# @author Regis Clouard.
#

"""
This file contains the function stubs for expert system engine.
"""

import copy
from utils import raiseNotDefined

def displayFact( fact ):
     """ Displays a fact. """
     print "   Adding new fact: ", fact
     
def displayRule( rule ):
     """ Displays a rule. """
     line = ""
     for c in rule[0]:
          if len(line) == 0:
               line += str(c)
          else:
               line += " ^ "+ str(c) 
     line += " -> ";
     line += str(rule[1])
     return line

#######
####### Exercise 1
#######
# Working memory
facts = []

# Rule base
rules = []

def addFact( fact ):
     """ Adds a fact to the working memory. 
     @param fact a new fact to introduce in the working memory. """
     global facts
     if fact not in facts:
          facts.append(fact)
     

def addRule( conditions, consequence ):
     """ Adds a rule in the knowledge base.
     @param conditions a condition list ['cond1',...,'cond']
     @param consequence a new fact to add to the working memory. """
     global rules
     rule=[conditions,consequence]
     if rule not in rules:
          rules.append(rule)


#######
####### Exercise 2
#######
def getRulePremise( rule ):
     """ Returns the premise part of the rule. """
     
     return rule[0]

def getRuleConclusion( rule ):
     """ Returns the conclusion part of the rule. """
     
     return rule[1]

#######
####### Exercise 3
#######
def isOneCondition( rule, fact ):
     """ Returns True if the fact matches one
     of the rule conditions.
     @param rule a rule
     @param fact a fact. """ 
     
     conditions=getRulePremise(rule)
     for condition in conditions :
          if fact==condition:
               return True
     return False

#######
####### Exercise 4
#######
def forwardChainingInference( facts, rules ):
     """ The forward chaining engine.
     Keeps on firing rules until there are no rules which can be applied
     on the initial and inferred facts.
     @param rules the list of rules.
     @param initialFacts The initials facts. """
     allfacts=[]
     allfacts=copy.deepcopy(facts)
     inferred=[]
     count=1
     while(count>0):
          count=count-1
          for r in rules :
               i=0
               for fact in allfacts:
                    if(isOneCondition(r,fact)):
                         i=i+1 
                         if(i==len(getRulePremise(r))):
                              conclusion=getRuleConclusion(r)
                              if (conclusion not in allfacts):
                                   allfacts.append(conclusion)
                                   inferred.append(conclusion)
                                   count=count+1
          
          
     return inferred       


          
     

#######
####### Exercise 5
#######
"Probleme je recois query avec chaque élément étant une lettre alors que c'est censé etre des faits"
def backwardChainingInference( query, facts, rules ):
     """ The backward chaining engine.
     @param query the fact to prove.
     @param facts current facts in the knowledge based
     @param rules rules in the knowledge base. """
     for q in query:
          if q not in facts :
               backward=[]
               for r in rules :
                    if q == getRuleConclusion(r):
                         backward.append(r)
               newquery=[]
               for rule in backward:
                    newquery.append(getRulePremise(rule))
               if(len(newquery)==0):
                    return False
               if not backwardChainingInference(newquery,facts,rules):
                    return False
               del(backward[:])
     return True
                    
                   
                    
