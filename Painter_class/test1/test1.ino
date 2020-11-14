#include "Painter.h"

void setup() {
  // put your setup code here, to run once:
  Painter.setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  int paint_number = 1;

  if(paint_number == 0) {
    Painter.spiral();
  }
  else if(paint_number == 1) {
    Painter.spiral();
  }
  else if(paint_number == 2) {
    Painter.grid();
  }
  else if(paint_number == 3) {
    Painter.lat_lines();
  }
  else if(paint_number == 4) {
    Painter.lon_lines();
  }

  
  
  
  
  
}
