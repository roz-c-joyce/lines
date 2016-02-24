#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  //check which
  int x, y, xe, ye;
  x = x0;
  y = y0;
  xe = x1;
  ye = y1;
  if(x0 > x1){
    draw_line(x1, y1, x0, y0, s, c);
    return;
  }
  if(y0>y1){//negative slope
    if(abs(ye - y) > abs(xe - x)){//octant 3 7
      O37(x0, y0, x1, y1, s, c);
    }
    else{//octant 4 8
      O48(x0, y0, x1, y1, s, c);
    }
  }
  else{//positive slope
    if(abs(ye - y) > abs(xe - x)){//octant 2 6
      O26(x0, y0, x1, y1, s, c);
    }
    else{//octant 1 5
      printf("[DRAW]madeoct1\n");
      O15(x0, y0, x1, y1, s, c);
    }
  }
  /*
  //oct 1 5
  d = 2 * A + B;
  while(x < xe){
    plot(s, c, x, y);
    if(d > 0){
      y += 1;
      d += 2 * B;
    }
    x += 1;
    d += 2 * A;
  }
  
  //oct 2 6
  d = 2 * B + A;
  while(y < ye){
    plot(s, c, x, y);
    if(d < 0){
      x += 1;
      d += 2 * A;
    }
    y += 1;
    d += 2 * B;
  }

  //oct 3 7
  d = 2 * B + A;
  while(y < ye){
    plot(s, c, x, y);
    if(d < 0){
      x += 1;
      d += 2 * A;
    }
    y -= 1;
    d += 2 * B;
  }

  //oct 4 8
  d = 2 * A + B;
  while(x < xe){
    plot(s, c, x, y);
    if(d > 0){
      y -= 1;
      d += 2 * B;
    }
    x += 1;
    d += 2 * A;
  }*/
}

void O15(int x0, int y0, int x1, int y1, screen s, color c){
  int d, A, B, x, xe, y, ye;
  x = x0;
  y = y0;
  xe = x1;
  ye = y1;
  A = xe - x;
  B = -1 * (ye - y);
  d = 2 * A + B;
  while(x < xe){
    plot(s, c, x, y);
    if(d > 0){
      y += 1;
      d += 2 * B;
    }
    x += 1;
    d += 2 * A;
  }
  return;
}

void O26(int x0, int y0, int x1, int y1, screen s, color c){
  int d, A, B, x, xe, y, ye;
  x = x0;
  y = y0;
  xe = x1;
  ye = y1;
  A = xe - x;
  B = -1 * (ye - y);
  d = 2 * B + A;
  while(y < ye){
    plot(s, c, x, y);
    if(d < 0){
      x += 1;
      d += 2 * A;
    }
    y += 1;
    d += 2 * B;
  }
  return;
}

void O37(int x0, int y0, int x1, int y1, screen s, color c){
  int d, A, B, x, xe, y, ye;
  x = x0;
  y = y0;
  xe = x1;
  ye = y1;
  A = xe - x;
  B = -1 * (ye - y);
  d = 2 * B + A;
  while(y < ye){
    plot(s, c, x, y);
    if(d < 0){
      x += 1;
      d += 2 * A;
    }
    y -= 1;
    d += 2 * B;
  }
  return;
}

void O48(int x0, int y0, int x1, int y1, screen s, color c){
  int d, A, B, x, xe, y, ye;
  x = x0;
  y = y0;
  xe = x1;
  ye = y1;
  A = xe - x;
  B = -1 * (ye - y);
  d = 2 * A + B;
  while(x < xe){
    plot(s, c, x, y);
    if(d > 0){
      y -= 1;
      d += 2 * B;
    }
    x += 1;
    d += 2 * A;
  }
  return;
}
