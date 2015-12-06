#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gmp.h>
#include "paillier.c"

int main (int argc, char* argv[]){
  if( argc == 2 ) {
    unsigned long int amount = strtoul(argv[1],NULL,0);
    printf("The argument supplied is %d\n", amount);
    
    paillier_pubkey_t* publicKey;
    publicKey = paillier_pubkey_from_hex("91b6a0c0e8374bac6d4e75f2497ff89f") ;
    
   paillier_plaintext_t* amt = paillier_plaintext_from_ui( amount);

   paillier_ciphertext_t* encr;
   encr = paillier_enc(0, publicKey,amt,paillier_get_rand_devurandom); 
   gmp_printf("Encrypted %d is %Zd\n",amount,encr);

   FILE *f;
   f = fopen("encrypt.txt", "w");
   gmp_fprintf(f,"%Zd\n",encr);
   fclose(f);
    
  }
  else if( argc > 2 ) {
    printf("Too many arguments supplied.\n");
  }
  else {
    printf("One argument expected.\n");
  }



}
