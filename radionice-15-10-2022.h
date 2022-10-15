#pragma once
#include "helper.h"
void RobotLine::radionica() {
  if (setup()) {
    armOpen();
  }
  // ZADATAK: uvedite varijablu brojača.
  // HINT: static int nazivVarijable = vrijednost;
  static int broj = 0;

  // VARIJABLA ZA PRETVORBU BROJA U TEKST
  char simbol[10 + sizeof(char)];

  // ZADATAK: skretanje s povećanjem brojača
  if (front() < 120) {
    go(-90, 90);
    delayMs(500);
    broj++;
  }
  if (rightFront() > 120)
    go(80, 20);
  else
    go(20, 80);

  // PRETVORBA VARIJABLE BROJAČA U TEKST
  sprintf(simbol, "%d", broj);
  // ZADATAK
  display(simbol);
  if (leftFront() < 220 and broj == 3) {
  go(-120, 120);
    delayMs(200);
    go(80, 80);
    delayMs(500);
    armCatchReady();
    delayMs(50);
    armCatch();
    armOpen();
  }
}
