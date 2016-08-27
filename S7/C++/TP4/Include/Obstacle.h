#ifndef _OBSTACLE_H
#define _OBSTACLE_H

/**
 * @file Obstacle.h
 * @author Mauranyapin Jean-Baptiste 
 * @auhor Derory Quentin
 * @version 1.0
 * @date 13 novembre 2014
 * */


class Obstacle{
 public:

  virtual void recoitPalet()=0;
  bool est_orphelin(){return orphelin;}
  void set_orphelin(bool val){orphelin=val;}
  virtual ~Obstacle()=0;

 private :

  bool orphelin=true;
  
};

#endif
