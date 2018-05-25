#include "cards.h"

int main(void) {
  card_t c;
  c.value = 11;
  c.suit = SPADES;
  print_card(c);
  card_t r = card_from_num(15);
  print_card(r);
  
  return 0;
}
