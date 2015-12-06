#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gmp.h>
#include "paillier.c"

int main (int argc, char* argv[]){
  paillier_pubkey_t* public;
  paillier_prvkey_t* private;

  paillier_keygen(128,&public,&private,paillier_get_rand_devurandom);



  printf("Public key is : %s\n",paillier_pubkey_to_hex(public));
  printf("Private key is : %s\n",paillier_prvkey_to_hex(private));
  return 0;

}
