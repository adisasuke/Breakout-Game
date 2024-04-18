#ifndef INTERACTION_H
#define INTERACTION_H

#include"entity.h"
#include"ball.h"
#include"paddle.h"
#include"brick.h"

bool isInteraction(entity& a,entity &b);

//handle collision between ball and paddle
void handleCollision(ball& b,paddle& p);

//handle collision between ball and brick
void handleCollision(ball& b,brick &br);



#endif