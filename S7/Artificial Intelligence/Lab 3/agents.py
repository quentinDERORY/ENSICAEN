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
# @file agents.py
#
# @author John DeNero and Dan Klein - UC Berkeley
# @version Regis Clouard.
#

from utils import manhattanDistance
from game import Directions
import random, utils

from game import Agent

def scoreEvaluationFunction( currentGameState ):
  """
    This default evaluation function just returns the score of the state.
    The score is the same one displayed in the Pacman GUI.

    This evaluation function is meant for use with adversarial search agents
    (not reflex agents).
  """
  return currentGameState.getScore()

######
###### Abstract class AgentSearchAgent
######

class AgentSearchAgent( Agent ):
  """
    This abstract class provides some common elements to all of your
    agent searchers.  Any methods defined here will be available
    to the MinimaxPacmanAgent, AlphaBetaPacmanAgent & ExpectimaxPacmanAgent.

    You *do not* need to make any changes here.
  """

  def __init__( self, evalFn = 'scoreEvaluationFunction', depth = '2' ):
    self.index = 0 # Pacman is always agent index 0
    self.evaluationFunction = utils.lookup(evalFn, globals())
    self.depth = int(depth)

  def isTerminalNode( self, gameState, depth ):
    return gameState.isLose() or gameState.isWin() or depth == 0

######
###### Minimax Agent
######

class MinimaxAgent1( AgentSearchAgent ):
  """
  Minimax agent.
  """
  def getAction( self, gameState ):
    """
    Returns the minimax action from the current gameState using self.depth
    and self.evaluationFunction.
    """
    legalActions = gameState.getLegalActions(0)
    nextStates = [gameState.generateSuccessor(0, action) for action in legalActions]
    v = [self.__miniMaxValue(1, nextGameState, self.depth - 1) for nextGameState in nextStates] 
    maxV = max(v)
    listMax = []
    
    # Get the index of maxV
    for i in range(0, len(v)):
      if v[i] == maxV:
        listMax.append(i)
    # random when there is a tie
    i = random.randint(0, len(listMax) - 1)
    action = legalActions[listMax[i]]
    return action

  def __miniMaxValue( self, agentIndex, gameState, depth ):
    if self.isTerminalNode(gameState, depth):
      return self.evaluationFunction(gameState)    
    else:
      legalActions = gameState.getLegalActions(agentIndex)
      nextStates = [gameState.generateSuccessor(agentIndex, action) for action in legalActions]
      if agentIndex == 0: # if it's Pacman then it's a max layer
        return max([self.__miniMaxValue(1 - agentIndex, nextState, depth - 1) for nextState in nextStates])

      else: # else if it's the ghost, then it's a min layer
        return min([self.__miniMaxValue(1 - agentIndex, nextState, depth - 1) for nextState in nextStates])

######
###### Exercise 1
######
class MinimaxAgentN( AgentSearchAgent ):
  """
  Minimax agent with n ghosts.
  """
  def getAction( self, gameState ):
    """
    Returns the minimax action from the current gameState using self.depth
    and self.evaluationFunction.
    """
    legalActions = gameState.getLegalActions(0)
    nextStates = [gameState.generateSuccessor(0, action) for action in legalActions]
    v = [self.__miniMaxValue(1, nextGameState, self.depth - 1) for nextGameState in nextStates] 
    maxV = max(v)
    listMax = []
    
    # Get the index of maxV
    for i in range(0, len(v)):
      if v[i] == maxV:
        listMax.append(i)
    # random when there is a tie
    i = random.randint(0, len(listMax) - 1)
    action = legalActions[listMax[i]]
    return action

  def __miniMaxValue( self, agentIndex, gameState, depth ):
    if self.isTerminalNode(gameState, depth):
      return self.evaluationFunction(gameState)    
    else:
      legalActions = gameState.getLegalActions(agentIndex)
      nextStates = [gameState.generateSuccessor(agentIndex, action) for action in legalActions]
      if agentIndex % gameState.getNumberOfAgents() == 0 : # if it's Pacman then it's a max layer
        return max([self.__miniMaxValue(agentIndex + 1, nextState, depth - 1) for nextState in nextStates])

      else: # else if it's the ghost, then it's a min layer
        return min([self.__miniMaxValue(1 + agentIndex, nextState, depth - 1) for nextState in nextStates])

######
###### Exercise 2
######
class AlphaBetaAgent(AgentSearchAgent):
  """ 
  Your minimax agent with alpha-beta pruning.
  """
  
  def getAction( self, gameState ):

    legalActions = gameState.getLegalActions(0)
    nextStates = [gameState.generateSuccessor(0, action) for action in legalActions]
    v = [self.__miniMAX_VALUE(nextGameState.getNumberOfAgents,1, nextGameState, self.depth - 1,-1000,1000) for nextGameState in nextStates] 
    maxV = max(v)
    listMax = []
    
    # Get the index of maxV
    for i in range(0, len(v)):
      if v[i] == maxV:
        listMax.append(i)
    # random when there is a tie
    i = random.randint(0, len(listMax) - 1)
    action = legalActions[listMax[i]]
    return action

  def __miniMAX_VALUE(self,numberOfAgent, agentIndex, gameState, depth, alpha, beta):

    if self.isTerminalNode(gameState, depth):
      return self.evaluationFunction(gameState)    
    else:
      legalActions = gameState.getLegalActions(agentIndex)
    nextStates = [gameState.generateSuccessor(agentIndex, action) for action in legalActions]
    if agentIndex % numberOfAgent() == 0 : 
      v=max([self.__miniMAX_VALUE(numberOfAgent, agentIndex + 1, nextState, depth - 1,alpha,beta) for nextState in nextStates])
      if(v>=beta):
        alpha=max(alpha,v)
    else: 
      v=min([self.__miniMAX_VALUE(numberOfAgent, agentIndex + 1, nextState, depth - 1,alpha,beta) for nextState in nextStates])
      if(v<=alpha):
        beta=min(beta,v) 
    return v


######
###### Exercise 3
######
class ExpectimaxAgent( AgentSearchAgent ):

  def getAction( self, gameState ):
    """
    Returns the minimax action from the current gameState using self.depth
    and self.evaluationFunction.
    """

    " *** YOUR CODE HERE ***"
    utils.raiseNotDefined()

######
###### Exercise 4
######
def betterEvaluationFunction( currentGameState ):
  """
  Your extreme ghost-hunting, pellet-nabbing, food-gobbling, unstoppable
  evaluation function.  
  """

  " *** YOUR CODE HERE ***"
  utils.raiseNotDefined()

# Abbreviation
better = betterEvaluationFunction
