#ifndef GETCH_H
#define GETCH_H

void initTermios(int echo) ;
void resetTermios(void);
char getch_(int echo);
char getch(void);

#endif