#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gmp.h>
#include "paillier.c"

int main (int argc, char* argv[]){
  if( argc == 2 ) {

    printf("The salary is: %s\n",argv[1]);
    paillier_plaintext_t* amt = paillier_plaintext_from_ui( atoi(argv[1]));
                                                                                                               
    paillier_pubkey_t* publicKey;
    publicKey = paillier_pubkey_from_hex("91b6a0c0e8374bac6d4e75f2497ff89f") ;
    

   paillier_ciphertext_t* encr;
   encr = paillier_enc(NULL, publicKey,amt,paillier_get_rand_devurandom); 
   char* result_string = mpz_get_str(NULL, 10, encr->c);
   
   printf("The encrypted value is: %s\n",result_string);
				     
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
