#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(c.value <= VALUE_ACE && c.value >= 2);
  assert(c.suit <= CLUBS && c.suit >= SPADES);
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r)
  {
    case STRAIGHT_FLUSH: return "STRAIGHT_FLUSH";
      break;
    case FOUR_OF_A_KIND: return "FOUR_OF_A_KIND";
      break;
    case FULL_HOUSE: return "FULL_HOUSE";
      break;
    case FLUSH: return "FLUSH";
      break;
    case STRAIGHT: return "STRAIGHT";
      break;
    case THREE_OF_A_KIND: return "THREE_OF_A_KIND";
      break;
    case TWO_PAIR: return "TWO_PAIR";
      break;
    case PAIR: return "PAIR";
      break;
    case NOTHING: return "NOTHING";
      break;
    default: return "Something went wrong";
  }
}

char value_letter(card_t c) {
  switch(c.value)
  {
    case 2: return '2';
      break;
    case 3: return '3';
      break;
    case 4: return '4';
      break;
    case 5: return '5';
      break;
    case 6: return '6';
      break;
    case 7: return '7';
      break;
    case 8: return '8';
      break;
    case 9: return '9';
      break;
    case 10: return '0';
      break;
    case VALUE_JACK: return 'J';
      break;
    case VALUE_QUEEN: return 'Q';
      break;
    case VALUE_KING: return 'K';
      break;
    case VALUE_ACE: return 'A';
      break;
    default: return 'S';
  }
}


char suit_letter(card_t c) {
  switch(c.suit)
  {
    case SPADES: return 's';
      break;
    case HEARTS: return 'h';
      break;
    case DIAMONDS: return 'd';
      break;
    case CLUBS: return 'c';
      break;
    case NUM_SUITS: return 'n';
      break;
    default: return 'L';
  }
}

void print_card(card_t c) {
  c.value = value_letter(c);
  c.suit = suit_letter(c);
  printf("%c%c", c.value, c.suit);
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  switch(value_let)
  {
    case '2': temp.value = 2;
      break;
    case '3': temp.value = 3;
      break;
    case '4': temp.value = 4;
      break;
    case '5': temp.value = 5;
      break;
    case '6': temp.value = 6;
      break;
    case '7': temp.value = 7;
      break;
    case '8': temp.value = 8;
      break;
    case '9': temp.value = 9;
      break;
    case '0': temp.value = 10;
      break;
    case 'J': temp.value = 11;
      break;
    case 'Q': temp.value = 12;
      break;
    case 'K': temp.value = 13;
      break;
    case 'A': temp.value = 14;
      break;
  }
  switch(suit_let)
  {
    case 's': temp.suit = SPADES;
      break;
    case 'h': temp.suit = HEARTS;
      break;
    case 'd': temp.suit = DIAMONDS;
      break;
    case 'c': temp.suit = CLUBS;
      break;
    case 'n': temp.suit = NUM_SUITS;
      break;
  }
  assert_card_valid(temp);
  return temp;
}

card_t card_from_num(unsigned c) {
  assert (c < 52 && c >= 0);
  card_t temp;
  temp.value = c % 13 + 2;
  temp.suit = c / 13;
  assert_card_valid(temp);
  return temp;
}
