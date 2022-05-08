// Copyright 2021 NNTU-CS
#include "train.h"

void Train::addCage(bool light) {
  if (!first) {
  first = create(true);
  } else if (first->prev == nullptr) {
    first->next = create(light);
    first->next->prev = first;
    first->next->next = first;
    first->prev = first->next;
  } else {
    first->prev->next = create(light);
    first->prev->next->next = first;
    first->prev->next->prev = first->prev;
    first->prev = first->prev->next;
  }
}

int Train::getLenght() {
  now = first;
  while (first->light) {
    shagi = 0;
    do {
      shagi += 1;
      countOp += 1;
      now = now->next;
    } while (!now->light);
      now->light = false;
      countOp += shagi;
      now = first;
    }
  return shagi;
}

int Train::getOpCount() {
  return countOp;
}
