/******************************************************************************
 * to emulate the serial input and output of an 8051 controller               *
 * frontend.hh - ncurses frontend                                             *
 ******************************************************************************/
#ifndef FRONTEND_HEADER
#define FRONTEND_HEADER

#include <sys/types.h>
#include <curses.h>
/*#include <term.h>*/
#include "config.h"

struct COORDS_S
{
  int min_x;
  int max_x;
  int min_y;
  int max_y;
};
typedef struct COORDS_S COORDS;

struct COORDINATES_S
{
  int x;
  int y;
};
typedef struct COORDINATES_S COORDINATES;


class Viewer
{
public:
  Viewer();
  virtual ~Viewer();
  virtual void DrawBox(void);
  virtual void AddStrOutWin(char *string);
  virtual void GetStrInWin(char *string);
  virtual void AddChOutWin(char b);
  virtual char GetChInWin(void);
  
private:
  WINDOW *inp, *outp;
  COORDS win_c, inp_c, outp_c;
  COORDINATES topleft, bottomright, current;
  int middle_y, middle_x;
};

#endif
