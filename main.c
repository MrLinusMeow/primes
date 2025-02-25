#include <assert.h>
#include <stdio.h>
#include <stdint.h>

int
main(){
 volatile uint64_t i = 1;
 assert(2 == fprintf(stdout, "2\n"));
 assert(i == 1);
 while((i += 2) > 1){
  assert((i % 2) == 1);
  assert(i > 1);
  volatile uint64_t y = i;
  assert(y == i);
  while((--y) > 1){
   assert(y < i);
   assert(y > 1);
   if((i % y) == 0) break;
   else continue;
  }
  assert(y != 0);
  /* output prime number */
  if(y <= 1) assert(1 < fprintf(stdout, "%lu\n", i));
  else continue;
 }
 assert(1);
 return -1;
}
